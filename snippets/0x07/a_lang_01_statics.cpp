// author: a.voss@fh-aachen.de

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;

struct address {                                            // (A)

    address() {
        ++m_count;
        cout << "-a|      ctor::address, cnt: " << m_count << endl;
    }

    address(const address&) {
        ++m_count;
        cout << "-b|      ctor::address, cnt: " << m_count << endl;
    }
    
    ~address() { 
        --m_count;
        cout << "-c|      dtor::address, cnt: " << m_count << endl;
    }
    
private:
    static int m_count;                                     // (B)

public:
    static int count() { return m_count; }                  // (C)
};

int address::m_count{0};                                    // (D)

void call_me();

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
        
    cout << "01|    address-count: " 
         << address::count() << endl;                       // (E)
    {
        address a1;
        address a2{a1};
        cout << "02|    address-count: " << address::count() << endl;
        unique_ptr<address> p{make_unique<address>()};
        cout << "03|    address-count: " << address::count() << endl;
    }
    cout << "04|    address-count: " << address::count() << endl;

    cout << "-----" << endl;
    call_me();
    call_me();
    call_me();
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

void call_me() {
    static int calls{0};                                    // (F)
    
    ++calls;
    cout << "-d|      call-me, calls: " << calls << endl;
}

/* Kommentierung
 * 
 * (A)  Eine einfach Klasse bei der wir mitzählen möchten, wie viele
 *      Instanzen es gerade gibt.
 * 
 * (B)  Das ist eine Klassenvariable. Sie existiert pro Klasse einmal
 *      und nicht pro Objektinstanz. Das bewirkt 'static'.
 * 
 * (C)  Diese Variable können wir mit einer Klassenfunktion auslesen,
 *      die keine Objektinstanz benötigt - ebenfalls 'static'.
 * 
 * (D)  Die Klassenvariable kann nicht innerhalb der Klasse initialisiert
 *      werden. Ausserhalb wird der komplette Name benötigt (inkl. Klasse).
 * 
 * (E)  Der Zugriff auf die Klassenelemente geschieht durch Angabe
 *      des kompletten Namens inkl. Klasse.
 *      Anmerkung: Man kann die Elemente auch über eine Instanz adressieren,
 *      aber über die Klasse ist es deutlicher.
 * 
 * (F)  Eine ganz andere Bedeutung: eine statische Variable in einer
 *      Funktion wird nur einmal initialisiert und behält danach ihren
 *      Wert. Man kann so interne Daten speichern, allerdings hat man
 *      von ausserhalb der Funktion keinen Zugriff.
 * 
 */
 
