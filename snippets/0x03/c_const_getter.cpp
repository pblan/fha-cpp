// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

class address {
    int m_id; 
    
public:
    address(int id) : m_id{id} { }
    
    int& id() {                                             // (A)
        cout << "-a|      id() &, id=" << m_id << endl;
        return m_id; 
    }    

    int id() const {                                        // (B)
        cout << "-b|      id() const, id=" << m_id << endl;
        return m_id; 
    }    
};

void print_address(const address& a)                        // (C)
{
    int id = a.id();
    cout << "-c|    a.id=" << id << endl;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    
    int id;
    address a(1);

    id = a.id();
    cout << "01|    a.id=" << id << endl;

    a.id() = 2;
    id = a.id();
    cout << "02|    a.id=" << id << endl;

    cout << "-----" << endl;

    address& ra = a;       
    id = ra.id();                                           // (D)
    cout << "03|    ra.id=" << id << endl;
    
    const address& cra = a;       
    id = cra.id();                                          // (E)
    cout << "04|    cra.id=" << id << endl;

    cout << "-----" << endl;

    print_address(a);
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Hier wird die Referenz auf die Membervariable 'id' zurück
 *      gegeben. Das hat viele Vor- aber auch Nachteile. In diesem 
 *      Beispiel führt es aber dazu, dass so der Wert gesetzt werden
 *      kann - es ist also ein 'setter'.
 *      Allerdings ist es eher unüblich, weil man direkten Zugriff auf
 *      die Interna des Objekts gewährt, was man in der Regel vermeiden
 *      sollte.
 * 
 * (B)  Hier steht 'const' hinter den Argumenten. Das bedeutet, diese
 *      Funktion verändert das Objekt nicht und kann aufgerufen werden,
 *      wenn es sich um ein konstantes Objekt handelt, siehe (C).
 * 
 * (C)  In 'print_address' ist das Argument eine konstante Referenz.
 *      Das bedeutet nicht, dass das aufrufende Objekt konstant sein muss,
 *      siehe main, sondern, dass innerhalb der Funktion (!) das Objekt
 *      konstant bleibt, also nicht verändert wird. 
 *      Um das zu garantieren, können nur Memberfunktionen aufgerufen
 *      werden, die das Objekt auch in jedem Fall konstant lassen - das
 *      sind gerade die Memberfunktionen, die mit 'const' gekennzeichnet
 *      sind. Ein 'setter' wie aus (A) kann hier nicht aufgerufen werden!
 * 
 * (D)  Hier ist es eine nicht-konstante Referenz, der 'setter' ist also
 *      verwendbar.
 * 
 * (E)  Hier ist es eine konstante Referenz, d.h. es wird die 'const'-
 *      Memberfunktion verwendet.
 * 
 */
 
