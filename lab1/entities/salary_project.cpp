#include "salary_project.h"

int salary_project::count = 0;

int salary_project::getID() const
{
    return ID;
}

void salary_project::setID(int value)
{
    ID = value;
}

vector<int> salary_project::getUsers_ID() const
{
    return users_ID;
}

void salary_project::setUsers_ID(const vector<int> &value)
{
    users_ID = value;
}

int salary_project::getCompany_bank_account_ID() const
{
    return company_bank_account_ID;
}

void salary_project::setCompany_bank_account_ID(int value)
{
    company_bank_account_ID = value;
}

int salary_project::getSum() const
{
    return sum;
}

void salary_project::setSum(int value)
{
    sum = value;
}

salary_project::salary_project(int company_bank_account_ID, int sum) {
    this->company_bank_account_ID = company_bank_account_ID;
    this->sum = sum;
    ID = ++count;
}

salary_project::salary_project(int company_bank_account_ID, int sum, int ID)
{
    this->company_bank_account_ID = company_bank_account_ID;
    this->sum = sum;
    this->ID = ID;
    this->count = ID;
}

salary_project::salary_project(int company_bank_account_ID, int sum, vector<int> users_ID, int ID) {
    this->company_bank_account_ID = company_bank_account_ID;
    this->sum = sum;
    this->users_ID = users_ID;
    this->ID = ID;
    this->count = ID;
}
