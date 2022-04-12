#ifndef LOG_IN_MENU_H
#define LOG_IN_MENU_H

#include <QDialog>
#include "database.h"

namespace Ui {
class log_in_menu;
}

class log_in_menu : public QDialog
{
    Q_OBJECT

public:
    explicit log_in_menu(bank *bank, QWidget *parent = nullptr);
    ~log_in_menu();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::log_in_menu *ui;
    bank *bankk;
};

#endif // LOG_IN_MENU_H
