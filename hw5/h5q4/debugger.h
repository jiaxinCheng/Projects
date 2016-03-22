#include "src/Statement.h"
#include "src/LetStatement.h"
#include "src/PrintStatement.h"
#include "src/IfStatement.h"
#include "src/EndStatement.h"
#include "src/PrintAllStatement.h"
#include "src/GotoStatement.h"
#include "src/AddStatement.h"
#include "src/SubStatement.h"
#include "src/MultStatement.h"
#include "src/DivStatement.h"
#include "src/ReturnStatement.h"
#include "src/GosubStatement.h"
#include "msort.h"
#include <iostream>
#include <string>
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
using namespace std;

class Debugger : public QWidget {
	Q_OBJECT
	public slots:
		void step();
		void quit();
		void load();
		void addBreak();
		void removeBreak();
		void acontinue();
		void reload();
		void inspect();
		void Iquit();
		void Update();
		void NameSI();
		void NameSD();
		void NumSI();
		void NumSD();
		void next();
	public:
		Debugger(QApplication *app);
		~Debugger();
	private:
		//load window
		QLabel *Lname;
		QPushButton *Lbutton1, *Lbutton2;
		QLineEdit* Lfile;
		QWidget *Lwindow;
		QHBoxLayout *Lh1;
		QHBoxLayout *Lh2;
		QVBoxLayout *Lv1;
		//error window
		QLabel *Emessage;
		QPushButton *Ebutton;
		QVBoxLayout *Ev1;
		QWidget *Ewindow;

		//inspect window 
		QListWidget *Inspect;
		QVBoxLayout *Iv1;
		QWidget *Iwindow;
		QHBoxLayout *Ih1;
		QHBoxLayout *Ih2;
		QHBoxLayout *Ih3, *Ih4;
		QPushButton *Ibutton1, *Ibutton2, *Ibutton3;
		QPushButton *Ibutton4, *Ibutton5, *Ibutton6;


		QApplication *app;
		QPushButton *button1, *button2, *button3;
		QPushButton *button4, *button5, *button6;
		QPushButton *button7;
		QListWidget *combo;
		QWidget *window;
		QHBoxLayout *h1, *h2;
		QHBoxLayout *h3;
		QVBoxLayout *v1;
		QVBoxLayout *v2;



		QFile* Facile;
		vector<Statement *> program;
		vector <int> breakpoints;
		ProgramState *state;
		vector<pair<string,int> > *values;

		bool debugsearch(int l, int r,int x);
		Statement* parseLine(string line);
		void updatevalue();
		int update;

};