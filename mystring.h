#ifndef __MYSTRING_H__
#define __MYSTRING_H__
#include <string>



class Mystring {
    //friends
    friend std::istream &operator>>(std::istream &is, Mystring &obj);
    friend std::ostream &operator<<(std::ostream &os, const Mystring &obj);
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);
    friend bool operator==(const Mystring &lhs ,const Mystring &rhs);
    friend Mystring operator--(const Mystring &obj);
private:
    char *str;

public:
    

    // constructors
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    Mystring(Mystring &&source);

    //destructor
    ~Mystring();

    //Overloading Operators
    Mystring &operator=(const Mystring &rhs); // copy assignment
    Mystring &operator=(Mystring &&rhs); // Move Assignment
    Mystring operator-();
  

    //getters
    size_t get_length();
    void display();
    char *get_string();

};

#endif // __MYSTRING_H__
