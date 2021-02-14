// author: a.voss@fh-aachen.de

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class object
{
public:
    object() {
        cout << "-1|      ctor object()" << endl;
    }

    ~object() { 
        cout << "-2|      dtor object()" << endl; 
    }

    string to_string() const { 
        return "object::to_string"; 
    }
};

class address : public object                               // (A)
{
public:
    address() {
        cout << "-3|      ctor address()" << endl;
    }

    ~address() { 
        cout << "-4|      dtor address()" << endl; 
    }
    
    string to_string() const {                              // (B)
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

    cout << "01|    " << a.to_string() << endl;             // (D)
    print_object(a);                                        // (E)

    cout << "-----" << endl;

    cout << "03|    sizeof a=" << sizeof(a) << endl;        // (F)
   
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  "single inheritance": einfache Vererbung, address erbt von object,
 *      d.h. jede address-Instanz ist auch ein object.
 *      Man beachte, dass analog zu Membervariablen beim Erzeugen
 *      zuerst die Basisklassen aufgerufen werden und entsprechend beim
 *      Freigeben rückwärts die Destruktoren.
 * 
 * (B)  Vergleichbar eine toString()-Methode in Java, wird hier eine
 *      Funktion 'überschrieben' - oder zumindest soll es so aussehen.
 * 
 * (C)  Der Parameter ist hier vom Basistyp object&, aber aufgerufen wird
 *      die Funktion später mit einer address-Instanz. Die Frage lautet:
 *      Welche Funktion wird aufgerufen? Wie wäre das Verhalten in Java?
 * 
 * (D)  Aufruf von to_string auf einem Objekt vom Typ address, d.h. hier wird
 *      in jedem Fall die aus der Klasse address aufgerufen.
 * 
 * (E)  Aufruf ebenfalls mit einem Objekt vom Typ address, was passiert?
 *      Vgl. b_object_virtual.
 * 
 * (F)  Man beachte, die Klassen enthalten keine Daten, aber da ein Objekt
 *      immer eine Mind.größe von 1 besitzt, ist es hier auch 1 groß.
 * 
 */
 
