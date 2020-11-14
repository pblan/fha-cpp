// author: a.voss@fh-aachen.de

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::find;
using std::ostream;
using std::out_of_range;

ostream &operator<<(ostream &os, const vector<int> &v);     // (A)

int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    // Elemente einfügen und ändern
    // ============================

    vector<int> v;                                          // (B)

    cout << "01|    v.size=" << v.size() << endl;
    v.push_back(23);                                        // (C), (D)
    v.push_back(42);
    cout << "02|    v.size=" << v.size() << ", v[0]=" << v[0] << ", v[1]=" << v[1] << endl;

    v[0] = 666;                                             // (E)
    v.at(1) = 1234;
    cout << "03|    v.size=" << v.size() << ", v[0]=" << v[0] << ", v[1]=" << v[1] << endl;

    try {                                                   // (F)
        cout << "04|    v[10]=" << v[10] << endl;
        cout << "05|    v.at(10)=" << v.at(10) << endl;
    } catch (out_of_range &e) {
        cout << endl << "06|    error e=" << e.what() << endl;
    }

    auto v_front = v.front();                               // (G)
    auto v_end = v.back();
    cout << "07|    v_front=" << v_front << ", v_end=" << v_end << endl;

    v.pop_back();                                           // (H)
    cout << "08|    v.size=" << v.size() << ", v[0]=" << v[0] << endl;

    v.clear();                                              // (I)
    cout << "09|    v.size=" << v.size() << endl;

    cout << "-----" << endl;

    // for-each = range-based-for
    // ==========================

    vector<int> w{2, 3, 5};                                 // (J)

    cout << "10|    w=[";
    for (size_t i = 0; i < w.size(); ++i)
        cout << " " << w[i];
    cout << " ], size=" << w.size() << endl;

    cout << "11|    w=[";
    for (auto x : w)                                        // (K)
        cout << " " << x;
    cout << " ], size=" << w.size() << endl;

    cout << "12|    w=" << w << ", size=" << w.size() << endl;

    cout << "-----" << endl;

    // Iteratoren
    // ==========

    cout << "13|    w=[";
    for (auto it = w.begin(); it != w.end(); ++it)          // (L)
        cout << " " << *it;
    cout << " ], size=" << w.size() << endl;

    auto it5 = find(w.begin(), w.end(), 5);                 // (M)
    if (it5 != w.end())                                     // (N)
        w.insert(it5, 23);                                  // (O)
    cout << "14|    w=" << w << ", size=" << w.size() << endl;

    auto it3 = find(w.begin(), w.end(), 3);
    if (it3 != w.end())
        w.erase(it3);                                       // (P)
    cout << "15|    w=" << w << ", size=" << w.size() << endl;

    for (auto it = w.begin(); it != w.end();) {             // (Q)
        if (*it % 2 == 1) {
            it = w.erase(it);
        } else {
            ++it;
        }
    }
    cout << "16|    w=" << w << ", size=" << w.size() << endl;

    cout << "-----" << endl;

    // Größenänderungen
    // ================

    cout << "17|    w.size=" << w.size() << ", w.capacity=" << w.capacity() << endl;
    w.resize(4);                                            // (R)
    cout << "18|    w.size=" << w.size() << ", w.capacity=" << w.capacity() << endl;
    w.reserve(8);                                           // (R)
    cout << "19|    w.size=" << w.size() << ", w.capacity=" << w.capacity() << endl;
    while (w.size() < w.capacity())
        w.push_back(0);
    cout << "20|    w.size=" << w.size() << ", w.capacity=" << w.capacity() << endl;
    w.push_back(0);                                         // (S)
    cout << "21|    w.size=" << w.size() << ", w.capacity=" << w.capacity() << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

ostream &operator<<(ostream &os, const vector<int> &v) {
    os << "[";
    for (auto x : v)
        os << " " << x;
    os << " ]";
    return os;
}

