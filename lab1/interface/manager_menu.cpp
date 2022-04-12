#include "manager_menu.h"
#include "ui_manager_menu.h"
#include "controllers/manager_controller.h"
#include "manager_salary_project.h"
using namespace std;

manager_menu::manager_menu(bank *bank, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manager_menu)
{
    ui->setupUi(this);
    bankk = bank;
    table_sign_up = new QStandardItemModel(bankk->getSign_up_requests().size(), 6, this);
    ui->table_sign_up->setModel(table_sign_up);
    table_sign_up->setHeaderData(0, Qt::Horizontal, "Username");
    table_sign_up->setHeaderData(1, Qt::Horizontal, "Password");
    table_sign_up->setHeaderData(2, Qt::Horizontal, "Name");
    table_sign_up->setHeaderData(3, Qt::Horizontal, "Passport");
    table_sign_up->setHeaderData(4, Qt::Horizontal, "Phone");
    table_sign_up->setHeaderData(5, Qt::Horizontal, "Email");
    QModelIndex index;
    vector<sign_up_request> sign_up_requests = bankk->getSign_up_requests();
    for (int i = 0; i < table_sign_up->rowCount(); i++){
        for (int j = 0; j < table_sign_up->columnCount(); j++){
            index = table_sign_up->index(i, j);
            switch(j){
            case 0:
                table_sign_up->setData(index, QString::fromStdString(sign_up_requests[i].getUsername()));
                break;
            case 1:
                table_sign_up->setData(index, QString::fromStdString(sign_up_requests[i].getPassword()));
                break;
            case 2:
                table_sign_up->setData(index, QString::fromStdString(sign_up_requests[i].getName()));
                break;
            case 3:
                table_sign_up->setData(index, QString::fromStdString(sign_up_requests[i].getPassport()));
                break;
            case 4:
                table_sign_up->setData(index, QString::fromStdString(sign_up_requests[i].getPhone()));
                break;
            case 5:
                table_sign_up->setData(index, QString::fromStdString(sign_up_requests[i].getEmail()));
                break;
            }
        }
    }
    table_credit = new QStandardItemModel(bankk->getCredit_requests().size(), 5, this);
    ui->table_credit->setModel(table_credit);
    table_credit->setHeaderData(0, Qt::Horizontal, "User_ID");
    table_credit->setHeaderData(1, Qt::Horizontal, "Bank_account_ID");
    table_credit->setHeaderData(2, Qt::Horizontal, "Money");
    table_credit->setHeaderData(3, Qt::Horizontal, "Percent");
    table_credit->setHeaderData(4, Qt::Horizontal, "Period");
    vector<credit_request> credit_requests = bankk->getCredit_requests();
    for (int i = 0; i < table_credit->rowCount(); i++){
        for (int j = 0; j < table_credit->columnCount(); j++){
            index = table_credit->index(i, j);
            switch(j){
            case 0:
                table_credit->setData(index, credit_requests[i].getUser_ID());
                break;
            case 1:
                table_credit->setData(index, credit_requests[i].getBank_account_ID());
                break;
            case 2:
                table_credit->setData(index, credit_requests[i].getMoney());
                break;
            case 3:
                table_credit->setData(index, credit_requests[i].getPercent());
                break;
            case 4:
                table_credit->setData(index, credit_requests[i].getPeriod());
                break;
            }
        }
    }
    table_salary = new QStandardItemModel(bankk->getJoin_salary_project_requests().size(), 2, this);
    ui->table_salary->setModel(table_salary);
    table_salary->setHeaderData(0, Qt::Horizontal, "User_ID");
    table_salary->setHeaderData(1, Qt::Horizontal, "Salary_project_ID");
    vector<join_salary_project_request> join_salary_project_requests = bankk->getJoin_salary_project_requests();
    for (int i = 0; i < table_salary->rowCount(); i++){
        for (int j = 0; j < table_salary->columnCount(); j++){
            index = table_salary->index(i, j);
            switch(j){
            case 0:
                table_salary->setData(index, join_salary_project_requests[i].getUser_ID());
                break;
            case 1:
                table_salary->setData(index, join_salary_project_requests[i].getSalary_project_ID());
                break;
            }
        }
    }
}

manager_menu::~manager_menu()
{
    delete ui;
}

void manager_menu::on_pushButton_clicked()
{
    string passport = ui->sign_up_passport->text().toStdString();
    manager_controller::approve_sign_up(bankk, passport);
}

void manager_menu::on_pushButton_3_clicked()
{
    int row_number = ui->row_number->text().toUInt();
    manager_controller::approve_credit(bankk, row_number);
}

void manager_menu::on_pushButton_2_clicked()
{
    int user_ID = ui->user_ID->text().toUInt();
    int salary_project_ID = ui->salary_ID->text().toInt();
    manager_controller::approve_join_salary_project(bankk, user_ID, salary_project_ID);
}

void manager_menu::on_pushButton_4_clicked()
{
    hide();
    manager_salary_project sal_menu(bankk);
    sal_menu.setModal(1);
    sal_menu.exec();
}
