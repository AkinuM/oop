#ifndef SALARY_PROJECT_REQUEST_H
#define SALARY_PROJECT_REQUEST_H
#include "salary_project.h"

class salary_project_request
{
private:
    int company_ID;
    int company_bank_account_ID;
    int sum;

public:
    salary_project_request(int company_ID, int company_bank_account_ID, int sum);

    int getCompany_ID() const;
    void setCompany_ID(int value);
    int getCompany_bank_account_ID() const;
    void setCompany_bank_account_ID(int value);
    int getSum() const;
    void setSum(int value);
};

#endif // SALARY_PROJECT_REQUEST_H
