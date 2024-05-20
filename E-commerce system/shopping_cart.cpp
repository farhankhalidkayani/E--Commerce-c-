#include <iostream>
#include <fstream>
#include "shopping_cart.h"
using namespace std;

void shopping_cart::readArr(){
	 // Reading products of Shopping cart from external file
    ifstream ifs4("Shopping_cart.txt");

    for (int i = 0; i < 25; i++)
    {
        ifs4 >> list_of_products[i];
    }
    ifs4.close();
    i1.readArr();
}
void shopping_cart::reader(){
	ifstream ifs2("index_shoppingCart.txt");

    ifs2 >> index_shoppingCart;

    ifs2.close();
    i1.reader();
}
void shopping_cart::addProduct() // To add product to the shopping cart
{
    Products p2;
    cout << "Please choose from the following products by Entering its name: " << endl;
    i1.showProductsFromInventory(); // Allowing user to see all the products in the inventory so they can choose from them
    cout << "Please enter the name of the product: " << endl;
    string info_product;
    cin >> info_product;
    bool found = false;
    int indexFound = 0;
    for (int i = 0; i < 25; i++)
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
        p2.setquantity();                                                        // To allow user to select the quantity they want to buy
        if (p2.getquantity() <= i1.inventory_of_products[indexFound].getquantity()) // Checking if the quantity user wants is equal or less than the quantity available to purchase
        {
            i1.inventory_of_products[indexFound].quantityless(p2.getquantity()); // reducing the quantity from the inventory
            list_of_products[index_shoppingCart] = p2;
            index_shoppingCart++;
        }
        else
        {
            cout << "The quantity you have entered is more than what is available at the moment, Please enter new Quantity: " << endl;
            p2.setquantity();                                                        // Getting user to reenter the quantity
            if (p2.getquantity() <= i1.inventory_of_products[indexFound].getquantity()) // Checking if the quantity user wants is equal or less than the quantity available to purchase
            {
                i1.inventory_of_products[indexFound].quantityless(p2.getquantity()); // reducing the quantity from the inventory
                list_of_products[index_shoppingCart] = p2;
                index_shoppingCart++;
            }
            else
            {
                cout << "The quantity you have entered is more than what is available at the moment, Please enter new Quantity: " << endl;
                p2.setquantity();                                                 // Getting user to reenter the quantity
                i1.inventory_of_products[indexFound].quantityless(p2.getquantity()); // reducing the quantity from the inventory
                list_of_products[index_shoppingCart] = p2;
                index_shoppingCart++;
            }
        }
        ofstream ifs1("index_shoppingCart.txt");

        ifs1 << index_shoppingCart;

        ifs1.close();
    }
    else
    {
        cout << "No such product was found." << endl;
    }
    // Storing the Shopping cart on external file
    ofstream ofs1("Shopping_cart.txt");
    for (int i = 0; i <= index_shoppingCart; i++)
    {
        ofs1 << list_of_products[i] << endl;
    }
    ofs1.close();
}
void shopping_cart::removeProduct() // To Delete a product from the Shopping Cart
{
    cout << "Please enter the name of the product that you wish to delete: " << endl;
    string info_product;
    cin >> info_product;
    bool found = false;
    int indexFound = 0;
    for (int i = 0; i < 25; i++)
    {
        if (info_product == list_of_products[i].getname())
        {
            found = true;
            indexFound = i;
            break;
        }
    }
    // finding the product
    if (found) // checking if the product was found
    {
        // Shift elements to the left to overwrite the deleted product
        for (int i = indexFound; i < 24; i++)
        {
            list_of_products[i] = list_of_products[i + 1];
        }
        list_of_products[24] = Products();
        cout << "Product deleted successfully!" << endl;
        index_shoppingCart--;
        ofstream ifs1("index_shoppingCart.txt");

        ifs1 << index_shoppingCart;

        ifs1.close();
    }
    else
    {
        cout << "No such product was found!" << endl;
    }
    // Storing the Shopping cart on external file
    ofstream ofs1("Shopping_cart.txt");
    for (int i = 0; i <= index_shoppingCart; i++)
    {
        ofs1 << list_of_products[i] << endl;
    }
    ofs1.close();
}

void shopping_cart::showShoppingCart() // Viewing the shopping cart using while loop
{
    for (int i = 0; i < index_shoppingCart; i++) // using for loop to access the Wishlist
    {

        cout << list_of_products[i] << endl;
    }
}
double shopping_cart::calculateTotal() // Method to calculate the Total price of the shopping cart
{

    double price;
    int quantity;
    int total_price=0;

    for (int i = 0; i <= index_shoppingCart; i++)
    {
        price = list_of_products[i].getprice();
        quantity = list_of_products[i].getquantity();

        total_price = total_price + (price * quantity);
    }
    return total_price;
}
