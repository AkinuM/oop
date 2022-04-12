#ifndef SALARY_PROJECT_H
#define SALARY_PROJECT_H
#pragma once
#include <vector>
using namespace std;

class salary_project
{
private:
    int ID;
    static int count;
    vector<int> users_ID;
    int company_bank_account_ID;
    int sum;

public:
    salary_project(int company_bank_account_ID, int sum);
    salary_project(int company_bank_account_ID, int sum, int ID);
    salary_project(int company_bank_account_ID, int sum, vector<int> users_ID, int ID);

    int getID() const;
    void setID(int value);
    vector<int> getUsers_ID() const;
    void setUsers_ID(const vector<int> &value);
    int getCompany_bank_account_ID() const;
    void setCompany_bank_account_ID(int value);
    int getSum() const;
    void setSum(int value);
};

#endif // SALARY_PROJECT_H
