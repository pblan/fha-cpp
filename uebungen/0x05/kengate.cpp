#include <iostream>

using std::cout;
using std::endl;

void swap1(double *ap, double *bp); // swap Methode über Zeiger
void swap2(double &a, double &b); // swap Methode über Referenzen
void swap_ptr(double *&ap, double *&bp);

int main() {
    double a{1.0};
    double b{2.0};

    cout << "a: " << a << ", b: " << b << endl;

    swap1(&a, &b); // &a gibt Speicheradresse von a

    cout << "swap1(&a, &b);" << endl;
    
    cout << "a: " << a << ", b: " << b << endl;

    swap2(a, b);

    cout << "swap2(a, b);" << endl;
    
    cout << "a: " << a << ", b: " << b << endl;

    double *ap{&a};
    double *bp{&b};

    cout << "*ap: " << *ap << ", *bp: " << *bp << endl;
    
    swap_ptr(ap, bp);

    cout << "swap_ptr(ap, bp);" << endl;
    
    cout << "*ap: " << *ap << ", *bp: " << *bp << endl;
    return 0;
}

void swap1(double* ap, double* bp) {
    double help = *ap;
    *ap = *bp;
    *bp = help;
}

void swap2(double &a, double &b) {
    double help = a;
    a = b;
    b = help;
}

void swap_ptr(double *&ap, double *&bp) {
    double *help = ap;
    ap = bp;
    bp = help;
}