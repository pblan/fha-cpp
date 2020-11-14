// author: a.voss@fh-aachen.de

#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::floor;
using std::string;

void cut(double& x1, double& x2) {
    x1 = floor(x1);
    x2 = floor(x2);
}

void shift(string& x1, string& x2, string& x3) {
    string t{x1};
    x1=x2; x2=x3; x3=t;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    double d1{1.1},d2{2.2};
    cout << "01|    d1=" << d1 << ", d2=" << d2 << endl;
    
    cut(d1,d2);
    cout << "02|    d1=" << d1 << ", d2=" << d2 << endl;

    cout << "-----" << endl;
    
    string s1{"s1"},s2{"s2"},s3{"s3"};
    cout << "03|    s1='" << s1 << "', s2='" << s2 << "', s3='" << s3 << "'" << endl;
    
    shift(s1,s2,s3);
    cout << "04|    s1='" << s1 << "', s2='" << s2 << "', s3='" << s3 << "'" << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
