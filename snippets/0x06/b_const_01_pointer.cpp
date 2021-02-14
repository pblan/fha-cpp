// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

	int i=1;                                                // (A) 
	int* pi = &i;                                           // (B)
	const int ci=2;                                         // (C)
    const int* pci = &ci;                                   // (D)
//  int const * pci = &ci;       

    cout << "01|    i=" << i << ", ci=" << ci << endl;
    cout << "02|    *pi=" << *pi << ", *pci=" << *pci << endl;

    int* const pic = &i;                                    // (E)
	const int* const pcic = &ci;                            // (F)

    cout << "03|    *pic=" << *pic << ", *pcic=" << *pcic << endl;

    i = 1;                                                  // (G)
    *pi = 2;
//  ci = 3;
//  *pci = 4;
    pi = nullptr;
//  ci = 7;
//  *pci = 8;
    pci = nullptr;
    *pic = 9;
//  pic = nullptr;
//  *pcic = 10;
//  pcic = nullptr;

    cout << "-----" << endl;

    const int n{1};
    cout << "04|    n=" << n << endl;

    int* pn = const_cast<int*>(&n);                         // (H)
//  int* pn = (int*)(&n);                                   // (I)

    *pn = 2;                                                // (J)
    cout << "05|    n=" << n << ", *pn=" << *pn << endl;

    int& rn = const_cast<int&>(n);                          // (K)
    rn = 3;

    cout << "06|    n=" << n                                // (L)
         << ", *pn=" << *pn 
         << ", rn=" << rn << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  einfacher int: Wert veränderbar (nicht-const)
 * 
 * (B)  Zeiger auf int: Wert veränderbar, Zeiger veränderbar
 * 
 * (C)  const int: Wert konstant
 * 
 * (D)  Zeiger auf const int: Wert konstant, Zeiger veränderbar 
 *      alternativ 'const' nach int
 * 
 * Zeiger von rechts nach links lesen: '*'='Zeiger', also
 *  int* = 'Zeiger auf int'
 *  const int* = 'Zeiger auf const int' bzw.
 *  int const*
 * 
 * (E)  const Zeiger auf int: Wert veränderbar (nicht-const), Zeiger konstant
 * 
 * (F)  const Zeiger auf const int: Wert konstant, Zeiger konstant
 * 
 * Hier sind die Zeiger selber konstant!
 * 
 * beachte: das 'const' steht rechts vom '*', also gelesen
 *  int* const = 'const Zeiger auf int'
 *  const int* const = 'const Zeiger auf const int'
 * 
 * (G)  jeweils durch gehen und sich fragen:
 *      Was ist konstant, Wert auf den der Zeiger zeigt oder Zeiger?
 * 
 * z.B. *pci = 4;
 *      verboten: pci zeigt auf konstanten Wert
 *      aber: Zuweisung einer Adresse einer nicht-konstanten Variable
 *      ist nicht verboten, nur kann sie nicht über den Zeiger pci
 *      geändert werden.
 * 
 * (H)  const kann "entfern" werden, aber das Ergebnis ist mglw. unerwartet.
 *      Änderungen z.B. über Zeiger.
 * 
 * (I)  (old-C-style)
 * 
 * (J)  Man sieht, dass im Speicher der neue Wert steht, die Ausgabe 
 *      von 'n' aber den alten Wert zeigt...warum?
 * 
 * (K)  Oder Änderung über Referenzen.
 * 
 * (L)  Siehe (J).
 * 
 */
 
