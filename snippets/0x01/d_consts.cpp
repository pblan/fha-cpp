// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

int mal3(const int n) { return n*3; }                       // (C)

int main()
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    int i{1};
    const int j{2};                                         // (A)
    
    cout << "01|    i=" << i << ", j=" << j << endl;

    i = 3;
    // j = 4;                                               // (B)

    cout << "02|    i=" << i 
         << ", i mal3=" << mal3(i) << endl;                 // (C)

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  const vor den Datentyp führt dazu, dass die Variable im
 *      Weiteren nicht mehr verändert werden kann - sie ist konstant.
 *      Es können alle Typen mit const versehen werden.
 *
 * (B)  Der Ausdruck führt zu einem Compiler-Fehler.
 * 
 * (C)  Eine Funktion, in der 'n' konstant ist, obwohl der Parameter
 *      'i' nicht konstant ist. Die konstante Eigenschaft gilt nur 
 *      innerhalb 'mal3'.
 */

