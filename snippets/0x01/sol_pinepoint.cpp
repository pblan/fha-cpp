// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

bool isPrim(int n);

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    int n;
    cout << "01|    Eingabe n: "; cin >> n;
    
    for (int i=2; i<=n; ++i) {
        if (isPrim(i))
            cout << "02|      i=" << i << " ist prim" << endl;
    }
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

bool isPrim(int n) 
{
    for (int i=2; i<n; ++i)
        if (n%i==0)
            return false;
    return true;
}
