#include "user_controller.h"
using namespace std;

void user_controller::open_bank_account(bank *bank, int ID, int money = 0)
{
    vector<bank_account> temp = bank->getBank_accounts();
    temp.push_back(*(new bank_account(money)));
    bank->setBank_accounts(temp);
    vector<user> users = bank->getUsers();
    for (int i = 0; i < users.size(); i++){
        if(ID == users[i].getID()){
            vector<int> bank_accounts_ID = users[i].getBank_accounts_ID();
            bank_accounts_ID.push_back(temp.back().getID());
            users[i].setBank_accounts_ID(bank_accounts_ID);
        }
    }
    bank->setUsers(users);
}

void user_controller::top_up_bank_account(bank *bank, int bank_account_ID, int money)
{
    vector<bank_account> temp = bank->getBank_accounts();
    for(int i = 0; i < temp.size(); i++){
        if (temp[i].getID() == bank_account_ID && !temp[i].getIsFrozen() && !temp[i].getIsBlocked()){
            temp[i].setMoney(temp[i].getMoney() + money);
            break;
        }
    }
    bank->setBank_accounts(temp);
}

void user_controller::withdrawal_bank_account(bank *bank, int bank_account_ID, int money)
{
    vector<bank_account> temp = bank->getBank_accounts();
    for(int i = 0; i < temp.size(); i++){
        if (temp[i].getID() == bank_account_ID && !temp[i].getIsFrozen() && !temp[i].getIsBlocked()){
            temp[i].setMoney(temp[i].getMoney() - money);
            break;
        }
    }
    bank->setBank_accounts(temp);
}

void user_controller::transfer_bank_account(bank *bank, int payer_ID, int payee_ID, int money)
{
    vector<bank_account> temp = bank->getBank_accounts();
    for(int i = 0; i < temp.size(); i++){
        if (temp[i].getID() == payer_ID){
            if(!temp[i].getIsFrozen() && !temp[i].getIsBlocked()){
                temp[i].setMoney(temp[i].getMoney() - money);
                break;
            }
            return;
        }
    }
    for(int i = 0; i < temp.size(); i++){
        if (temp[i].getID() == payee_ID){
            temp[i].setMoney(temp[i].getMoney() + money);
        }
    }
    bank->setBank_accounts(temp);
    vector<transfer> transfers = bank->getTransfers();
    transfers.push_back(*(new transfer(payer_ID, payee_ID, money)));
    bank->setTransfers(transfers);
}

void user_controller::open_deposit(bank *bank, int ID, int percent, int money = 0)
{
    vector<deposit> temp = bank->getDeposits();
    temp.push_back(*(new deposit(money, percent)));
    bank->setDeposits(temp);
    vector<user> users = bank->getUsers();
    for (int i = 0; i < users.size(); i++){
        if(ID == users[i].getID()){
            vector<int> deposits_ID = users[i].getDeposits_ID();
            deposits_ID.push_back(temp.back().getID());
            users[i].setDeposits_ID(deposits_ID);
        }
    }
    bank->setUsers(users);
}

void user_controller::top_up_deposit(bank *bank, int deposit_ID, int money)
{
    vector<deposit> temp = bank->getDeposits();
    for(int i = 0; i < temp.size(); i++){
        if (temp[i].getID() == deposit_ID){
            temp[i].setMoney(temp[i].getMoney() + money);
            break;
        }
    }
    bank->setDeposits(temp);
}

void user_controller::withdrawal_deposit(bank *bank, int deposit_ID, int money)
{
    vector<deposit> temp = bank->getDeposits();
    for(int i = 0; i < temp.size(); i++){
        if (temp[i].getID() == deposit_ID){
            temp[i].setMoney(temp[i].getMoney() - money);
            break;
        }
    }
    bank->setDeposits(temp);
}

void user_controller::freeze_bank_account(bank *bank, int bank_account_ID)
{
    vector<bank_account> temp = bank->getBank_accounts();
    for(int i = 0; i < temp.size(); i++){
        if (temp[i].getID() == bank_account_ID){
            temp[i].setIsFrozen(1);
            break;
        }
    }
    bank->setBank_accounts(temp);
}

void user_controller::unfreeze_bank_account(bank *bank, int bank_account_ID)
{
    vector<bank_account> temp = bank->getBank_accounts();
    for(int i = 0; i < temp.size(); i++){
        if (temp[i].getID() == bank_account_ID){
            temp[i].setIsFrozen(0);
            break;
        }
    }
    bank->setBank_accounts(temp);
}

void user_controller::block_bank_account(bank *bank, int bank_account_ID)
{
    vector<bank_account> temp = bank->getBank_accounts();
    for(int i = 0; i < temp.size(); i++){
        if (temp[i].getID() == bank_account_ID){
            temp[i].setIsBlocked(1);
            break;
        }
    }
    bank->setBank_accounts(temp);
}

void user_controller::take_credit(bank *bank, int ID, int bank_account_ID, credit *new_credit)
{
    vector<credit> temp = bank->getCredits();
    temp.push_back(*new_credit);
    bank->setCredits(temp);
    vector<user> users = bank->getUsers();
    for (int i = 0; i < users.size(); i++){
        if(ID == users[i].getID()){
            vector<int> credits_ID = users[i].getCredits_ID();
            credits_ID.push_back(temp.back().getID());
            users[i].setCredits_ID(credits_ID);
            break;
        }
    }
    bank->setUsers(users);
    user_controller::top_up_bank_account(bank, bank_account_ID, new_credit->getMoney());
}

void user_controller::join_salary_project(bank *bank, int user_ID, int salary_project_ID)
{
    vector<salary_project> salary_projects = bank->getSalary_projects();
    for(int i = 0; i < salary_projects.size(); i++){
        if(salary_project_ID == salary_projects[i].getID()){
            vector<int> users_ID = salary_projects[i].getUsers_ID();
            users_ID.push_back(user_ID);
            salary_projects[i].setUsers_ID(users_ID);
        }
    }
    bank->setSalary_projects(salary_projects);
}
