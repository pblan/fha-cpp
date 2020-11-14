// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

struct fraction {                                           // (A)
	int num;
	int denom;
};

int main()
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

	fraction f{1,2};                                        // (B)
	
	cout << "01|    f.num=" << f.num                        // (C)
         << ", f.denom=" << f.denom << endl;

	f.num = 5;                                              // (D)
	f.denom = 8;
	cout << "02|    f.num=" << f.num 
         << ", f.denum=" << f.denom << endl;
    
    cout << "-----" << endl;

	cout << "03|    f=" 
        <<  (double)f.num/(double)f.denom << endl;                // (E)

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Ein "zusammengesetzter" Datentyp. Woran erinnert Sie das?
 * 
 * (B)  Eine Variable vom Typ 'fraction', initialisiert mit n=1, d=2. Man
 *      beachte, die Variable existiert offensichtlich, also auch ohne
 *      new oder Ähnliches.
 * 
 * (C)  Zugriff auf die Member, die Elemente des Bruchs.
 * 
 * (D)  Analog Ändern der Komponenten n und d von f.
 * 
 * (E)  Ein Wechsel des Datentypes, ein cast.
 */

