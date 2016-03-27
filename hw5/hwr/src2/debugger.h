#include "../src/Statement.h"
#include "../src/LetStatement.h"
#include "../src/PrintStatement.h"
#include "../src/IfStatement.h"
#include "../src/EndStatement.h"
#include "../src/PrintAllStatement.h"
#include "../src/GotoStatement.h"
#include "../src/AddStatement.h"
#include "../src/SubStatement.h"
#include "../src/MultStatement.h"
#include "../src/DivStatement.h"
#include "../src/ReturnStatement.h"
#include "../src/GosubStatement.h"
#include "inspect.h"
#include "error.h"
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

class Debugger : public QWidget {
	Q_OBJECT
	public slots: 
		void step(); // step functions that used to connect to the button step
		void quit(); //quit function
		void Break(); // break slots that used to add and remove breakpoints
		void acontinue(); // continue
		void next();
		void inspect();
	public:
		Debugger(std::vector<Statement *> a, std::vector<QString> b);
		~Debugger();
		void show();
	private:
		//declaring all of the elements needed for GUI
		QPushButton *button1, *button2, *button3;
		QPushButton *button4, *button5, *button6;
		QListWidget *combo;
		QWidget *window;
		QHBoxLayout *h1, *h2;
		QVBoxLayout *v1;
		QVBoxLayout *v2;
		//vector of breakpoints
		std::vector <int> breakpoints;
		//binary search for sorted vector breakpoints
		int debugsearch(int l, int r,int x);
		ProgramState *state;
		std::vector<Statement *> prog; 
		std::vector<QString> disp;
		Inspect *inspect1; // has a pointer for inspect 
		Error *error1; // has a pointer for error

};