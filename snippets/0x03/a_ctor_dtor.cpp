// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::string;

class address {                                             // (A)
public:                                                     // (B)
    int n;
    string s;

    address() : n{}, s{"-"} {                               // (C)
        cout << "-a|      ctor()" << endl;
        // n=0; s="-";
    }

    ~address() {                                            // (D)
        cout << "-b|      dtor()" << endl; 
    }
};                                                          // (E)

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01|    start, vor if" << endl;
    
    {
        cout << "02|    vor a1" << endl;
        address a1;                                         // (F)
        cout << "03|    nach a1, vor a2; n=" << a1.n << ", s=" << a1.s << endl;
        address a2;
        cout << "04|    nach a2" << endl;
        // address a3();
        cout << "05|    nach a3" << endl;
    }                                                       // (G)

    cout << "06|    nach if, ende" << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Definition einer Klasse 'address', vgl. 'struct'.
 * 
 * (B)  Zunächst ist alles 'private', d.h. nur für Memberfunktionen
 *      der Klasse verwendbar. Nutzt man 'public:', so sind ab dieser Stelle
 *      alle dann definierten Teile der Klasse zugreifbar. Solange, bis
 *      wieder 'private:' folgt, oder (später) 'protected:'. 
 * 
 * (C)  Standard-Konstruktor (ctor), ohne Argumente, Verwendung siehe main.
 *      Er wird aufgerufen, nachdem (intern) Speicher für die Instanz angelegt 
 *      wurde und dient der Initialisierung des Objekts.
 *      Die Initialisierungsliste nach dem Doppelpunkt initialisiert die
 *      Attribute. Es wird doppelte Initialisierung vermieden.
 * 
 * (D)  Destruktor (dtor). Er wird aufgerufen, wenn die Instanz den
 *      scope verläßt. Beachte: Es gibt in C++ keine garbage-collection,
 *      sondern der Destruktor wird in jedem Fall sofort aufgerufen. 
 *      Eine der Hauptaufgabe ist das Zurückgeben von Ressourcen des Objekts.
 * 
 * (E)  Beachte das ';' am Ende der Klasse. Fehlt es -> Syntaxfehler.
 * 
 * (F)  Hier wird eine Objektinstanz 'a1' angelegt. Es gibt kein 'new'
 *      oder Ähnliches, dieses Objekt ist ab diesem Punkt angelegt und
 *      initialisiert, da der ctor aufgerufen wurde.
 * 
 * (G)  Hier sind 'a1' und 'a2' nicht mehr gültig und es wurde der
 *      dtor aufgerufen.
 */
 
