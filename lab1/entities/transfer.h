#ifndef TRANSFER_H
#define TRANSFER_H


class transfer
{
private:
    int payer_ID;
    int payee_ID;
    int sum;

public:
    transfer(int payer_ID, int payee_ID, int sum);

    int getPayer_ID() const;
    void setPayer_ID(int value);
    int getPayee_ID() const;
    void setPayee_ID(int value);
    int getSum() const;
    void setSum(int value);
};

#endif // TRANSFER_H
