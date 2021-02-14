// author: a.voss@fh-aachen.de

#include <iostream>
using namespace std;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    int n{23};                                              // (A)
    cout << "01|    n=" << n 
         << ", &n=" << &n << endl;

    int* pn = &n;                                           // (B)
    cout << "02|    pn=" << pn 
         << ", *pn=" << *pn
         << ", &pn=" << &pn << endl;

    int** ppn = &pn;                                        // (C)
    cout << "03|    ppn=" << ppn 
         << ", *ppn=" << *ppn
         << ", **ppn=" << **ppn << endl;

    cout << "-----" << endl;
    
    *pn = 1;                                                // (D)
    cout << "04|    *pn=1, n=" << n << endl;
    **ppn = 2;                                              // (E)
    cout << "05|    **ppn=2, n=" << n << endl;

    int*** pppn = &ppn;                                     // (F)
    ***pppn = 3;
    cout << "06|    ***pppn=3, n=" << n << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Nur 'int'.
 * 
 * (B)  Von rechts nach links: '*'=pointer auf 'int'.
 * 
 * (C)  '*'=pointer auf 'pointer auf int'.
 * 
 * (D)  *Ptr.-Variable=Dereferenzierung, nimmt ein 'pointer auf' weg, 
 *      also Deref. von 'pointer auf int' => 'int'.
 * 
 * (E)  Deref. von Deref. von 'pointer auf pointer auf int' => int.
 * 
 * (F)  Analog zu (B) und (D) bzw. (C) und (E), nur mit einem '*' mehr.
 * 
 */
 
