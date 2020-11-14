// author: a.voss@fh-aachen.de

#include <iostream>
using namespace std;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

	string s{"Beispiel"};                                   // (A)

    cout << "01|    s='" << s << "'" << endl;               // (B)

    cout << "-----" << endl;

    cout << "02|    s+s='" << s+s << "' (op+)" << endl;     // (C)
    cout << "03|    s[1]='" << s[1] << "' (op[])" << endl;  // (D)
    s += "!";                                               // (E)
    cout << "04|    s='" << s << "' (op+=)" << endl;

    cout << "-----" << endl;

    cout << "05|    s.size()=" << s.size() << endl;         // (F)
    cout << "06|    s.empty()=" << s.empty() << endl;       // (G)
    cout << "07|    s.at(1)='" << s.at(1) << "'" << endl;   // (H)
    cout << "08|    s.substr(1,3)='"                        // (I)
         << s.substr(1,3) << "'" << endl;

    cout << "-----" << endl;

    string::size_type pos;                                  // (J)
    bool found;
    
    found = ((pos=s.find("spiel"))!=string::npos);          // (K), (L)
    cout << "09|    find(\"spiel\") ok? " << found 
         << ", pos=" << pos << endl;
    found = ((pos=s.find("Reis"))!=string::npos);
    cout << "10|    find(\"Reis\") ok? " << found << endl;

    found = ((pos=s.rfind("i"))!=string::npos);             // (M)
    cout << "11|    rfind(\"i\") ok? " << found 
         << ", pos=" << pos << endl;

    cout << "-----" << endl;

    string rep1{"Bei"};
    pos=s.find(rep1);
    s.replace(pos,rep1.size(),"Fussball");                  // (N)
    cout << "12|    s.replace(...), s='" << s << "'" << endl;

    string rep2{"!"};
    pos=s.find(rep2);
    s.erase(pos,rep2.size());                               // (O)
    cout << "13|    s.erase(...), s='" << s << "'" << endl;

    s.insert(0,"XXL-");                                     // (P)
    cout << "14|    insert(0,\"XXL-\"), s='" << s << "'" << endl;

    s.append("e");                                          // (Q)
    cout << "15|    append(\"e\"), s='" << s << "'" << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Definition eines 'string'.
 * 
 * (B)  Die Ausgabe auf cout.
 * 
 * (C)  Strings können 'addiert' werden, d.h. über '+' werden sie 
 *      aneinander gehängt.
 * 
 * (D)  Über '[pos]' können einzelne Zeichen gelesen werden, ohne Test
 *      der Grenzen.
 * 
 * (E)  Der Operator '+=' hängt Zeichen oder Texte an.
 * 
 * (F)  'size' gibt die Länge des Strings zurück, 0 ist möglich.
 * 
 * (G)  'empty' testet, ob der String leer ist (Größe 0).
 * 
 * (H)  'at' liest Zeichen an einer Position, aber mit Test der Grenzen.
 * 
 * (I)  'substr' liest einen Teilstring ab einer Position für eine
 *      gegebene Länge.
 * 
 * (J)  'size_type' ist der Datentyp, der eine Position im String aufnehmen
 *      kann.
 * 
 * (K)  'find' sucht ein Muster und gibt die Position zurück.
 * 
 * (L)  Die Konstante 'npos' wird zurück gegeben, wenn keine Muster
 *      gefunden wurde.
 * 
 * (M)  'rfind' sucht vom Ende.
 * 
 * (N)  'replace' ersetzt im String ab einer Position für eine
 *      gegebene Länge den dortigen Text mit einem neuen.
 * 
 * (O)  'erase' löscht im String ab einer Position für eine
 *      gegebene Länge.
 * 
 * (P)  'insert' fügt an einer Position neuen Text ein.
 * 
 * (Q)  'append' hängt Text an.
 * 
 */
 
