#ifndef USER_MENU_H
#define USER_MENU_H
#pragma once
#include <QDialog>
#include "database.h"
#include <QStandardItemModel>
#include <controllers/user_controller.h>
#include "deposit_credit_menu.h"

namespace Ui {
class user_menu;
}

class user_menu : public QDialog
{
    Q_OBJECT

public:
    explicit user_menu(bank *bank, int ID, QWidget *parent = nullptr);
    ~user_menu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_freeze_button_clicked();

    void on_unfreeze_button_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::user_menu *ui;
    bank *bankk;
    int ID;
    QStandardItemModel *table;
};

#endif // USER_MENU_H
