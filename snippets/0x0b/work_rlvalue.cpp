// author: a.voss@fh-aachen.de

#include <iostream>
using namespace std;

int m = 42;                                                 // (A)
int & set_m() { return m; }	                                // (B)
string get_name() { return "Smith"; }                       // (C)

                                                            // (D)
void f(const string& s)  { cout << "-1|      f(&), s: " << s << endl; }
void f(const string&& s) { cout << "-2|      f(&&), s: " << s << endl; }

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    int n{};                                                // (E)
    set_m() = 23;                                           // (F)
    
    string s;
    s = get_name();                                         // (G)
    
    f(s);			                                        // (H)
    f(get_name());                                          // (I)
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  glob. variable besitzt eine Adresse.
 * 
 * (B)  lvalue, ist ein Alias fuer m, besitzt eine Adresse.
 * 
 * (C)  temp. Objekt
 * 
 * 	wird zurueckgegeben, also kein lvalue.
 * 
 * (D)  *	Zwei Varianten einer Funktion
 * 
 * 	Eine fuer lvalues (&), eine fuer rvalues (&&).
 * 	Gibt es die rvalue-Variante nicht, wird immer die lvalue-Variante
 * 	verwendet.
 *
 * 
 * (E)   lvalue, der nicht direkt eine Variable ist
 * 
 * // get_name liefert einen rvalue
 * 
 * lvalue-Variante
 * rvalue-Variante
 * 
 */
 
/*	rvalues, lvalues
 * 	Es gibt lvalues und rvalues (locator value).
 * 	Ein lvalue ist etwas, was eine Adresse hat, dem man etwas
 * 	zuweisen kann.
 * 	Ein rvalue ist etwas, was kein lvalue ist. Z.B. ein temp. Objekt.
 * 
 * 	Es gibt noch mehr, etwa xvalues, siehe
 *	http://en.cppreference.com/w/cpp/language/value_category
 */

