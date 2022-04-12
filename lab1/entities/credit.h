#ifndef CREDIT_H
#define CREDIT_H
#include "bank_account.h"

class credit : public bank_account
{
private:
    int percent;
    int period;
    static int count1;

public:
    credit(int money, int percent, int period);
    credit(int ID, int money, int percent, int period);

    int getPercent() const;
    void setPercent(int value);
    int getPeriod() const;
    void setPeriod(int value);
};

#endif // CREDIT_H
