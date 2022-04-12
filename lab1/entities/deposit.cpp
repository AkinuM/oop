#include "deposit.h"

int deposit::count1 = 0;

int deposit::getPercent() const
{
    return percent;
}

void deposit::setPercent(int value)
{
    percent = value;
}

deposit::deposit(int money, int percent) {
    this->money = money;
    this->percent = percent;
    ID = ++count1;
}

deposit::deposit(int ID, int money, int percent) {
    this->money = money;
    this->percent = percent;
    this->ID = ID;
    this->count1 = ID;
}
