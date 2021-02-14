// author: a.voss@fh-aachen.de

#include <iostream>
#include <algorithm>
#include <functional>
#include <array>
#include <vector>
#include <iostream>
#include <numeric>

using std::cout;
using std::endl;
using std::ostream;
using std::array;
using std::vector;
using std::sort;

// see http://en.cppreference.com/w/cpp/algorithm

template <typename T, size_t DIM>                           // (A)
ostream& operator<<(ostream& os, const array<T,DIM>& a) {
    os << "[ ";
    for (auto x : a) {
        os << x << " ";
    }   
    os << "]";
    return os;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    array<int,11> a = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3, 5};
    cout << "01|    a=" << a << endl;

    cout << "-----" << endl;
    
    // Non-modifying sequence operations

    cout << "02|    all>=0 ? "                              // (B)
         << std::all_of(a.begin(), a.end(), [](int i){return i>=0;}) 
         << endl;
    cout << "03|    any<0 ? "                               // (C)
         << std::any_of(a.begin(), a.end(), [](int i){return i<0;}) 
         << endl;
    cout << "04|    none>=9 ? "                             // (D)
         << std::none_of(a.begin(), a.end(), [](int i){return i>=9;}) 
         << endl;

    cout << "-----" << endl;

    int sum{0};
    std::for_each(a.begin(), a.end(), 
                 [&sum](int i){sum+=i;});                   // (E)
    cout << "05|    for_each, sum=" << sum << endl;
    
    struct sum_op {
        sum_op(): sum{0} { }
        void operator()(int n) { sum += n; }
        int sum;
    };
    sum_op s = std::for_each(a.begin(), a.end(), sum_op() );// (F)
    cout << "06|    for_each, sum=" << s.sum << endl;

    cout << "-----" << endl;

    cout << "07|    count 1:" 
         << std::count(a.begin(), a.end(), 1) << endl;      // (G)
    cout << "08|    count 5:" 
         << std::count(a.begin(), a.end(), 5) << endl;
         
    cout << "09|    count>6:" 
         << std::count_if(a.begin(), a.end(),               // (H)
                          [](int i){return i>6;}) 
         << endl;

    cout << "-----" << endl;

    auto find_even = std::find_if(a.begin(), a.end(),       // (I)
                                  [](int i){return (i%2)==0;});
    cout << "10|    find even ? " << (find_even!=a.end());
    if (find_even!=a.end())
        cout << " -> " << *find_even;
    cout << endl;

    array<int,3> b = {1, 2, 4}; 
    auto find_one = std::find_first_of(a.begin(), a.end(),  // (J)
                                       b.begin(), b.end());
    cout << "11|    find first of ? " << (find_one!=a.end());
    if (find_one!=a.end())
        cout << " -> at:" 
             << std::distance(a.begin(),find_one);          // (K)
    cout << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}


/* Kommentierung
 * 
 * (A)  Ausgaben.
 * 
 * (B)  Erfuellen alle Elemente den lambda-Ausdruck? Hier >=0
 * 
 * (C)  Ist ein Element <0?
 * 
 * (D)  Ist kein Element >=9?
 * 
 * (E)  Summiere ueber alle Elemente. Beachte: &sum
 * 
 * (F)  Wie (E), nur als Struktur. Diese ist den internen Strukturen
 *      fuer lambda-Ausdruecke vergleichbar.
 * 
 * (G)  Zaehle alle "1" bzw. "5".
 * 
 * (H)  Zaehle mit Bedingung.
 * 
 * (I)  Finde ein Element, welches Bedingung erfuellt. Rueckgabe ist
 *      ein Iterator auf das Element oder end().
 * 
 * (J)  Finde eines der Elemente in der zweiten Menge, jeweils sind
 *      die zu betrachtenden Bereiche angegeben.
 * 
 * (K)  Anstatt nur das Element zu referenzieren kann man auch den Abstand
 *      zum Anfang berechnen.
 * 
 */
 
