// author: a.voss@fh-aachen.de

#include <iostream>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <string>
using std::cout;
using std::endl;
using std::array;
using std::thread;
using std::mutex;
using std::lock_guard;
using std::condition_variable;

#include "ts.h"

void process_sort_data_in_memory(bool only_few_data) {      // (A)
    // [...]
    if (!only_few_data)
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void read_image_in_main() {                                 // (B)
    // [...]
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void process_image(condition_variable & cv, mutex & m);     // (C)

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01| " << ts() << " |    starte thread 'tpaul'" << endl;

    std::condition_variable cv;                             // (D)
    std::mutex m;
    std::thread tpaul(process_image,ref(cv),ref(m));

    bool only_few_data{false};
    process_sort_data_in_memory(only_few_data);
        
    {
    lock_guard<mutex> lk(m);                                // (E)
    
    read_image_in_main();
    cout << "02| " << ts() << " |    image OK, Signal an thread" << endl;
    cv.notify_one();                                        // (F)
    }

    cout << "03| " << ts() << " |    join" << endl;
    tpaul.join();
   
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

void process_image(condition_variable & cv, mutex & m) {
    cout << "-a| " << ts() << " |      thread gestartet, warte auf mutex" << endl;

    std::unique_lock<std::mutex> lk(m);                     // (G)
    cout << "-b| " << ts() << " |      mutex OK, warte auf Signal" << endl;

	cv.wait(lk);						                    // (H)
    cout << "-c| " << ts() << " |      Signal da, proc. image" << endl;
    
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "-d| " << ts() << " |      image OK, thread done" << endl;     
}


/* Kommentierung
 * 
 * (A)  Diese Funktion steht für eine Routine, die keine oder etwas Zeit kostet.
 *      Sie entscheidet darüber, ob das Programm hängt oder nicht.
 * 
 * (B)  Ebenfalls eine dummy-Funktion, die im Prinzip die Daten bereitstellt,
 *      damit Threads darauf parallel arbeiten können.
 * 
 * (C)  Workerfunktion des/der Thread(s).
 * 
 * (D)  Eine condition variable wird verwendet, um auf das Eintreten einer 
 *      Bedingung zu warten.
 * 
 * (E)  Das Mutex wird zunächst reserviert um die globalen Daten zu schützen.
 * 
 * (F)  Dann wird dem Thread signalisiert, dass er nun arbeit kann. Befindet
 *      er sich in einem wait, wacht er nun auf.
 * 
 * (G)  Wir nutzen einen lock, weil die condition variable beim warten einen
 *      lock verwendet, siehe (H).
 * 
 * (H)  Hier wird auf das Signal gewartet. Das Mutex muss hier natuerlich 
 *      freigegeben werden, damit an anderer Stelle auch die condition variable 
 *      signalisiert werden kann. wait gibt es intern frei.
 * 
 *      Warum hängt das Programm bei kürzerer Zeit in (A)?
 */
 
 
