// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

class address {
    int id;
    
public:
    address() : id{0} {                                     // (A)
        cout << "-a|      ctor(), id=" << id << endl;
    }
    
    address(int id) : id{id} {                              // (B)
        cout << "-b|      ctor(int), id=" << id << endl;
    }

    address(const address& a) : id{a.id+1} {                // (C)
        cout << "-c|      ctor(address&), id=" << id << endl;
    }

    ~address() { 
        cout << "-d|      dtor(), id=" << id << endl; 
    }
};

address a(-1);                                              // (D)

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01|    start" << endl;
    
    address a0;
    address a1(1);
    address a2(a1);
    address a3=a2;                                          // (E)
    address a4{a3};                                         // (F)

    cout << "02|    ende" << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}                                                           // (G)

/* Kommentierung
 * 
 * (A)  Standard-ctor, Verwendung ohne Argumente (auch ohne Klammern),
 *      siehe 'a0' in 'main'.
 * 
 * (B)  ctor mit 'int'-Argument, siehe 'a1' in 'main'.
 * 
 * (C)  ctor mit 'address'-Argument, siehe 'a2' in 'main'. Dies ist der
 *      sogenannte Kopierkonstruktor (copy-ctor), er initialisiert die
 *      Instant anhand des Arguments, d.h. häufig kopiert er den Inhalt.
 * 
 * (D)  Eine globale Variable, man beachte den Zeitpunkt der Aufrufe
 *      ctor und dtor.
 *
 * (E)  Das sieht aus wie eine Zuweisung, tatsächlich ist es aber der
 *      copy-ctor.
 * 
 * (F)  In diesem Fall wie (E), der copy-ctor.
 * 
 * (G)  dtor der globalen Variablen.
 * 
 */
 
