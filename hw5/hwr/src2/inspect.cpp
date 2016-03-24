#include "inspect.h"
using namespace std;

Inspect::Inspect(std::vector<std::pair<std::string,int> > a, ProgramState* b) {
	update = 1;
	state = b;
	values  = a;
	//Inspect window
	Iwindow = new QWidget;
	Iv1 = new QVBoxLayout;
	Ih1 = new QHBoxLayout;
	Ih2 = new QHBoxLayout;
	Ih3 = new QHBoxLayout;
	Ih4 = new QHBoxLayout;
	inspect = new QListWidget;
	Ibutton1 = new QPushButton("Update");
	Ibutton2 = new QPushButton("Sort by name(I)");
	Ibutton3 = new QPushButton("Sort by name(D)");
	Ibutton4 = new QPushButton("Sort by value(I)");
	Ibutton5 = new QPushButton("Sort by value(D)");
	Ibutton6 = new QPushButton("Quit");
	Ih1 -> addWidget(inspect);
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
	QObject::connect(Ibutton6, SIGNAL(clicked()), this, SLOT(quit()));
	QObject::connect(Ibutton1, SIGNAL(clicked()), this, SLOT(Update()));
	QObject::connect(Ibutton2, SIGNAL(clicked()), this, SLOT(NameSI()));
	QObject::connect(Ibutton3, SIGNAL(clicked()), this, SLOT(NameSD()));
	QObject::connect(Ibutton4, SIGNAL(clicked()), this, SLOT(NumSI()));
	QObject::connect(Ibutton5, SIGNAL(clicked()), this, SLOT(NumSD()));
}

Inspect::~Inspect() {
	delete Ibutton1;
	delete Ibutton2;
	delete Ibutton3;
	delete Ibutton4;
	delete Ibutton5;
	delete Ibutton6;
	delete Ih1;
	delete Ih2;
	delete Ih3; 
	delete Ih4;
	delete Iv1;
	delete Iwindow;

}

void Inspect::show(){
	Iwindow -> show();

}

void Inspect::Update(){
	while(inspect->count() >0){
		inspect -> takeItem(0);
	}
	stringstream ss;
	values = state -> getValue();
	if(update == 1){
		NameCompI comp;
		mergeSort(values, comp);
	}
	else if (update ==2){
		NameCompD comp2;
		mergeSort(values, comp2);
	}
	else if (update ==3){
		NumCompI comp3;
		mergeSort(values, comp3);
	}
	else {
		NumCompD comp4;
		mergeSort(values,comp4);
	}
	for (unsigned int i = 0; i < values.size(); i++){
		string temp;
		ss<< values[i].first << ":" << values[i].second;
		ss >> temp;
		ss.clear();
		inspect -> addItem(QString::fromStdString(temp));
	}
}
void Inspect::NameSI(){
	update = 1;
}
void Inspect::NameSD(){
	update = 2;
}
void Inspect::NumSI(){
	update = 3;
}
void Inspect::NumSD(){
	update = 4;
}
void Inspect::quit(){
	Iwindow -> hide();
}
void Inspect::inspectI(){
	stringstream ss;
	NameCompI comp;
	update =1;
	mergeSort(values, comp);
	for (unsigned int i = 0; i < values.size(); i++){
		string temp;
		ss<< values[i].first << ":" << values[i].second;
		ss >> temp;
		ss.clear();
		inspect -> addItem(QString::fromStdString(temp));
	}
}