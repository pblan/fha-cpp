// author: paddel@paddel.xyz

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() 
{
    cout << "n: ";
    int n;
    cin >> n;

    cout << "c: ";
    char c;
    cin >> c;

    bool capital = c >= 'A' && c <= 'Z';
    
    n > 0 ? cout << n << " ist größer als 0" : cout << n << " ist kleiner als 0";
    cout << endl;
    
    cout << c << " ist " << (capital ? "ein" : "kein") << " Großbuchstabe!";
    cout << endl;
}
