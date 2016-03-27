#include "debugger.h"

using namespace std;

Debugger::Debugger(vector<Statement *> a, vector<QString> b) {
	prog = a; //initiate the vector of statements in order to execute later
	disp = b; // all the statement needed to be showed 
	// main debugger set up
	error1 = new Error; //declare error in case that the user did not get an error
	vector <std::pair <string, int> > temp1;
	inspect1 = new Inspect(temp1,state);
	h1 = new QHBoxLayout;
	combo = new QListWidget;
	v1 = new QVBoxLayout;
	v2 = new QVBoxLayout;
	h2 = new QHBoxLayout;
	window = new QWidget;
	button1 = new QPushButton("Step");
	button2 = new QPushButton("Next");
	button3 = new QPushButton("Continue");
	button4 = new QPushButton("Break");
	button5 = new QPushButton("Inspect");
	button6 = new QPushButton("Quit");
	h1->addWidget(button1);
	h1->addWidget(button2);
	h1->addWidget(button3);
	v1->addWidget(combo);
	v1->addLayout(h1);
	h2 -> addWidget(button4);
	h2 -> addWidget(button5);
	h2 -> addWidget(button6);
	v1 -> addLayout(h2);
	window->setLayout(v1);
	window->setWindowTitle("Debugger");

	state = new ProgramState(1);
	state -> setStatement(prog.size()-1);
	// let combo show all the statement the Facile program has
	for (unsigned int i = 0; i < disp.size(); ++i){
		combo -> addItem(disp[i]);
	}
	//connect all the button with slots
	QObject::connect(button1, SIGNAL(clicked()), this, SLOT(step()));
	QObject::connect(button6, SIGNAL(clicked()), this, SLOT(quit()));
	QObject::connect(button4, SIGNAL(clicked()), this, SLOT(Break()));
	QObject::connect(button3, SIGNAL(clicked()), this, SLOT(acontinue()));
	QObject::connect(button5, SIGNAL(clicked()), this, SLOT(inspect()));
	QObject::connect(button2, SIGNAL(clicked()), this, SLOT(next()));
}

Debugger::~Debugger() {
	delete error1;
	delete inspect1;
	delete h1;
	delete h2;
	delete v1;
	delete v2;
	delete combo;
	delete button1;
	delete button2;
	delete button3;
	delete button4;
	delete button5;
	delete button6;
	delete window;
	delete state;
}
void Debugger::step() {
	int num = state -> getline();
	prog[num] -> execute(state, cout);	//execute one line first
	if (state -> getline() == -1){ //if divide by zero, show error
			error1 -> div();
			error1 -> show();
	}
	else if (state -> getline() ==-2){ // if illeagal jump, show error window
		error1 -> jump();
		error1 -> show();
	}
	else {
		combo -> item(num-1) -> setForeground(Qt::black); //cancel visual effect for previous line
		combo -> item(state ->getline()-1) -> setForeground(Qt::red); // visual effect
	}
	if(state -> endcheck()){ // if end reset the program state and start the program again
		combo -> item(num-1) -> setForeground(Qt::black);
		delete state;
		state = new ProgramState(1);
		state -> setStatement(disp.size());
		combo -> item(0) -> setForeground(Qt::red);
	}
}

void Debugger::quit(){
	QApplication::exit();
}

void Debugger::Break(){
	int row =  combo ->currentRow();
	int i = debugsearch(0,breakpoints.size()-1,row+1); //search if the row is already a breakpoint
	if (breakpoints.size() ==0){ // if there is no breakpoints previous, add break 
		breakpoints.push_back(row+1);
		combo -> item(row) -> setBackground(Qt::yellow);
	}
	if (i>0){ //if current line is already a breakpoint remove it
		breakpoints.erase(breakpoints.begin()+i);
		combo -> item(row) -> setBackground(Qt::white);
	}
	else{ // if not, add the current line into the breakpoint vector and keep the vector sorted
		if (row +1 < breakpoints[0]){
			breakpoints.insert(breakpoints.begin(), row+1);
			combo -> item(row) -> setBackground(Qt::yellow);
		}
		else if (row +1 > breakpoints[breakpoints.size()-1]){
			breakpoints.push_back(row+1);
			combo -> item(row) -> setBackground(Qt::yellow);
		}
		else {
			while(row+1 > breakpoints[i]) {	
				++i;
			}			
			breakpoints.insert(breakpoints.begin()+i, row+1);
			combo -> item(row) -> setBackground(Qt::yellow);	
		}
	}
}

