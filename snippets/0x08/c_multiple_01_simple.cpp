// author: a.voss@fh-aachen.de

#include <iostream>
#include <vector>
using std::cout;
using std::endl;

#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"

struct A 
{
    int id;

    A(int id) : id(id) { cout << "-1|      A(" << id << ")" << endl; }
    ~A()               { cout << "-2|      ~A(" << id << ")" << endl; }
};

struct B1 : public A
{
    B1(int id) : A(id) { cout << "-3|      B1(" << id << ")" << endl; }
    ~B1()              { cout << "-4|      ~B1(" << id << ")" << endl; }
};

struct B2 : public A
{
    B2(int id) : A(id) { cout << "-5|      B2(" << id << ")" << endl; }
    ~B2()              { cout << "-6|      ~B2(" << id << ")" << endl; }
};

struct C : public B1, public B2                             // (A)
{
    C(int id) : B1(id+1),B2(id+2) { 
        cout << "-7|      C(" 
             << B1::id << "," << B2::id << ")" << endl;     // (B)
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

    cout << "04|    c.B1.n=" << c.B1::id
         << ", c.B2::n=" << c.B2::id << endl;
    
    cout << "05|    size B1=" << sizeof(B1) 
         << ", size B2=" << sizeof(B2) 
         << ", size C=" << sizeof(C) << endl;               // (C)
    
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  'multiple inheritance', aber über mehrere Ebenen. Die Frage lautet
 *      hier: Wie oft ist die id aus A in C vorhanden, einmal für jedes
 *      B oder insgesamt nur einmal?
 * 
 * (B)  Der Zugriff auf die id aus B1 bzw. B2 wird mit dem Klassennamen
 *      versehen, um den Member eindeutig zu adressieren.
 * 
 * (C)  Die Größe von C ist 8, was genau den zwei ints entspricht.
 * 
 */
 
