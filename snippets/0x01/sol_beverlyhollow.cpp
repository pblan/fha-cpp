// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void fib_iterativ(int n);
void fib_rekursiv(int n);

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    int n;
    cout << "01|    Eingabe n: "; cin >> n;

    cout << "-----" << endl;
    
    fib_iterativ(n);

    cout << "-----" << endl;

    fib_rekursiv(n);
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

void fib_iterativ(int n) 
{
    cout << "01|    fib iterativ, n=" << n << endl;
    
    int a{1},b{1},c;
    
    cout << "02|      a_0=" << a << endl;
    cout << "03|      a_1=" << b << endl;
    for (int i=2; i<=n; ++i) {
        c = a+b;
        cout << "04|      a_" << i << "=" << c << endl;
        a=b;
        b=c;
    }
}

int fib(int n) {
    return (n<=1) ? 1 : fib(n-2)+fib(n-1);
}

void fib_rekursiv(int n)
{
    cout << "05|    fib rekursiv, n=" << n << endl;
    
    cout << "06|      a_0=" << fib(0) << endl;
    cout << "07|      a_1=" << fib(1) << endl;
    for (int i=2; i<=n; ++i) {
        cout << "08|      a_" << i << "=" << fib(i) << endl;
    }
}
