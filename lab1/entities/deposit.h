#ifndef DEPOSIT_H
#define DEPOSIT_H
#include "bank_account.h"

class deposit : public bank_account
{
private:
    int percent;
    static int count1;

public:
    deposit(int money, int percent);
    deposit(int ID, int money, int percent);

    int getPercent() const;
    void setPercent(int value);
};

#endif // DEPOSIT_H
