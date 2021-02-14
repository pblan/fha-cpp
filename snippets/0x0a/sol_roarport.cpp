// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;


int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    auto add = [](double x1, double x2, double x3) -> double {return x1+x2+x3;};
    cout << "01|    add(2,3,5): " << add(2,3,5) << endl; 

    cout << "-----" << endl;

    int a{2}, b{5};
    auto chk = [=](int x) -> auto {return (a<=x) && (x<=b);};
    cout << "02|    3 in [" << a << "," << b << "]: " << chk(3) << endl; 
    cout << "03|    6 in [" << a << "," << b << "]: " << chk(6) << endl; 

    cout << "-----" << endl;

    int z{-1};
    auto rev = [&z]() -> auto {z=-z;};                      // akademisches Bsp.!

    cout << "04|    z: " << z << endl; 
    rev();
    cout << "05|    z: " << z << endl; 

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

 
