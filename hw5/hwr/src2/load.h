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
#include "debugger.h"

class Load : public QWidget {
	Q_OBJECT
	public slots:	
		void quit();
		void load();
	public:
		Load(QApplication *app);
		~Load();
	private:
		//load window
		QLabel *Lname;
		QPushButton *Lbutton1, *Lbutton2;
		QLineEdit* Lfile;
		QWidget *Lwindow;
		QHBoxLayout *Lh1;
		QHBoxLayout *Lh2;
		QVBoxLayout *Lv1;
		QApplication *app;
		QFile* Facile;
		vector<Statement *> program;
		Debugger *debug;
		Statement* parseLine(std::string line);
		Error *error2;
};