#include <iostream>

using namespace std;

int main() {

    int a{65};
    cout << "a: " << a << endl;

    char *cp = (char*) &a;
    cout << "*cp: " << *cp << endl;
    cp[0]++;
    cout << "cp[0]++: " << cp[0] << endl;


    return 0;
}