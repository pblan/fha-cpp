// author: a.voss@fh-aachen.de

#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>
#include <iomanip>
using std::cout;
using std::endl;
using std::thread;

#include "ts.h"

void work(int sleep);

int main()
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    
    cout << "time   0--+--+--+--+--|--+--+--+--+--1--+--" << endl
         << "Main   P..L..H..JP....JHJL..............." << endl
         << "Paul   ---------------!" << endl 
         << "Lisa      ------------------------------!" << endl
         << "Hans         -!" << endl << endl;

    cout << "01| " << ts() << " |    starte worker thread 'Paul' (P), warte 100ms" << endl;

    thread tpaul(work,500);                                 // (A)
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    cout << "02| " << ts() << " |    starte worker thread 'Lisa' (L), warte 100ms" << endl;
    thread tlisa(work,1000);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    cout << "03| " << ts() << " |    starte lambda thread 'Hans' (H), warte 100ms" << endl;
    thread thans([](){                                      // (B)
        cout << "-c| " << ts() << " |      thread gestartet, arbeite für 10ms" << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        cout << "-d| " << ts() << " |      thread fertig" << endl;
    });      
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
 
    cout << "04| " << ts() << " |    warte auf 'Paul' (join,JP)" << endl;
    tpaul.join();

    cout << "05| " << ts() << " |    warte auf 'Hans' (join,JH)" << endl;
    thans.join();                                           // (C)

    cout << "06| " << ts() << " |    warte auf 'Lisa' (join,JL)" << endl;
    tlisa.join();

    cout << "07| " << ts() << " |    worker threads fertig" << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

void work(int sleep) {
    cout << "-a| " << ts() << " |      thread gestartet, arbeitet für " 
         << sleep << "ms" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
    cout << "-b| " << ts() << " |      thread fertig (!)" << endl;
}

/* Kommentierung
 * 
 * (A)  Wir starten den Thread und warten etwas in 'main', so dass der
 *      Thread auch gestartet ist und die Ausgaben nach cout in sinnvoller
 *      Reihenfolge erscheinen. Wartet man nicht, so läuft 'main' weiter
 *      und das Starten des neuen Threads läuft parallel. Dann erhält
 *      man manchmal eine wirre Ausgabe.
 * 
 * (B)  Es ist auch möglich, statt einer Funktion eine lambda-Expr.
 *      anzugeben.
 * 
 * (C)  Achtung, wir warten nach 'Paul' zuerst auf 'Hans' statt auf 'Lisa'
 *      um zu sehen, dass 'Hans' schon lange fertig ist.
 * 
 */
