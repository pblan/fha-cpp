#include <condition_variable>
#include <iostream>
#include <thread>

std::mutex signal1;
std::mutex signal2;

void work_1();
void work_2();

// Mutex, lock, unlock, unique_lock
int main() {
  // Starten Sie zwei Threads in main und lassen Sie sie sicher (!) in einen
  // Wartezustand laufen.
  signal1.lock();
  signal2.lock();

  std::thread thread1(work_1);
  std::thread thread2(work_2);

  // Signalisieren Sie aus main heraus dem ersten Thread, dass er weiterlaufen
  // kann und warten auf das Ende der beiden Threads.
  signal1.unlock();

  thread1.join();
  thread2.join();
  // Die beiden Threads haben keine besonderen Aufgaben, es geht hier lediglich
  // um eine wohldefinierte Reihenfolde der Abarbeitung. Verwenden Sie kein
  // sleep, sondern lösen Sie das Problem durch die richtige Verwendung der
  // Befehle.
};

void work_1() {
  std::unique_lock<std::mutex> lock(signal1);

  // Nach Erhalt des Signals im ersten Thread signalisieren dem zwieten Thread,
  // dass er nun weiterlaufen kann.
  signal2.unlock();
};

void work_2() { std::unique_lock<std::mutex> lock(signal2); };