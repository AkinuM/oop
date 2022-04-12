#include "operator_menu.h"
#include "ui_operator_menu.h"
#include "controllers/manager_controller.h"

operator_menu::operator_menu(bank *bank, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::operator_menu)
{
    ui->setupUi(this);
    bankk = bank;
    table = new QStandardItemModel(bankk->getSalary_project_requests().size(), 3, this);
    ui->table->setModel(table);
    table->setHeaderData(0, Qt::Horizontal, "Company_ID");
    table->setHeaderData(1, Qt::Horizontal, "Company_bank_account_ID");
    table->setHeaderData(2, Qt::Horizontal, "Sum");
    QModelIndex index;
    vector<salary_project_request> salary_project_requests = bankk->getSalary_project_requests();
    for (int i = 0; i < table->rowCount(); i++){
        for (int j = 0; j < table->columnCount(); j++){
            index = table->index(i, j);
            switch(j){
            case 0:
                table->setData(index, QString::number(salary_project_requests[i].getCompany_ID()));
                break;
            case 1:
                table->setData(index, QString::number(salary_project_requests[i].getCompany_bank_account_ID()));
                break;
            case 2:
                table->setData(index, QString::number(salary_project_requests[i].getSum()));
                break;
            }
        }
    }
}

operator_menu::~operator_menu()
{
    delete ui;
}

void operator_menu::on_pushButton_clicked()
{
    int row_number = ui->row_number->text().toInt();
    manager_controller::approve_salary_project(bankk, row_number);
}
