#include "error.h"
using namespace std;

Error::Error() {
	//error window
	Eh1 = new QHBoxLayout;
	Ev1 = new QVBoxLayout;
	Eh2 = new QHBoxLayout;
	Ewindow = new QWidget;
	Emsg = new QLabel("Error -");// create a dummy
	Ebutton1 = new QPushButton("Ok");
	Eh2 -> addWidget(Emsg);
	Eh1->addWidget(Ebutton1);
	Ev1 -> addLayout(Eh2);
	Ev1->addLayout(Eh1);
	Ewindow->setLayout(Ev1);
	Ewindow->setWindowTitle("Error");
	Ebutton1->setDefault(true);
	QObject::connect(Ebutton1, SIGNAL(clicked()), this, SLOT(quit()));
}

Error::~Error() {
	delete Ebutton1;
	delete Emsg;
	delete Eh1;
	delete Eh2;
	delete Ev1;
	delete Ewindow;

}

void Error::quit(){
	Ewindow -> hide();// quit is to hide the windows
}

void Error::show(){
	Ewindow -> show();
}
void Error::jump(){
	Emsg -> setText("Error - Illeagal jump instruction");//if called,set the msg to Illeagal jump
}
void Error::div(){
	Emsg -> setText("Error - Divide by zero exception");
}

void Error::load(){
	Emsg -> setText("Error - Wrong file name. Reload!");
}
