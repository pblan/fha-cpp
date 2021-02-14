// author: a.voss@fh-aachen.de

#include <iostream>
#include <stdexcept>
using std::cout;
using std::endl;
using std::ostream;
using std::invalid_argument;

const int dim{4};

class polynom {                                             // (A)
public:
    double coeffs[dim];

//  double eval(double x) {
    double operator()(double x) {                           // (B)
        double r{0.0};
        for (int i=dim-1; i>=1; --i)
            r = x*(coeffs[i]+r);
        r += coeffs[0];
        return r;    
    }
    
//  double at(size_t i) const {
    double operator[](size_t i) const {                     // (C)
        if (i>=dim)
            throw invalid_argument("index too large");
        return coeffs[i];
    }

//  double& at(size_t i) {                                  // (D)
    double& operator[](size_t i) {
        if (i>=dim)
            throw invalid_argument("index too large");
        return coeffs[i];
    }
};

ostream& operator<<(ostream& os, const polynom& p) {
    os << p[0];
    for (int i=1; i<dim; ++i)
        os << "+" << p[i] <<"x^" << i;
    return os;
}

// polynom add(const polynom& p1, const polynom& p2) {
polynom operator+(const polynom& p1, const polynom& p2) {   // (E)
    polynom r;
    for (int i=0; i<dim; ++i)
        r[i] = p1[i]+p2[i];
    return r;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;
    
    polynom p{1.0,2.0,3.0,4.0};
    cout << "01|    p=" << p << endl;

    cout << "-----" << endl;
    
    cout << "02|    p(1)=" << p(1.0) << endl;               // (F)
    cout << "03|    p(2)=" << p(2.0) << endl;

    cout << "-----" << endl;

    polynom q1{4.0,5.0,6.0}, q2{1.0,2.0,3.0}, q3;
    cout << "04|    q1=" << q1 << endl;
    cout << "05|    q2=" << q2 << endl;
    
    q3 = q1+q2;                                             // (G)
    cout << "06|    q3=" << q3 << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Die Klasse abstrahiert ein Polynom, welches die Koeffizienten
 *      enthält und ausgewertet werden kann, siehe auch Übung meadowriver.
 * 
 * (B)  Wie eval, nur als Aufruf in (), siehe auch (F).
 * 
 * (C),(D) Getter und Setter für die Koeffizienten, nur als Operator [],
 *      siehe auch (E).
 * 
 * (E)  Binärer op +, siehe auch (G).
 * 
 * (F)  Siehe (B).
 * 
 * (G)  Siehe (E).
 * 
 */



