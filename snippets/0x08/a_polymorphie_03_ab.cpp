// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"  // (A)

class A                                                     // (B)
{
public:
    void f()               { cout << "-1|      A::f" << endl; }
    virtual void g()       { cout << "-2|      A::g" << endl; }
};

class B : public A                                          // (C)
{
public:
    void f()               { cout << "-3|      B::f" << endl; }
    void g()               { cout << "-4|      B::g" << endl; }
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    A a;
    B b;
    
    cout << "01|    a:" << endl;                            // (D)
    a.f();
    a.g();

    cout << "02|    b:" << endl;                            // (E)
    b.f();
    b.g();

    cout << "-----" << endl;

    A *pa = new A(), *pb = new B();
    
    cout << "03|    pa:" << endl;                           // (F)
    pa->f();
    pa->g();

    cout << "04|    pb:" << endl;
    pb->f();
    pb->g();

    delete pa;
    delete pb;

    cout << "-----" << endl;
   
    A &ra = a, &rb = b;
    
    cout << "05|    ra:" << endl;                           // (G)
    ra.f();
    ra.g();

    cout << "06|    rb:" << endl;
    rb.f();
    rb.g();
   
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Bei Klassen mit virtuellen Funktionen, wo Objekte mit new erzeugt
 *      bzw. mit delete freigegeben werden, muss in der Regel der dtor
 *      auch als virtual gekennzeichnet werden, um Speicherlecks zu vermeiden,
 *      wenn delete auf einem Basiszeiger oder einer -referenz aufgerufen
 *      wird. Hier brauchen wir das nicht, wollen aber die Warnung unterdrücken.
 * 
 * (B)  Eine einfache Klasse A, in der f nicht virtuell, g aber schon 
 *      virtuell ist.
 * 
 * (C)  B erbt von A, d.h. auch wenn es nicht da steht, g ist und bleibt
 *      virtuell.
 * 
 * (D)  Hier werden nur die Funktionen aus A aufgerufen, da a vom Typ A ist.
 * 
 * (E)  Hier werden die Funktionen aus B aufgerufen, da b vom Typ B ist.
 * 
 * (F)  Neue Situation: die Objekte sind vom Typ A bzw. B, aber der Typ 
 *      des Zeigers ist A*. Was passiert?
 *      Nur bei den virtuellen Funktionen wird auch die entsprechende
 *      'richtige' Funktion der Klasse aufgerufen, alle anderen sind vom 
 *      Typ A und deswegen führt pb->f zur Funktion von A und nicht von B.
 * 
 * (G)  Die Erklärung ist wie bei (F), nur dass wir Basisreferenzen statt
 *      Zeiger haben.
 
 */
 
