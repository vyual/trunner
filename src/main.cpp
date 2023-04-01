#include "mainwindow.h"

#include <QApplication>
//#include <QTranslator>

// TODO complete translations change with registry
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QTranslator translator;
//    translator.load("po/trunner_ru_RU.qm", ".");
//    a.installTranslator(&translator);

    MainWindow w;
    w.show();
    return a.exec();
}
