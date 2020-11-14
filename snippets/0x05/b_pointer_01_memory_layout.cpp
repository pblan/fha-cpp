// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    int n{15}; 
    int m{31}; 
    cout << "01|    n=" << n << ", &n=" << &n << endl;      // (A)
    cout << "02|    m=" << m << ", &m=" << &m << endl;      // (B)

    cout << "-----" << endl;

    int* p{nullptr};                                        // (C)
    cout << "03|    p=" << p << " " << endl;
    p = &n;                                                 // (D)
    cout << "04|    n=" << n << ", m=" << m
         << ", *p=" << *p << ", p=" << p << endl;           // (E)
    p = &m;                                                 // (F)
    cout << "05|    n=" << n << ", m=" << m
         << ", *p=" << *p << ", p=" << p << endl;           // (G)
    *p = 3;                                                 // (H)
    cout << "06|    n=" << n << ", m=" << m
         << ", *p=" << *p << ", p=" << p << endl;

    double d{4.2};                                          // (I)
    float f{8.1f};
    bool b{true};
    cout << "07|    d=" << d << ", &d=" << &d << endl;
    cout << "08|    f=" << f << ", &f=" << &f << endl;
    cout << "09|    b=" << b << ", &b=" << &b << endl;

    cout << "-----" << endl;

    int* pn = &n;                                           // (J)
    int* pm = &m;
    double* pd = &d;
    cout << "10|    pn=" << pn << "=&n, &pn=" << &pn << endl;
    cout << "11|    pm=" << pm << "=&m, &pm=" << &pm << endl;
    cout << "12|    pd=" << pd << "=&d, &pd=" << &pd << endl;

    cout << "-----" << endl;

    int** ppn = &pn;                                        // (K)
    cout << "13|    ppn=" << ppn << "=&pn, &ppn=" << &ppn << endl;

    cout << "14|    n=" << **ppn << endl;                   // (L)
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 *
 * (A)  'n' ist eine lokale Variable auf dem Stack. '&n' bezeichnet die
 *      Adresse im Speicher, häufig hexadezimal angegeben.
 *
 * (B)  'm' ist eine weitere lokale Variable auf dem Stack. In der Regel
 *      liegt 'm' direkt an 'n', d.h. 4 Bytes entfernt, da 'n' als int
 *      4 Bytes gross ist.
 *      Man beachte, dass sich die Adressen je Ausführung des Programms ändern!
 *
 * (C)  'p' ist ein Zeiger auf int (int*), der mit 'nullptr', eine 0
 *      für Zeiger, initialisiert wird.
 *
 * (D)  Hier wird der Wert von 'p' gesetzt und zwar auf die Adresse von 'n'.
 *
 * (E)  Der Dereferenzierungsoperator '*' liest jetzt aus der Adresse, auf
 *      die der Zeiger zeigt (hier 'n') den Wert, d.h. er liest faktisch 'n'.
 *
 * (F)  Man kann Zeiger mit einem anderen Wert belegen, d.h. 'woanders hin
 *      zeigen lassen', z.B. auf 'm'. Das geht mit Referenzen so nicht.
 *
 * (G)  Liest man jetzt 'aus dem Zeiger', so wird der Wert von 'm' gelesen.
 *
 * (H)  Im Beispiel zeigt 'p' wieder auf 'm'. Wir können auch über den
 *      Zeiger den Wert verändern, d.h. faktisch 'm' verändern.
 *
 * (I)  Die Variablen 'd','f' und 'b' liegen auch auf dem Stack, aber
 *      'b' liegt z.B. vor 'n', 'f' vor 'd' und genau nach 'm'.
 * 
 * (J)  Angenommen, wir wollen, dass eine Variable die Adresse von 'n'
 *      enthält. Welchen Typ hat sie dann? Das ist ein Zeiger auf int, oder
 *      kurz 'int*'.
 *      Diese Variable 'pn' ist ein Zeiger auf int (Datentyp 'int*') und
 *      enthält als Wert (so wie n=15) die Adresse von 'n', d.h. '&n'.
 *      Analog ist 'pm' ebenfalls ein Zeiger auf int (int*) aber als Wert
 *      die Adresse von 'm', d.h. '&m'.
 *      Es ist natürlich auch möglich, Zeiger auf andere Typen zu haben, z.B. 
 *      ist 'pd' ein Zeiger auf eine double-Variable, nämlich 'd'. Der
 *      Wert von 'pd' ist folglich die Adresse von 'd', d.h. '&d'.
 * 
 *      Man beachte, dass 'pn', 'pm' und 'pd' selbst wieder Variablen sind
 *      und auf dem Stack die Werte stehen. Ein Zeiger belegt selbst 8 Byte
 *      und daher liegen 'pm' und 'pd' 8 Byte auseinander.
 *
 * (K)  Im Prinzip kann man das jetzt so weiter fortführen. Ein Zeiger auf
 *      'pn' wäre vom Typ 'Zeiger auf Zeiger auf int', also 'int**' und wird
 *      mit der Adresse von 'pn', also '&pn' initialisiert.
 *
 * (L)  Mehrfachdereferenzierung.
 */
