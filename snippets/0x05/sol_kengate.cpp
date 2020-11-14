// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

void swap(double& d1, double& d2) {
    double d = d1;
    d1 = d2;
    d2 = d;
}

void swap(double* pd1, double* pd2) {
    double d = *pd1;
    *pd1 = *pd2;
    *pd2 = d;
}

void swap_ptr(double*& pd1, double*& pd2) {
    double* pd = pd1;
    pd1 = pd2;
    pd2 = pd;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    double d1{1.1}, d2{2.2};
    
    cout << "01|    d1=" << d1 << ", d2=" << d2 << endl;
    swap(d1,d2);
    cout << "02|    d1=" << d1 << ", d2=" << d2 << endl;
    swap(&d1,&d2);
    cout << "03|    d1=" << d1 << ", d2=" << d2 << endl;

    cout << "-----" << endl;

    double *pd1{&d1}, *pd2{&d2};
    cout << "04|    *pd1=" << *pd1 << ", *pd2=" << *pd2 << endl;
    swap_ptr(pd1,pd2);
    cout << "05|    *pd1=" << *pd1 << ", *pd2=" << *pd2 << endl;
    
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
