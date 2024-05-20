#include "inventory.h"
#include <iostream>
#include <fstream>

using namespace std;

void Inventory::readArr(){
	// Reading products of inventory from external file
    ifstream ifs3("Inventory.txt");
    for (int i = 0; i < 25; i++)
    {
        ifs3 >> inventory_of_products[i] ;
    }
    ifs3.close();
}

void Inventory::reader(){
	//Reading Index of inventory from external file
	ifstream ifs("index_inventory.txt");

    ifs >> index_inventory;

    ifs.close();
}

void Inventory::addProductToInventory() {//adding product to the inventory
    p1.setname();
    p1.setprice();
    p1.setquantity();

    inventory_of_products[index_inventory] = p1;
    index_inventory++;
    ofstream ofs4("index_inventory.txt");//Saving the index of inventory on an external file
    ofs4 << index_inventory;
    ofs4.close();

    ofstream ofs1("Inventory.txt");//Saving the products stored in inventory to external file
    for (int i = 0; i <= index_inventory; i++) {
        ofs1 << inventory_of_products[i] << endl;
    }
    ofs1.close();
}

void Inventory::updateProduct() {// Updating the products stored in inventory
    cout << "Please enter the name of the product: " << endl;
    string info_product;
    cin >> info_product;
    bool found = false;
    int indexFound = 0;
    for (int i = 0; i < 25; i++) {//for finding th product
        if (info_product == inventory_of_products[i].getname()) {
            found = true;
            indexFound = i;
            break;
        }
    }
    if (found) {//if the product was found
        cout << "What do you wish to update? " << endl << "(1)Name (2)Price (3)Quantity " << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                inventory_of_products[indexFound].setname();
                cout << "Name Updated!" << endl;
                break;
            case 2:
                inventory_of_products[indexFound].setprice();
                cout << "Price Updated!" << endl;
                break;
            case 3:
                inventory_of_products[indexFound].setquantity();
                break;
            default:
                cout << "Invalid choice. " << endl;
        }
    } else {// If the product was not found
        cout << "No such product was found." << endl;
    }

    ofstream ofs1("Inventory.txt");//Storing the product after updating
    for (int i = 0; i <= index_inventory; i++) {
        ofs1 << inventory_of_products[i] << endl;
    }
    ofs1.close();
}

void Inventory::removeProductFromInventory() {// to remove product from inventory
    cout << "Please enter the name of the product that you wish to delete: " << endl;
    string info_product;
    cin >> info_product;
    bool found = false;
    int indexFound = 0;
    for (int i = 0; i < 25; i++) {//Finding the product
        if (info_product == inventory_of_products[i].getname()) {
            found = true;
            indexFound = i;
            break;
        }
    }
    if (found) {//Deleting the product if found
        for (int i = indexFound; i < 24; i++) {
            inventory_of_products[i] = inventory_of_products[i + 1];//Shifting products to the left
        }
        inventory_of_products[24] = Products();// Setting the last index of product to default;
        index_inventory--;//decrement index of inventory
        ofstream ofs4("index_inventory.txt");//Storing the index of inventory to external file
        ofs4 << index_inventory;
        ofs4.close();
        cout << "Product deleted successfully!" << endl;
    } else {
        cout << "No such product was found!" << endl;
    }

    ofstream ofs1("Inventory.txt");//Storing the products of inventory to external file
    for (int i = 0; i <= index_inventory; i++) {
        ofs1 << inventory_of_products[i] << endl;
    }
    ofs1.close();
}

void Inventory::showProductsFromInventory() {// to see all the products stored in the inventory
    for (int i = 0; i < index_inventory; i++) {
        cout << inventory_of_products[i] << endl;
    }
}

void Inventory::findProductFromInventory() {// to find the product in the inventory
    cout << "Please enter the name of the product: " << endl;
    string info_product;
    cin >> info_product;
    bool found = false;
    int indexFound = 0;
    for (int i = 0; i < 25; i++) {
        if (info_product == inventory_of_products[i].getname()) {
            found = true;
            indexFound = i;
            break;
        }
    }
    if (found) {
        cout << inventory_of_products[indexFound] << endl;
    } else {
        cout << "No such product was found." << endl;
    }
}
