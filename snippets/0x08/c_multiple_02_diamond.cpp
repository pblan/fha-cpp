// author: a.voss@fh-aachen.de

#include <iostream>
#include <vector>
using namespace std;

#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"

struct A 
{
    int id;

    A(int id) : id(id) { cout << "-1|      A(" << id << ")" << endl; }
    ~A()               { cout << "-2|      ~A(" << id << ")" << endl; }
};

struct B1 : virtual public A                                // (A)
{
    B1(int id) : A(id) { cout << "-3|      B1(" << id << ")" << endl; }
    ~B1()              { cout << "-4|      ~B1(" << id << ")" << endl; }
};

struct B2 : virtual public A
{
    B2(int id) : A(id) { cout << "-5|      B2(" << id << ")" << endl; }
    ~B2()              { cout << "-6|      ~B2(" << id << ")" << endl; }
};

struct C : public B1, public B2                             // (B)
{
    C(int id) : A(id), B1(id+1),B2(id+2) {                  // (C)
        cout << "-7|      C(" 
             << B1::id << "," << B2::id << ")" << endl;
    }
    ~C()                          { 
        cout << "-8|      ~C(" 
             << B1::id << "," << B2::id << ")" << endl; 
    }
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01|    b1:" << endl;
    B1 b1(1);
    cout << "02|    b2:" << endl;
    B2 b2(2);

    cout << "-----" << endl;

    cout << "03|    c:" << endl;
    C c(3);

    cout << "-----" << endl;

    cout << "03a: sizeof A" << sizeof(A) << endl;

    cout << "04|    c.B1.n=" << c.B1::id
         << ", c.B2::n=" << c.B2::id << endl;
    
    cout << "05|    size B1=" << sizeof(B1) 
         << ", size B2=" << sizeof(B2) 
         << ", size C=" << sizeof(C) << endl;               // (D)
    
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  'multiple inheritance', aber mit virtual.
 * 
 * (B)  Das führt dazu, dass die A-Anteile in B1 und B2 quasi 'überander'
 *      gelegt werden, d.h. es gibt nur ein A-Objekt in C, also nur eine
 *      id.
 * 
 * (C)  Hier haben wir die einzige Situation, wo der ctor von A in C
 *      (und nicht in B1 oder B2) adressiert wird. Überlegt man sich einmal,
 *      warum das so ist, dann kommt man zu dem Schluss, dass der ctor
 *      von A ja nur einmal aufgerufen werden darf. Soll das in B1 oder
 *      B2 passieren? Man muss es extra angeben.
 * 
 * (D)  Die Größe von C ist jetzt 24, obwohl wir nur eine id haben. Das
 *      hat mit der Verwaltung der virtuellen Basisklassen zu tun.
 * 
 */
 
