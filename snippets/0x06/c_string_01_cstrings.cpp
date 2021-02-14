// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    const char* s = "Text";                                 // (A)
    cout << "01|    s='" << s << "'" << endl;

    cout << "02|    s={";
    for (const char* p=s; (*p); ++p) {                      // (B)
        cout << " '" << *p << "'";
    }
    cout << " }" << endl;

    cout << "-----" << endl;

    cout << "03|    p+i:" << endl;
    for (const char* p=s; (*p); ++p) {                      // (C)
        cout << "04|      p=" << (void*)p << ", p='" << p << "'" << endl;
    }
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Dies ist ein C-String, ein alter in C verwendeter Text, der
 *      immer mit einem '\0' (0-Byte) endet.
 *      Vom Typ her ist es ein char* auf einen konstanten Text.
 * 
 * (B)  Dieser Zeiger kann wie ein Feld durchlaufen werden. Die
 *      Schleife endet, wenn das Zeichen 0 ist.
 * 
 * (C)  Ausgabe ab i'tem Zeichen. Man beachte, dass 'cout' anstelle
 *      der Adresse, wie sonst bei Zeigern, den Text ausgibt. Das hängt
 *      mit der besonderen Rolle der char* zusammen.
 *      Möchte man die Adresse haben, so kann man den Zeiger in einen
 *      untypisierten Zeiger (void*) wandeln.
 * 
 */
 
