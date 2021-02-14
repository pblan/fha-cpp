// author: a.voss@fh-aachen.de

#include <iostream>
#include <vector>
#include <thread>
#include <condition_variable>
#include <random>

using std::cout;
using std::endl;
using std::ostream;
using std::vector;
using std::thread;
using std::mutex;
using std::lock_guard;
using std::ref;

#include "ts.h"

// langweilige zwei thread Variante

void work(size_t a, size_t b, size_t& sum, mutex& m) {
    for (size_t i=a; i<b; ++i) {
        lock_guard<mutex> lk(m);
        sum+=i;
    }
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    
    std::srand(0);
    
    cout << "01| " << ts() << " |    starte threads" << endl;

    mutex mutex_sum; 
    const size_t n{10};
    size_t sum{0};
    
    thread tpaul(work,0,n/2,ref(sum),ref(mutex_sum));
    thread tlisa(work,n/2,n+1,ref(sum),ref(mutex_sum));
    
    tpaul.join();
    tlisa.join();

    cout << "02| " << ts() << " |    sum=" << sum 
         << ", korrekt? " << (sum==n*(n+1)/2) << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

 
