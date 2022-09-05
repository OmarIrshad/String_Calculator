#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

int main() {
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    
    string a = ""; 
    string b = "";
    string c = "";

    cin >> a;
    cin >> b;
    c = multiply(a,b);
    cout << c << endl;
    // TODO(student): implement the UI
}

