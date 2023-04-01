#include "mainwindow.h"
#include "ui_mainwindow.h"


QProcess proc;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&proc, &QProcess::readyReadStandardOutput, this, &MainWindow::slotDataOnStdout);
    connect(&proc, &QProcess::readyReadStandardError, this, &MainWindow::slotDataOnStderr);
    QMainWindow::setWindowIcon(QIcon(":recources/window_icon.ico"));
    ms = 0;
    s = 0;
    m = 0;
    h = 0;
    d = 0;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerSlot()));
    flag = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerSlot()
{
    s++;
    if (s >= 60) {
        s=0;
        m++;
    }
    if (m>=60) {
        m=0;
        h++;
    }
    if (h>24) {
        h=0;
        d++;
    }
    ui->upTime->setText(QString::number(d) + "d:" + QString::number(h) + "h:" + QString::number(m) + "m:" + QString::number(s) + "s");
}

void MainWindow::on_exploreButton_clicked()
{
    QString directory = QFileDialog::getOpenFileName(0,
                                                  tr("Run file"));

    if (!directory.isEmpty()) {
        ui->pathLineEdit->setText(QString("no path"));
    }
    ui->pathLineEdit->setText(directory);
}

void MainWindow::on_runButton_clicked()
{
        if(flag == false) {
            ui->consoleStdError->clear();
            ui->consoleStdOutput->clear();
            QString filePath = ui->pathLineEdit->text();
            if (filePath.isEmpty()) {
                QMessageBox::warning(this, tr("Path Error | Telerunner"),
                                               tr("Enter the path using the field above, or the button \"...\""),
                                               QMessageBox::Cancel);
            }
            else {
                QString executeCommand;
    #ifdef Q_OS_LINUX
            executeCommand = "python3 -u";
    #else
            executeCommand = "python -u";
    #endif
                proc.start(QString("%1 %2").arg(executeCommand).arg(filePath));
                ui->runButton->setText(tr("STOP"));
                flag = true;
                ui->upTime->setText("0d:0h:0m:0s");
                timer->start(1000);
                // set running color
                ui->telerunner->setStyleSheet("QLabel#telerunner{color: #61b06e; border-radius: 10px; border: 3px solid #61b06e; background-color: white; }");
                }
        } else {
            flag = false;
            // set default color
            ui->telerunner->setStyleSheet("QLabel#telerunner{color: #0088cc; border-radius: 10px; border: 3px solid #0088cc; background-color: white; }");
            ui->runButton->setText(tr("Run"));
            ms = 0;
            s = 0;
            m = 0;
            h = 0;
            d = 0;
            timer->stop();
            proc.close();
        }

}

void MainWindow::slotDataOnStdout()
{
    QString output = proc.readAllStandardOutput().toStdString().c_str();
    ui->consoleStdOutput->append(output);
}

void MainWindow::slotDataOnStderr()
{
    QString output = proc.readAllStandardError().toStdString().c_str();
    ui->consoleStdError->append(output);
}


void MainWindow::on_actionSettings_triggered()
{
    QMessageBox::information(this, tr("Development..."),
                                   tr("Development proces..."),
                                   QMessageBox::Cancel);
}


void MainWindow::on_actionAuthor_triggered()
{
    QMessageBox::about(this, tr("About"),
                       tr("This program was created for convenient "
                          "GUI hosting of telegram bots, created for developers "
                          "of telegram bots and for those who just need convenient hosting. \n\n"
                          "This program can be installed on a WIndows GUI server, "
                          "Full-fledged CLI tool for Ubuntu Server version will be released soon"));
}

void MainWindow::on_clearButton_clicked()
{
    ui->consoleStdError->clear();
    ui->consoleStdOutput->clear();
}

void MainWindow::on_actionGithub_triggered()
{
    QDesktopServices service;
    QUrl link = QUrl("https://github.com/vR4eslav/trunner");
    service.openUrl(link);
}

void MainWindow::on_botGitUpdateButton_clicked()
{
    QString url = ui->urlGitRepoEdit->text();
    if (url.isEmpty()) {
        QMessageBox::warning(this, tr("Url Error | Telerunner"),
                                       tr("Enter the link using the field above"),
                                       QMessageBox::Cancel);
    }
    else {
        QString executeCommand;
        executeCommand = "git pull";
        proc.start(QString("%1 %2").arg(executeCommand).arg(url));

    }
}

void MainWindow::on_actionEdit_triggered()
{
    EnvEdit *envEdit = new EnvEdit;
    envEdit->exec();
}
