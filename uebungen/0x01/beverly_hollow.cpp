// author: paddel@paddel.xyz

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int fib(int n);

int main() 
{
    int n, fib0 = 1, fib1 = 1, fibNext = 1;

    cout << "n: ";
    cin >> n;

    // iterativ
    cout << "Iterativ:\n";
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            cout << i << ". Element:" << fib0 << endl;
            continue;
        }

        if (i == 2)
        {
            cout << i << ". Element:" << fib1 << endl;
            continue;
        }

        fibNext = fib0 + fib1;
        fib0 = fib1;
        fib1 = fibNext;

        cout << i << ". Element:" << fibNext << endl;
    }

    int i = 1;
    // rekursiv
    cout << "Rekursiv:\n";
    while (i <= n) {
        cout << i << ". Element:" << fib(i) << endl;
        i++;
    }

    return 0;
}

int fib(int n) {
    if (n == 0 || n == 1) return n;
    return fib(n-1) + fib(n-2);
}

// Vermutlich wird in dieser Lösung der iterative Weg schneller sein, da nicht immer zwischen Funktionen hin- und hergesprungen werden muss.