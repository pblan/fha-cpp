// author: a.voss@fh-aachen.de

#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>
#include <iomanip>
using std::cout;
using std::endl;
using std::array;
using std::thread;

#include "ts.h"

void workp(int id, int& sum) {
    std::this_thread::sleep_for(std::chrono::milliseconds(id*500));
    // [...]
    sum = id*100;
    cout << "-a| " << ts() << " |      id=" << id << ", done" << endl;
}

void workl(int id, int* psum) {
    std::this_thread::sleep_for(std::chrono::milliseconds(id*500));
    // [...]
    *psum = id*100;
    cout << "-b| " << ts() << " |      id=" << id << ", done" << endl;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01| " << ts() << " |    starte threads" << endl;
    int sump{0}, suml{0};
    thread tpaul(workp,1,std::ref(sump));                   // (A)
    thread tlisa(workl,2,&suml);                            // (B)

    cout << "-----" << endl;

    cout << "02| " << ts() << " |    join, warte auf 'Paul'" << endl;
    tpaul.join();
    
    cout << "03| " << ts() << " |    join, warte auf 'Lisa'" << endl;
    tlisa.join();
    
    cout << "04| " << ts() << " |    threads fertig"
         << ", sump=" << sump << ", suml=" << suml << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Hier werden zwei Threads gestartet, aber es sollen Werte aus dem
 *      Thread zurückgegeben werden. Daher gibt es einen call-by-Ref. Aufruf.
 *      Der Unterschied ist hier, dass die Verwendung der Referenz explizit
 *      angegeben werden muss: ref().
 * 
 * (B)  Inhaltlich gleich, es kann natürlich auch ein Zeiger verwendet werden.
 * 
 * Wo können hier Probleme auftauchen?
 * 
 */
