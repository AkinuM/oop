#ifndef SIGN_UP_MENU_H
#define SIGN_UP_MENU_H

#include <QDialog>
#include <database.h>

namespace Ui {
class sign_up_menu;
}

class sign_up_menu : public QDialog
{
    Q_OBJECT

public:
    explicit sign_up_menu(bank *bank, QWidget *parent = nullptr);
    ~sign_up_menu();

private slots:
    void on_pushButton_clicked();

    void on_sign_up_button_clicked();

private:
    Ui::sign_up_menu *ui;
    bank *bankk;
};

#endif // SIGN_UP_MENU_H
