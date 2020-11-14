// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

// #pragma GCC diagnostic ignored "-Wunused-but-set-parameter"

class C {
public:
    int n=1;
    void out() { 
        // 'this' is the pointer on me, type C*
        cout << "0a|    n=" << this->n 
             << "=" << (*this).n 
             << ", " << this << endl;
    }
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    int n{23};

    // note:
    // int* pn1,pn2;    // means: pn1 is int* and pn2 is int
    // int *pn1,*pn2;   // means: both are int*
    // better: declare individually, with or w.o. init.
    int* pn1;
    int* pn2;
    pn1 = &n;
    pn2 = &n;

    cout << "01|    n=" << n << ", &n=pn1=" << pn1 << "=pn2=" << pn2 << endl;
 
    cout << "-----" << endl;

    // this is a const char* with '/0'(null-char) at the end
    cout << "02|    'Hello'" << endl;

    // do it manually
    const char* pcc = "Hello";
    cout << "03|    '" << pcc << "'" << endl;
    // so this is the reason why a char* does not print its address
    // but some strange string...
 
    // check if there actually is a '/0'
    cout << "04|    check bytes:";
    for (size_t i = 0; i<6; ++i)
        cout << " " << (int)(*(pcc+i));
    cout << endl;

    cout << "-----" << endl;

    C c;
    c.out();    // note: special pointer 'this' in out()

    // compare: &c = &c.n, i.e. member n is on top of object
    cout << "05|    &c=" << &c << ", &c.n=" << &c.n << endl;
    
    // use -> instead of (*).
    C* pc{&c};
    cout << "06|    c.n=" << (*pc).n << "=" << pc->n << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

