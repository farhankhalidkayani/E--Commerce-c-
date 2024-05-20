#ifndef ORDERS_H
#define ORDERS_H

class orders // Class to perform all the opeariotns regarding the Orders
{
private:
    bool order_status = 0; // Represents the order status

public:
    void placeOrder(bool is_paid) // To place the order
   ;
    void cancelOrder() // Cancelling the order
   ;
    bool getorderstatus()// to get order status
    ;
    void checkOrderStatus();// to check order status
};
#endif // ORDERS_H
