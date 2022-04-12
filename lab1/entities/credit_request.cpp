#include "credit_request.h"

int credit_request::getBank_account_ID() const
{
    return bank_account_ID;
}

void credit_request::setBank_account_ID(int value)
{
    bank_account_ID = value;
}

credit_request::credit_request(int user_ID, int bank_account_ID, int money, int percent, int period)
{
    this->user_ID = user_ID;
    this->bank_account_ID = bank_account_ID;
    this->money = money;
    this->percent = percent;
    this->period = period;
}

int credit_request::getMoney() const
{
    return money;
}

void credit_request::setMoney(int value)
{
    money = value;
}

int credit_request::getPercent() const
{
    return percent;
}

void credit_request::setPercent(int value)
{
    percent = value;
}

int credit_request::getPeriod() const
{
    return period;
}

void credit_request::setPeriod(int value)
{
    period = value;
}

int credit_request::getUser_ID() const
{
    return user_ID;
}

void credit_request::setUser_ID(int value)
{
    user_ID = value;
}
