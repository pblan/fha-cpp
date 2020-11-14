// author: a.voss@fh-aachen.de

#include <iostream>
#include <stdexcept>
using std::cout;
using std::endl;
using std::ostream;
using std::invalid_argument;

const int dim{4};

class polynom {
public:
    double coeffs[dim];

    double eval(double x) {
        double r{0.0};
        for (int i=dim-1; i>=1; --i)
            r = x*(coeffs[i]+r);
        r += coeffs[0];
        return r;    
    }
    
    [[nodiscard]] double at(size_t i) const {
        if (i>=dim)
            throw invalid_argument("index too large");
        return coeffs[i];
    }

    // operator[] could also be used
    double& at(size_t i) {
        if (i>=dim)
            throw invalid_argument("index too large");
        return coeffs[i];
    }
};

ostream& operator<<(ostream& os, const polynom& p) {
    os << p.at(0);
    for (int i=1; i<dim; ++i)
        os << "+" << p.at(i) <<"x^" << i;
    return os;

}

polynom add(const polynom& p1, const polynom& p2) {
    polynom r;
    for (int i=0; i<dim; ++i)
        r.at(i) = p1.at(i)+p2.at(i);
    return r;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;
    
    polynom p{1.0,2.0,3.0,4.0};
    cout << "01|    p=" << p << endl;

    cout << "-----" << endl;
    
    cout << "02|    p(1)=" << p.eval(1.0) << endl;
    cout << "03|    p(2)=" << p.eval(2.0) << endl;

    cout << "-----" << endl;

    polynom q1{4.0,5.0,6.0}, q2{1.0,2.0,3.0}, q3;
    cout << "04|    q1=" << q1 << endl;
    cout << "05|    q2=" << q2 << endl;
    
    q3 = add(q1,q2);
    cout << "06|    q3=" << q3 << endl;

    cout << "-----" << endl;

    try {
        double c0{p.at(0)};
        cout << "07|    c0=" << c0 << endl;
        double ce{p.at(dim)};
        cout << "08|    ce=" << ce << endl;
    } catch (const invalid_argument& e) {
        cout << "09|    catch, what='" << e.what() << "'" << endl;
    } catch (...) {
        cout << "10|    catch, default" << endl;
    }
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}




