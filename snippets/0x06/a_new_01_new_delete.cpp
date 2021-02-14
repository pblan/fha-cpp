// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;


int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    int n{42};
    int* lpn{&n};                                           // (A)

    int* hpn{new int{23}};                                  // (B)

    cout << "01|    lpn=" << lpn << ", *lpn=" << *lpn << endl;
    cout << "02|    hpn=" << hpn << ", *hpn=" << *hpn << endl;

    hpn = new int{123};                                     // (C)
    cout << "03|    hpn=" << hpn << ", *hpn=" << *hpn << endl;

    delete hpn;                                             // (D)

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  lpn ist ein Zeiger auf n, welches lokal auf dem Stack liegt.
 *
 * (B)  hpn ist ein Zeiger auf eine int-Variable, die auf dem Heap
 *      mit new reserviert wird.
 *
 * (C)  new reserviert hier nun eine neue int-Var. auf dem Heap. Das
 *      Problem ist, dass der alte Zeigerwert nun überschrieben wurde
 *      und damit ist dieser Speicher zwar reserviert, aber nicht mehr
 *      zugreifbar... -> Speicherleck.
 *
 * (D)  Um das zu vermeiden, muss aller Speicher, der mit new reserviert
 *      wurde, auch wieder gelöscht werden. Das macht delete.
 *      Hier liegt natürlich eine große Gefahr...
 */
 
