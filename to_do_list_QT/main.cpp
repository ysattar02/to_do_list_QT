#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Fix For Menu Bar Not Showing
    QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar);

    MainWindow w;
    w.show();
    return a.exec();
}
