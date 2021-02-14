// author: a.voss@fh-aachen.de

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <memory>
using std::cout;
using std::endl;
using std::hex;
using std::string;
using std::runtime_error;
using std::unique_ptr;                                      // (A)
using std::make_unique;                                     // (B)
using std::move;

struct pair {                                               // (C)
    long key;
    long value;

    pair(int k, int v) : key(k), value(v) {
        cout << "-a|      ctor::pair" << endl;
    }
    
    ~pair() { 
        cout << "-b|      dtor::pair" << endl;
    }
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
        
    try {
        pair* p = new pair{1,2};                            // (D)
        cout << "01|    raw: p:" << hex << p << endl;
        
        // comment this in -> memory leak                   // (E)
        throw runtime_error("oops, some error");

        delete p;                                           // (F)
        cout << "02|    raw: nach delete" << endl;
    } catch (...) {
        cout << "03|    raw: in catch" << endl;
    }

    cout << "-----" << endl;

    try {
        unique_ptr<pair> p = make_unique<pair>(1,2);        // (G)
        // unique_ptr<pair> p{new pair{1,2}};
        cout << "04|    smart: p:" << hex << p.get() << endl;

        throw runtime_error("oops, some error");

        // no delete                                        // (H)
        cout << "05|    smart: nach delete" << endl;
    } catch (...) {
        cout << "06|    smart: in catch" << endl;
    }

    cout << "-----" << endl;

    unique_ptr<pair> p1 = make_unique<pair>(3,4);
    unique_ptr<pair> p2;

    cout << "07|    p1:" << p1.get() << ", p2:" << p2.get() << endl;
    // p1 = p2;

    p2 = move(p1);                                          // (I)
    cout << "08|    p1:" << p1.get() << ", p2:" << p2.get() << endl;

    p2.reset();                                             // (J)
    cout << "09|    p1:" << p1.get() << ", p2:" << p2.get() << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  unique_ptr kapselt einen sog. raw-Ptr. und gibt den Speicher 
 *      wieder frei, wenn der Ptr. out-of-scope geht (normal oder auch
 *      bei Exceptions).
 * 
 * (B)  Wir benötigen make_unique, siehe (G).
 * 
 * (C)  Einfach eine nicht-triviale Datenklasse, ctor und dtor nur
 *      zur Verfolgung.
 * 
 * (D)  Ein sog. raw-Ptr., wir sind selber für das Management, d.h.
 *      insbes. das Löschen, verantwortlich.
 * 
 * (E)  Wenn alles planmäßig verläuft, ist der Code so in Ordnung. 
 *      Das Problem taucht auf, wenn wir delete vergessen oder aber
 *      Exceptions fliegen.
 * 
 * (F)  Ganz wichtig, aber... Code wird bei Exception nicht erreicht.
 * 
 * (G)  make_unique ist der korrekte Weg, einen unique_ptr zu erzeugen.
 *      Probleme mit "direktem" new treten dann auf, wenn tmp. Objekte
 *      ins Spiel kommen, z.B. in
 *          f(new A(), new B());
 *      Wenn hier der ctor von B eine Exception wirft und A bereits
 *      erzeugt wurde, dann ist der Speicher verloren.
 * 
 * (H)  delete ist nicht notwendig, da unique_ptr den Speicher freigibt.
 * 
 * (I)  'move' transferiert die Verantwortung von p1 auf p2, p1 ist danach
 *      "leer".
 * 
 * (J)  'reset' gibt den Zeiger frei.
 * 
 * Test für memory leaks:
 * - valgrind installieren (einmalig):
 *      sudo apt install valgrind
 * - Ausführung über valgrind
 *      valgrind out/f_sharedptr.out
 * 
 */
 
