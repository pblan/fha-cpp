// author: a.voss@fh-aachen.de

#include <iostream>
using namespace std;

#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"


bool reserve2(size_t size, int*& p) {
    p = new int[size];
    return (p!=nullptr);
}

bool reserve3(size_t size, int** p) {
    *p = new int[size];
    return (*p!=nullptr);
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    
    int* p;
    bool ok;
    
    ok = reserve2(100,p);
    cout << "07|    reserve ok? " << ok << ", p=" << p << endl;
    free(p);

    ok = reserve3(100,&p);
    cout << "08|    reserve ok? " << ok << ", p=" << p << endl;
    free(p);
    
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

