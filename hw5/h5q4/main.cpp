#include "debugger.h"
int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	Debugger debug(&app);
	return app.exec();
}