#include <iostream>
#include <fstream>
#include "admin.cpp"
#include "inventory.cpp"
#include "orders.cpp"
#include "payment.cpp"
#include "products.cpp"
#include "regular_user.cpp"
#include "shopping_cart.cpp"
#include "user.cpp"
#include "wallet.cpp"
#include "wishlist.cpp"
using namespace std;
int userMenu(User* u){//Menu for the user
	int choice;
	cout << "*****************   E-Commerce Platform   *************************" << endl;
                        cout << "**(1)Update profile                                              **" << endl;
                        cout << "**(2)Top-up Balance in your Walet                                **" << endl;
                        cout << "**(3)Check Wallet Balance                                        **" << endl;
                        cout << "**(4)Add item to your Shopping Cart                              **" << endl;
                        cout << "**(5)View Shopping Cart                                          **" << endl;
                        cout << "**(6)Remove Item from Shopping Cart                              **" << endl;
                        cout << "**(7)Calculate Total of Shopping Cart                            **" << endl;
                        cout << "**(8)Place the order                                             **" << endl;
                        cout << "**(9)Cancel the order                                           **" << endl;
                        cout << "**(10)Check Order Status                                         **" << endl;
                        cout << "**(11)Add Item to Wishlist                                       **" << endl;
                        cout << "**(12)Remove Item to Wishlist                                    **" << endl;
                        cout << "**(13)Show Wishlist                                              **" << endl;
                        cout << "**(14)Find Item From Wishlist                                    **" << endl;
                        cout << "**(15)Log out                                                    **" << endl;
                        cout << "**(16)Exit                                                       **" << endl;
                        cout << "*******************************************************************" << endl;
                        cin >> choice;
                        if (choice == 1)
                        {
                            u->update_profile(); // To update profile
                            // Storing Users information on an external file
                            ofstream ofs("User_detail_regular.txt");
                            ofs << *u;
                            ofs.close();
                            return 3;
                        }
                        else if (choice == 2)
                        {
                            u->top_up(); // To Top-Up balance to users wallet
                        }
                        else if (choice == 3)

                        {

                            u->check_balance(); // To check users Balance
                            return 3;
                        }
                        else if (choice == 4)
                        {
                            u->addToCart(); // To add product to Shopping Cart
                        return 3;}
                        else if (choice == 5)
                        {
                            u->viewCart(); // To view Shopping Cart
                        return 3;}
                        else if (choice == 6)
                        {
                            u->removeFromCart(); // To remove product from Shopping Cart
                        return 3;}
                        else if (choice == 7)
                        {
                            u->calculateTotalOfCart(); // To calculate the total price of the cart
                        return 3;}

                        else if (choice == 8)
                        {
                            
                            u->placeOrder( u->getbalance()); // To Place the order
                       return 3; }
                        else if (choice == 9)
                        {
                            
                            u->cancelOrder( u->getbalance()); // To Cancel the order
                      return 3;  }
                        else if (choice == 10)
                        {
                            u->checkOrderStatus(); // To check the order status
                      return 3;  }
                        else if (choice == 11)
                        {
                            u->addproducttowishlist(); // To add product to Wishlist
                      return 3;  }
                        else if (choice == 12)
                        {
                            u->removeproductfromwishlist(); // To remove product from Wishlist
                       return 3; }
                        else if (choice == 13)
                        {
                            u->showproductsfromwishlist(); // To show Wishlist
                      return 3;  }
                        else if (choice == 14)
                        {
                            u->findproductfromwishlist(); // To find product on Wishlist
                      return 3;  }

                        else if (choice == 15)
                        {
                            u->logout(); // to log out
                            return 1;
                        }
                        else if (choice == 16)
                        {
                            delete u; // Deleting u to prevent memory leak
                            return 0;
                        }
                        else
                        {
                            cout << "Invalid choice!" << endl;
                       return 3; }
}

int adminMenu(User* u){// Menu for the admin
	int choice;
	
	 cout << "*****************   E-Commerce Platform   *************************" << endl;
                        cout << "**(1)Update profile                                              **" << endl;
                        cout << "**(2)Add product to Inventory                                    **" << endl;
                        cout << "**(3)Update product from Inventory                               **" << endl;
                        cout << "**(4)Remove product from Inventory                               **" << endl;
                        cout << "**(5)View Inventoy                                               **" << endl;
                        cout << "**(6)Find product in Inventory                                   **" << endl;
                        cout << "**(7)Log out                                                     **" << endl;
                        cout << "**(8)Exit                                                        **" << endl;
                        cout << "*******************************************************************" << endl;
                        cin >> choice;
                        if (choice == 1)
                        {
                            u->update_profile(); // To update profile
                            // Storing Users information on an external file
                            ofstream ofs("User_detail_admin.txt");
                            ofs << *u;
                            ofs.close();
                        return 3;}
                        else if (choice == 2)
                        {
                            u->addProductToInventory(); // To add product to inventory
                        return 3;}
                        else if (choice == 3)
                        {
                            u->updateProductInInventory(); // To update product in inventory
                        return 3;}
                        else if (choice == 4)
                        {
                            u->removeProductFromInventory(); // To remove product from inventory
                        return 3;}
                        else if (choice == 5)
                        {
                            u->viewInventory(); // to view inventory
                        
						return 3;}
                        else if (choice == 6)
                        {
                            u->findproductininventory(); // to find product in inventory
                            return 3;
                        }

                        else if (choice == 7)
                        {
                            u->logout(); // to log out

                            return 1;
                        }
                        else if (choice == 8)
                        {
                            delete u; // Deleting u to prevent memory leak
                            return 0;
                        }
                        else
                        {
                            cout << "Invalid choice!" << endl;
                            return 3;
                        }
                    }


