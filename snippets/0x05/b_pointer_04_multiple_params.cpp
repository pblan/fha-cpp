// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

bool divmod(int n, int p, int* pdiv, int* pmod);            // (A)

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    int n{17},p{5},d,m;                                     // (B)
    bool ok = divmod(n,p,&d,&m);                            // (C)
    cout << "01|    div ok? " << ok << endl;
    cout << "02|    " << n << "/" << p << "=" 
        << d << "*" << p << "+" << m << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

bool divmod(int n, int p, int* pdiv, int* pmod) {
    if (p!=0) {
        *pdiv = n/p;                                        // (D)
        *pmod = n%p;
        return true;
    } else {
        *pdiv = *pmod = 0;
        return false;
    }
}

/* Kommentierung
 * 
 * (A)  'divmod' soll die ganzzahlige Division und den Rest 'zurückgeben'
 *      und auch, ob die Division grundsätzlich geklappt hat (nicht 
 *      durch 0 geteilt). Das sind drei Informationen, wovon wir  
 *      nur eine über die Rückgabe und zwei mittels Zeigern zurück geben.
 *      'pdiv' und 'pmod' sollen auf die Variablen zeigen, die das
 *      Ergebnis nach der Funktion enthalten sollen.
 * 
 * (B)  'n' wird durch 'p' geteilt, 'd' und 'm' sollen das Ergebnis der
 *      Division bzw. den Rest enthalten.
 * 
 * (C)  Wir rufen 'divmod' mit den Adressen von'd' und 'm' auf, so dass 
 *      die Funktion über die Dereferenzierung * das Ergebnis in 'd' und
 *      'm' schreiben kann.
 * 
 * (D)  Wenn wir nicht durch 0 teilen, dann wird hier der Wert gesetzt,
 *      sonst wird 0 in '*pdiv' und 'pmod' geschrieben.
 * 
 */
 
