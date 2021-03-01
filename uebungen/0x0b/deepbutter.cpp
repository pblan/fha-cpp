#include <iostream>
#include <thread>
#include <condition_variable>

std::mutex signal_1;
std::mutex signal_2;

void work_1();
void work_2();

// Mutex, lock, unlock, unique_lock
int main()
{
    // Starten Sie zwei Threads in main und lassen Sie sie sicher (!) in einen Wartezustand laufen.
    signal_1.lock();
    signal_2.lock();

    std::thread t1(work_1);
    std::thread t2(work_2);

    // Signalisieren Sie aus main heraus dem ersten Thread, dass er weiterlaufen kann und warten auf das Ende der beiden Threads.
    signal_1.unlock();

    t1.join();
    t2.join();
    // Die beiden Threads haben keine besonderen Aufgaben, es geht hier lediglich um eine wohldefinierte Reihenfolde der Abarbeitung.
    // Verwenden Sie kein sleep, sondern lösen Sie das Problem durch die richtige Verwendung der Befehle.
};

void work_1()
{
    std::unique_lock<std::mutex> lk(signal_1);

    // Nach Erhalt des Signals im ersten Thread signalisieren dem zwieten Thread, dass er nun weiterlaufen kann.
    signal_2.unlock();
};

void work_2()
{
    std::unique_lock<std::mutex> lk(signal_2);
};