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

template <typename T, size_t DIM>                           // (A)
ostream& operator<<(ostream& os, const array<T,DIM>& a) {
    os << "[ ";
    for (auto x : a) {
        os << x << " ";
    }   
    os << "]";
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& a) {
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
        
    // Modifying sequence operation

    vector<int> v(5);
    std::fill(v.begin(), v.end(), 11);                      // (B)
    
    cout << "02|    fill 11, v=" << v << endl;
    
    std::copy_n(a.begin()+2, 5, v.begin());                 // (C)
    cout << "03|    copy_n from a, v=" << v << endl;
    
    int f1{0},f2{0};
    std::generate(v.begin(), v.end(),                       // (D)
        [&f1,&f2] () { int f{(f2>0)?f1+f2:1}; f1=f2; f2=f; return f; });
    cout << "04|    generate fib, v=" << v << endl;

    cout << "-----" << endl;

    std::replace(v.begin(), v.end(), 1, -1);                // (E)
    cout << "05|    replace 1, v=" << v << endl;
    std::replace_if(v.begin(), v.end(),                     // (F)
        [](int i){return (i>0);}, -2);
    cout << "06|    replace >0, v=" << v << endl;

    std::fill(v.end()-1, v.end(), 0);
    cout << "07|    fill last, v=" << v << endl;
    std::remove_if(v.begin(), v.end(),                      // (G)
                   [](int i){return (i==-1);});
    cout << "08|    remove -1, v=" << v << endl;

    cout << "-----" << endl;

    std::iota(v.begin(), v.end(), 10);                      // (H)
    cout << "09|    iota, v=" << v << endl;

    std::reverse(v.begin(), v.end());                       // (I)
    cout << "10|    reverse, v=" << v << endl;

    std::rotate(v.begin(), v.begin()+2, v.end());           // (J)
    cout << "11|    rotate 2, v=" << v << endl;

    cout << "-----" << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}


/* Kommentierung
 * 
 * (A)  Ausgaben fuer array und vectors.
 * 
 * (B)  Vektor mit Werten fuellen
 * 
 * (C)  Aus a ab Position 2 fuenf Elemente kopieren.
 * 
 * (D)  Den Vektor mit einer Generatorfunktion fuellen, hier mit den
 *      Fibonaccizahlen.
 * 
 * (E)  Einzelne Elemente ersetzen.
 * 
 * (F)  Einzelne Elemente je nach Bedingung ersetzen.
 * 
 * (G)  Einzelne Elemente entfernen. Das restliche Feld wird dabei nach
 *      vorne kopiert.
 * 
 * (H)  Eine aufsteigende Sequenz erzeugen...
 * 
 * (I)  ... oder umdrehen...
 * 
 * (J)  ... oder rotieren.
 * 
 */
 
