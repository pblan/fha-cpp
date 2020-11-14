// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::string;

string doppelt(const string& s);

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
        
    auto f = 1.23f;                                         // (A) 
    auto d = 2.34;                                          // (B)
    
    auto i = 1;                                             // (C)
    auto l = 2l;                                            // (D)
    auto c = 'x';                                           // (E)
    
    // Anwendungsfall z.B.
    // for (auto x : v) { ... }

    cout << "01|    f=" << f << ", sizeof(f)=" << sizeof(f) << endl;
    cout << "02|    d=" << d << ", sizeof(d)=" << sizeof(d) << endl;
    cout << "03|    i=" << i << ", sizeof(i)=" << sizeof(i) << endl;
    cout << "04|    l=" << l << ", sizeof(l)=" << sizeof(l) << endl;
    cout << "05|    c='" << c << "', sizeof(c)=" << sizeof(c) << endl;

    cout << "-----" << endl;

    auto& r{i};                                             // (F)
    cout << "06|    r=" << r << ", sizeof(r)=" << sizeof(r) << endl;

    cout << "-----" << endl;
    
    auto s = doppelt("01234");                              // (G)
    cout << "07|    s='" << s << "', sizeof(s)=" << sizeof(s) << endl;
       
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

string doppelt(const string& s)
{
    return s+s;
}

/* Kommentierung
 * 
 * (A)  Aus dem Literal oder Ergebnistyp kann auf den Datentyp 
 *      geschlossen werden, hier 'float'...
 * 
 * (B)  hier 'double'...
 * 
 * (C)  hier 'int'...
 * 
 * (D)  hier 'long'...

 * (E)  und 'char'.
 * 
 * (F)  'auto' gibt es auch als Referenz, das entspricht hier einem 'int'.
 * 
 * (G)  Der Datentyp wird von der rechten Seite abgeleitet (type deduction),
 *      das geht auch für Rückgabetypen einer Funktion.
 *      Frage: Warum ist der String 32 Bytes groß?
 */
 
