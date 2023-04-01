#ifndef ENVEDIT_H
#define ENVEDIT_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class EnvEdit;
}

class EnvEdit : public QDialog
{
    Q_OBJECT

public:
    explicit EnvEdit(QWidget *parent = nullptr);
    ~EnvEdit();

private slots:
    void on_exploreBtn_clicked();

    void on_openEnv_clicked();

    void on_saveBtn_clicked();

    void on_closeBtn_clicked();

    void on_autoFind_clicked();

private:
    Ui::EnvEdit *envEditUi;
};

#endif // ENVEDIT_H
