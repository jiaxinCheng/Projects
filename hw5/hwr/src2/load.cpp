#include "load.h"
using namespace std;

Load::Load(QApplication *app) {
	this->app = app;
	//load window
	vector <QString> tempa;
	debug = new Debugger(program,tempa);
	error2 = new Error;
	Lh1 = new QHBoxLayout;
	Lfile = new QLineEdit;
	Lv1 = new QVBoxLayout;
	Lh2 = new QHBoxLayout;
	Lwindow = new QWidget;
	Lname = new QLabel("filename");
	Lbutton1 = new QPushButton("load");
	Lbutton2 = new QPushButton("quit");
	Facile = new QFile(Lfile -> text());
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
}

Load::~Load() {
	delete Lfile;
	delete Lbutton1;
	delete Lbutton2;
	delete Lname;
	delete Facile;
	delete Lh1;
	delete Lh2;
	delete Lv1;
	delete Lwindow;
	delete error2;

}
void Load::load(){
	delete Facile;
	Facile = new QFile(Lfile -> text());
	if (Lfile -> text().isEmpty()){
		return;
	}
	vector <QString> temp;
	if (Facile ->open(QIODevice::ReadOnly)){
		program.push_back(NULL);
		QTextStream in(Facile);
		while (!in.atEnd()){
      		QString line = in.readLine();
    		string a =  line.toStdString();
    		temp.push_back(line);
    		program.push_back(parseLine(a));
		}
		delete debug;
		debug = new Debugger(program,temp);
		Facile -> close();
		Lwindow -> hide();
		debug -> show();
	}
	else {
		error2 -> load();
		error2 -> show();
		Lfile -> clear();
	}
}

void Load::quit(){
	QApplication::exit();
}

Statement * Load::parseLine(string line)
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
	else if (type == "PRINT"){
		ss >> var;
		statement = new PrintStatement(var);
	}
	else if (type == "END"|| type == "."){
		statement = new EndStatement();
	}
	else if (type == "IF"){
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
	else if (type == "PRINTALL"){
		statement = new PrintAllStatement();
	}

	else if (type == "GOTO"){
		ss >> val;
		statement = new GotoStatement(val);
	}

	else if (type == "ADD"){
		string something;
		ss >> var;
		ss >> something;
		statement = new AddStatement(var, something);
	}
	else if (type == "SUB"){
		string something;
		ss >> var;
		ss >> something;
		statement = new SubStatement(var, something);
	}
	else if (type == "MULT"){
		string something;
		ss >> var;
		ss >> something;
		statement = new MultStatement(var, something);
	}
	else if (type == "DIV"){
		string something;
		ss >> var;
		ss >> something;
		statement = new DivStatement(var, something);
	}
	
	else if (type == "GOSUB"){
		ss >> val;
		statement = new GosubStatement(val);
	}
	
	else{
		statement = new ReturnStatement();
	}
	return statement;
}