// author: a.voss@fh-aachen.de

#include <iostream>
#include <vector>
#include <set>

using std::cout;
using std::endl;
using std::pair;
using std::vector;
using std::set;
using std::ostream;

ostream &operator<<(ostream &os, const vector<int> &v);     // (A)

int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    vector<int> v{2, 3, 5};
    cout << "01|    v=" << v << endl;

    cout << "-----" << endl;

    cout << "02|    v=[";                                   // (B)
    for (size_t i = 0; i < v.size(); ++i)
        cout << " " << v[i];
    cout << " ]" << endl;

    cout << "03|    v=[";                                   // (C)
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << " " << *it;
    cout << " ]" << endl;

    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        *it += 1;
    cout << "04|    v=" << v << endl;

    for (auto x : v)                                        // (D)
        x -= 1;
    cout << "05|    v=" << v << endl;

    for (auto &x : v)                                       // (E)
        x -= 1;
    cout << "06|    v=" << v << endl;

    cout << "07|    v=[";
    for (const auto &x : v)                                 // (F)
        cout << " " << x;
    cout << " ]" << endl;

    cout << "-----" << endl;

    cout << "08|    v=[ ";                                  // (G)
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        cout << *it << " ";
        // *it += 1;
    }
    cout << "]" << endl;

    const vector<int> &cv{v};
    cout << "09|    cv=[ ";                                 // (H)
    for (auto it = cv.begin(); it != cv.end(); ++it) {
        cout << *it << " ";
        // *it += 1;
    }
    cout << "]" << endl;

    cout << "10|    v=[ ";                                  // (I)
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        cout << *it << " ";
    }
    cout << "]" << endl;

    cout << "11|    v=[ ";                                  // (J)
    auto rit = v.end();
    while (rit != v.begin()) {
        --rit;
        cout << *rit << " ";
    }
    cout << "]" << endl;

    cout << "12|    v=[ ";                                  // (K)
    auto iit = v.begin();
    for (size_t i = 0; i < v.size(); ++i)
        cout << *(iit + i) << " ";
    cout << "]" << endl;

    cout << "-----" << endl;

    set<int> s{1, 2, 3};
    cout << "13|    s={";                                   // (L)
    for (const auto &x : s)
        cout << " " << x;
    cout << " }" << endl;

    // for (auto& x : s)                                    // (M)
    //     x -= 1;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

ostream &operator<<(ostream &os, const vector<int> &v) {
    os << "[";
    for (const auto &x : v)
        os << " " << x;
    os << " ]";
    return os;
}

/* Kommentierung
 *
 * (A)  Einfache Ausgabe eines Vektors, definiert hinter main.
 *
 * (B)  Standardweg über [] und Index.
 *
 * (C)  Dieser Iterator durchläuft den Vektor Element für Element. Es
 *      ist eine Art Position innerhalb des Containers, im einfachen
 *      Fall des Vektors ein Index, aber im Fall eines nicht-trivialen
 *      Containers (map) etwas anders.
 *      Es gibt Iteratoren, mit denen man vorwärts und/oder rückwärts
 *      laufen kann, über andere kann man Elemente verändern (*), aber
 *      es gibt auch welche, die können nicht verwendet werden, um
 *      die Elemente zu ändern (const).
 *      Der Typ des Iterators ist in der Klasse 'vector<int>'
 *      definiert und wird mit '::' verwendet - analog zu std.
 *      Der Iterator 'it' wird mit dem Beginn des Vektors initialisiert
 *      (entspricht dem Index 0) und er kann inkrementiert werden, bis
 *      er end() (entspricht Index size()) erreicht.
 *      Ein Iterator mit dem Wert end() kann nicht dereferenziert werden,
 *      ansonsten ergibt *it das Element des Containers.
 *
 * (D)  Der Compiler wandelt diese Form in ein Iterator-for-Schleife um,
 *      wobei x eine Kopie von *it ist. Das erklärt hier auch, warum
 *      der Vektor v sich nicht ändert.
 *
 * (E)  Wie (D), nur dass x nun eine Referenz auf das Element und damit
 *      änderbar ist.
 *
 * (F)  Wie (E), nur dass x nun eine konstante Referenz auf das Element
 *      und damit nicht änderbar ist. Analog zu call-by-ref.
 *
 * (G)  Hier cbegin() statt begin(). Hier ist nicht der Iterator konstant,
 *      sondern das Element, worauf er zeigt, wird als konstant angenommen
 *      und kann nicht verändert werden.
 *
 * (H)  Wie (G). Da der Container cv konstant ist, ist der Aufruf von
 *      begin() wie cbegin().
 *
 * (I)  Ein Rückwärtsiterator, d.h. er läuft von Hause in die andere
 *      Richtung - allerdings aus seiner Sicht vorwärts (daher ++it).
 *      Siehe auch (J).
 *
 * (J)  Bei Iteratoren, die in beide Richtungen laufen können, kann
 *      man den Iterator auch dekrementieren (--it).
 *
 * (K)  Mit Iteratoren kann man auch rechnen. Welche Operationen
 *      unterstützt werden, hängt am Iteratortyp und letztendlich auch am
 *      Container. Hier können wir nach vorne sehen.
 *
 * (L)  Um die Analogie zu zeigen hier eine Schleife über eine Menge,
 *      die Schleifen über begin() etc. funktionieren hier natürlich
 *      ebenso.
 *
 * (M)  Vorsicht: Im Gegensatz zum Vektor verändert des Ändern der
 *      Elemente einer Menge womöglich die interne Struktur
 *      (z.B. doppelter Wert) und dadurch würde sich
 *      auch die Schleife ändern. Das geht daher hier nicht analog.
 *
 */
