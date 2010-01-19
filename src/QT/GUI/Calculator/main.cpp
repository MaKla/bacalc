#include <QtGui/QApplication>
#include "qtguicalculator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qtGuiCalculator w;
    w.show();
    return a.exec();
}
