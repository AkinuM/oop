#ifndef USER_SALARY_PROJECT_MENU_H
#define USER_SALARY_PROJECT_MENU_H

#include <QDialog>
#include "database.h"
#include "deposit_credit_menu.h"

namespace Ui {
class user_salary_project_menu;
}

class user_salary_project_menu : public QDialog
{
    Q_OBJECT

public:
    explicit user_salary_project_menu(bank *bank, int ID, QWidget *parent = nullptr);
    ~user_salary_project_menu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::user_salary_project_menu *ui;
    bank *bankk;
    int ID;
};

#endif // USER_SALARY_PROJECT_MENU_H
