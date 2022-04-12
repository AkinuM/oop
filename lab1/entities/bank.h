#ifndef BANK_H
#define BANK_H
#pragma once
#include "user.h"
#include "company.h"
#include "salary_project.h"
#include "deposit.h"
#include "credit.h"
#include "transfer.h"
#include "sign_up_request.h"
#include "credit_request.h"
#include "join_salary_project_request.h"
#include "salary_project_request.h"

class bank
{
private:
    string name;
    vector<user> users;
    vector<bank_account> bank_accounts;
    vector<credit> credits;
    vector<deposit> deposits;
    vector<company> companies;
    vector<salary_project> salary_projects;
    vector<transfer> transfers;
    vector<sign_up_request> sign_up_requests;
    vector<credit_request> credit_requests;
    vector<join_salary_project_request> join_salary_project_requests;
    vector<salary_project_request> salary_project_requests;

public:
    bank(string name1);

    string getName() const;
    void setName(const string &value);
    vector<user> getUsers() const;
    void setUsers(const vector<user> &value);
    vector<bank_account> getBank_accounts() const;
    void setBank_accounts(const vector<bank_account> &value);
    vector<credit> getCredits() const;
    void setCredits(const vector<credit> &value);
    vector<deposit> getDeposits() const;
    void setDeposits(const vector<deposit> &value);
    vector<company> getCompanies() const;
    void setCompanies(const vector<company> &value);
    vector<salary_project> getSalary_projects() const;
    void setSalary_projects(const vector<salary_project> &value);
    vector<transfer> getTransfers() const;
    void setTransfers(const vector<transfer> &value);
    vector<sign_up_request> getSign_up_requests() const;
    void setSign_up_requests(const vector<sign_up_request> &value);
    vector<credit_request> getCredit_requests() const;
    void setCredit_requests(const vector<credit_request> &value);
    vector<join_salary_project_request> getJoin_salary_project_requests() const;
    void setJoin_salary_project_requests(const vector<join_salary_project_request> &value);
    vector<salary_project_request> getSalary_project_requests() const;
    void setSalary_project_requests(const vector<salary_project_request> &value);
};

#endif // BANK_H
