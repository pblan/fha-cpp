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

mutex signal_paul; 
mutex signal_lisa; 

void work_paul() {
    cout << "-a| " << ts() << " |      thread 'paul' gestartet, warte auf mutex" << endl;
    
    std::unique_lock<std::mutex> lk(signal_paul);
    cout << "-b| " << ts() << " |      mutex OK, signal 'lisa'" << endl;
    
    signal_lisa.unlock();
}

void work_lisa() {
    cout << "-c| " << ts() << " |      thread 'lisa' gestartet, warte auf mutex" << endl;
    
    std::unique_lock<std::mutex> lk(signal_lisa);
    cout << "-d| " << ts() << " |      mutex OK" << endl;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01| " << ts() << " |    starte threads 'tpaul', 'lisa'" << endl;
    
    signal_paul.lock();   
    signal_lisa.lock();   
    
    std::thread tpaul(work_paul);
    std::thread tlisa(work_lisa);
    
    cout << "02| " << ts() << " |    signal 'tpaul'" << endl;
    signal_paul.unlock();
    
    tpaul.join();
    tlisa.join();
    
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

