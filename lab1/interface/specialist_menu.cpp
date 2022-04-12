#include "specialist_menu.h"
#include "ui_specialist_menu.h"
using namespace std;

specialist_menu::specialist_menu(bank *bank, int ID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::specialist_menu)
{
    ui->setupUi(this);
    bankk = bank;
    this->ID = ID;
}

specialist_menu::~specialist_menu()
{
    delete ui;
}

void specialist_menu::on_pushButton_clicked()
{
    int company_bank_account_ID = ui->open_ID->text().toInt();
    int sum = ui->open_sum->text().toUInt();
    vector<salary_project_request> salary_project_requests = bankk->getSalary_project_requests();
    vector<company> companies = bankk->getCompanies();
    for (auto company : companies){
        vector<int> specialists_ID = company.getSpecialists_ID();
        for (auto spec_ID : specialists_ID){
            if(ID == spec_ID){
                salary_project_requests.push_back(*(new salary_project_request(company.getID(), company_bank_account_ID, sum)));
                break;
            }
        }
    }
    bankk->setSalary_project_requests(salary_project_requests);
}
