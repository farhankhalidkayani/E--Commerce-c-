#include "regular_user.h"

void regular_user::reader(){
	s1.reader();//to read the shopping cart index
	s1.readArr();//to read the shopping cart array
	w.reader();//to read the wishlist index
	w.readArr();//to read the wishlist array
	
}
    void regular_user::register_user() // Method to register the user
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
    bool regular_user::login() // Method to login the user
    {

        string input_logine, input_loginp;
        cout << "Please enter the username or email: " << endl;
        cin.clear();
        cin.sync();
        getline(cin, input_logine);
        cout << "Please enter the password: " << endl;
        cin.clear();
        cin.sync();
        getline(cin, input_loginp);
        if (input_logine == username || input_logine == email) // Condition to check if the email and the password are correct
        {
            if (input_loginp == password)
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
    void regular_user::logout() // Method to log out the user
    {
        is_logged_in = false;
    }
    void regular_user::update_profile() // Method to update the user profile
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
    bool regular_user::is_logged() // To get the logged status of the User
    {
        return is_logged_in;
    }
    void regular_user::top_up() // To top-up amount to the user wallet
    {
        cout << "Please enter the amount that you wish to top-up: " << endl;
        double amount;
        cin >> amount;
        w1.addbalance(amount);
        // Storing wallets balance on external file
        ofstream ofs4("Balance.txt");
        double balance;
        balance = w1.getbalance();
        ofs4 << balance;
        ofs4.close();
    }
    void regular_user::check_balance() // TO check the amount in the users wallet
    {
        cout << "Your Current Wallet Balance is: " << w1.getbalance() << endl;
    }
    void regular_user::addToCart() // To add product to the Shopping cart
    {
        s1.addProduct();
    }
    void regular_user::viewCart() // To view products from the Shopping cart
    {
        s1.showShoppingCart();
    }
    void regular_user::removeFromCart() // To remove product from the Shopping cart
    {
        s1.removeProduct();
    }

    void regular_user::calculateTotalOfCart() // To calculate total of the Shopping cart
    {

        cout << "Your Total is: " << s1.calculateTotal() << endl;
    }
    void regular_user::placeOrder(double balance) // To place the order
    {
    	 if (o1.getorderstatus() == 0){// checking if the order is placed or not
if(s1.list_of_products[0].getquantity()>0){ // checking if the shopping cart is not empty
if(balance>=s1.calculateTotal()){


        balance = p1.processPayment(balance,s1.calculateTotal());
        bool is_paid = p1.getpaymentstatus();
        o1.placeOrder(is_paid);
        w1.setbalance(balance);
        ofstream ofs4("Balance.txt");

        ofs4 << balance;
        ofs4.close();}
		else{
			cout<<"Not Enough Balance"<<endl;
		}
		}
        else{
        	cout<<"Please first add items to your shopping cart."<<endl;
		}}
		else{
			cout<<"Order already placed"<<endl;
		}
    }
    void regular_user::cancelOrder(double balance) // To cancel the order
    {
        if (o1.getorderstatus() == 1)// checking if the order is placed or not
        {
            o1.cancelOrder();
            balance = p1.refund(balance,s1.calculateTotal());
            w1.setbalance(balance);
            ofstream ofs4("Balance.txt");

            ofs4 << balance;
            ofs4.close();
        }
        else
        {
            cout << "There is no order to cancel" << endl;
        }
    };
    void regular_user::checkOrderStatus() // To check the order status
    {
        o1.checkOrderStatus();
    };
    void regular_user::addproducttowishlist() // To add product to the Wishlist
    {
        w.addProductToWishlist();
    }
    void regular_user::removeproductfromwishlist() // To remove product from the Wishlist
    {
        w.removeProductFromWishlist();
    }
    void regular_user::showproductsfromwishlist() // To show products from the Wishlist
    {
        w.showProductsFromWishlist();
    }
    void regular_user::findproductfromwishlist() // To find product from the Wishlist
    {
        w.findProductFromWishlist();
    }
    void regular_user::setbalance(double b) // To set balance of the user wallet
    {
        w1.setbalance(b);
    }
    double regular_user::getbalance() // to get balance of the user wallet
    {

        double balance = w1.getbalance();
        return balance;
    }

    // These methods are for the use of admin so we dont need to define functionality in them here
    void regular_user::addProductToInventory() {}
    void regular_user::updateProductInInventory() {}
    void regular_user::removeProductFromInventory() {}
    void regular_user::viewInventory() {}
    void regular_user::findproductininventory() {}
