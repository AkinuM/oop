#include "salary_project_request.h"

int salary_project_request::getCompany_ID() const
{
    return company_ID;
}

void salary_project_request::setCompany_ID(int value)
{
    company_ID = value;
}

int salary_project_request::getCompany_bank_account_ID() const
{
    return company_bank_account_ID;
}

void salary_project_request::setCompany_bank_account_ID(int value)
{
    company_bank_account_ID = value;
}

int salary_project_request::getSum() const
{
    return sum;
}

void salary_project_request::setSum(int value)
{
    sum = value;
}

salary_project_request::salary_project_request(int company_ID, int company_bank_account_ID, int sum)
{
    this->company_ID = company_ID;
    this->company_bank_account_ID = company_bank_account_ID;
    this->sum = sum;
}
