// author: a.voss@fh-aachen.de

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;

class A {
public:
    A() {}
private:
    void f() {}

    friend class B;                                         // (A)
};

class B {
    A a;
    B() {}
    void f() { a.f(); }                                     // (B)

    friend B make_B();                                      // (C)
};

B make_B() { return B(); }                                  // (D)

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
        
    cout << "01|    Compile-Test..." << endl;

    A a;
    // a.f();                                               // (E)

    // B b1;                                                // (F)
    B b2 = make_B();

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A),(B),(E)  Die Funktion f ist privat in A, aber B ist Freund von A.
 *              Auskommentierung der Zeile (A) führt zum Fehler.
 * (C),(D),(F)  ctor von B ist privat, aber die Funktion make_B ist ein Freund,
 *              und darf das im Gegensatz zu main.
 */
 
