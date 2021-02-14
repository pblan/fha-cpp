// author: a.voss@fh-aachen.de

#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::ostream;
using std::function;

typedef double (*function_t)(int x, int y);

double Q(int x, int y) { return (double)x/(double)y; }

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    
    function_t q{Q};
    cout << "01|    q(1,2)=1/2=" << q(1,2) << endl; 

    function<double(int,int)> r{Q};
    cout << "02|    r(1,2)=1/2=" << r(1,2) << endl; 

    double(*s)(int,int){Q}; 
    cout << "03|    s(1,2)=1/2=" << s(1,2) << endl; 

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

 
