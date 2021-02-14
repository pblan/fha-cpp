// author: a.voss@fh-aachen.de

#include <iostream>
#include <algorithm>
#include <functional>
#include <array>

using std::cout;
using std::endl;
using std::ostream;
using std::array;
using std::sort;

template <typename T, size_t DIM>                           // (A)
ostream& operator<<(ostream& os, const array<T,DIM>& a) {
    os << "[ ";
    for (auto x : a) {
        os << x << " ";
    }   
    os << "]";
    return os;
}

bool even_odd(int a, int b) {                               // (B)
    return (a%2==b%2) ? (a<=b) : (a%2==0);
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    array<int,10> a = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3}; 
    cout << "01|    init.   a=" << a << endl;
    
    sort(a.begin(), a.end());                               // (C)
    cout << "02|    sort    a=" << a << endl;
 
    sort(a.begin(), a.end(), even_odd);                     // (D)
    cout << "03|    even    a=" << a << endl;

    struct {
        bool operator()(int a, int b) const { 
            return (a%2==b%2) ? (a>=b) : (a%2==1); 
        }   
    } odd_even;
    sort(a.begin(), a.end(), odd_even);                     // (E)
    cout << "04|    odd     a=" << a << endl;
    
    sort(a.begin(), a.end(), std::greater<>());             // (F)
    cout << "05|    greater a=" << a << endl;
    
                                                            // (G)
    sort(a.begin(), a.end(), [](int a, int b) -> bool { return a <= b; });
    cout << "06|    lambda  a=" << a << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}


/* Kommentierung
 * 
 * (A)  Nur Ausgabe des array.
 * 
 * (B)  Vergleich zweier ints, der in zwei Gruppen teilt (gerade,ungrade)
 *      und innerhalb der Gruppen nach Groesse sortiert.
 * 
 * (C)  sort-Funktion ohne weitere Parameter, nur von- und bis-Iteratoren;
 *      sortiert nach Groesse.
 * 
 * (D)  Sortiert wie in (C), aber verwendet fuer den Vergleich zweier Elemente
 *      die angegebene Funktion. Frage: Welchen Datentyp hat der Parameter?
 * 
 * (E)  Analog zu (D), aber der Vergleichsoperator ist durch das Objekt
 *      und den ()-Operator gegeben.
 * 
 * (F)  Manche Vergleichsoperatoren sind vordefiniert, so etwa greater<>.
 * 
 * (G)  Das ist die kuerzeste Variante mit lambda-Expressions - wird in
 *      weiteren Snippets erklaert. Vorteil: kann direkt an Ort und Stelle
 *      ohne weitere Strukturen oder Funktionen definiert werden.
 * 
 */
 
