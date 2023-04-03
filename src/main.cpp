#include "mainwindow.h"

#include <QApplication>
//#include <QTranslator>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "readability-static-accessed-through-instance"

// TODO complete translations change with registry
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
//    QTranslator translator;
//    translator.load("po/trunner_ru_RU.qm", ".");
//    app.installTranslator(&translator);

    QFont font("Arial");
    app.setFont(font);
    MainWindow w;
    w.show();
    return app.exec();
}

#pragma clang diagnostic pop
