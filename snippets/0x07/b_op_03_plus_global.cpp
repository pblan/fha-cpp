// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class int3 {                                                // (A)
    int m_n{0};
    
public:
    int3() {}
    
    int3(int n) : m_n{n%3} {}

    int3(const int3& i) : m_n{i.m_n} {} 

    operator int() const { return m_n; }                    // (B)
    
    int3& operator+=(const int3& i) {                       // (C)
        m_n = (m_n+i.m_n)%3;
        return *this;
    }

};

int3 operator+(const int3& lhs, const int3& rhs) {          // (D)
    cout << "-a|      op+, lhs=" << lhs << ", rhs=" << rhs << endl;
    int3 res{lhs};
    return res+=rhs; // res.operator+=(rhs)
}

int3 operator+(const int3& lhs, int rhs) {                  // (E)
    cout << "-b|      op+, lhs=" << lhs << ", rhs=" << rhs << endl;
    return lhs+int3{rhs};
}

int3 operator+(int lhs, const int3& rhs) {                  // (F)
    cout << "-c|      op+, lhs=" << lhs << ", rhs=" << rhs << endl;
    return rhs+lhs;
}

ostream& operator<<(ostream& os, const int3& i) {
    os << (int)(i);
    return os;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    //g(3);

    int3 i0{0},i1{1},i2{2},i3{3};
        
    cout << "01|    i0=" << i0 << ", i1=" << i1
         << ", i2=" << i2 << ", i3=" << i3 << endl;
    
    cout << "-----" << endl;

    cout << "02|    i1=" << i1 << endl;
    int n1{i1};                                             // (G)
    cout << "03|    i1.int: n1=" << n1 << endl;

    cout << "-----" << endl;

    i2 = 3;                                                 // (H)
    cout << "04|    i2=3: i2=" << i2 << endl;
    
    i2 += i1;                                               // (I)
    cout << "05|    i2+=i1: i2=" << i2 << endl;

    i2 += 4;                                                // (J)
    cout << "06|    i2+=4: i2=" << i2 << endl;

    cout << "-----" << endl;
    
    i3 = i1+i2;   
                                              // (K)
    cout << "07|    i3=i1+i2: i3=" << i3 << endl;

    i3 = i1+4;                                              // (L)
    cout << "08|    i3=i1+4: i3=" << i3 << endl;

    i3 = 5+i1;                                              // (M)
    cout << "09|    i3=5+i1: i3=" << i3 << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Die Klasse repräsentiert eine Zahl zwischen 0 und 2, quasi
 *      alles mod 3.
 * 
 * (B)  Das ist ein Operator, der eine instanz in einen 'int' umwandelt.
 * 
 * (C)  Der += Operator für die Klasse, siehe auch (I).
 * 
 * (D)  Der (binäre) + Operator, d.h. der Operator mit zwei Argumenten
 *      vom Typ int3, siehe auch (K).
 * 
 * (E)  Noch ein + Operator, aber für einen Summanden vom Typ int3 
 *      und einen int, siehe auch (L).
 * 
 * (F)  Wie (E), nur dass int links und int3 rechts angegeben sind, siehe
 *      auch (M).
 * 
 * (G)  Der copy-ctor wird benötigt.
 * 
 * (H)  Die Zuweisung geht nicht direkt, aber da es einen ctor gibt, der
 *      einen int bekommt, kann man mit dem copy-ctor den Ausdruck auflösen.
 * 
 * (J..M) Additionen, siehe (C) bis (F).
 */
