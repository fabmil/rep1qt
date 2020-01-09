#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    w.setWindowTitle("rep v1");
    w.resize(900, 800);
    w.show();

    return a.exec();
}
