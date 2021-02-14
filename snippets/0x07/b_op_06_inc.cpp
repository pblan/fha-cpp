// author: a.voss@fh-aachen.de

#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::ostream;
using std::fabs;
using std::sqrt;

// siehe auch sol_stoneridge

const double eps = 1e-4;

class punkt {                                               // (A)
    double m_x;
    double m_y;
    
public:
    punkt() : m_x{}, m_y{} {}
    ~punkt() {}
    
    punkt(double x, double y) 
        : m_x(x), m_y(y) {}

    punkt(const punkt& p) 
        : m_x{p.m_x}, m_y{p.m_y} {}
    
    const double& x() const { return m_x; }
    const double& y() const { return m_y; }
    
    // ++p
    punkt& operator++() {                                   // (B)
        ++m_x; ++m_y;
        return *this;
    }
    
    // p++
    punkt operator++(int) {                                 // (C)
        punkt tmp(*this);
        ++(*this);
        return tmp;
    }
    
    double operator!() const {                              // (D)
        return sqrt(m_x*m_x+m_y*m_y);
    }

};

bool operator==(const punkt& p1, const punkt& p2) {         // (E)
    return (fabs(p1.x()-p2.x())<eps && fabs(p1.y()-p2.y())<eps);
}

bool operator!=(const punkt& p1, const punkt& p2) {         // (F)
    return !(p1==p2);
}

bool operator<(const punkt& p1, const punkt& p2) {          // (G)
    return ((!p1)<(!p2));
}

bool operator>=(const punkt& p1, const punkt& p2) {         // (H)
    return !(p1<p2);
}

ostream& operator<<(ostream& os, const punkt& p) {
    os << "(" << p.x() << "," << p.y() << ")";
    return os;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    punkt p1{1.0,2.0};
    punkt p2(1.1,2.1);
    punkt p3{1.00001,2.00001};
    
    cout << "01|    p1=" << p1 << endl;
    cout << "02|    p2=" << p2 << endl;
    cout << "03|    p3=" << p3 << endl;
    
    cout << "-----" << endl;

    cout << "04|    p1==p2: " << (p1==p2) << endl;
    cout << "05|    p1!=p2: " << (p1!=p2) << endl;
    cout << "06|    p1==p3: " << (p1==p3) << endl;

    cout << "-----" << endl;

    ++p1;
    p3 = p2++;
    cout << "07|    p1=" << p1 << endl;
    cout << "08|    p2=" << p2 << endl;
    cout << "09|    p3=" << p3 << endl;

    cout << "-----" << endl;

    punkt p4{3,4};
    punkt p5{1,2};
    cout << "10|    sqrt(p4)=" << !p4 << endl;
    cout << "11|    sqrt(p5)=" << !p5 << endl;
    cout << "12|    p4<p5: " << (p4<p5) << endl;
    cout << "13|    p4>=p5: " << (p4>=p5) << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Die Klasse medelliert einen Punkt in X-Y, der Operationen wie
 *      bspw. Addieren via +-Operator beherrscht.
 * 
 * (B)  Derr Pre-Inkrement-Operator ++p erhöht beide Argumente. Wichtig
 *      ist hier, dass die Signatur ohne Argument die Pre-Inc. Op. meint.
 * 
 * (C)  Ebenfalls ein Inkrement-Operator, aber Post. Das int-Argument
 *      hat keine Funktion, es dient nur dazu, unterschiedliche Signaturen
 *      für beide Operatoren zu haben.
 *      Man sieht aber, dass intern dieser Operator etwas aufwändiger ist,
 *      da der alte Wert zurückgegeben wird. D.h. es wird in der Regel
 *      eine temp. Variable benötigt.
 * 
 * (D)  Der Not-Op., hier verwendet für die Wurzel. Like it or not.
 * 
 * (E)  Der Vergleichs-Operator, global, damit man symmetrisch verschiedene
 *      Kombinationen von Parametern implementieren könnte.
 * 
 * (F)  Der Vergleichs-Operator für Ungleich. Wichtig ist hier, dass er
 *      über den Vergleichs-Operator implementiert wird.
 * 
 * (G)  Der Kleiner-Operator vergleicht die Wurzeln.
 * 
 * (H)  Auch hier wird der Operator durch Verwendung des Kleiner-Operators
 *      realisiert.
 * 
 */
