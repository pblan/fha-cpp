// author: a.voss@fh-aachen.de

#include <iostream>
using namespace std;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    int i;
    
    cout << "01|    for:" << endl;
	for (i=-10; i<=20; ++i)
    {
        if (i<5)
            continue;                                       // (A)
        cout << "02|      i=" << i << endl;
        if (i>=10)
            break;                                          // (B)
    }

    cout << "-----" << endl;

    cout << "03|    goto:" << endl;

    i=5;
label:                                                      // (C)
    cout << "04|      i=" << i << endl;
	if ( i++<10)
		goto label;                                         // (D)
       
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  'continue' führt zum nächsten Schleifendurchgang, nicht nur 'for'.
 * 
 * (B)  'break' beendet die aktuelle Schleife, nicht nur 'for'.
 * 
 * (C)  Hier wird eine Sprungmarke namens 'label' definiert. Hierhin kann
 *      mit 'goto' gesprungen werden, siehe (D).
 * 
 * (D)  Springe zur Marke. Wo liegt das Problem in diesem Konstrukt und
 *      warum wird es nicht verwendet?
 * 
 */
 
