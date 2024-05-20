#ifndef PAYMENT_H
#define PAYMENT_H

#include "shopping_cart.h"
#include "wallet.h"
class payment // Class to perform all the operations regarding the Payments
{
    shopping_cart s1; // So that we can access the total of the shopping cart
    wallet w1;        // So that we can access the Wallet Balance
    bool is_paid = 0; // To check if the Amount was paid or not

public:
    bool getpaymentstatus() // To get the payment status
   ;
    double processPayment(double b,double t) // Method to process the payment
   ;
    double refund(double b,double t) // Method to refund amount upon cancellation of the order
    ;
};
#endif // PAYMENT_H
