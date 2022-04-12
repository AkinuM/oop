#ifndef DEPOSIT_CREDIT_MENU_H
#define DEPOSIT_CREDIT_MENU_H
#pragma once
#include <QDialog>
#include <controllers/user_controller.h>
#include <database.h>
#include "user_menu.h"
#include <QStandardItemModel>

namespace Ui {
class deposit_credit_menu;
}

class deposit_credit_menu : public QDialog
{
    Q_OBJECT

public:
    explicit deposit_credit_menu(bank *bank, int ID, QWidget *parent = nullptr);
    ~deposit_credit_menu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::deposit_credit_menu *ui;
    bank *bankk;
    int ID;
    QStandardItemModel *table_deposits;
    QStandardItemModel *table_credits;
};

#endif // DEPOSIT_CREDIT_MENU_H
