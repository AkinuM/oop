#include "user_menu.h"
#include "ui_user_menu.h"
using namespace std;

user_menu::user_menu(bank *bank, int ID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_menu)
{
    ui->setupUi(this);
    bankk = bank;
    this->ID = ID;
    vector<int> bank_accounts_ID;
    for (auto user : bankk->getUsers()){
        if(user.getID() == ID){
            table = new QStandardItemModel(user.getBank_accounts_ID().size(), 4, this);
            bank_accounts_ID = user.getBank_accounts_ID();
        }
    }
    ui->tableView->setModel(table);
    table->setHeaderData(0, Qt::Horizontal, "ID");
    table->setHeaderData(1, Qt::Horizontal, "Money");
    table->setHeaderData(2, Qt::Horizontal, "isFrozen");
    table->setHeaderData(3, Qt::Horizontal, "isBlocked");
    QModelIndex index;
    vector<bank_account> bank_accounts;
    for(auto bank_account : bankk->getBank_accounts()){
        for(auto ID : bank_accounts_ID){
            if(ID == bank_account.getID()){
                bank_accounts.push_back(bank_account);
                break;
            }
        }
    }
    for (int i = 0; i < table->rowCount(); i++){
        for (int j = 0; j < table->columnCount(); j++){
            index = table->index(i, j);
            switch(j){
            case 0:
                table->setData(index, bank_accounts[i].getID());
                break;
            case 1:
                table->setData(index, bank_accounts[i].getMoney());
                break;
            case 2:
                table->setData(index, bank_accounts[i].getIsFrozen());
                break;
            case 3:
                table->setData(index, bank_accounts[i].getIsBlocked());
                break;
            }
        }
    }
}

user_menu::~user_menu()
{
    delete ui;
}

void user_menu::on_pushButton_clicked()
{
    user_controller::open_bank_account(bankk, ID , ui->open_money->text().toInt());
}

void user_menu::on_pushButton_2_clicked()
{
    user_controller::top_up_bank_account(bankk, ui->top_up_ID->text().toInt(), ui->top_up_money->text().toInt());
}

void user_menu::on_pushButton_4_clicked()
{
    user_controller::withdrawal_bank_account(bankk, ui->withdrawal_ID->text().toInt(), ui->withdrawal_money->text().toInt());
}

void user_menu::on_pushButton_5_clicked()
{
    user_controller::transfer_bank_account(bankk, ui->payer_ID->text().toUInt(), ui->payee_ID->text().toUInt(), ui->transfer_money->text().toUInt());
}

void user_menu::on_freeze_button_clicked()
{
    user_controller::freeze_bank_account(bankk, ui->freeze_ID->text().toUInt());
}

void user_menu::on_unfreeze_button_clicked()
{
    user_controller::unfreeze_bank_account(bankk, ui->freeze_ID->text().toUInt());
}

void user_menu::on_pushButton_6_clicked()
{
    user_controller::block_bank_account(bankk, ui->block_ID->text().toUInt());
}

void user_menu::on_pushButton_3_clicked()
{
    hide();
    deposit_credit_menu dc_menu(bankk, ID);
    dc_menu.setModal(1);
    dc_menu.exec();
}
