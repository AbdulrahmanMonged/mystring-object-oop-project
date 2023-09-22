#include <iostream>
#include "mystring.h"


using namespace std;

int main() {
    Mystring a{};
    Mystring b{};
    Mystring c{};
    cin >> a >> b >> c;
    cout << a + " " + b + " " + c;
    
    return 0;

}