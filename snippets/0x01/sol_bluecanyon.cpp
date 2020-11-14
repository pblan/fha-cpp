// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int pot(int b, int n);

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl
         << endl;

    int b,n;
    cout << "01|    Eingabe b: "; cin >> b;
    cout << "02|    Eingabe n: "; cin >> n;
    
    cout << "03|    b^n=" << pot(b,n) << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

int pot(int b, int n) {
    int prod{1};

//    for (int i=1; i<=n; ++i)
//        prod*=b;

    while ( (n--)>0 )
        prod*=b;

    return prod;
}
