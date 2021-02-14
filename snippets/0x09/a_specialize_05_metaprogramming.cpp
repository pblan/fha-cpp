// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

template <int N>                                            // (A)
struct fib {
    static const int value=fib<N-1>::value+fib<N-2>::value;
};

template <>                                                 // (B)
struct fib<1> {
    static const int value=1;
};

template <>                                                 // (C)
struct fib<0> {
    static const int value=0;
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01|    fib={1,1,2,3,5,8,13,21,...}" << endl;

    cout << "-----" << endl;

    cout << "02|    fib(1)=" << fib<1>::value << endl;      // (D)
    cout << "03|    fib(5)=" << fib<5>::value << endl;
    cout << "04|    fib(8)=" << fib<8>::value << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Ziel ist es, die Fibonacci Folge bzw. einzelne Folgenglieder
 *      zur compile-Zeit zu berechnen.
 *      Dazu gibt es das Template, welches die Rekursionsvorschrift
 *      enthält und explizit die value-Werte niedriger fib-values
 *      verwendet. Das führt dazu, dass diese Klassen ebenfalls
 *      generiert werden ... usw.
 * 
 * (B),(C)  Spezialisierung für 0 und 1. Das beendet die Rekursion 
 *      aus (A).
 * 
 * (D)  Hier wird der Wert zur Compilezeit berechnet.
 * 
 */
 
