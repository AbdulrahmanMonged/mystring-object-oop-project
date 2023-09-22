#include <cstring>
#include <iostream>
#include "mystring.h"

using namespace std;


// Constructors
Mystring::Mystring() : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

Mystring::Mystring(const char *s) {
    if (s == nullptr ) {
        str = new char[1];
        *str = '\n';
    } else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

Mystring::~Mystring() {
    delete [] str;
}

Mystring::Mystring(const Mystring &source) : Mystring(source.str) {
    cout << "Copy Constructor is being called" << endl;
}

Mystring::Mystring(Mystring &&source) {
    str = source.str;
    source.str = nullptr;
    cout << "Move Constructor is being called" << endl;
    
}
//assignments
Mystring &Mystring::operator=(const Mystring &rhs) {
    cout << "Copy assignment is being called" << endl;
    if (this == &rhs) {
        return *this;
    } else {
        delete [] str;
        str = new char[strlen(rhs.str) + 1];
        strcpy(str, rhs.str);
        return *this;
    }
}

Mystring &Mystring::operator=(Mystring &&rhs) {
    cout << "Move Assignment is being called" << endl;
    if (this == &rhs) {
        return *this;
    } else {
        delete [] str;
        str = rhs.str;
        rhs.str = nullptr;
        return *this;
    }
}


Mystring Mystring::operator-() {
    cout << "Decreament is being called" << endl;
    char *buff = new char[strlen(str) + 1];
    for (size_t i{}; i < strlen(str); ++i) {
        buff[i] = tolower(str[i]);
    }
    Mystring temp{buff};
    delete [] buff;
    return temp;
}



size_t Mystring::get_length() {
    return strlen(str);
}

void Mystring::display() {
    cout << str << " : " << get_length() << endl;
}
char *Mystring::get_string() {
    return str;
    }


bool operator==(const Mystring &lhs ,const Mystring &rhs) {
    return (strcmp(lhs.str, rhs.str) == 0);
}

Mystring operator--(const Mystring &obj) {
    for(size_t i{}; i < strlen(obj.str) ; ++i) {
        (obj.str)[i] = tolower((obj.str)[i]);
    }
    return obj;
}

Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    char *buff = new char[strlen(lhs.str) + strlen(rhs.str) + 1];
    strcpy(buff, lhs.str);
    strcat(buff, rhs.str);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}


ostream &operator<<(ostream &os, const Mystring &obj) {
    os << obj.str;
    return os;
}

istream &operator>>(istream &is, Mystring &obj) {
    char *buff = new char[1000];
    is >> buff;
    obj = Mystring{buff};
    delete [] buff;
    return is;
}