#include "envedit.h"
#include "ui_envedit.h"

EnvEdit::EnvEdit(QWidget *parent) :
        QDialog(parent),
        envEditUi(new Ui::EnvEdit) {
    envEditUi->setupUi(this);
}

EnvEdit::~EnvEdit() {
    delete envEditUi;
}

void EnvEdit::onExploreBtnClicked() {
    QString directory = QFileDialog::getOpenFileName(nullptr,
                                                     tr("Run file"));

    if (!directory.isEmpty()) {
        envEditUi->pathToEnv->setText(QString("no path"));
    }
    envEditUi->pathToEnv->setText(directory);
}

void EnvEdit::onOpenEnvClicked() {
    QString directory = envEditUi->pathToEnv->text();
    if (directory.isEmpty()) {
        QMessageBox::warning(this, tr("Path Error | Telerunner"),
                                   tr("Enter the path using the field above, or the button \"...\""),
                                   QMessageBox::Cancel);
    } else {
        QFile env(directory);
        if (env.open(QIODevice::ReadWrite)) {
            envEditUi->envBrowser->setText(env.readAll());
        }
    }

}

void EnvEdit::onSaveBtnClicked() {
    QString directory = envEditUi->pathToEnv->text();
    QFile env(directory);
    QByteArray a = QString(envEditUi->envBrowser->toPlainText()).toUtf8();
    if (env.open(QIODevice::WriteOnly)) {
        env.write(a);
    }

}

void EnvEdit::onCloseBtnClicked() {
    EnvEdit::close();
}

void EnvEdit::onAutoFindClicked() {
    QString envPath = QApplication::applicationDirPath() + "/.env";
    if (QFile::exists(envPath)) {
        // загрузить файл .env
    } else {
        QMessageBox::warning(this, "Warning", ".env file not found.");
    }
}

