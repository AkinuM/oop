#include "transfer.h"

int transfer::getPayer_ID() const
{
    return payer_ID;
}

void transfer::setPayer_ID(int value)
{
    payer_ID = value;
}

int transfer::getPayee_ID() const
{
    return payee_ID;
}

void transfer::setPayee_ID(int value)
{
    payee_ID = value;
}

int transfer::getSum() const
{
    return sum;
}

void transfer::setSum(int value)
{
    sum = value;
}

transfer::transfer(int payer_ID, int payee_ID, int sum) {
    this->payer_ID = payer_ID;
    this->payee_ID = payee_ID;
    this->sum = sum;
}
