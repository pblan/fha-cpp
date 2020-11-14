// author: a.voss@fh-aachen.de

#include <iostream>                                         // (A)
#include <cassert>

using std::cout;                                            // (B)
using std::endl;
using std::cin;
using std::string;
//using namespace std;                                      // (B)

int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl    // (C)
         << endl;

    int i{23};                                              // (D)

    cout << "01|    i=" << i << endl;                       // (E)
    cout << "02|    2*i+3=" << 2 * i + 3 << " " << endl;        // (F)

    cout << "-----" << endl;                                // (G)

    int n;

    cout << "03|    Eingabe n: ";
    cin >> n;                                               // (H)

    cout << "04|    n=" << n << endl;

    assert(n > 0);

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;                                               // (I)
}

/* Kommentierung
 * 
 * (A)  Importiere Definitionen aus der Datei 'iostream' und 'cassert'. 
 *      Erstere enthält u.a. Definitionen der Objekte 'cout', 'cin', 
 *      'endl'. Diese sind im namespace (Namensraum) 'std' definiert.
 * 
 * (B)  Wenn man über 'cout' (character out) etwas auf die Konsole
 *      ausgeben möchte, müsste man 'cout' eigentlich komplett angeben,
 *      d.h. 'std::cout', da es im Namensraum 'std' definiert ist.
 *      Verwendet man 'using' entweder für alle oder explizit je Object,
 *      so kann 'std::' weggelassen werden.
 * 
 * (C)  Zu Beginn der Ausgabe und am Ende wird das Programm ausgegeben,
 *      welches gerade läuft. Der Name der cpp-Datei steht in der 
 *      Konstante '__FILE__'.
 *      Hier sieht man auch ganz schön, wie Daten nacheinander über 
 *      die Operation '<<' in den Stream 'cout' 'geschoben' werden.
 * 
 * (D)  Deklaration und Definition einer Variable Namens 'i', 
 *      initialisiert mit 23 - klassischer Stil vor C++11.
 * 
 * (E)  Jede Ausgabe wird mit einer Nummer eingeleitet, so dass man die
 *      jeweilige Ausgabe der Code-Zeile zuordnen kann.
 * 
 * (F)  Es kann nicht nur Text, sondern auch jeder gültige Ausdruck
 *      ausgegeben werden, hier das Ergebnis der Berechnung.
 * 
 * (G)  '-----' trennt logische Blöcke in der Ausgabe, damit man etwas
 *      Orientierung hat.
 * 
 * (H)  Analog zu 'cout' können über 'cin' Daten eingelesen werden. Dabei
 *      werden Daten über die Operation '>>' in 'cin' geschoben.
 *      Bei Zahlen bis zum ersten Zeichen, das nicht mehr in das Format
 *      passt, also z.B. ein Buchstabe.
 *      Das ist keine schöne und stabile Eingabe. Es dient hier lediglich
 *      dazu, Werte zur Laufzeit angeben zu können.
 * 
 * (I)  'assert' garantiert, dass der Ausdruck zur Laufzeit gültig ist, 
 *      ansonsten wird das Programm abgebrochen. Man kennt das Kommando
 *      vom Testen.
 *      
 * (J)  Der Rückgabewert von 'main' sagt aus, ob das Programm mit einem
 *      Fehler (!=0) oder keinem Fehler (0) beendet wurde. Das ist wichtig, 
 *      wenn mehrere Befehle in der Konsole bei Erfolg nacheinander ausgeführt 
 *      werden sollen. Besser wäre eigentlich die Konstante 'EXIT_SUCCESS'.
 * 
 */

