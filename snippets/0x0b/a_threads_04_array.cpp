// author: a.voss@fh-aachen.de

#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <array>
using std::cout;
using std::endl;
using std::array;
using std::thread;

#include "ts.h"

void work(int sleep);

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "time   0--+--+--+--+--|--+--+--+--+--1--+--" << endl
         << "Main   P..L..H..R.JP..JL....JH....JR....." << endl
         << "Paul   ---------------!" << endl 
         << "Lisa      -----------------!" << endl
         << "Hans         ---------------------!" << endl 
         << "Rosi                --------------------!" << endl << endl;

    cout << "01| " << ts() << " |    starte worker threads im Abstand von jeweils 100ms" << endl;

    array<thread,4> threads;                                // (A)
    for (size_t i=0; i<threads.size(); ++i) {
        threads[i] = thread(work,i*100+500);                // (B)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    cout << "02| " << ts() << " |    warte auf threads (join)" << endl;
    for (auto & t : threads)
        t.join();                                           // (C)

    cout << "03| " << ts() << " |    worker threads fertig" << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

void work(int sleep) {
    cout << "-a| " << ts() << " |      thread gestartet, arbeitet für " 
         << sleep << "ms" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
    cout << "-b| " << ts() << " |      thread fertig" << endl;
}


/* Kommentierung
 * 
 * (A)  Ein Feld von Threads. Da keine worker-Funktion angegeben ist,
 *      läuft hier auch kein Thread. Die Threads werden erst danach
 *      erzeugt und gestartet, siehe (B).
 * 
 * (B)  Hier wird ein Thread gestartet und zugewiesen, so dass wir
 *      später mit join warten können, siehe (C).
 * 
 * (C)  Der Reihe nach auf die Threads warten. Man beachte das & in for.
 * 
 */
