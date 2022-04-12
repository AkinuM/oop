#pragma once
#include "log_in_menu.h"
#include "ui_log_in_menu.h"
#include "sign_up_menu.h"
#include <QMessageBox>
#include "user_menu.h"
#include "manager_menu.h"
#include "specialist_menu.h"
#include "operator_menu.h"
using namespace std;

log_in_menu::log_in_menu(bank *bank, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::log_in_menu)
{
    ui->setupUi(this);
    this->bankk = bank;
}

log_in_menu::~log_in_menu()
{
    delete ui;
}

void log_in_menu::on_pushButton_2_clicked()
{
    hide();
    sign_up_menu su_menu(bankk);
    su_menu.setModal(1);
    su_menu.exec();
}

void log_in_menu::on_pushButton_clicked()
{
    for(auto user : bankk->getUsers()){
        if (user.getUsername() == ui->username->text().toStdString() && user.getPassword() == ui->password->text().toStdString()){
            hide();
            if (user.getAuthority() == "Client") {
                user_menu us_menu(bankk, user.getID());
                us_menu.setModal(1);
                us_menu.exec();
            }
            else if (user.getAuthority() == "Manager"){
                manager_menu man_menu(bankk);
                man_menu.setModal(1);
                man_menu.exec();
            }
            else if (user.getAuthority() == "Specialist"){
                specialist_menu spec_menu(bankk, user.getID());
                spec_menu.setModal(1);
                spec_menu.exec();
            }
            else if (user.getAuthority() == "Operator"){
                operator_menu op_menu(bankk);
                op_menu.setModal(1);
                op_menu.exec();
            }
            return;
        }
    }
    QMessageBox::information(this, "Error", "Wrong username or password");
}
