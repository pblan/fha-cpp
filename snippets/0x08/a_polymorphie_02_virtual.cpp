// author: a.voss@fh-aachen.de

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class object
{
public:
    virtual string to_string() const {                      // (A)
        return "object::to_string"; 
    }
};

class address : public object
{
public:
    string to_string() const override {                              // (B)
        return "address::to_string"; 
    }
};

void print_object(const object& o) {                        // (C)
    cout << "02|    " << o.to_string() << endl; 
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    address a;

    cout << "01|    " << a.to_string() << endl;
    print_object(a);

    cout << "-----" << endl;

    cout << "03|    sizeof a=" << sizeof(a) << endl;        // (D)
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Hier wurde das Schlüsselwort 'virtual' hinzugefügt, vgl. a_object,
 *      sonst nichts.
 * 
 * (B)  Die Klasse erbt wie in a_object, aber to_string ist einmal als
 *      virtual gekennzeichnet und daher bleibt sie virtual und das
 *      Schlüsselwort muss nicht wiederholt werden.
 * 
 * (C)  Wie zuvor ist der Parameter vom Basistyp, aber dadurch dass die
 *      Funktion virtual ist, wird zur _Laufzeit_ entschieden, von welchem
 *      Typ das object wirklich ist und dann die entsprechende Funktion
 *      der richtigen Klasse, hier address, aufgerufen.
 * 
 * (D)  Der Preis für das erwartete Verhalten von virtuellen Funktionen
 *      liegt in einer internen Zeigervariablen auf eine sogenannte
 *      Funktionentabelle - je Klasse mit den virtuellen Funktionen. So wird
 *      der Aufruf zur Laufzeit aufgelöst und kostet Speicher im object,
 *      size=8, und in der Laufzeit.
 * 
 */
 
