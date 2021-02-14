// author: a.voss@fh-aachen.de

#include <iostream>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <string>
#include <functional>
using std::cout;
using std::endl;
using std::array;
using std::thread;
using std::mutex;
using std::lock_guard;
using std::function;

#include "ts.h"

mutex mutex_sum;                                            // (A)

                                                            // (B)
void work1(unsigned int id, long long inc, long long n, long long& sum);
void work2(unsigned int id, long long inc, long long n, long long& sum);
void work3(unsigned int id, long long inc, long long n, long long& sum);

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    const long long n = 100000;                             // (C)
    const int variante = 2;                                 // (D)
    function<void(unsigned int,long long,long long,long long&)> work[] 
        = {work1,work2,work3};                              // (E)
    
    cout << "01| " << ts() << " |    variante=" << variante << ", n=" << n << endl; 

    cout << "-----" << endl;

    cout << "02| " << ts() << " |    starte threads" << endl;

    long long sum{0};
    thread t1(work[variante],1,+1,n,std::ref(sum));         // (F)
    thread t2(work[variante],2,-1,n,std::ref(sum)); 

    cout << "03| " << ts() << " |    join, warte auf threads" << endl;
    t1.join();
    t2.join();

    cout << "-----" << endl;

    cout << "04| " << ts() << " |    fertig, sum=" 
         << sum << endl;                                    // (G)
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

void work1(unsigned int id, long long inc, long long n, long long& sum) {
    cout << "-a| " << ts() << " |      starte thread, id=" << id << endl;
    for (long long i=0; i<n; ++i) {
        sum += inc; // sum = sum + inc                      // (H)
    }  
    cout << "-b| " << ts() << " |      thread fertig, id=" << id << endl;
}

void work2(unsigned int id, long long inc, long long n, long long& sum) {
    cout << "-c| " << ts() << " |      starte thread, id=" << id << endl;
    for (long long i=0; i<n; ++i) {
        mutex_sum.lock();				                    // (I)
        sum += inc;      
        mutex_sum.unlock();
    }  
    cout << "-d| " << ts() << " |      thread fertig, id=" << id << endl;
}

void work3(unsigned int id, long long inc, long long n, long long& sum) {
    cout << "-e| " << ts() << " |      starte thread, id=" << id << endl;
    for (long long i=0; i<n; ++i) {
        lock_guard<mutex> lk(mutex_sum);                    // (J)
        sum += inc; 
    }  
    cout << "-f| " << ts() << " |      thread fertig, id=" << id << endl;
}


/* Kommentierung
 * 
 * (A)  Das mutex wird in (I) erklärt.
 * 
 * (B)  Es wird auf drei verschiedene Arten parallel summiert. Das sind 
 *      die entsprechenden Worker-Funktionen.
 * 
 * (C)  Wir summieren im ersten Thread n mal (+1) und um zweiten Thread 
 *      n mal (-1).
 * 
 * (D)  Es wird nur eine Variante der drei betrachtet.
 * 
 * (E)  Um eine der Worker-Funktionen zu wählen sammeln wir sie in einem
 *      Feld von Funktionen. Alternativ kann man Funktionszeiger verwenden:
 *          typedef void (*worker_t)(unsigned int id, long long inc, long long n, long long& sum) ;
 *          worker_t work[] = {work1,work2,work3};                  
 * 
 * (F)  Start der beiden Threads mit einer id (alternativ zum Namen).
 * 
 * (G)  Die Summe sollte 0 sein, da n*(+1)+n*(-1)=0.
 * 
 * (H)  Erste Variante:
 *      Diese Funktion wird von zwei Threads gleichzeitig verwendet,
 *      d.h. gleichzeitig wird sum erhoeht. 
 * 	    Der Ausdruck x = x+d ist nicht sicher, da zwischen dem Auslesen von x
 * 	    auf der rechten Seite und dem Update von x, also der Zuweisung auf
 * 	    der linken Seite, ein anderer Thread x veraendern kann. Diese Aenderung
 * 	    geht beim Update von x dann verloren.
 * 	    Deswegen ist die Summe hier am Ende nicht wieder 0, wenn die Anzahl
 * 	    Wiederholungen nur hoch genug ist (n).
 * 
 * (I)  Zweite Variante:
 * 	    Das mutex mit lock() verhindert, dass zwei Threads gleichzeitig diesen Codebereich
 * 	    betreten. Dadurch wird das Update von sum nicht von einem anderen Thread
 * 	    unterbrochen und die Summe stimmt hinterher. Das mutex sperrt den Bereich
 *      solange, bis unlock() aufgerufen wird. Andere Threads warten im
 *      lock() solange, bis freigegeben wurde.
 *      
 *      Warum ist die Loesung nicht gut?
 *      Falls z.B. exceptions zwischen lock und unlock auftreten, so wird 
 *      die Funktion verlassen, aber das Lock nicht aufgehoben... wartende
 *      Threads warten ewig.
 * 
 * (J)  Dritte Variante:
 *      Bettet man das lock und unlock in ein Objekt ein, welches am Ende
 * 	    seiner Lebenszeit das mutex wieder freigibt, dann wird im Falle
 * 	    einer exception das Objekt aufgeraeumt und so das mutex immer 
 * 	    freigegeben. Das Prinzip nennt sich RAII (Resource Acquisition Is 
 *  	Initialization) - etwas sperrig...
 *  	Und die Objekte heissen locks, genauer hier lock_guard.
 * 
 */
 
