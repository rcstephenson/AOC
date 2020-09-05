#include <iostream>

using namespace std; 

int main() {
    string x = "abc";
    string * y; 
    y = &x;

    cout << *y;
    
return 0;
}
