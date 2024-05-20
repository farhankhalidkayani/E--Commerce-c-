#ifndef INVENTORY_H
#define INVENTORY_H

#include "products.h"

class Inventory {// Class to handle all the operations regarding the Inventory
private:
    Products p1;//Composition
    

public:
	int index_inventory=0 ;//Index of inventory to use with the inventory array
Products inventory_of_products[25];// Inventory array
void reader();//to read index inventory 
void readArr();//to read inventory array
    void addProductToInventory();
    void updateProduct();
    void removeProductFromInventory();
    void showProductsFromInventory();
    void findProductFromInventory();
};

#endif // INVENTORY_H
