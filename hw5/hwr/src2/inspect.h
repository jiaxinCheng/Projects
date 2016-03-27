#include "../src/GotoStatement.h"
#include "../src/AddStatement.h"
#include "../src/SubStatement.h"
#include "../src/MultStatement.h"
#include "../src/DivStatement.h"
#include "../src/ReturnStatement.h"
#include "../src/GosubStatement.h"
#include "msort.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QListWidget>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

class Inspect : public QWidget {
	Q_OBJECT
	public slots:
		void Update();
		void NameSI();
		void NameSD();
		void NumSI();
		void NumSD();
		void quit();
	public:
		Inspect(std::vector<std::pair<std::string,int> > a, ProgramState* b); //pass in a vector of pair and programstate
		~Inspect();
		void show();
		void inspectI();
	private:
		QListWidget *inspect;
		QVBoxLayout *Iv1;
		QWidget *Iwindow;
		QHBoxLayout *Ih1;
		QHBoxLayout *Ih2;
		QHBoxLayout *Ih3, *Ih4;
		QPushButton *Ibutton1, *Ibutton2, *Ibutton3;
		QPushButton *Ibutton4, *Ibutton5, *Ibutton6;
		vector <pair<string, int> > values;
		ProgramState* state;
		int update;//update value to see the way to search
};