void Debugger::acontinue(){
	int num = state -> getline();// get the next line that neede to be executed
	prog[num] -> execute(state,cout); //execute one line 
	combo -> item(num-1) -> setForeground(Qt::black); // cancel the visual effect of previous
	if (state -> getline() == -1){// if there is error, show error window
		error1 -> div();
		error1 -> show();	
	}
	else if (state -> getline() ==-2){
		error1 -> jump();
		error1 -> show();	
	}
	while(!state -> endcheck()&&debugsearch(0,breakpoints.size()-1,state->getline()) ==-1){
		//while the program is not end and the next line is not a breakpoint,execute the program
		prog[state->getline()] -> execute(state,cout);
		if (state -> getline() == -1){
			error1 -> div();
			error1 -> show();
			break;
		}
		else if (state -> getline() ==-2){
			error1 -> jump();
			error1 -> show();
			break;
		}
	}
	if (state -> getline() >0 && !state -> endcheck()){ // if there is no error and program not end
		combo -> item(state -> getline()-1) -> setForeground(Qt::red);
	}
	if(state -> endcheck()){ // if program terminated, reset the program
		combo -> item(num-1) -> setForeground(Qt::black);
		delete state;
		state = new ProgramState(1);
		state -> setStatement(disp.size());
		combo -> item(0) -> setForeground(Qt::red);
	}
}

int Debugger::debugsearch(int l, int r, int x){ //binart search for the breakpoints
	int m = (l+r)/2;
	if (l > r){
		return -1;
	}
	else if (x == breakpoints[m]){
		return m;
	}
	else if(x > breakpoints[m]){
		return debugsearch(m+1,r,x);
	}
	else {
		return debugsearch(l,m-1,x);
	}
}

void Debugger::next(){
	int val = state -> getGosub();//get gosub, if every gosub will increase gosub by one, every return decrease one
	int num = state -> getline();
	prog[num] -> execute(state, cout); // first execute one line 
	int val2 = state -> getGosub();	// check gosub again
	if (val == val2){// if not changed, there is no gosub, everything is the same as step		 
		if (state -> getline() == -1){
			error1 -> div();
			error1 -> show();
		}
		else if (state -> getline() ==-2){
			error1 -> jump();
			error1 -> show();
		}
		else {
			combo -> item(num-1) -> setForeground(Qt::black);
			combo -> item(state ->getline()-1) -> setForeground(Qt::red);
		}
	}
	else {	// or there is a gosub
		combo -> item(num-1) -> setForeground(Qt::black);
		while (val < state -> getGosub() && !state -> endcheck()){// while the program not changed and the val is smaller than current gosub value
			prog[state -> getline()] -> execute(state,cout);
			if (state -> getline() == -1){
				error1 -> div();
				error1 -> show();
				break;
			}
			else if (state -> getline() ==-2){
				error1 -> jump();
				error1 -> show();
				break;
			}
		}
	}
	if(state -> endcheck()){ // if program ends, reset
		combo -> item(num-1) -> setForeground(Qt::black);
		delete state;
		state = new ProgramState(1);
		state -> setStatement(disp.size());
		combo -> item(0) -> setForeground(Qt::red);
	}
}

void Debugger::show(){ //public function of show, for load to used
	window -> show();
}

void Debugger::inspect(){ 
	vector <std::pair <string, int> > temp = state -> getValue();
	delete inspect1;// delete previous inspect and create a new one to be used
	inspect1 = new Inspect(temp,state);
	inspect1 ->inspectI();
	inspect1 -> show(); // show inspect
}