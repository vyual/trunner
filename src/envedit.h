#ifndef ENVEDIT_H
#define ENVEDIT_H

#include <QtWidgets>

namespace Ui {
    class EnvEdit;
}

class EnvEdit : public QDialog {
Q_OBJECT

public:
    explicit EnvEdit(QWidget *parent = nullptr);

    ~EnvEdit() override;

public slots:

    void onExploreBtnClicked();

    void onOpenEnvClicked();

    void onSaveBtnClicked();

    void onCloseBtnClicked();

    void onAutoFindClicked();

private:
    Ui::EnvEdit *envEditUi;
};

#endif // ENVEDIT_H