// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    int n{1};
    float f{2.0};
    
    int* pn{&n};
    float* pf{&f};
    
    cout << "01|    n=" << n << ", *pn=" << *pn << ", pn=" << pn << endl;
    cout << "02|    f=" << f << ", *pf=" << *pf << ", pf=" << pf << endl;

    *pn = 3;
    *pf = 4.0;
    cout << "03|    n=" << n << ", *pn=" << *pn << ", pn=" << pn << endl;
    cout << "04|    f=" << f << ", *pf=" << *pf << ", pf=" << pf << endl;

    cout << "-----" << endl;

    int** ppn{&pn};
    cout << "05|    n=" << n << ", **ppn=" << **ppn << ", ppn=" << ppn << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
