// author: a.voss@fh-aachen.de

#include <iostream>
using namespace std;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    int n{4};
	switch(n)                                               // (A)
	{
	case 3:                                                 // (B)
        cout << "01|    case 3" << endl;
        break;                                              // (C)
	case 4:
        cout << "02|    case 4" << endl;
		break;
    default:                                                // (D)
        cout << "03|    default" << endl;
	}

    cout << "-----" << endl;

    char c{'A'};                                            // (E)
	switch(c)
	{
	case 'A':                                               // (F)
        cout << "04|    case 'A'" << endl;
	case 'B':
        cout << "05|    case 'B'" << endl;
		break;
    default:
        cout << "05|    default" << endl;
	}
       
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Der 'switch'-Befehl funktioniert für ganzzahlige Argumente.
 * 
 * (B)  Die einzelnen Fälle, hier 3 und 4. 
 * 
 * (C)  Der Befehl 'break' springt ans Ende des 'switch'-Blocks, er
 *      ist aber optional, siehe auch (F).
 * 
 * (D)  Für den Fall, dass kein Fall zutrifft, gibt es den optionalen
 *      'default'-Block.
 * 
 * (E)  Der Typ 'char' ist natürlich auch zulässig, da er ganzzahlig ist.
 * 
 * (F)  Hier gibt es einen 'fall through', d.h. es wurde bewusst auf das
 *      'break' verzichtet, so dass c=='A' auch den Code von 'B' durchläuft.
 *      Manchmal ist ein fehlendes 'break' ein Feature, häufig ein Fehler.
 * 
 */
 
