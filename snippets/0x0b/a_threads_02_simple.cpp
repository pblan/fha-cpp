// author: a.voss@fh-aachen.de

#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>
#include <iomanip>
using std::cout;
using std::endl;
using std::thread;
 
#include "ts.h"                                             // (A)

void work(int sleep);                                       // (B)

int main()
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "time   0--+--+--+--+--|--+--+--+--+--1--+--" << endl
         << "Main   ...P.JP............" << endl
         << "Paul      ---------------!" << endl 
         << endl << endl;

    cout << "01| " << ts() << " |    schlafe 100ms und wache wieder auf" << endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // (C)

    cout << "02| " << ts() << " |    starte worker thread 'Paul' (P)" << endl;

    thread tpaul(work,500);                                 // (D)

    cout << "03| " << ts() << " |    es laufen jetzt 'Main' und 'Paul'" << endl;
    cout << "04| " << ts() << " |      'Main'-id: 0x"       // (E)
         << std::hex << std::this_thread::get_id() << std::dec << endl;
    cout << "05| " << ts() << " |      'Paul'-id: 0x" 
         << std::hex << tpaul.get_id() << std::dec << endl;
  
    cout << "06| " << ts() << " |    'Main' wartet auf 'Paul' (join, JP)" << endl;

    tpaul.join();                                           // (F)

    cout << "07| " << ts() << " |    worker threads fertig" << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

void work(int sleep) {
    cout << "-a| " << ts() << " |      thread gestartet, arbeitet für " 
         << sleep << "ms" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep));  // (G)
    cout << "-b| " << ts() << " |      thread fertig" << endl;
}

/* Kommentierung
 * 
 * (A)  Die Funktion ts() gibt einen Zeitstempel und den aktuellen Thread
 *      (mit Namen statt id) aus. Diese Funktion wird hier eingebunden.
 * 
 * (B)  Jeder Thread hat eine Aufgabe, die er parallel abarbeiten soll.
 *      Dazu bekommt jeder Thread eine Funktion übergeben, die parallel
 *      aufgerufen wird. Hier ist das die Funktion 'work'. Ist diese 
 *      Funktion beendet, so endet der Thread. 
 * 
 * (C)  Main thread schläft für 100ms.
 * 
 * (D)  Man beachte: dieser Thread ist der zweite Thread, da ja schon
 *      der main-Thread läuft und in diesem 'main' ausgeführt wird. 
 *      Im zweiten Thread wird die genannte 'work' Funktion mit den 
 *      Parametern aufgerufen, hier '500'. 
 *      Diese Funktion steht stellvertretend für Arbeiten, die parallel
 *      ausgeführt werden (Daten laden etc.). Im Beispiel schläft sie
 *      für n=500 ms.
 * 
 * (E)  get_id() gibt eine eindeutige id zurück. Anhand dieser id kann
 *      man Threads unterscheiden. Vorsicht: ist ein Thread beendet, so
 *      ist es möglich, dass diese id nochmal vom System verwendet wird.
 * 
 * (F)  Wir warten explizit auf das Ende des Threads tpaul. 'main'
 *      schläft solange, bis das eintritt. Wird der Thread nicht beendet,
 *      so hängt das Programm an dieser Stelle. Umgekehrt, vergisst man
 *      den join, so läuft am Ende der Funktion 'main' noch der Thread
 *      und das gibt auch einen Fehler.
 * 
 * (G)  sleep_for gibt im aktuellen Thread die Kontrolle ans System und 
 *      läuft nach der angegebenen Zeit weiter (stellvertretend für z.B.
 *      das Laden von Daten). Beachte: in dieser Zeit wird auch keine
 *      CPU Last erzeugt, da der Thread wirklich schläft. Das wäre bei 
 *      einer Schleife derart: 
 *          while (solange-Zeit-nicht-um);
 *      anders (busy-loop). Das ist in jedem Fall zu vermeiden!
 * 
 */
