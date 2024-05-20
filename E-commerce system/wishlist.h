#ifndef WISHLIST_H
#define WISHLIST_H


#include"inventory.h"
#include"products.h"

class wishlist // class to perform all the operation regarding the wishlist
{
private:
    Products p1;  // product and inventory has a realtionship of composition
    Inventory i1; // Using an object of inventory so that we can access inventory to see all the products in the inventory

public:
	int index_wishlist = 0;
Products wishlist_of_products[25];  // Storage for Shopping Cart
void reader();
void readArr();
    void addProductToWishlist() // method to add the product to wishlist
    ;

    void removeProductFromWishlist() // method to remove the product from the wishlist
    ;
    void showProductsFromWishlist() // Method to display all the objects stored in the wishlist
   ;
    void findProductFromWishlist() // method to find the specific product stored in the wishlist
   ;
};
#endif // WISHLIST_H
