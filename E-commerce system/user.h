#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>

using namespace std;

class User {//Abstract user class for the purpose of polymorphism
protected:
    string username, password, email, address;
    bool is_logged_in = 0;

public:
    virtual void register_user() = 0;
    virtual bool is_logged() = 0;
    virtual bool login() = 0;
    virtual void logout() = 0;
    virtual void update_profile() = 0;
    virtual void addProductToInventory() = 0;
    virtual void updateProductInInventory() = 0;
    virtual void removeProductFromInventory() = 0;
    virtual void viewInventory() = 0;
    virtual void findproductininventory() = 0;
    virtual void top_up() = 0;
    virtual void check_balance() = 0;
    virtual void addToCart() = 0;
    virtual void viewCart() = 0;
    virtual void placeOrder(double) = 0;
    virtual void addproducttowishlist() = 0;
    virtual void removeproductfromwishlist() = 0;
    virtual void showproductsfromwishlist() = 0;
    virtual void findproductfromwishlist() = 0;
    virtual void cancelOrder(double) = 0;
    virtual void checkOrderStatus() = 0;
    virtual void removeFromCart() = 0;
    virtual void calculateTotalOfCart() = 0;
    virtual void setbalance(double) = 0;
    virtual double getbalance() = 0;
    virtual void reader()=0;

    friend ofstream& operator<<(ofstream& out, User& u);
    friend ifstream& operator>>(ifstream& in, User& u);
};

#endif // USER_H
