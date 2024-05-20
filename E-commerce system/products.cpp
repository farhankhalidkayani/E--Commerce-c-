#include "products.h"
#include <iostream>
using namespace std;

void Products::quantityless(int q) {// to reduce the quantity by the passed argument
    quantity = quantity - q;
}

void Products::setname() {
    cout << "Please enter the Name: " << endl;
    cin.clear();
    cin.sync();
    getline(cin, name);
}

void Products::setprice() {
    cout << "Please enter Price: " << endl;
    cin >> price;
}

void Products::setquantity() {
    cout << "Please enter the quantity: " << endl;
    cin >> quantity;
}

string Products::getname() {
    return name;
}

double Products::getprice() {
    return price;
}

int Products::getquantity() {
    return quantity;
}

ofstream& operator<<(ofstream& out, Products& p1) {
    out << p1.name << endl;
    out << p1.price << endl;
    out << p1.quantity << endl;
    return out;
}

istream& operator>>(istream& in, Products& p1) {
    in >> p1.name >> p1.price >> p1.quantity;
    return in;
}

ostream& operator<<(ostream& out, Products& p1) {
    out << "Name: " << p1.name << endl;
    out << "Price: " << p1.price << endl;
    out << "Quantity: " << p1.quantity << endl;
    return out;
}
