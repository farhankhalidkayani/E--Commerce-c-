#include<iostream>
#include"payment.h"
using namespace std;
    bool payment::getpaymentstatus() // To get the payment status
    {
        return is_paid;
    }
    double payment::processPayment(double b, double t) // Method to process the payment
    {

                        // Assigning the wallet balance obtained as argument to variable named balance
        

        if (b >= t) // Checking if the balance is more than the total cost
        {
           

            cout << "Payment made successfully!" << endl;

            cout << "Your current balance is: " << b - t << endl; // Showing the remaining Balance

            is_paid = 1;
            return b - t; // Returning the remaining balance so that it can be stored in the wallet balance
        }
        else
        {
            cout << "You dont have sufficent funds to make the payment kindly first top-up in your wallet." << endl;
            is_paid = 0;
        }
    }
    double payment::refund(double b,double t) // Method to refund amount upon cancellation of the order
    {

       
        cout << "Refund made successfully!" << endl;
        cout << "Your current balance is: " << b + t << endl;

        is_paid = 0;
        return b + t; // Returning the remaining balance so that it can be stored in the wallet balance
    }
