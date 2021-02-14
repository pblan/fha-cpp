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

    array<int,6> a = {  }; 
    cout << "01|    a=" << a << endl;

    cout << "-----" << endl;
    
    // numerics

    std::iota(a.begin(), a.end(),1);                        // (B)
    cout << "02|    iota from 1, a=" << a << endl;
    
    int sum_1_3 = std::accumulate(a.begin()+1, a.begin()+3+1,101);
    cout << "03|    sum idx 1..3 +101: " << sum_1_3 << endl;// (C)

    array<int,6> s = {  }; 
    std::partial_sum(a.begin(), a.end(),s.begin());         // (D)
    cout << "04|    partial sums, s=" << s << endl;

    cout << "-----" << endl;

    std::string msg("hello kurs");
    std::transform(msg.begin(), msg.end(), msg.begin(),     // (E)
                   [](unsigned char c) -> unsigned char { return (char)std::toupper(c); });
    cout << "05|    upper msg: '" << msg << "'" << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}


/* Kommentierung
 * 
 * (A)  Ausgaben.
 * 
 * (B)  Eine aufsteigende Sequenz erzeugen.
 * 
 * (C)  Ab Pos. 1 bis 3 aufsummieren (2+3+4), dann noch 101 addieren.
 * 
 * (D)  Partialsummen berechnen (1,1+2,1+2+3,...) , je nach inhalt in a.
 * 
 * (E)  Eine Sequenz von Elementen transformieren, hier in Grossbuchstaben
 *      umwandeln und wieder ablegen.
 * 
 */
 
