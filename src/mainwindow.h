#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "envedit.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

public slots:

    void timerSlot();

    void onExploreButtonClicked();

    void onRunButtonClicked();

    void slotDataOnStdout();

    void slotDataOnStderr();

    void onActionSettingsTriggered();

    void onActionAuthorTriggered();

    void onClearButtonClicked();

    void onActionGithubTriggered();

    void onBotGitUpdateButtonClicked();

    void onActionEditTriggered();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int ms, s, m, h, d;
    bool flag;
};

#endif // MAINWINDOW_H