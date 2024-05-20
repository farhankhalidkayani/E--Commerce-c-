#include <iostream>
#include <fstream>
#include "admin.h"
using namespace std;
void admin::reader(){//Reading index inventory and products to be stored in the inventory
	i1.reader();
	i1.readArr();
}
void admin::register_user() // Method to register the user
{
    cout << "Please enter the username you wish to register with: " << endl;
    cin.clear();
    cin.sync();
    getline(cin, username);
    cout << "Please enter the password: " << endl;
    cin.clear();
    cin.sync();
    getline(cin, password);
    cout << "Please enter the email address: " << endl;
    cin.clear();
    cin.sync();
    getline(cin, email);
    cout << "Please enter your address: " << endl;
    cin.clear();
    cin.sync();
    getline(cin, address);
}
bool admin::login() // Method to login the user
{

    string input_login1, input_login2;
    cout << "Please enter the username or email: " << endl;
    cin.clear();
    cin.sync();
    getline(cin, input_login1);
    cout << "Please enter the password: " << endl;
    cin.clear();
    cin.sync();
    getline(cin, input_login2);
    if (input_login1 == username || input_login1 == email) // Condition to check if the email and the password are correct
    {
        if (input_login2 == password)
        {
            cout << "You have logged in successfully!" << endl;
            is_logged_in = true;
            return true;
        }
        else
        {
            cout << "Wrong Password!" << endl;
            is_logged_in = false;
            return false;
        }
    }
    else
    {
        cout << "Wrong Email or Password!" << endl;
        is_logged_in = false;
        return false;
    }
}
void admin::logout() // Method to log out the user
{
    is_logged_in = false;
}
void admin::update_profile() // Method to update the user profile
{
    cout << "What do you wish to update? " << endl
         << "(1)Username (2)Password (3)Email (4)Address " << endl;
    int choice;
    cin >> choice;
    switch (choice) // Switch to check what the user wants to update and then update it.
    {
    case 1:
        cout << "Please enter the username you wish to change to: " << endl;
        cin.clear();
        cin.sync();
        getline(cin, username);
        cout << "Username Updted!" << endl;
        break;
    case 2:
        cout << "Please enter the password: " << endl;
        cin.clear();
        cin.sync();
        getline(cin, password);
        cout << "Password Updted!" << endl;
        break;

    case 3:
        cout << "Please enter the email address: " << endl;
        cin.clear();
        cin.sync();
        getline(cin, email);
        cout << "Email Updted!" << endl;
        break;
    case 4:
        cout << "Please enter your address: " << endl;
        cin.clear();
        cin.sync();
        getline(cin, address);
        break;
    default:
        cout << "Invalid choice. " << endl;
    }
}
bool admin::is_logged() // Getting the Logged in status
{
    return is_logged_in;
}
void admin::addProductToInventory() // To add product to the inventory
{
    i1.addProductToInventory();
}
void admin::updateProductInInventory() // To update product in the inventory
{
    i1.updateProduct();
}
void admin::removeProductFromInventory() // To remove product from the inventory
{
    i1.removeProductFromInventory();
}
void admin::viewInventory() // To view products from the inventory
{
    i1.showProductsFromInventory();
}
void admin::findproductininventory() // To find product from the inventory
{
    i1.findProductFromInventory();
};
// These are the methods that user need so we dont need to define functionality in them for the admin
void admin::setbalance(double) {}
double admin::getbalance() {}
void admin::top_up() {}
void admin::check_balance() {}
void admin::addToCart() {}
void admin::viewCart() {}
void admin::placeOrder(double) {}
void admin::addproducttowishlist() {}
void admin::removeproductfromwishlist() {}
void admin::showproductsfromwishlist() {}
void admin::findproductfromwishlist() {}
void admin::cancelOrder(double) {}
void admin::checkOrderStatus() {}
void admin::removeFromCart() {}
void admin::calculateTotalOfCart() {}
