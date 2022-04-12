#include "bank_account.h"

int bank_account::count = 0;

int bank_account::getID() const
{
    return ID;
}

void bank_account::setID(int value)
{
    ID = value;
}

int bank_account::getMoney() const
{
    return money;
}

void bank_account::setMoney(int value)
{
    money = value;
}

bool bank_account::getIsFrozen() const
{
    return isFrozen;
}

void bank_account::setIsFrozen(bool value)
{
    isFrozen = value;
}

bool bank_account::getIsBlocked() const
{
    return isBlocked;
}

void bank_account::setIsBlocked(bool value)
{
    isBlocked = value;
}

bank_account::bank_account(int money) {
    this->money = money;
    ID = ++count;
    isBlocked = 0;
    isFrozen = 0;
}

bank_account::bank_account(){

}

bank_account::bank_account(int money, int ID, int isFrozen, int isBlocked){
    this->money = money;
    this->ID = ID;
    this->count = ID;
    this->isFrozen = isFrozen;
    this->isBlocked = isBlocked;
}
