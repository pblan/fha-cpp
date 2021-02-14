// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"

class report 
{
    virtual void create_report() = 0;                       // (A)
};

class customer : public report                              // (B)
{
public:
    void create_report() { 
        cout << "-a|      create_report()" << endl; 
    }
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    // report r;                                            // (C)
    customer c;
    
    cout << "01|    c:" << endl;
    c.create_report();
    
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  "=0" heisst 'pure virtual', d.h. diese Funktion ist virtuell
 *      und wenn man ein Objekt einer Klasse instanziieren möchte, müssen
 *      alle virtuellen Funktionen definiert sein.
 *      Diese Syntax legt im Prinzip ein Interface fest, welches zu 
 *      implementieren ist. In C++ gibt es aber kein Interface, sondern
 *      dadurch dass man von vielen Klassen erben kann, kann man auch 
 *      beliebig viele Interfaces implementieren.
 *      Eine Klasse mit mind. einer rein virtuellen Methode heisst auch
 *      'abstrakte Klasse'.
 * 
 * (B)  Die Klasse customer implementiert jetzt das Interface, heisst, 
 *      definiert die entsprechende Funktion und dann kann es auch Objekte 
 *      davon geben.
 * 
 * (C)  Von report könnte man jetzt kein Objekt anlegen, ohne in der Klasse
 *      create_report zu definieren.
 * 
 */
 
