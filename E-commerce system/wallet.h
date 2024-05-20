#ifndef WALLET_H
#define WALLET_H

class wallet // Class to perform all the operations regarding Wallet
{
private:
    double balance = 0; // To store wallet balance

public:
    void addbalance(double b) // To add the amount passed as argument to the balance
    ;
    void setbalance(double b) // To set the Balance
    ;
    double getbalance() // To get the  Balance
    ;
};
#endif // WALLET_H
