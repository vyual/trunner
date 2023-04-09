#include "mainwindow.h"


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "readability-static-accessed-through-instance"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QTranslator translator;

    bool loaded = translator.load("trunner_ru_RU.qm", ".");
    if (!loaded) {
        qDebug() << "Failed to load translator!";
    } else {
        qDebug() << "Translator loaded successfully.";
    }

    MainWindow w;
    w.show();
    return app.exec();
}

#pragma clang diagnostic pop
