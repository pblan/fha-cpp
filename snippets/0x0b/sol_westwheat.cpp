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

#include "ts.h"

 
const size_t n{5};  // stürzt sogar schon manchmal bei 5 ab
vector<int> data;
mutex mutex_data; 

// für die Übergabe lokal und per Ref. siehe d_ref.cpp

void work() {
// ungeschützt
//    for (size_t i=0; i<n; ++i)
//        data.push_back(i);

// mit guard
    for (size_t i=0; i<n; ++i) {
        lock_guard<mutex> lk(mutex_data);
        data.push_back(std::rand()%100);
    }
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    
    std::srand(0);
    
    cout << "01| " << ts() << " |    data.size()=" << data.size() << endl;

    thread tpaul(work);
    thread tlisa(work);
    
    tpaul.join();
    tlisa.join();

    cout << "02| " << ts() << " |    data=[ ";
    for (auto x : data)
        cout << x << " ";
    cout << "]" << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

 
