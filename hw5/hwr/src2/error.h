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

class Error : public QWidget {
	Q_OBJECT
	public slots:	
		void quit();
	public:
		Error();
		~Error();
		void jump();
		void div();
		void show();
		void load();
	private:
		//error window
		QLabel *Emsg;
		QPushButton *Ebutton1;
		QWidget *Ewindow;
		QHBoxLayout *Eh1;
		QHBoxLayout *Eh2;
		QVBoxLayout *Ev1;
};