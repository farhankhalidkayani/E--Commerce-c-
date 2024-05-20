#ifndef REGULAR_USER_H
#define REGULAR_USER_H


#include "wishlist.h"
#include "payment.h"
#include "user.h"
#include "orders.h"
#include "shopping_cart.h"

class regular_user : public User // Class the handles all the operation regarding the regular user
{
    shopping_cart s1; // So that we can access the methods of the Shopping cart
    wallet w1;        // So that we can access the methods of the Wallet
    orders o1;        // So that we can access the methods of the Orders
    wishlist w;       // So that we can access the methods of the Wishlist
    payment p1;       // So that we can access the methods of the  Payment

public:
	void reader();// method to read the necessary things from external files
    void register_user() // Method to register the user
   ;
    bool login() // Method to login the user
    ;
    void logout() // Method to log out the user
   ;
    void update_profile() // Method to update the user profile
   ;
    bool is_logged() // To get the logged status of the User
   ;
    void top_up() // To top-up amount to the user wallet
   ;
    void check_balance() // TO check the amount in the users wallet
   ;
    void addToCart() // To add product to the Shopping cart
    ;
    void viewCart() // To view products from the Shopping cart
    ;
    void removeFromCart() // To remove product from the Shopping cart
   ;

    void calculateTotalOfCart() // To calculate total of the Shopping cart
    ;
    void placeOrder(double balance) // To place the order
   ;
    void cancelOrder(double balance) // To cancel the order
   ;
    void checkOrderStatus() // To check the order status
   ;
    void addproducttowishlist() // To add product to the Wishlist
   ;
    void removeproductfromwishlist() // To remove product from the Wishlist
   ;
    void showproductsfromwishlist() // To show products from the Wishlist
   ;
    void findproductfromwishlist() // To find product from the Wishlist
   ;
    void setbalance(double b) // To set balance of the user wallet
   ;
    double getbalance() // to get balance of the user wallet
   ;

    // These methods are for the use of admin so we dont need to define any functionality in them here
    void addProductToInventory() ;
    void updateProductInInventory() ;
    void removeProductFromInventory() ;
    void viewInventory() ;
    void findproductininventory() ;
};
#endif // REGULAR_USER_H
