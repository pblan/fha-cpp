// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::ostream;

class address {
    int id_;                                                // (A)
    string name_;
    string number_;
    unsigned int age_;
    
public:    
    address(int id, const string& name, const string& number, unsigned int age) 
        : id_{id}, name_{name}, number_{number}, age_{age} {
    }

    address(const address& a)                               // (B)
        : id_{a.id_}, name_{a.name_}, age_{a.age_} {
        number_ = a.number_;                                // (C)
    }
    
    int id() const { return this->id_; }

    string name() const { return name_; }                   // (D)

    const string& number() const { return number_; }
    string& number() { return number_; }                    // (E)

    unsigned int age() const { return age_; }
    
    ~address() { 
    }

};

void print_address(ostream& os, const address& a) {         // (F)
    os << "a|    a="
            << "{id:" << a.id() << ",name:'" << a.name()
            << ",number:" << a.number() << ",age:" << a.age()
            << "}" 
        << endl;
}

ostream& operator<<(ostream& os, const address& a) {        // (G)
    os << "{id:" << a.id() << ",name:'" << a.name()
        << ",number:" << a.number() << ",age:" << a.age()
        << "}";
    return os;
}

int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    address a(1,"Max Mustermann","0241/12345",46);
         
    print_address(cout,a);
        
    cout << "-----" << endl;

    cout << "A|    a=" << a << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Die Member sind nach verschiedenen, häufig zu findenden 
 *      Namenskonventionen benannt. Hintegrund, sie nicht einfach
 *      'id' oder 'name' zu nennen ist der, dass die 'getter' und 'setter'
 *      häufig nicht 'get_id' heissen, sondern gerne nur 'id'.
 *      - das 'm' wird für 'Member' vorangestellt.
 *      - voran- oder nachgestellter '_'.
 *      - 'm_' ebenfalls für Member.
 * 
 * (B)  copy-ctor.
 * 
 * (C)  Um es gegenüberzustellen: die Member 'mId', '_name' und 'm_age'
 *      sind in der Liste initialisiert. Das bedeutet, 'number_' ist
 *      mit dem Standard-ctor initialisiert worden. 
 *      Dann wird der Wert zugewiesen, was die vorhergegangene Initialisierung
 *      überflüssig macht.
 * 
 * (D)  'getter' 'name' und 'number', einmal Rückgabe als Wert und einmal 
 *      als Referenz, was ist besser?.
 *
 * (E)  'setter'.
 * 
 * (F)  'print_address' bekommt einen 'ostream', also z.B. 'cout' und gibt
 *      Daten des Objekts aus.
 * 
 * (G)  'operator<<' ist eine globale Funktion, die aufgerufen wird, wenn
 *      eine Instanz mit '<<' an einen 'ostream' übergeben wird, siehe
 *      'main'.
 *      Dieser Operator kann für alle unsere eigenen Klassen definiert
 *      werden und dann können wir unsere Objekte genau so in 'cout'
 *      'schieben' wie die anderen Datentypen.
 * 
 */
 
