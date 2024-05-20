#include<iostream>
#include<fstream>
#include "wishlist.h"
using namespace std;
void wishlist::reader(){
	 ifstream ifs1("index_wishlist.txt");

    ifs1 >> index_wishlist;

    ifs1.close();
     i1.readArr();
}
void wishlist::readArr(){
	 // Reading products of Wishlist from external file
    ifstream ifs5("Wishlist.txt");

    for (int i = 0; i < 25; i++)
    {
        ifs5 >> wishlist_of_products[i];
    }
    ifs5.close();
    i1.reader();

}
    void wishlist::addProductToWishlist() // method to add the product to wishlist
    {
        Products p2;
        cout << "Please choose from the following products by Entering its name: " << endl;
        i1.showProductsFromInventory(); // Allowing user to see all the products in the inventory so they can choose from them
        cout << "Please enter the name of the product: " << endl;
        string info_product;
        cin >> info_product;
        bool found = false;
        int indexFound = 0;
        for (int i = 0; i <25; i++)
        {
            if (info_product == i1.inventory_of_products[i].getname())
            {
                found = true;
                indexFound = i;
                break;
            }
        }

        // finding that specific product and then copying it in another product object so we can store it in the wishlist

        if (found)
        {
            p2 = i1.inventory_of_products[indexFound];

            wishlist_of_products[index_wishlist] = p2;
            index_wishlist++;
            ofstream ifs1("index_wishlist.txt");

            ifs1 << index_wishlist;

            ifs1.close();
        }
        else
        {
            cout << "No such product was found." << endl;
        }
        // Storing the Wishlist on external file
        ofstream ofs1("Wishlist.txt");
        for (int i = 0; i < 25; i++)
        {
            ofs1 << wishlist_of_products[i] << endl;
        }
        ofs1.close();
    }

    void wishlist::removeProductFromWishlist() // method to remove the product from the wishlist
    {
        cout << "Please enter the name of the product that you wish to delete: " << endl;
        string info_product;
        cin >> info_product;
        bool found = false;
        int indexFound = 0;
        for (int i = 0; i < 25; i++)
        {
            if (info_product == wishlist_of_products[i].getname())
            {
                found = true;
                indexFound = i;
                break;
            }
        }
        // fidning the product
        if (found) // checking if the product was found
        {
            // Shift elements to the left to overwrite the deleted product
            for (int i = indexFound; i < 24; i++)
            {
                wishlist_of_products[i] = wishlist_of_products[i + 1];
            }
            wishlist_of_products[24] = Products();
            cout << "Product deleted successfully!" << endl;
            index_wishlist--;
            ofstream ifs1("index_wishlist.txt");

            ifs1 << index_wishlist;

            ifs1.close();
        }
        else
        {
            cout << "No such product was found!" << endl;
        }
        // Storing the Wishlist on external file
        ofstream ofs1("Wishlist.txt");
        for (int i = 0; i <= index_wishlist; i++)
        {
            ofs1 << wishlist_of_products[i] << endl;
        }
        ofs1.close();
    }
    void wishlist::showProductsFromWishlist() // Method to display all the objects stored in the wishlist
    {
        for (int i = 0; i < index_wishlist; i++) // using for loop to access the Wishlist
        {

            cout << wishlist_of_products[i] << endl;
        }
    }
    void wishlist::findProductFromWishlist() // method to find the specific product stored in the wishlist
    {
        cout << "Please enter the name of the product: " << endl;
        string info_product;
        cin >> info_product;
        bool found = false;
        int indexFound = 0;
        for (int i = 0; i <= index_wishlist; i++)
        {
            if (info_product == wishlist_of_products[i].getname())
            {
                found = true;
                indexFound = i;
                break;
            }
        }
        // fidning the product
        if (found) // checking if the product was found
        {
            cout << wishlist_of_products[indexFound] << endl;
        }
        else
        {
            cout << "No such product was found." << endl;
        }
    }
