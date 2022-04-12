#ifndef MANAGER_SALARY_PROJECT_H
#define MANAGER_SALARY_PROJECT_H

#include <QDialog>
#include "database.h"
#include <QStandardItemModel>

namespace Ui {
class manager_salary_project;
}

class manager_salary_project : public QDialog
{
    Q_OBJECT

public:
    explicit manager_salary_project(bank *bank, QWidget *parent = nullptr);
    ~manager_salary_project();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::manager_salary_project *ui;
    bank *bankk;
    QStandardItemModel *table;
};

#endif // MANAGER_SALARY_PROJECT_H
