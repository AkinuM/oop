#include "user_salary_project_menu.h"
#include "ui_user_salary_project_menu.h"

user_salary_project_menu::user_salary_project_menu(bank *bank, int ID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_salary_project_menu)
{
    ui->setupUi(this);
    bankk = bank;
    this->ID = ID;
}

user_salary_project_menu::~user_salary_project_menu()
{
    delete ui;
}

void user_salary_project_menu::on_pushButton_clicked()
{
    int salary_project_ID = ui->salary_ID->text().toInt();
    vector<join_salary_project_request> temp = bankk->getJoin_salary_project_requests();
    temp.push_back(*(new join_salary_project_request(ID, salary_project_ID)));
    bankk->setJoin_salary_project_requests(temp);
}

void user_salary_project_menu::on_pushButton_2_clicked()
{
    hide();
    deposit_credit_menu dc_menu(bankk, ID);
    dc_menu.setModal(1);
    dc_menu.exec();
}
