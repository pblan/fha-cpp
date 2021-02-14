// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;


class address {
    static int next_id;                                             // (A)

    int id;
    
public:
    address() : id(next_id++) { 
        cout << "-a|      ctor(), this->id=" << id << endl;
    }
    
    address(const address& a) : id(next_id++) {
        cout << "-b|      ctor(&), this->id=" << id 
             << ", a.id=" << a.id << endl;
    }

    address& operator=(const address& a) {                  // (B)
        cout << "-c|      op=(&), this-id=" << id
             << ", a.id=" << a.id << endl;
        return *this;                                       // (C)
    }
};

int address::next_id{1};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01|    ctors" << endl;
    
    address a1;
    address a2(a1);
    address a3=a2;                                          // (D)

    cout << "-----" << endl;

    cout << "02|    op=" << endl;
    
    a3 = a2;                                                // (E)
    a3.operator=(a2);

    cout << "-----" << endl;

    cout << "03|    op=(op=)" << endl;

    a3 = a2 = a1;                                           // (F)
    a3.operator=(a2.operator=(a1));
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Globaler id-Zähler.
 * 
 * (B)  Operator= (assignment), d.h. kopiere inhaltlich wie bei copy-ctor
 *      vom Argumnt a.
 *      Wichtig: Wird der op= nicht angegeben, so wird der Default-op
 *      genommen, d.h. a=b funktioniert. Problematisch wird es, wenn
 *      dynamische Ressourcen wie Speicher verwendet wird, dann muss man
 *      den op= implementieren.
 * 
 * (C)  Gib Referenz auf this zurück, damit a=b=c funktioniert, siehe (F).
 * 
 * (D)  Das sieht aus wie op=, ist aber ein copy-ctor!
 * 
 * (E)  a=b steht für a.op=(b)
 * 
 * (F)  Ausführung von rechts nach links.
 * 
 */
 
