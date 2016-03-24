#include "load.h"
int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	Load load(&app);
	return app.exec();
}