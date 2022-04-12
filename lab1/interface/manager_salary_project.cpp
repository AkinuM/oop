#include "manager_salary_project.h"
#include "ui_manager_salary_project.h"
#include "controllers/manager_controller.h"
#include "manager_menu.h"
using namespace std;

manager_salary_project::manager_salary_project(bank *bank, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manager_salary_project)
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

manager_salary_project::~manager_salary_project()
{
    delete ui;
}

void manager_salary_project::on_pushButton_clicked()
{
    int row_number = ui->row_number->text().toInt();
    manager_controller::approve_salary_project(bankk, row_number);
}

void manager_salary_project::on_pushButton_2_clicked()
{
    hide();
    manager_menu man(bankk);
    man.setModal(1);
    man.exec();
}
