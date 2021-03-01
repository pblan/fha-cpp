#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>
#include <functional>
#include <condition_variable>

#define TASK 2

std::mutex mutex_vector;

std::vector<int> v;

void work_1();
void work_2();
void work_3();

std::vector<std::function<void()>> work = {work_1, work_2, work_3};

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> v)
{
    os << "<";
    std::for_each(v.begin(), v.end(), [&](T x) -> void { os << " " << x << " "; });
    os << "> "
       << "[" << v.size() << " elements]";
    return os;
}

// Threads, Mutex, ref
int main()
{
    std::srand(std::time(0));

    // Starten Sie zwei Threads und füllen Sie in der Workerfunktion einen (globalen) int-vector jeweils mit n Zufallszahlen.

    // ============ TASK = 1 ============
    // Starten Sie mit kleinem n (<5) und schützen Sie den Zugriff auf den Vektor nicht.
    // Funktioniert das? => Ja!

    // ============ TASK = 2 ============
    // Erhöhen Sie nun die Anzahl n solange, bis das Programm abstürzt. Warum ist das so?
    // => Beide Threads greifen auf v zu. Es kommt zu Datenverlust.
    /*
    $ ./westwheat.out 
    double free or corruption (fasttop)
    Aborted
    */

    // ============ TASK = 3 ============
    // Schützen Sie den Vektor beim Einfügen mit einem lock_guard (thread-safe).
    // Funktioniert es jetzt wieder?

    std::thread t1(work[TASK - 1]);
    std::thread t2(work[TASK - 1]);

    t1.join();
    t2.join();

    std::cout << "TASK " << TASK << std::endl;

    //std::cout << v << std::endl;
    std::cout << "Elements in v: " << v.size() << std::endl;
};

void work_1()
{
    for (int i{0}; i < 3; ++i)
    {
        v.push_back(1 + std::rand() / ((RAND_MAX + 1u) / 20));
    }
};

void work_2()
{
    for (int i{0}; i < 1000; ++i)
    {
        v.push_back(1 + std::rand() / ((RAND_MAX + 1u) / 20));
    }
};

void work_3()
{
    for (int i{0}; i < 1000; ++i)
    {
        std::lock_guard<std::mutex> lk(mutex_vector);
        v.push_back(1 + std::rand() / ((RAND_MAX + 1u) / 20));
    }
};