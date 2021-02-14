// author: a.voss@fh-aachen.de

#include <iostream>
#include <limits>
using std::cout;
using std::endl;
using std::numeric_limits;

void print_limits();
void print_sizes();

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    print_limits();                                         // (A)
    
    cout << "-----" << endl;

    print_sizes();                                          // (B)
    
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

void print_limits() {                                       // (C)
    cout << "01|    int::min=" << numeric_limits<int>::min() << endl;
    cout << "02|    int::max=" << numeric_limits<int>::max() << endl;
    cout << "03|    double::eps=" << numeric_limits<double>::epsilon() << endl;
}

template <typename T>                                       // (D)
struct type_special {
    static size_t calc_size() { return sizeof(T); }
};

template <>								                    // (E)
struct type_special<bool> {
    static double calc_size() { return 1.0/8.0; }
};

void print_sizes() {
    cout << "04|    int::size=" << type_special<int>::calc_size() << endl;
    cout << "05|    double::size=" << type_special<double>::calc_size() << endl;
    cout << "06|    bool::size=" << type_special<bool>::calc_size() << endl;
}


/* Kommentierung
 * 
 * (A)  Wir besprechen zuerst numeric_limits in print_limits.
 * 
 * (B)  Dann implementieren wir eine ähnliche eigene Funktionalität in
 *      print_sizes. Damit die template-Spezialisierung nicht vorher
 *      verwirrt, gibt es diese in den beiden Funktionen.
 * 
 * (C)  numeric_limits<int>::min() etc. sind statische Funktionen, die
 *      abhängig vom Template-Parameter (z.B. hier int) Metainformationen  
 *      zum Typ (z.B. min) geben.
 *      Realisiert wird das natürlich dadurch, dass es das Template
 *      numeric_limits in verschiedenen Spezialisierungen gibt.
 * 
 * (D)  Das Template type_special enthält eine statische Funktion calc_size
 *      (analog numeric_limits::min) die die Größe des Datentyps in Bytes liefert.
 * 
 * (E)  Ausser für bool, da würden wir gerne 1/8 als Größe liefern
 *      (man erinnere sich: sizeof >= 1 normalerweise).
 *      Dies ist eine Spezialisierung ohne weitere Parameter, daher ist 
 *      die Menge der übrigen Template-Parameter leer: <>
 *      Achtung: auch der return-Typ darf anders sein.
 * 
 */
 
