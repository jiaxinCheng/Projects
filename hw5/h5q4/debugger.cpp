#include "debugger.h"
using namespace std;

Debugger::Debugger(QApplication *app) {
	int update = 0;
	state = new ProgramState(1);
	values  = new vector <pair<string, int> >;
	this->app = app;
	//load window
	Lh1 = new QHBoxLayout;
	Lfile = new QLineEdit;
	Lv1 = new QVBoxLayout;
	Lh2 = new QHBoxLayout;
	Lwindow = new QWidget;
	Lname = new QLabel("filename");
	Lbutton1 = new QPushButton("load");
	Lbutton2 = new QPushButton("quit");
	Lh2 -> addWidget(Lname);
	Lh2 -> addWidget(Lfile);
	Lh1->addWidget(Lbutton1);
	Lh1->addWidget(Lbutton2);
	Lv1 -> addLayout(Lh2);
	Lv1->addLayout(Lh1);
	Lwindow->setLayout(Lv1);
	Lwindow->setWindowTitle("Load");
	Lwindow->show();
	//Lbutton1->setDefault(true);
	//Lbutton1 -> setAutoDefault(true);
	QObject::connect(Lfile, SIGNAL(returnPressed()), this, SLOT(load()));
	QObject::connect(Lbutton1, SIGNAL(clicked()), this, SLOT(load()));
	QObject::connect(Lbutton2, SIGNAL(clicked()), this, SLOT(quit()));
	//error window 
	Emessage = new QLabel("Error - cannot open the file, please provide correct filename");
	Ebutton = new QPushButton("reload file");
	Ev1 = new QVBoxLayout;
	Ewindow = new QWidget;
	Ev1 -> addWidget(Emessage);
	Ev1 -> addWidget(Ebutton);
	Ewindow -> setLayout(Ev1);
	Ewindow -> setWindowTitle("ERROR");
	Ebutton -> setDefault(true);
	QObject::connect(Ebutton, SIGNAL(clicked()), this, SLOT(reload()));

	//Inspect window
	Iwindow = new QWidget;
	Iv1 = new QVBoxLayout;
	Ih1 = new QHBoxLayout;
	Ih2 = new QHBoxLayout;
	Ih3 = new QHBoxLayout;
	Ih4 = new QHBoxLayout;
	Inspect = new QListWidget;
	Ibutton1 = new QPushButton("Update");
	Ibutton2 = new QPushButton("Sort by name(I)");
	Ibutton3 = new QPushButton("Sort by name(D)");
	Ibutton4 = new QPushButton("Sort by value(I)");
	Ibutton5 = new QPushButton("Sort by value(D)");
	Ibutton6 = new QPushButton("Quit");
	Ih1 -> addWidget(Inspect);
	Ih2 -> addWidget(Ibutton2);
	Ih2 -> addWidget(Ibutton3);
	Ih3 -> addWidget(Ibutton4);
	Ih3 -> addWidget(Ibutton5);
	Ih4 -> addWidget(Ibutton1);
	Ih4 -> addWidget(Ibutton6);
	Iv1 -> addLayout(Ih1);
	Iv1 -> addLayout(Ih2);
	Iv1 -> addLayout(Ih3);
	Iv1 -> addLayout(Ih4);
	Iwindow -> setLayout(Iv1);
	Iwindow -> setWindowTitle("Inspect");
	QObject::connect(Ibutton6, SIGNAL(clicked()), this, SLOT(Iquit()));
	QObject::connect(Ibutton1, SIGNAL(clicked()), this, SLOT(Update()));
	QObject::connect(Ibutton2, SIGNAL(clicked()), this, SLOT(NameSI()));
	QObject::connect(Ibutton3, SIGNAL(clicked()), this, SLOT(NameSD()));
	QObject::connect(Ibutton4, SIGNAL(clicked()), this, SLOT(NumSI()));
	QObject::connect(Ibutton5, SIGNAL(clicked()), this, SLOT(NumSD()));

	// main debugger
	h1 = new QHBoxLayout;
	combo = new QListWidget;
	v1 = new QVBoxLayout;
	v2 = new QVBoxLayout;
	h2 = new QHBoxLayout;
	h3 = new QHBoxLayout;
	window = new QWidget;
	button1 = new QPushButton("Step");
	button2 = new QPushButton("Next");
	button3 = new QPushButton("Continue");
	button4 = new QPushButton("Break");
	button5 = new QPushButton("Inspect");
	button6 = new QPushButton("Quit");
	button7 = new QPushButton("RemoveBreak");
	h1->addWidget(button1);
	h1->addWidget(button2);
	h1->addWidget(button3);
	v1->addWidget(combo);
	v1->addLayout(h1);
	h2 -> addWidget(button4);
	h2 -> addWidget(button5);
	h2 -> addWidget(button6);
	h3 -> addWidget(button7);
	v1 -> addLayout(h2);
	v1 -> addLayout(h3);
	window->setLayout(v1);
	window->setWindowTitle("Debugger");
	//window->show();
	QObject::connect(button1, SIGNAL(clicked()), this, SLOT(step()));
	QObject::connect(button6, SIGNAL(clicked()), this, SLOT(quit()));
	QObject::connect(button4, SIGNAL(clicked()), this, SLOT(addBreak()));
	QObject::connect(button7, SIGNAL(clicked()), this, SLOT(removeBreak()));
	QObject::connect(button3, SIGNAL(clicked()), this, SLOT(acontinue()));
	QObject::connect(button5, SIGNAL(clicked()), this, SLOT(inspect()));
	QObject::connect(button2, SIGNAL(clicked()), this, SLOT(next()));
}

