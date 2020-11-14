// author: a.voss@fh-aachen.de

#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::array;
using std::vector;
using std::deque;
using std::list;
using std::set;
using std::unordered_set;
using std::map;
using std::unordered_map;

int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    // array
    // =====

    array<int, 3> a{2, 3, 5};                               // (A)
    cout << "01|    a=[";
    for (auto x : a)                                        // (B)
        cout << " " << x;
    cout << " ], size=" << a.size() << endl;

    cout << "-----" << endl;

    // vector, deque, list
    // ===================

    vector<int> v{1, 2, 3};                                 // (C)
    v.push_back(4);
    cout << "02|    v=[";
    for (auto x : v)
        cout << " " << x;
    cout << " ], size=" << v.size() << endl;

    deque<int> d{1, 2, 3};                                  // (D)
    d.push_front(0);
    d.push_back(4);
    cout << "03|    d=[";
    for (auto x : d)
        cout << " " << x;
    cout << " ], size=" << d.size() << endl;

    list<int> l{6, 7, 8};                                   // (E)
    l.push_front(5);
    l.push_back(9);
    cout << "04|    l=[";
    for (auto x : l)
        cout << " " << x;
    cout << " ], size=" << l.size() << endl;

    cout << "-----" << endl;

    // set, unordered_set
    // ==================

    set<char> s1{'A', 'B', 'A', 'B'};                       // (F)
    cout << "05|    s1={";
    for (auto x : s1)
        cout << " " << x;
    cout << " }, size=" << s1.size() << endl;

    set<int> s2{3, 2, 1};                                   // (G)
    s2.insert(2);
    s2.insert(4);
    s2.insert(0);
    cout << "06|    s2={";
    for (auto x : s2)
        cout << " " << x;
    cout << " }, size=" << s2.size() << endl;

    if (s2.find(2) != s2.end())                             // (H)
        cout << "07|    Element 2: existiert" << endl;

    unordered_set<int> s3{3, 2, 1};                         // (I)
    s3.insert(2);
    s3.insert(4);
    s3.insert(0);
    cout << "08|    s3={";
    for (auto x : s3)
        cout << " " << x;
    cout << " }, size=" << s3.size() << endl;

    cout << "-----" << endl;

    // map, unordered_map
    // ==================

    map<int, string> m1{{1, "Eins"},
                        {2, "Zwei"}};                        // (J)
    m1[3] = "Drei";
    cout << "09|    m1={";
    for (auto x : m1)
        cout << " (" << x.first << "," << x.second << ")";
    cout << " }, size=" << m1.size() << endl;

    cout << "10|    m1[3]='" << m1[3] << "'" << endl;
    cout << "11|    m1[4]='" << m1[4] << "'" << endl;

    auto it3 = m1.find(3);                                  // (K)
    if (it3 != m1.end())
        cout << "12|    Element 3: (" << (*it3).first << "," << (*it3).second << ")" << endl;

    // unordered_map
    // =============

    unordered_map<int, string> m2{{1, "Eins"},
                                  {2, "Zwei"}};              // (L)
    cout << "13|    m2={";
    for (auto x : m2)
        cout << " (" << x.first << "," << x.second << ")";
    cout << " }, size=" << m2.size() << endl;

    //for (auto it = m2.begin(); it!=m2.end(); ++it) {
    //    cout << it->second << endl;
    //}

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 *
 * siehe auch https://en.cppreference.com/w/cpp/container
 *
 * (A)  Eine template Klasse 'array' mit Datentyp T und einer Dimension.
 *      Diese Klasse ersetzt das eingebaute Standard-Array.
 *      - Achtung: der zweite Template-Parameter ist eine Zahl!
 *      - Achtung: Diese Dimension muss zur Compile-Zeit feststehen.
 *        Die Dimension darf hier sogar 0 sein.
 *        Weniger Argumente als die Länge in der Deklaration sind zulässig.
 *
 * (B)  Vorteil gegenüber einem raw-C-Array (int n[3]) ist die Möglichkeit
 *      zur Verwendung der üblichen Container-Methoden, als z.B.
 *      [] oder at()-Zugriff, range-based-for, size() etc.
 * 
 * (C)  vector ist ebenfalls ein generischer Datentyp, welcher aber
 *      dynamisch, also zur Laufzeit, wachsen und schrumpfen kann
 *      -> siehe generics_vector-Snippet.
 *      Hier kann man explizit auf einzelne Elemente über den Index
 *      lesend und schreiben zugreifen und Elemente am Ende anhängen.
 *
 * (D)  deque ist eine double-ended-queue, d.h. vergleichbar zu
 *      vector, allerdings kann man Elemente am Anfang und am Ende
 *      anhängen.
 *
 * !!!  Aufwendig ist bei vector und deque immer das Löschen und Einfügen,
 *      da Elemente verschoben werden, wohingegen der direkte Zugriff schnell
 *      ist.
 *      Bei Listen ist das Einfügen und Löschen effizient, aber der direkte
 *      Zugriff auf das n'te Element nicht oder nur ineffizient möglich.
 *      Bei sets und maps hängt der Aufwand für diese Operationen an dem
 *      internen Aufbau, d.h. sortiert oder als Hashmap, dafür ist hier ist
 *      der Container selber aufwändiger und benötigt mehr Speicher.
 *
 * (E)  list ist eine double-linked-list, d.h. hier sind Einfüge und
 *      Löschaktionen vergleichsweise billig, dafür ist aber der direkte
 *      Zugriff auf die Elemente via [] oder at() nicht möglich.
 * 
 * (F)  set ist eine sortierte Menge von einzigartigen Elementen, weswegen
 *      die Größe von s1 auch nur 2 beträgt.
 *
 * (G)  Hier sieht man auch nochmal schön, dass die Reihenfolge sortiert
 *      ist ud dass das Element 2 nur einmal vorkommt, obwohl es zweimal
 *      eingefügt wird.
 *
 * (H)  find ist hier Teil der Klasse, da alle sets und maps über effiziente
 *      Strategien verfügen, um ein Element zu suchen bzw. die Existenz
 *      anzugeben. Wie üblich bezeichnet die Rückgabe end(), dass das
 *      Element nicht gefunden wurde.
 *
 * (I)  Im gegensatz zu set ist unordered_set eine unsortierte Menge.
 *      Die Operationen sind aber identisch.
 *
 * (J)  map ist vergleichbar zu set, nur dass es sich um einen
 *      assoziativer Container handelt, d.h. mit einem Schlüssel
 *      ist ein Wert verknüpft.
 *      Hier ist der Zugriff über [] lesend und schreibend möglich, wobei
 *      man beachten muss, dass beim Lesen eines nicht-existierenden
 *      Element ein Default-Wert zurückgegeben wird (hier der leere
 *      String). Alternativ nutzt man find, siehe (K).
 *
 * (K)  Siehe (H), allerdings erhält man bei Erfolgt einen Iterator auf
 *      das key-value-Pärchen, daher der Zugriff auf first und second.
 *
 * (L)  unordered_map ist eine unsortierte Hashmap, bzw. ein
 *      assoziativer Container. Der Funktionsumfang ist vergleichbar
 *      zu map.
 *
 * !!!  Generell gilt, dass man sich die Klassen im Detail ansehen muss
 *      und je nach Aufgabe entscheiden muss, welcher Container die
 *      Anforderungen an Geschwindigkeit und Speicher am besten erfüllt.
 */

