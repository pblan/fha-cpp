// author: a.voss@fh-aachen.de

#include <iostream>
#include <functional>
#include <cmath>
using std::cout;
using std::endl;
using std::string;
using std::function;
using std::asin;

// Approximation eines Integrals (numerische Quadratur).
// https://de.wikipedia.org/wiki/Trapezregel
//
// T(f,a,b) = (b-a)*(f(a)+f(b))/2

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    double a{1.0}, b{2.0};
    auto trapezrule = [=](function<double(double)> f)       // (A)
                      {return (b-a)*(f(b)+f(a))/2.0; };

    double A;
    
    A = trapezrule([](double x) -> auto {return x*x;});     // (B)
    cout << "01|    integral(x^2)_[a,b]=" << A << endl;

    A = trapezrule([](double x) -> auto {return x*x*x;});
    cout << "02|    integral(x^3)_[a,b]=" << A << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Wir definieren die Trapezregel als lambda-Ausdruck mit
 *      festen Granzen a und b.
 * 
 * (B)  Angewendet auf x->x^2 und x->x^3.
 * 
 */
 
