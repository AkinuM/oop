#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H


class bank_account
{
protected:
    int ID;
    int money;

private:
    static int count;
    bool isFrozen;
    bool isBlocked;

public:
    bank_account(int money);
    bank_account();
    bank_account(int money, int ID, int isFrozen, int isBlocked);

    int getID() const;
    void setID(int value);
    int getMoney() const;
    void setMoney(int value);
    bool getIsFrozen() const;
    void setIsFrozen(bool value);
    bool getIsBlocked() const;
    void setIsBlocked(bool value);
};

#endif // BANK_ACCOUNT_H
