// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

const int dim{3};

struct polynom {
    double coeffs[dim];
};

double eval(const polynom& p, double x) {
    return p.coeffs[0]+x*(p.coeffs[1]+x*p.coeffs[2]);
}

ostream& operator<<(ostream& os, const polynom& p) {
    os << p.coeffs[0] 
        << "+" << p.coeffs[1] << "x^1"
        << "+" << p.coeffs[2] << "x^2";
    return os;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;
    
    polynom p{1.0,2.0,3.0};
    cout << "01|    p=" << p << endl;

    cout << "-----" << endl;
    
    cout << "02|    p(1)=" << eval(p,1.0) << endl;
    cout << "03|    p(2)=" << eval(p,2.0) << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}


