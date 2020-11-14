// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
 
    int r;
    do {                                                    // (A)
        cout << "01|    Eingabe Reihe[2..20]: ";
        cin >> r;
    } while (r<=1 || r>20);
    
    int n;
    if (r<10) {                                             // (B)
        cout << "02|    Kleines 1x1:" << endl;
        n=10;
    } else {
        cout << "03|    Grosses 1x1:" << endl;
        n=20;
    } 
    
    for (int i=1; i<=n; ++i) {                              // (C)
        cout << "04|      " << r << "*" << i << ": " << r*i << endl;
    }

    // int i=1;
    // while (i<=n) {
    //     cout << "04|      " << r << "*" << i << ": " << r*i << endl;
    //     ++i;
    // }

    if (int r2=r*r) {                                       // (D)
        cout << "05|      r=" << r << ", r^2=" << r2 << endl;
    }
    // cout << r2 << endl; // r2 ist ungueltig
    
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}


/* Kommentierung
 * 
 * (A)  do-while-Schleife, wird mind. einmal durchlaufen.
 * 
 * (B)  if-else-Bedingung. 'else' ist optional.
 * 
 * (C)  for-Schleife mit den drei klassischen Blöcken: Initialisierung,
 *      Bedingung, 'next'-Anweisung.
 * 
 * (D)  If mit Zuweisung. Die Variable r2 ist nur innerhalb des Blocks
 *      sichtbar. Und if wird nur ausgeführt, wenn der Wert != 0 ist.
 * 
 * Allgemein gilt: die { } können jeweils weggelassen werden, wenn 
 * nur eine Anweisung in dem Block steht. In der Regel ist es aber 
 * sinnvoll, da weniger fehleranfällig, sie in jedem Fall zu verwenden.
 * 
 */
