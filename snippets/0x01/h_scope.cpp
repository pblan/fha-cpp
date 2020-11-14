// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

int n{1};                                                   // (A)

int isNear(int i, int j) 
{
    ++j;                                                    // (B)
	return (i==j);
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01|    n=" << n << endl;                       // (C)
    
    int n{2}, m{3};                                         // (D)
    cout << "02|    n=" << n << ", m=" << m << endl;
    cout << "03|    ::n=" << ::n << endl;                   // (E)

    cout << "-----" << endl;

    {
        int n{4}, m{5};                                     // (F)
        cout << "04|    n=" << n << ", m=" << m << endl;
    } 
    cout << "05|    n=" << n << ", m=" << m << endl;        // (G)
    
    cout << "-----" << endl;
    
    for (int i=1; i<=2; ++i) {                              // (H)
        cout << "06|    i=" << i << endl;
    }
    
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Das ist eine für diesen Quellcode global sichbare Variable n.
 * 
 * (B)  Innerhalb von isNear ist j eine Kopie der aufrufenden Variable
 *      und nur diese Kopie wird verändert - call by value.
 * 
 * (C)  An dieser Stelle ist nur das global n bekannt.
 * 
 * (D)  Ab hier gibt es ein lokales n, welches das globale n verdeckt.
 * 
 * (E)  Das globale n ist aber nach wie vor über die Angabe :: erreichbar.
 * 
 * (F)  Die lokalen n und m werden hier durch neue lokale n und m verdeckt. 
 *      Die anderen lokalen n und m sind nicht mehr sichtbar.
 * 
 * (G)  Ab hier ist der Gültigkeitsbereich (scope) von if vorbei und die
 *      beiden ersten lokalen n und m sind wieder sichtbar.
 * 
 * (F)  i wird verdeckt
 * 
 * (G)  Kopie von j
 * 
 * (H)  Die Variable i ist nur inerhalb des for-Blocks existent, danach 
 *      ist sie nicht mehr vorhanden.
 * 
 */
 
