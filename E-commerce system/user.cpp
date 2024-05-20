#include "user.h"

ifstream& operator>>(ifstream& in, User& u) {
    in >> u.username >> u.password >> u.email >> u.address;
    return in;
}

ofstream& operator<<(ofstream& out, User& u) {
    out << u.username << endl;
    out << u.password << endl;
    out << u.email << endl;
    out << u.address << endl;
    return out;
}
