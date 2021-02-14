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

void process_sort_data_in_memory(bool only_few_data) {
    // [...]
    if (!only_few_data)
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void read_image_in_main() { 
    // [...]
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void process_image(condition_variable & cv, mutex & m, bool & workdone); 

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01| " << ts() << " |    starte thread 'tpaul'" << endl;

    std::condition_variable cv;
    std::mutex m;
    bool workdone = false;                                  // (A)
    
    std::thread tpaul(process_image,ref(cv),ref(m),std::ref(workdone));

    bool only_few_data{true};
    process_sort_data_in_memory(only_few_data);
        
    {
    lock_guard<mutex> lk(m); 
    
    read_image_in_main();
    cout << "02| " << ts() << " |    image OK, Signal an thread" << endl;
    
    workdone = true;                                        // (B)
    cv.notify_one();
    }

    cout << "03| " << ts() << " |    join" << endl;
    tpaul.join();
   
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

void process_image(condition_variable & cv, mutex & m, bool & workdone) {
    cout << "-a| " << ts() << " |      thread gestartet, warte auf mutex" << endl;

    std::unique_lock<std::mutex> lk(m);
    cout << "-b| " << ts() << " |      mutex OK, warte auf Signal" << endl;

    while(!workdone)                                        // (C)
	    cv.wait(lk);
    cout << "-c| " << ts() << " |      Signal da, proc. image" << endl;
    
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "-d| " << ts() << " |      image OK, thread done" << endl;     
}


/* Kommentierung
 * 
 * (A)  Wird verwendet, um den dead lock zu vermeiden.
 * 
 * (B)  Wenn das Flag wahr ist, und sich der Thread noch nicht im wait
 *      befindet, wird das wait auch niemals aufgerufen, siehe (C).
 * 
 * (C)  Nur starten, wenn das signal noch nicht gesendet.
 *      Anmerkung: die Schleife ist deshalb notwendig, da das wait
 *      auch "irrtümlich" mal verlassen werden kann und dann sofort
 *      wieder ins wait soll.
 * 
 */
 
 
