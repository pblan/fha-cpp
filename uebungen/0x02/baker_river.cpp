#include <iostream>
#include <cmath>

using namespace std;

void cut(double &a, double &b);
void shift(string &a, string &b, string &c);

int main() 
{
    double a{5.4}, b{1.2};
    cout << "a: " << a << ", b: " << b << endl;
    cut(a, b);
    cout << "a: " << a << ", b: " << b << endl;

    string x{"Test A"}, y{"Test B"}, z{"Test C"};
    cout << "x: " << x << ", y: " << y << ", z: " << z << endl;
    shift(x,y,z);
    cout << "x: " << x << ", y: " << y << ", z: " << z << endl;
    return 0;
}

void cut(double &a, double &b) {
    a = floor(a);
    b = floor(b);
}

void shift(string &a, string &b, string &c) {
    string help = a;
    a = b;
    b = c; 
    c = help;
}