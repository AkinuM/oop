#include "bank.h"

string bank::getName() const
{
    return name;
}

void bank::setName(const string &value)
{
    name = value;
}

vector<user> bank::getUsers() const
{
    return users;
}

void bank::setUsers(const vector<user> &value)
{
    users = value;
}

vector<bank_account> bank::getBank_accounts() const
{
    return bank_accounts;
}

void bank::setBank_accounts(const vector<bank_account> &value)
{
    bank_accounts = value;
}

vector<credit> bank::getCredits() const
{
    return credits;
}

void bank::setCredits(const vector<credit> &value)
{
    credits = value;
}

vector<deposit> bank::getDeposits() const
{
    return deposits;
}

void bank::setDeposits(const vector<deposit> &value)
{
    deposits = value;
}

vector<company> bank::getCompanies() const
{
    return companies;
}

void bank::setCompanies(const vector<company> &value)
{
    companies = value;
}

vector<salary_project> bank::getSalary_projects() const
{
    return salary_projects;
}

void bank::setSalary_projects(const vector<salary_project> &value)
{
    salary_projects = value;
}

vector<transfer> bank::getTransfers() const
{
    return transfers;
}

void bank::setTransfers(const vector<transfer> &value)
{
    transfers = value;
}

vector<sign_up_request> bank::getSign_up_requests() const
{
    return sign_up_requests;
}

void bank::setSign_up_requests(const vector<sign_up_request> &value)
{
    sign_up_requests = value;
}

vector<credit_request> bank::getCredit_requests() const
{
    return credit_requests;
}

void bank::setCredit_requests(const vector<credit_request> &value)
{
    credit_requests = value;
}

vector<join_salary_project_request> bank::getJoin_salary_project_requests() const
{
    return join_salary_project_requests;
}

void bank::setJoin_salary_project_requests(const vector<join_salary_project_request> &value)
{
    join_salary_project_requests = value;
}

vector<salary_project_request> bank::getSalary_project_requests() const
{
    return salary_project_requests;
}

void bank::setSalary_project_requests(const vector<salary_project_request> &value)
{
    salary_project_requests = value;
}

bank::bank(string name1) {
    this->name = name1;
}
