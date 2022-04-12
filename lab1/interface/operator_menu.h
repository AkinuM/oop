#ifndef OPERATOR_MENU_H
#define OPERATOR_MENU_H

#include <QDialog>
#include "database.h"
#include <QStandardItemModel>

namespace Ui {
class operator_menu;
}

class operator_menu : public QDialog
{
    Q_OBJECT

public:
    explicit operator_menu(bank *bank, QWidget *parent = nullptr);
    ~operator_menu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::operator_menu *ui;
    bank *bankk;
    QStandardItemModel *table;
};

#endif // OPERATOR_MENU_H
