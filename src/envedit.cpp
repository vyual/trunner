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

void EnvEdit::on_exploreBtn_clicked() {
    QString directory = QFileDialog::getOpenFileName(nullptr,
                                                     tr("Run file"));

    if (!directory.isEmpty()) {
        envEditUi->pathToEnv->setText(QString("no path"));
    }
    envEditUi->pathToEnv->setText(directory);
}

void EnvEdit::on_openEnv_clicked() {
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

void EnvEdit::on_saveBtn_clicked() {
    QString directory = envEditUi->pathToEnv->text();
    QFile env(directory);
    QByteArray a = QString(envEditUi->envBrowser->toPlainText()).toUtf8();
    if (env.open(QIODevice::WriteOnly)) {
        env.write(a);
    }

}

void EnvEdit::on_closeBtn_clicked() {
    EnvEdit::close();
}

// todo auto explore .env func
void EnvEdit::on_autoFind_clicked() {

}
