// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

#pragma GCC diagnostic ignored "-Wuninitialized"            // (A)

int main()
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    int v1;                                                 // (B)
    int v2=23;                                              // (C)
    int v3{42};                                             // (D)
 // int v2a=123456789012345;
 // int v3a{123456789012345};
    int v4{};                                               // (E)

    cout << "01|    v1=" << v1 << endl;
    cout << "02|    v2=" << v2 << endl;
    cout << "03|    v3=" << v3 << endl;
    cout << "04|    v4=" << v4 << endl;

    cout << "-----" << endl;

    unsigned int i{1};                                      // (F)
    signed int j{-1};
    cout << "05|    i=" << i << endl;
    cout << "06|    j=" << j << endl;

    cout << "-----" << endl;
 
	long l{123456789012345};                                // (G)
    cout << "07|    l=" << l << endl;

    cout << "-----" << endl;
	
 	char c{'A'};                                            // (H)
    cout << "08|    c='" << c << "'" << endl;

    cout << "-----" << endl;

	bool b{true};                                           // (I)
    cout << "09|    b=" << b << endl;

    cout << "-----" << endl;

	float f{1.2f};                                          // (J)
	double d{2.4};
    cout << "10|    f=" << f << endl;
    cout << "11|    d=" << d << endl;

    cout << "-----" << endl;
    
    size_t z;
    z = sizeof(int);                                        // (K)
    cout << "12|    z=" << z 
        << ", sizeof(int)=" << sizeof(int) 
        << ", sizeof(i)=" << sizeof(i) << endl;
	
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Comp.anweisung: Ignoriere hier die Warnung fuer 
 *      uninitialisierte Variablen.
 * 
 * (B)  Variable v1 nicht initialisiert. Was enthaelt i? Hier wird 
 *      die Warnung generiert.
 * 
 * (C)  Variable v2 mit 23 initialisiert. Alter bzw. klassischer Stil.
 * 
 * (D)  Variable v3 mit 42 initialisiert. Wie v2, nur neuer Stil (C++11,
 *      vereinheitlichte Initialisierung).
 *      Es ist nicht ganz gleich. Falls der Datentyp unter Genauigkeitsverlust
 *      umgewandelt wird (narrowing conversion) ergibt v2a eine Warnung,
 *      und v3a einen Fehler.
 *
 * (E)  Variable v4 mit Defaultwert (0) initialisiert.
 * 
 * (F)  Integer ohne (i) und mit (j) Vorzeichen.
 * 
 * (G)  Eine ganze Zahl höherer Genauigkeit.
 * 
 * (H)  Ein einzelnes (ASCII-)Zeichen.
 * 
 * (I)  Boolsche Werte true oder false.
 * 
 * (J)  Flieskommazahlen einfacher, doppelter und 
 *      doppelt doppelter Genauigkeit.
 * 
 * (K)  Ein Datentyp, der Größen und Indizes aufnehmen kann (implement.spezifisch).
 * 
 */
 
