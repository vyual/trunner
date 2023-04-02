#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>
#include <QDebug>
#include <QDesktopServices>
#include <QTimer>
#include <QMainWindow>
#include "envedit.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private slots:

    void timerSlot();

    void on_exploreButton_clicked();

    void on_runButton_clicked();

    void slotDataOnStdout();

    void slotDataOnStderr();

    void on_actionSettings_triggered();

    void on_actionAuthor_triggered();

    void on_clearButton_clicked();

    void on_actionGithub_triggered();

    void on_botGitUpdateButton_clicked();

    void on_actionEdit_triggered();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int ms, s, m, h, d;
    bool flag;
};

#endif // MAINWINDOW_H