int main() // Main function
{
   

    User *u;    // Base class pointer to implement polymorphism
       int choice;
        int action;
   
    // Menu for the user interface
    while (choice != 3)
    {

        cout << "*****************   E-Commerce Platform   *************************" << endl;
        cout << "**(1)Register                                                    **" << endl;
        cout << "**(2)Login                                                       **" << endl;
        cout << "**(3)Exit                                                        **" << endl;
        cout << "*******************************************************************" << endl;
        cin >> choice;
        if (choice == 1)
        {
            while (choice != 3)
            {
                cout << "*****************   E-Commerce Platform   *************************" << endl;
                cout << "**(1)Register as Admin                                           **" << endl;
                cout << "**(2)Register as User                                            **" << endl;
                cout << "**(3)Exit                                                        **" << endl;
                cout << "*******************************************************************" << endl;
                cin >> choice;
                if (choice == 1)
                {
                    u = new admin;// Base class pointer derived class object
					u->reader();    // reading the necessary from external files  
                    u->register_user(); // to register the user
                    // Storing user information on external file
                    ofstream ofs("User_detail_admin.txt");
                    ofs << *u;
                    ofs.close();
                   
                    // Menu for the Admin to perfrom Operations
                    while (choice != 8)
                    {
                      
					  action= adminMenu(u);
					  if(action==1){
					  	break;
					  }
					  if(action==0){
					  	return 0;
					  }
                }}
                else if (choice == 2)
                {
                    u = new regular_user; // Base class pointer derived class object
                    	u->reader(); // reading the necessary from external files
                    u->register_user();
                    // to register the user
                    // Storing user information on external file
                    ofstream ofs("User_detail_regular.txt");
                    ofs << *u;
                    ofs.close();
                    ifstream ifs6("Balance.txt");// reading the users balance stored in external file so that it can be used
                    double balance;
                    ifs6 >> balance;
                    u->setbalance(balance);

                    ifs6.close();

                    // Menu for the User to perfrom Operations
                    while (choice != 16)
                    {
                        action= userMenu(u);
					  if(action==1){
					  	break;
					  }
					  if(action==0){
					  	return 0;
					  }
                    }
                }

                else if (choice == 3)
                {
                    delete u; // Deleting u to prevent memory leak
                    return 0;
                }
                else
                {
                    cout << "Invalid Choice!" << endl;
                }
            }
        }
        else if (choice == 2)
        {
            while (choice != 3)
            {
                cout << "*****************   E-Commerce Platform   *************************" << endl;
                cout << "**(1)Log in as Admin                                             **" << endl;
                cout << "**(2)Log in as User                                              **" << endl;
                cout << "**(3)Exit                                                        **" << endl;
                cout << "*******************************************************************" << endl;
                cin >> choice;
                if (choice == 1)
                {
                    u = new admin; // Base class pointer derived class object
	u->reader(); // reading the necessary from external files
                    // Retreiving user information from external file
                    ifstream ifs("User_detail_admin.txt");
                    ifs >> *u;
                    ifs.close();
                    while (u->is_logged() == false)//Checking if the user is logged in or not
                    {
                        u->login(); // to log in the user
                    }

                    // Menu for the Admin to perfrom Operations
                    while (choice != 8)
                    {
                       action= adminMenu(u);
					  if(action==1){
					  	break;
					  }
					  if(action==0){
					  	return 0;
					  }
                    }
                }
                else if (choice == 2)
                {
                    u = new regular_user; // Base class pointer derived class object
	u->reader(); // reading the necessary from external files
                    // Retreiving user information on external file
                    ifstream ifs("User_detail_regular.txt");
                    ifs >> *u;
                    ifs.close();

                    while (u->is_logged() == false)
                    {
                        u->login(); // to log in the user
                    }

                    ifstream ifs6("Balance.txt");
                    double balance;
                    ifs6 >> balance;
                    u->setbalance(balance);

                    ifs6.close();

                    // Menu for the User to perfrom Operations
                    while (choice != 16)
                    {
action= userMenu(u);
					  if(action==1){
					  	break;
					  }
					  if(action==0){
					  	return 0;
					  }
                    }
                }

                else if (choice == 3)
                {
                    delete u; // Deleting u to prevent memory leak
                    return 0;
                }
                else
                {
                    cout << "Invalid Choice!" << endl;
                }
            }
        }
        else if (choice == 3)
        {
            delete u; // Deleting u to prevent memory leak
            return 0;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
