#include<iostream>
#include"wallet.h"
using namespace std;
    void wallet::addbalance(double b) // To add the amount passed as argument to the balance
    {
        balance = balance + b;
    }
    void wallet::setbalance(double b) // To set the Balance
    {
        balance = b;
    }
    double wallet::getbalance() // To get the  Balance
    {
        return balance;
    }
