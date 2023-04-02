#include "mainwindow.h"

#include <QApplication>
//#include <QTranslator>

// TODO complete translations change with registry
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
//    QTranslator translator;
//    translator.load("po/trunner_ru_RU.qm", ".");
//    a.installTranslator(&translator);

    QFont font("Arial");
    QApplication::setFont(font);
    MainWindow w;
    w.show();
    return QApplication::exec();
}
