// author: paddel@paddel.xyz

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

bool isPrim(int n);

int main() {
    int n;
    cout << "n: ";
    cin >> n;

    for (int i = 2; i <= n; i++)
        if (isPrim(i)) cout << i << endl;
    return 0;
}

bool isPrim(int n) 
{
    for (int i = 2; i < n; i++)
        if (n % i==0) return false;
    return true;
}
