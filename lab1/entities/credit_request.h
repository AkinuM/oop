#ifndef CREDIT_REQUEST_H
#define CREDIT_REQUEST_H
#include "credit.h"

class credit_request
{
private:
    int user_ID;
    int bank_account_ID;
    int money;
    int percent;
    int period;

public:
    credit_request(int user_ID, int bank_account_ID, int money, int percent, int period);
    int getUser_ID() const;
    void setUser_ID(int value);
    int getBank_account_ID() const;
    void setBank_account_ID(int value);
    int getMoney() const;
    void setMoney(int value);
    int getPercent() const;
    void setPercent(int value);
    int getPeriod() const;
    void setPeriod(int value);
};

#endif // CREDIT_REQUEST_H
