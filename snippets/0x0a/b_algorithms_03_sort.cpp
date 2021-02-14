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

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    array<int,6> a = { 1, 2, 3, 9, 8, 7 }; 
    cout << "01|    a=" << a << endl;

    cout << "-----" << endl;
    
    // sorting

    cout << "02|    is sorted ? " 
         << std::is_sorted(a.begin(), a.end() )             // (B)
         << endl;

    auto until_elem = std::is_sorted_until(a.begin(), a.end() );
    cout << "03|    is sorted until ? "                     // (C)
         << *until_elem
         << endl;
         
    std::sort(a.begin(), a.end());
    cout << "04|    sort, a=" << a << endl;
    cout << "05|    is sorted ? " 
         << std::is_sorted(a.begin(), a.end() ) 
         << endl;

    cout << "-----" << endl;
    
    auto min_elem = std::min_element(a.begin(), a.end());   // (D)
    cout << "06|    min ? " 
         << *min_elem
         << endl;

    auto max_elem = std::max_element(a.begin(), a.end()); 
    cout << "07|    max ? " 
         << *max_elem
         << endl;
         
    auto upper_bnd_elem = std::upper_bound(a.begin(), a.end(),3); 
    cout << "08|    upper bound 3 ? "                       // (E)
         << *upper_bnd_elem
         << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}


/* Kommentierung
 * 
 * (A)  Ausgaben.
 * 
 * (B)  Ist das Feld sortiert?
 * 
 * (C)  Oder, bis wohin ist es denn sortiert?
 * 
 * (D)  Minimum bzw. Maximum ermitteln.
 * 
 * (E)  Das erste Element groesser als 3.
 * 
 */
 
