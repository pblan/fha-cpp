// author: a.voss@fh-aachen.de

#include <iostream>
using namespace std;

template <typename T>
T inverse(const T & t) { return (T)1/t; }

template <>
char inverse(const char & t) { return (char)(90-(int)t+65); }

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01|    inv(0.1)=" << inverse(0.1) << endl;
    cout << "02|    inv(10.0)=" << inverse(10.0) << endl;
    cout << "03|    inv('B')='" << inverse('B') << "'" << endl;
 
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Spezialisierung funktioniert auch bei Funktionen
 * 
 * (B)  Berechne "Inverse" fuer chars wie folgt: A -> Z, B -> Y und vice versa
 * 
 * 
 */
 
