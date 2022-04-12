#include "credit.h"

int credit::count1 = 0;

int credit::getPercent() const
{
    return percent;
}

void credit::setPercent(int value)
{
    percent = value;
}

int credit::getPeriod() const
{
    return period;
}

void credit::setPeriod(int value)
{
    period = value;
}

credit::credit(int money, int percent, int period) {
    this->money = money;
    this->percent = percent;
    this->period = period;
    ID = ++count1;
}

credit::credit(int ID, int money, int percent, int period){
    this->money = money;
    this->percent = percent;
    this->period = period;
    this->ID = ID;
    this->count1 = ID;
}