Debugger::~Debugger() {
	/*delete h1;
	delete v1;
	delete combo;
	delete button1;
	delete button2;
	delete button3;
	delete window;
	delete Lh1;
	delete Lv1;
	delete Lh2;
	delete Lfile;
	delete Lbutton1;
	delete Lbutton2;
	delete Lwindow;
	delete Lname;
	delete Facile;*/

}
void Debugger::step() {
	int num = state -> getline();
	if(!state -> endcheck()){
		program[num] -> execute(state, cout);	
		if (state -> getline() == -1){
			QMessageBox::information(window, "Error", "Divide by zero exception");
			//combo -> item(num-1) -> setForeground(Qt::black);
		}
		else if (state -> getline() ==-2){
			QMessageBox::information(window, "Error", "Illegal jump instruction");
			//combo -> item(num-1) -> setForeground(Qt::black);
		}
		else {
			combo -> item(num-1) -> setForeground(Qt::black);
			combo -> item(state ->getline()-1) -> setForeground(Qt::red);
		}
	}
	else {
		return;
	}
}

void Debugger::load(){
	if (Lfile -> text().isEmpty()){
		return;
	}

	Facile = new QFile(Lfile -> text());
	program.push_back(NULL);
	if (Facile ->open(QIODevice::ReadOnly)){
		QTextStream in(Facile);
		while (!in.atEnd()){
      		QString line = in.readLine();
    		combo -> addItem(line);
    		string a =  line.toStdString();
    		program.push_back(parseLine(a));
		}
		state -> setStatement(program.size()-1);
		Facile -> close();
		combo -> item(0) -> setForeground(Qt::red);
		Lwindow -> hide();
		window -> show();
	}
	else {
		Ewindow -> show();
	}
	
}

void Debugger::quit(){
	//for(unsigned int i = 0; i < breakpoints.size();++i){
	//	cout << breakpoints[i] <<endl;
	//}
	QApplication::exit();
}
void Debugger::removeBreak(){
	int row = combo -> currentRow();
	int i = 0;
	if (breakpoints.size() == 0){
		return;
	}
	while(row+1 > breakpoints[i]){ 
		++i;
	}
	if (row +1 == breakpoints[i]){
		breakpoints.erase(breakpoints.begin()+i);
		combo -> item(row) -> setBackground(Qt::white);
	}
	else{
		return;
	}
	
}
void Debugger::addBreak(){
	int row =  combo ->currentRow();
	if (breakpoints.size() ==0){
		breakpoints.push_back(row+1);
		combo -> item(row) -> setBackground(Qt::yellow);
	}
	else{
		int i = 0;
		if (row +1 < breakpoints[0]){
			breakpoints.insert(breakpoints.begin(), row+1);
			combo -> item(row) -> setBackground(Qt::yellow);
			return;
		}
		else if (row +1 > breakpoints[breakpoints.size()-1]){
			breakpoints.push_back(row+1);
			combo -> item(row) -> setBackground(Qt::yellow);
			return;
		}
		while(row+1 > breakpoints[i]) {	
			++i;
		}
		if (row+1 == breakpoints[i+1]){
			return;
		}			
		breakpoints.insert(breakpoints.begin()+i, row+1);
		combo -> item(row) -> setBackground(Qt::yellow);	
	}
}

