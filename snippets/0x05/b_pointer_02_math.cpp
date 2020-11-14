// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    int n{1};
    int* pn{&n};
    
    cout << "01|    pn=" << pn << ", *pn=" << *pn << endl;
    ++pn;                                                   // (A)
    cout << "02|    pn=" << pn << endl;
    ++pn;
    cout << "03|    pn=" << pn << endl;
    pn-=2;                                                  // (B)
    cout << "04|    pn=" << pn << endl;

    cout << "-----" << endl;

    double d{2.0};
    double* pd{&d};
    cout << "04|    pd=" << pd << ", *pd=" << *pd << endl;
    ++pd;                                                   // (C)
    cout << "05|    pd=" << pd << endl;
    ++pd;
    cout << "06|    pd=" << pd << endl;
    --pd; --pd;                                             // (D)
    cout << "06|    pd=" << pd << endl;

    cout << "-----" << endl;

    bool b{true};
    bool* pb{&b};

    cout << "07|    pb=" << pb << ", *pb=" << *pb << endl;
    ++pb;                                                   // (E)
    cout << "08|    pb=" << pb << endl;
    ++pb;
    cout << "09|    pb=" << pb << endl;

    cout << "-----" << endl;

    void* p;                                                // (F)
    p=pn;
    cout << "10|    p=" << p << endl;
    p=pd;
    cout << "11|    p=" << p << endl;
    p=pb;
    cout << "12|    p=" << p << endl;
    // ++p;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  pn wird um sizeof int, also 4, erhöht.
 * 
 * (B)  pn wird um 2*sizeof int verringert.
 * 
 * (C)  pd wird um sizeof double, also 8, erhöht.
 * 
 * (D)  pd wird zweimal dekrementiert, dh. jeweils um 8 verringert.
 * 
 * (E)  pd wird um sizeof bool, also 1, erhöht. 
 *      Beachte, bool ist auch size 1.
 * 
 * (F)  void* ist typlos und kann jeden Zeiger speichern, aber da
 *      der Typ nicht definiert ist, ist ++p nicht definiert.
 * 
 */
 
