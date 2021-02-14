// author: a.voss@fh-aachen.de

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;

struct name {                                               // (A)
    string vorname;
    string nachname;
    
    name(const string& vorname, const string& nachname) 
        : vorname(vorname), nachname(nachname) {}
};

ostream& operator<<(ostream& os, const name& n) {
    os << "('" << n.vorname << "','" << n.nachname << "')";
    return os;
}

istream& operator>>(istream& is, name& n) {                 // (B)
    is >> n.vorname;
    is >> n.nachname;
    return is;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    
    int id{0};
    name n("Max","Mustermann");

    cout << "01|    n=" << n << ", id=" << id << endl;

    cout << "-----" << endl;

    cout << "02|    Eingabe (Vorname,Nachname,id): "; 
    cin >> n >> id;                                         // (C)
    cout << "03|    n=" << n << ", id=" << id << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Eine Datenstruktur, die man aber ausgeben und einlesen kann.
 * 
 * (B)  Das ist der Eingabe-Operator. Er ist vergleichbar dem Ausgabe-
 *      Operator, nur dass es ein istream ist, aus dem gelesen wird.
 * 
 * (C)  Analog zur Ausgabe kann man die Eingabe auch hintereinander hängen.
 *      Schön wird es dadurch auf der Konsole aber nicht. Bei Dateioperationen
 *      kann das aber Sinn machen.
 * 
 */
 
