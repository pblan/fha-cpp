// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

class address {
    int id;                                                 // (A)

public:
    address(int nid) : id{nid} {                            // (B)
        cout << "-a|      ctor(int), id=" << id << endl;
    }

    ~address() { 
        cout << "-b|      dtor(), id=" << id << endl; 
    }

    int get_id() {                                          // (C)
        return id; 
    }        

    void set_id(const int id) {                             // (D)
        this->id = id;
    }        
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    
    address a1(1);                                          // (E)
    address a2{2};

    cout << "01|    a1.id=" << a1.get_id() << endl;         // (F)
    cout << "02|    a2.id=" << a2.get_id() << endl;

    cout << "-----" << endl;

    a1.set_id(11);                                          // (G)
    cout << "03|    a1.id=" << a1.get_id() << endl;
    cout << "04|    a2.id=" << a2.get_id() << endl;

    cout << "-----" << endl;

    cout << "05|    sizeof address=" 
         << sizeof(address) << endl;                        // (H)
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  'id' ist eine private Membervariable.
 * 
 * (B)  Das ist nicht der Standard-ctor, da ein Argument erwartet wird.
 *      Die Initialisierung der Membervariablen kann in einer Aufzählung
 *      nach dem ':' erfolgen. 
 *      Bei Membervariablen, die selber Objekte sind, kann so der richtige
 *      ctor ausgewählt werden. Initialisiert man solche Membervariablen
 *      erst im Code, so würden sie zweimal initialisiert, was überflüssig
 *      ist.
 * 
 * (C)  Ein 'getter', der die Variable 'id' liest und den Wert zurück gibt.
 *      Hier ist klar, dass mit 'id' die Membervariable gemeint ist.
 * 
 * (D)  Ein 'setter', der den neuen Wert übergeben bekommt. Man beachte,
 *      dass 'this->' hier notwendig ist, da der Parametername gleich 
 *      dem Namen der Membervariablen ist, und man nur so auf die 
 *      Membervariable zugreifen kann. Das 'this->' gilt natürlich nicht 
 *      nur im 'setter', sondern generell. 
 * 
 * (E)  Anlegen der Objektinstanzen 'a1' und 'a2' mit Argumenten. Beachte,
 *      dass die Argumente in () stehen. 
 *
 *      !!! Allerdings ist der Aufruf eines ctors ohne Argumente in der Art
 *      'address a1();' also mit leeren () falsch !!!

 * (F)  Aufruf des 'getters'.
 * 
 * (G)  Aufruf des 'setters'.
 * 
 * (H)  Die Größe der Instanz ist hier gleich der Summe der Größen der
 *      Membervariablen.
 * 
 */
 
