// author: a.voss@fh-aachen.de

#include <iostream>
#include <utility>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::pair;
using std::make_pair;
using std::tuple;
using std::make_tuple;
using std::get;

int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    // pair
    // ====

    pair<int, double> p1{1, 1.1};                           // (A)
    cout << "01|    p1=(" << p1.first << "," << p1.second << ")" << endl;

    auto p2 = make_pair(2, 2.2);                            // (B)
    cout << "02|    p2=(" << p2.first << "," << p2.second << ")" << endl;

    auto p3 = make_pair<int, double>(3, 3.3);               // (C)
    cout << "03|    p3=(" << p3.first << "," << p3.second << ")" << endl;

    auto p4 = pair{4, 4.4};                                 // (D)
    cout << "04|    p4=(" << p4.first << "," << p4.second << ")" << endl;

    cout << "-----" << endl;

    // tuple
    // =====

    tuple<int, double, char> t1 = tuple{1, 1.1, 'A'};       // (E)
    cout << "05|    t1=(" << get<0>(t1) << "," << get<1>(t1)
         << "," << get<2>(t1) << ")" << endl;

    auto t2 = make_tuple(2, 2.2, 'B');                      // (F)
    cout << "06|    t2=(" << get<0>(t2) << "," << get<1>(t2)
         << "," << get<2>(t2) << ")" << endl;

    auto t3 = make_tuple<int, double, char>(3, 3.3, 'C');   // (G)
    cout << "07|    t3=(" << get<0>(t3) << "," << get<1>(t3)
         << "," << get<2>(t3) << ")" << endl;

    auto t4 = tuple{4, 4.4, 'D'};                           // (H)
    cout << "08|    t4=(" << get<0>(t4) << "," << get<1>(t4)
         << "," << get<2>(t4) << ")" << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 *
 * siehe auch https://en.cppreference.com/w/cpp/utility
 *
 * (A)  pair ist ein generischer Datentyp - ein Template. In den < > stehen
 *      gewöhnlich die Typangaben. Bei pair sind es der Datentyp des ersten
 *      Elements und der Datentyp des zweiten Elements, die wiederum über
 *      first und second zu lesen und zu schreiben sind.
 * 
 * (B)  make_pair ist ein sog. Object Generator idiom, d.h. eine Art Standard
 *      Objekte zu generieren (make_xxx). Hier kann der Compiler die Typangaben
 *      für das Template pair selbst herausfinden und in Verbindung mit auto
 *      wird so die Deklaration recht kurz.
 * 
 * (C)  Wie (B), man kann aber die Typen auch explizit nennen.
 *
 * (D)  Ab C++17 geht das auch direkt mit der Template-Klasse und dem ctor.
 *
 * (E)  Tuple ist ein generalisiertes pair mit beliebig vielen Parametern,
 *      also auch 4 oder 5.
 *      Hier liegt die Schwierigkeit darin, dass so keine Namen für die Member
 *      definiert sind (kein first oder second), sondern der Zugriff über
 *      die Funktion get mit dem Index als Template-Parameter (lesend und
 *      schreibend, also get<0>(t1)=xx ).
 *
 * (F),(G),(H) wie (B),(C),(D).
 *
 */

