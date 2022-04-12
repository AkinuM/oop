#ifndef SPECIALIST_MENU_H
#define SPECIALIST_MENU_H

#include <QDialog>
#include "database.h"

namespace Ui {
class specialist_menu;
}

class specialist_menu : public QDialog
{
    Q_OBJECT

public:
    explicit specialist_menu(bank *bank, int ID, QWidget *parent = nullptr);
    ~specialist_menu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::specialist_menu *ui;
    bank *bankk;
    int ID;
};

#endif // SPECIALIST_MENU_H
