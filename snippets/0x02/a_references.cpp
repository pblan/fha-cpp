// author: a.voss@fh-aachen.de

#include <iostream>

using std::cout;
using std::endl;

void set_zero_val(int n);                                   // Funktion steht hinter main
void set_zero_ref(int &n);

int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    int n;

    n = 1;
    int& m{n};                                              // (A)
    cout << "01|    n=" << n << ", m=" << m << endl;        // (B)

    n = 2;                                                  // (C)
    cout << "02|    n=" << n << ", m=" << m << endl;

    m = 3;                                                  // (D)
    cout << "03|    n=" << n << ", m=" << m << endl;

    cout << "-----" << endl;

    int k{4};
    m = k;                                                  // (E)
    cout << "04|    n=" << n << ", m=" << m << endl;

    cout << "-----" << endl;

    n = 1;
    cout << "05|    val: vorher n=" << n << endl;
    set_zero_val(n);                                        // (F)
    cout << "06|    nachher n=" << n << endl;

    cout << "-----" << endl;

    n = 2;
    cout << "07|    ref: vorher n=" << n << endl;
    set_zero_ref(n);                                        // (G)
    cout << "08|    nachher n=" << n << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

void set_zero_val(int n) {                                  // (F)
    cout << "-a|      n=" << n << endl;
    n = 0;
    cout << "-b|      n=" << n << endl;
}

void set_zero_ref(int& n) {                                 // (G)
    cout << "-c|      n=" << n << endl;
    n = 0;
    cout << "-d|      n=" << n << endl;
}

/* Kommentierung
 * 
 *  (A) m ist eine Referenz auf n, ein Alias für n, d.h. m ist nicht von n
 *      unterscheidbar - m ist n!
 * 
 * (B)  Auslesen von m ergibt den Wert von n.
 * 
 * (C)  Ändern von n ergibt neuen Wert für m (m ist n).
 * 
 * (D)  Wert von n über m ändern.
 * 
 * (E)  Eine Referenz kann nicht neu gesetzt werden! Hier wird der Wert
 *      von n auf den Wert von k gesetzt.
 * 
 * (F)  set_zero_val setzt den Parameter auf 0. In dieser Form ist es
 *      aber ein call-by-value, d.h. der Parameter wird kopiert und die 
 *      Kopie wird auf 0 gesetzt.
 * 
 * (G)  set_zero_ref setzt ebenfalls den Parameter auf 0. In dieser Form
 *      ist es ein call-by-ref (&), d.h. der aufrufende Parameter wird
 *      auf 0 gesetzt und es wird keine Kopie erzeugt.
 * 
 */
 
