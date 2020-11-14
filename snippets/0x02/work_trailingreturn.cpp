// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

auto add(int a, int b) -> int { return a+b; }               // (A)
auto sub(int a, int b) { return a-b; }                      // (B)

auto mul(int a, double b) { return a*b; }                   // (C)
auto div(int a, double b) -> decltype(a/b) { return a/b; }  // (D)
//decltype(a/b) div(int a, double b) { return a/b; }        // (E)

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;
    
    cout << "01|    add(2,3)=" << add(2,3) << endl;
    cout << "02|    sub(3,4)=" << sub(3,4) << endl;

    cout << "03|    mul(2,5.1)=" << mul(2,5.1) << endl;
    cout << "04|    div(4,8.0)=" << div(4,8.0) << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Nachfolgender Ergebnistyp int.
 * 
 * (B)  Compiler ermittelt aus return-Typ den Rückgabetyp 
 *      (type deduction).
 * 
 * (C)  Auch hier wird der Typ implizit ermittelt, aber es ist das
 *      Ergebnis einer Operation verschiedener Typen.
 * 
 * (D)  Das ist der Fall (C) explizit. decltype ist ein Operator, der
 *      einen Datentyp ergibt, und zwar den des Ergebnisses a/b.
 * 
 * (E)  Hier ist der Grund, warum dieser 'trailing return type'
 *      notwendig wird: a und b sind in decltype zu Beginn noch nicht 
 *      bekannt - in (D) nach den Parametern schon.
 * 
 *      Noch mehr Anwendungen bei Templates!
 */