/* Kommentierung
 *
 * (A)  Wird benötigt, um den Vektor auszugeben; ist hinter main definiert.

 * (B)  vector ist ein generischer Datentyp. In den < > steht der Datentyp
 *      des Vektors, hier int. Ein Vektor ist, kurz gesagt, eine array,
 *      welches aber dynamisch, also zur Laufzeit, wachsen und schrumpfen
 *      kann und wo einzelne Elemente ersetzt werden können.
 *      Gibt man in der Definition eine Liste von Elementen an, so ist der
 *      vector damit gefüllt, sonst leer.
 * 
 * (C)  push_back fügt ein Element am Ende hinzu (statt add oder Ähnliches).
 *
 * (D)  size fragt die aktuelle Anzahl enthaltener Elemente ab.
 * 
 * (E)  Auf einzelne Element kann mit einem Index zugegriffen werden, 
 *      sowohl lesend als auch schreibend.
 *
 * (F)  Der Unterschied im Zugriff über [] oder at() ist der, dass bei at eine
 *      Überprüfung des Index passiert und ggf. eine Exception geworfen wird
 *      (out_of_range).
 * 
 * (G)  Erstes und letztes Element.
 * 
 * (H)  Nimmt das letztes Element weg, aber ohne es zurückzugeben (dafür gibt
 *      es Gründe, Stichwort: exception safe).
 *
 * (I)  Löscht den Inhalt und der Vektor ist danach leer.
 *
 * (J)  Neuer Vektor mit einer Liste von Elementen, die er zu Beginn enthält.
 *
 * (K)  range-based-for, wird noch besprochen, ist im Kern eine for-each-Schleife.
 *
 * (L)  Das Konzept des Iterators ist, kurz gesagt, eine Variable eines
 *      Iterator-Typs, hier "it", die z.B. vom Beginn des Vektors bis zum Ende (exkl.)
 *      läuft und über die dann auf die Elemente via *it zugegriffen werden kann
 *      (Dereferenzierung).
 *      Das ermöglicht for-each-Schleifen, bzw. ranged-based-for, auch für Datentypen,
 *      wo nicht klar ist, wie man über alle Elemente läuft, etwa ein Baum.
 *
 * (M)  So ein Iterator ist eine Art Position in einen Datencontainer. Er eignet sich
 *      daher auch, um Positionen zum Einfügen und Löschen anzuzeigen.
 *
 * (N)  Die Ende-Position end() ist ein gültiger Iterator, aber über ihn darf nicht
 *      dereferenziert (*it) werden. Es ist vergleichbar zum Index=size, der auf das
 *      erste Element hinter dem letzten Element in einem Vektor zeigt (gültig ist
 *      ja 0..size-1). Folglich kann man end() gut nutzen, um anzuzeigen, dass man
 *      am Ende angekommen ist bzw. beim Suchen (find) nichts gefunden hat.
 *
 * (O)  An einer Position, gegeben durch den Iterator, einfügen. btw: man kann mit
 *      dem Iterator auch rechnen, also it+2 würde bedeutet, 2 hinter der Position it.
 *
 * (P)  An einer Position, gegeben durch den Iterator, löschen.
 *
 * (Q)  Vorsicht, wenn man mit einem Iterator über einen Container läuft und diesen
 *      dabei ändert. Hier gibt erase einen gültigen Iterator zurück, der entweder
 *      auf das nächste Element zeigt, oder sonst end() enthält.
 *
 * (R)  resize ändert die Anzahl der Elemente und füllt den Vektor entsprechend mit
 *      Default-Elementen auf oder löscht sie. capacity ändert den für den Vektor
 *      intern reservierten Speicher an möglichen Elementen. Das zu ändern kann z.B.
 *      Sinn machen, wenn man im Vorfeld schon weiß, dass 1000 Elemente in den Vektor
 *      sollen und man das dynamische Umkopieren beim Vergrößern vermeiden möchte.
 *
 * (S)  Zuvor ist der Vektor komplett voll und durch das Hinzufügen wird der interne
 *      Platz vergrößert. Häufig führt das zum Umkopieren der Elemente in den neuen
 *      größeren Puffer.
 *
 *  !!! Generell sind viele hier beschriebenen Prinzipien für alle Container der STL
 *      = Standard-Template-Library gültig.
 */

