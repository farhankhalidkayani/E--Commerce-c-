#ifndef ADMIN_H
#define ADMIN_H


#include"inventory.h"
#include "user.h"
class admin : public User{ // Class that handles all the operations regarding the Admin

private:
    Inventory i1; // To access inventory

public:
	void reader();//to read index inventory and inventory array

    void register_user() // Method to register the user
   ;
    bool login() // Method to login the user
    ;
    void logout() // Method to log out the user
   ;
    void update_profile() // Method to update the user profile
  ;
    bool is_logged() // Getting the Logged in status
   ;
    void addProductToInventory() // To add product to the inventory
   ;
    void updateProductInInventory() // To update product in the inventory
   ;
    void removeProductFromInventory() // To remove product from the inventory
   ;
    void viewInventory() // To view products from the inventory
   ;
    void findproductininventory() // To find product from the inventory
   ;
    // These are the methods that user need so we dont need to define them for the admin
    void setbalance(double);
    double getbalance() ;
    void top_up() ;
    void check_balance();
    void addToCart();
    void viewCart() ;
    void placeOrder(double) ;
    void addproducttowishlist() ;
    void removeproductfromwishlist() ;
    void showproductsfromwishlist() ;
    void findproductfromwishlist() ;
    void cancelOrder(double);
    void checkOrderStatus() ;
    void removeFromCart() ;
    void calculateTotalOfCart() ;
};
#endif // ADMIN_H
