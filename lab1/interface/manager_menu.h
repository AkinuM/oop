#ifndef MANAGER_MENU_H
#define MANAGER_MENU_H

#include <QDialog>
#include "database.h"
#include <QStandardItemModel>

namespace Ui {
class manager_menu;
}

class manager_menu : public QDialog
{
    Q_OBJECT

public:
    explicit manager_menu(bank *bank, QWidget *parent = nullptr);
    ~manager_menu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::manager_menu *ui;
    bank *bankk;
    QStandardItemModel *table_sign_up;
    QStandardItemModel *table_credit;
    QStandardItemModel *table_salary;
};

#endif // MANAGER_MENU_H
