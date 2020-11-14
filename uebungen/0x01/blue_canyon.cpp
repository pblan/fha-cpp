// author: paddel@paddel.xyz

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int pot(int b, int n, bool isWhile);

int main() 
{
    cout << "b: ";
    int b;
    cin >> b;
    
    cout << "n: ";
    int n;
    cin >> n;
    
    cout << "b^n (while): " << pot(b, n, 1) << endl;
    cout << "b^n (for): " << pot(b, n, 0) << endl;
}

int pot(int b, int n, bool isWhile) {
    int res = b;
    if (isWhile) while (n-- > 1) res *= b;
    else for (int i = 1; i < n; i++) res *= b; 
    return res;
}