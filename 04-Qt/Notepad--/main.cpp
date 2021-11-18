#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QLocale>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator tr;
    //if(tr.load(":/lang/" + QLocale::system().name() + ".qm"))
    if(tr.load(":/lang/pt_BR.qm"))
        a.installTranslator(&tr);

    MainWindow w;
    w.show();

    return a.exec();
}
