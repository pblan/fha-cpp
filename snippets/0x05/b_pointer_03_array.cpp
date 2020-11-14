// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    const int dim = 3;
    int a[dim]={1,22,333};                                  // (A)
    int* p;

    p = &a[0];                                              // (B)
    cout << "01|    p=" << p << ", *p=" << *p << endl;
    p = &a[1];
    cout << "02|    p=" << p << ", *p=" << *p << endl;
    p = &a[2];
    cout << "03|    p=" << p << ", *p=" << *p << endl;

    cout << "-----" << endl;
    
    p = a;                                                  // (C)
    cout << "04|    p+0=" << p+0 
        << ", *(p+0)=" << *(p+0) << endl;                   // (D)
    cout << "05|    p+1=" << p+1 
        << ", *(p+1)=" << *(p+1) << endl;
    cout << "06|    p+2=" << p+2 
        << ", *(p+2)=" << *(p+2) << endl;

    cout << "-----" << endl;

    p = a;
    for (size_t i=0; i<dim; ++i) {
        cout << "07|    p+" << i << "=" << p+i              // (E)
            << ", *(p+" << i << ")=" << *(p+i) << endl;
    }

    cout << "-----" << endl;

    for (p=a; p-a < dim; ++p) {                             // (F)
        cout << "08|    p-a=" << p-a << ", *p=" << *p << endl;
    }
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Es wird ein Feld der Länge drei initialisiert. Wichtig ist hier 
 *      zu sehen, dass diese drei Werte direkt hintereinander im
 *      Speicher liegen!
 * 
 * (B)  Sieht man sich die Speicheradressen an, so folgen die Elemente
 *      unmittelbar hinter einander.
 * 
 * (C)  Wieso geht das, sind das gleich Typen? Ja, ein Feld ist nichts
 *      anderes als die Adresse des ersten (Index 0) Elements, also hier 
 *      ein Zeiger auf int.
 * 
 * (D)  Dereferenziert man also p+0 (erstes Element), p+1 (zweites Elem.)
 *      und p+2 (drittes Element), ergeben sich die drei Werte des Feldes.
 *      Wichtig ist hier festzuhalten, dass p+i sich auf die i'te int-Variable
 *      bezieht (Zeigerarithmetik), d.h. die Adresse in Bytes 
 *      ist p+i*sizeof(int).
 *      Deswegen sind typisierte Zeiger notwendig!
 * 
 * (E)  Wie (D) nur in einer Schleife.
 * 
 * (F)  Hier wird Zeigerarithmetik umgekehrt verwendet: p-a ist die 
 *      Differenz in Anzahl ints und ++p zählt p in int-Schritten hoch,
 *      also immer +4 Bytes.
 * 
 */
 
