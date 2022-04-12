#pragma once
#include "sign_up_menu.h"
#include "ui_sign_up_menu.h"
#include "log_in_menu.h"
#include "controllers/user_controller.h"

sign_up_menu::sign_up_menu(bank *bank, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sign_up_menu)
{
    ui->setupUi(this);
    this->bankk = bank;
}

sign_up_menu::~sign_up_menu()
{
    delete ui;
}

void sign_up_menu::on_pushButton_clicked()
{
    hide();
    log_in_menu li_menu(bankk);
    li_menu.setModal(1);
    li_menu.exec();
}

void sign_up_menu::on_sign_up_button_clicked()
{
    string username = ui->username->text().toStdString();
    string password = ui->password->text().toStdString();
    string name = ui->name->text().toStdString();
    string passport = ui->passport->text().toStdString();
    string phone = ui->phone->text().toStdString();
    string email = ui->email->text().toStdString();
    vector<sign_up_request> temp = bankk->getSign_up_requests();
    temp.push_back(*(new sign_up_request(username, password, name, passport, phone, email)));
    bankk->setSign_up_requests(temp);
}
