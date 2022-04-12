#include "deposit_credit_menu.h"
#include "ui_deposit_credit_menu.h"
#include "user_salary_project_menu.h"
using namespace std;

deposit_credit_menu::deposit_credit_menu(bank *bank, int ID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deposit_credit_menu)
{
    ui->setupUi(this);
    bankk = bank;
    this->ID = ID;
    vector<int> deposits_ID;
    for (auto user : bankk->getUsers()){
        if(user.getID() == ID){
            table_deposits = new QStandardItemModel(user.getDeposits_ID().size(), 3, this);
            deposits_ID = user.getDeposits_ID();
        }
    }
    ui->table_deposit->setModel(table_deposits);
    table_deposits->setHeaderData(0, Qt::Horizontal, "ID");
    table_deposits->setHeaderData(1, Qt::Horizontal, "Money");
    table_deposits->setHeaderData(2, Qt::Horizontal, "Percent");
    QModelIndex index;
    vector<deposit> deposits;
    for(auto deposit : bankk->getDeposits()){
        for(auto ID : deposits_ID){
            if(ID == deposit.getID()){
                deposits.push_back(deposit);
                break;
            }
        }
    }
    for (int i = 0; i < table_deposits->rowCount(); i++){
        for (int j = 0; j < table_deposits->columnCount(); j++){
            index = table_deposits->index(i, j);
            switch(j){
            case 0:
                table_deposits->setData(index, deposits[i].getID());
                break;
            case 1:
                table_deposits->setData(index, deposits[i].getMoney());
                break;
            case 2:
                table_deposits->setData(index, deposits[i].getPercent());
                break;
            }
        }
    }
    vector<int> credits_ID;
    for (auto user : bankk->getUsers()){
        if(user.getID() == ID){
            table_credits = new QStandardItemModel(user.getCredits_ID().size(), 4, this);
            credits_ID = user.getCredits_ID();
        }
    }
    ui->table_credit->setModel(table_credits);
    table_credits->setHeaderData(0, Qt::Horizontal, "ID");
    table_credits->setHeaderData(1, Qt::Horizontal, "Money");
    table_credits->setHeaderData(2, Qt::Horizontal, "Percent");
    table_credits->setHeaderData(3, Qt::Horizontal, "Period");
    vector<credit> credits;
    for(auto credit : bankk->getCredits()){
        for(auto ID : credits_ID){
            if(ID == credit.getID()){
                credits.push_back(credit);
                break;
            }
        }
    }
    for (int i = 0; i < table_credits->rowCount(); i++){
        for (int j = 0; j < table_credits->columnCount(); j++){
            index = table_credits->index(i, j);
            switch(j){
            case 0:
                table_credits->setData(index, credits[i].getID());
                break;
            case 1:
                table_credits->setData(index, credits[i].getMoney());
                break;
            case 2:
                table_credits->setData(index, credits[i].getPercent());
                break;
            case 3:
                table_credits->setData(index, credits[i].getPeriod());
                break;
            }
        }
    }
}

deposit_credit_menu::~deposit_credit_menu()
{
    delete ui;
}

void deposit_credit_menu::on_pushButton_clicked()
{
    user_controller::open_deposit(bankk, ID, ui->deposit_percent->text().toUInt(), ui->deposit_money->text().toUInt());
}

void deposit_credit_menu::on_pushButton_2_clicked()
{
    user_controller::top_up_deposit(bankk, ui->top_up_ID->text().toUInt(), ui->top_up_money->text().toUInt());
}

void deposit_credit_menu::on_pushButton_3_clicked()
{
    user_controller::withdrawal_deposit(bankk, ui->withdrawal_ID->text().toUInt(), ui->withdrawal_money->text().toUInt());
}

void deposit_credit_menu::on_pushButton_4_clicked()
{
    int bank_account_ID = ui->credit_ID->text().toInt();
    int percent = ui->credit_percent->text().toUInt();
    int period = ui->credit_period->text().toUInt();
    int money = ui->credit_money->text().toUInt();
    vector<credit_request> temp = bankk->getCredit_requests();
    temp.push_back(*(new credit_request(ID, bank_account_ID, money, percent, period)));
    bankk->setCredit_requests(temp);
}

void deposit_credit_menu::on_pushButton_5_clicked()
{
    hide();
    user_menu us_menu(bankk, ID);
    us_menu.setModal(1);
    us_menu.exec();
}

void deposit_credit_menu::on_pushButton_6_clicked()
{
    hide();
    user_salary_project_menu sp_menu(bankk, ID);
    sp_menu.setModal(1);
    sp_menu.exec();
}
