#include<iostream>
#include"orders.h"
using namespace std;
    void orders::placeOrder(bool is_paid) // To place the order
    {

        cout << "Please hold as we check the payment status: " << endl;
        if (is_paid == 1) // Checking if the User has paid for the order or not
        {

            cout << "We have verfied your payment have been processed." << endl;
            cout << "The order is now live" << endl;
            cout << "Pleasure doing business with you :)" << endl;
            order_status = 1; // Setting order status to live
        }
        else
        {
            cout << "Seems that your payment has not been processed kindly proceed to pay for the order first." << endl;
        }
    }
    void orders::cancelOrder() // Cancelling the order
    {
        cout << "Sure we will cancel the order for you now." << endl;
        order_status = 0; // Setting the order status to InActive
    }
    void orders::checkOrderStatus() // To check the order status
    {
        if (order_status == 1)
        {
            cout << "The order is active." << endl;
        }
        else
        {
            cout << "The order is not active." << endl;
        }
    }
    bool orders::getorderstatus()
    {
        return order_status;
    }

