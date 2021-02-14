// author: a.voss@fh-aachen.de

#include <iostream>
#include <functional>
#include <cmath>

using std::cout;
using std::endl;
using std::ostream;
using std::function;

// nur die Template Version
double approx(double x0, function<double(double)> f, double eps) { 
    double xlast;
        cout << "-a|      x0:" << x0 << endl; 
    do {
        xlast = x0;
        x0 = f(x0);
        cout << "-b|      x:" << x0 << ", err: " << std::fabs(x0-xlast) << endl; 
    } while (std::fabs(x0-xlast)>eps);
    return x0;
}

double zero(double x) { return x*x; }

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    
    double x;
    const double eps{1e-8};
    
    cout << "01|    check const 1" << endl; 
    x = approx(1,[](double)->double{return 1.0;},eps);
    cout << "02|    x: " << x << endl; 

    cout << "-----" << endl;

    cout << "03|    check sqrt 2" << endl; 
    x = approx(1,[](double x)->double{return 0.5*(x+2.0/x);},eps);
    cout << "04|    x: " << x << endl; 

    cout << "-----" << endl;

    cout << "05|    check zero" << endl; 
    x = approx(0.5,zero,eps);
    cout << "06|    x: " << x << endl; 

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

 
