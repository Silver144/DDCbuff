#include "DDCbuff.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DDCbuff w;
	w.show();
	return a.exec();
}
