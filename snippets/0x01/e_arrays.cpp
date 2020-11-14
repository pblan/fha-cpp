// author: a.voss@fh-aachen.de

#include <iostream>
#include <array>
#include <vector>
using std::cout;
using std::endl;
using std::array;
using std::vector;

int main()
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

	const int dim{3};                                       // (A)
	int a[dim] { 2, 3, 5 };                                 // (B)
	
    cout << "01|    dim=" << dim << endl;
    cout << "02|    a[0]=" << a[0]                          // (C)
	     << ", a[1]=" << a[1] 
	     << ", a[2]=" << a[2] 
	     << endl;

    a[0] = 1;                                               // (D)
    a[1] = 1;
    a[2] = a[1]+a[0];
    // a[3] = 1234;
    cout << "03|    a[0]=" << a[0] 
	     << ", a[1]=" << a[1] 
	     << ", a[2]=" << a[2] 
	     << endl;

    array<int,dim> f{5,6,8};                                  // (E)
    f[2] = 7;
    // f[3] = 9;
    cout << "04|    f[0]=" << f[0] 
	     << ", f[1]=" << f[1] 
	     << ", f[2]=" << f[2]
         << ", f[2]=" << f.at(2)
	     << endl;

    vector<int> v{1,2};                                     // (F)
    v.push_back(4);
    v[2] = 3;
    cout << "05|    v[0]=" << v[0] 
	     << ", v[1]=" << v[1] 
	     << ", v[2]=" << v[2]
         << ", v[2]=" << v.at(2)
	     << endl;
    
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Dimension des Feldes ist konstant.
 * 
 * (B)  Datentyp Feld/Array der Laenge dim, initialisiert mit 2,3,5.
 *      Man beachte, dass die Klammern hinter der Variablen stehen und
 *      dass die Dimension ein konstanter Ausdruck sein muss.
 *      Das Feld existiert ab diesem Moment und biete im Prinzip Platz
 *      für dim Elemente.
 * 
 * (C)  Zugriff auf die Elemente des Feldes Index 0..dim-1
 *      Was passiert bei Index<0 oder >=dim?
 * 
 * (D)  Werte können auch neu zugewiesen werden.
 * 
 * (E)  Ein generischer Datentyp für ein Array, so dass die Standard-
 *      funktionen wie size() genutzt werden können. Achtung, das
 *      Feld hat eine feste Länge, das ist der zweite generische Par.
 *      Die Funktion at() nimmt einen Indexcheck vor.
 *      Siehe auch cppreference.
 * 
 * (F)  Ein generischer Datentyp für ein Array, welcher im Gegensatz zu
 *      array<> aber wachsen kann. push_back() fügt Elemente hinten an.
 *      Siehe auch cppreference.
 */

