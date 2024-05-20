#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <iostream>
#include <fstream>

using namespace std;

class Products {//Class to handle all the operations regarding the products
private:
    string name;
    double price;
    int quantity;

public:
    void quantityless(int q);// to reduce the quantity by passed argument
    void setname();
    void setprice();
    void setquantity();
    string getname();
    double getprice();
    int getquantity();
//Overlaoding the operators to help with the file handling and displaying the products
    friend ostream& operator<<(ostream& out, Products& p1);
    friend ofstream& operator<<(ofstream& out, Products& p1);
    friend istream& operator>>(istream& in, Products& p1);
};

#endif // PRODUCTS_H
