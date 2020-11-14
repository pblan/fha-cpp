// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::string;

int main()
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

	string s1;                                              // (A)
    cout << "01|    s1='" << s1 << "'" << endl;

	string s2{"Hallo"};                                     // (B)
    cout << "02|    s2='" << s2 << "'" << endl;

	string s3{"Kurs"};
    cout << "03|    s3='" << s3 << "'" << endl;

    cout << "-----" << endl;

    cout << "04|    s2+' '+s3='" << s2+" "+s3               // (C)
        << "'" << endl;

    cout << "05|    s3.size()=" << s3.size()                // (D)
        << ", s3.empty()=" << s3.empty() 
        << ", s3.substr(1,2)='" << s3.substr(1,2) << "'" << endl;
 
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Initialisierung eines leeren Strings.
 *
 * (B)  Initialisierung eines Strings mit Inhalt "Hallo".
 * 
 * (C)  String-Objekte können mit dem +-Operator verwendet werden.
 * 
 * (D)  Für String-Objekte können ganz 'klassich' Memberfunktionen
 *      aufgerufen werden. Weitere Funktionen der string-Klasse in
 *      den Onlinereferenzen.
 *  
 */

