#include <algorithm>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <thread>
#include <vector>

#define _TASK 1 // 1-3

#if (_TASK < 1 || _TASK > 3)
#error _TASK not valid.
#endif

std::mutex mutex_vector;

std::vector<int> data;

void work_1();
void work_2();
void work_3();

std::vector<std::function<void()>> work = {work_1, work_2, work_3};

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> vec) {
  os << "<";
  std::for_each(vec.begin(), vec.end(),
                [&](T x) -> void { os << " " << x << " "; });
  os << "> "
     << "[" << vec.size() << " elements]";
  return os;
}

// Threads, Mutex, ref
int main() {
  std::srand(std::time(nullptr));

  // Starten Sie zwei Threads und füllen Sie in der Workerfunktion einen
  // (globalen) int-vector jeweils mit n Zufallszahlen.

  // ============ _TASK = 1 ============
  // Starten Sie mit kleinem n (<5) und schützen Sie den Zugriff auf den Vektor
  // nicht. Funktioniert das? => Ja!

  // ============ _TASK = 2 ============
  // Erhöhen Sie nun die Anzahl n solange, bis das Programm abstürzt. Warum ist
  // das so?
  // => Beide Threads greifen auf vec zu. Es kommt zu Datenverlust.
  /*
  $ ./westwheat.out
  double free or corruption (fasttop)
  Aborted
  */

  // ============ _TASK = 3 ============
  // Schützen Sie den Vektor beim Einfügen mit einem lock_guard (thread-safe).
  // Funktioniert es jetzt wieder?

  std::thread thread1(work[_TASK - 1]);
  std::thread thread2(work[_TASK - 1]);

  thread1.join();
  thread2.join();

  std::cout << "_TASK " << _TASK << std::endl;

  // std::cout << v << std::endl;
  std::cout << "Elements in data: " << data.size() << std::endl;
};

void work_1() {
  for (int i{0}; i < 3; ++i) {
    data.push_back(1 + std::rand() / ((RAND_MAX + 1U) / 20));
  }
};

void work_2() {
  for (int i{0}; i < 1000; ++i) {
    data.push_back(1 + std::rand() / ((RAND_MAX + 1U) / 20));
  }
};

void work_3() {
  for (int i{0}; i < 1000; ++i) {
    std::lock_guard<std::mutex> lock(mutex_vector);
    data.push_back(1 + std::rand() / ((RAND_MAX + 1U) / 20));
  }
};