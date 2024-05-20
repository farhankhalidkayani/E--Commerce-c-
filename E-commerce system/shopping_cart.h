#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include"inventory.h"
#include"products.h"

class shopping_cart // Class to perform all the operations regarding the Shopping Cart
{
private:
    Inventory i1; // So that we can see all the products that are stored in the inventory
    Products p1;  // Product and Shopping cart have a composition relationship

    double total_price = 0; // To store the total price of all the products that are stored in the Shopping cart

public:
	int index_shoppingCart = 0;
Products list_of_products[25];      // Storage for Shopping Cart
void reader();
void readArr();
    void addProduct() // To add product to the shopping cart
    ;
    void removeProduct() // To Delete a product from the Shopping Cart
   ;
    void showShoppingCart() // Viewing the shopping cart using while loop
   ;
    double calculateTotal() // Method to calculate the Total price of the shopping cart
   ;
};
#endif // SHOPPING_CART_H