Statement * Debugger::parseLine(string line)
{
	Statement * statement;	
	stringstream ss;
	string type;
	string var;
	int val;

	ss << line;
	ss >> type;
	
	if ( type == "LET" )
	{
		ss >> var;
		ss >> val;
		statement = new LetStatement(var, val);
	}
	if (type == "PRINT"){
		ss >> var;
		statement = new PrintStatement(var);
	}
	if (type == "END"|| type == "."){
		statement = new EndStatement();
	}
	if (type == "IF"){
		ss >> var;
		string oper;
		ss >> oper;
		ss >> val;
		string then;
		ss >> then;
		int lnum;
		ss >> lnum;
		statement = new IfStatement(var,val,oper,lnum);
	}
	if (type == "PRINTALL"){
		statement = new PrintAllStatement();
	}

	if (type == "GOTO"){
		ss >> val;
		statement = new GotoStatement(val);
	}

	if (type == "ADD"){
		string something;
		ss >> var;
		ss >> something;
		statement = new AddStatement(var, something);
	}
	if (type == "SUB"){
		string something;
		ss >> var;
		ss >> something;
		statement = new SubStatement(var, something);
	}
	if (type == "MULT"){
		string something;
		ss >> var;
		ss >> something;
		statement = new MultStatement(var, something);
	}
	if (type == "DIV"){
		string something;
		ss >> var;
		ss >> something;
		statement = new DivStatement(var, something);
	}
	
	if (type == "GOSUB"){
		ss >> val;
		statement = new GosubStatement(val);
	}
	
	if(type == "RETURN"){
		statement = new ReturnStatement();
	}
	
	
	// Incomplete;  TODO:  Finish this function!
	//what remaining are the number operations
	
	return statement;
}
void Debugger::acontinue(){
	int num = state -> getline();
	if (num <0){
		return;
	}
	combo -> item(num-1) -> setForeground(Qt::black);
	program[num] -> execute(state,cout);
	if (state -> getline() == -1){
		QMessageBox::information(window, "Error", "Divide by zero exception");
	}
	if (state -> getline() ==-2){
		QMessageBox::information(window, "Error", "Illegal jump instruction");
	}
	while(state -> endcheck()!= true && !debugsearch(0,breakpoints.size()-1,state->getline())){
		program[state->getline()] -> execute(state,cout);

		if (state -> getline() == -1){
			QMessageBox::information(window, "Error", "Divide by zero exception");
		}
		if (state -> getline() ==-2){
			QMessageBox::information(window, "Error", "Illegal jump instruction");
		}
	}
	if (state -> getline() >0){
		combo -> item(state -> getline()-1) -> setForeground(Qt::red);
	}
	
}

bool Debugger::debugsearch(int l, int r, int x){
	int m = (l+r)/2;
	if (l > r){
		return false;
	}
	else if (x == breakpoints[m]){
		return true;
	}
	else if(x > breakpoints[m]){
		return debugsearch(m+1,r,x);
	}
	else {
		return debugsearch(l,m-1,x);
	}
}

void Debugger::reload(){
	Ewindow -> hide();
	Lfile -> clear();
} 
void Debugger::updatevalue(){
	vector <std::pair <string, int> > temp = state -> getValue();
	for (unsigned int i =0; i < temp.size();++i){
		std::pair<string,int> mypair(temp[i].first,temp[i].second);
		values->push_back(mypair);
	}
}
void Debugger::inspect(){
	updatevalue();
	if (Inspect -> count() >0){
		Iwindow -> show();
		return;
	}
	stringstream ss;
	vector<pair<string,int> > v=*values;
	NameCompI comp;
	mergeSort(v, comp);
	for (unsigned int i = 0; i < values ->size(); i++){
		string temp;
		ss<< v[i].first << ":" << v[i].second;
		ss >> temp;
		ss.clear();
		Inspect -> addItem(QString::fromStdString(temp));
	}
	Iwindow -> show();
}

void Debugger::Iquit(){
	Iwindow -> hide();
}

void Debugger::Update(){
	if (update == 0) {
		return;
	}
	while(Inspect->count() >0){
		Inspect -> takeItem(0);
	}
	stringstream ss;
	vector<pair<string,int> > v=*values;
	if(update == 1){
		NameCompI comp;
		mergeSort(v, comp);
	}
	else if (update ==2){
		NameCompD comp2;
		mergeSort(v, comp2);
	}
	else if (update ==3){
		NumCompI comp3;
		mergeSort(v, comp3);
	}
	else {
		NumCompD comp4;
		mergeSort(v,comp4);
	}
	for (unsigned int i = 0; i < values ->size(); i++){
		string temp;
		ss<< v[i].first << ":" << v[i].second;
		ss >> temp;
		ss.clear();
		Inspect -> addItem(QString::fromStdString(temp));
	}
}
void Debugger::NameSI(){
	update = 1;
}
void Debugger::NameSD(){
	update = 2;
}
void Debugger::NumSI(){
	update = 3;
}
void Debugger::NumSD(){
	update = 4;
}
void Debugger::next(){
	int num = state -> getline();
	if(!state -> endcheck()){
		if (!state -> getGosub()){
			program[num] -> execute(state, cout);	
			if (state -> getline() == -1){
				QMessageBox::information(window, "Error", "Divide by zero exception");
				//combo -> item(num-1) -> setForeground(Qt::black);
			}
			else if (state -> getline() ==-2){
				QMessageBox::information(window, "Error", "Illegal jump instruction");
				//combo -> item(num-1) -> setForeground(Qt::black);
			}
			else {
				combo -> item(num-1) -> setForeground(Qt::black);
				combo -> item(state ->getline()-1) -> setForeground(Qt::red);
			}
		}
		else {
			combo -> item(num-1) -> setForeground(Qt::black);
			while (state -> getGosub()){
				program[state -> getline()] -> execute(state,cout);
				if (state -> getline() == -1){
					QMessageBox::information(window, "Error", "Divide by zero exception");
					break;
					//combo -> item(num-1) -> setForeground(Qt::black);
				}
				else if (state -> getline() ==-2){
					QMessageBox::information(window, "Error", "Illegal jump instruction");
					break;
					//combo -> item(num-1) -> setForeground(Qt::black);
				}
			}
			combo -> item(state -> getline()-1) -> setForeground(Qt::red);
		}
	}
	else {
		return;
	}
}
