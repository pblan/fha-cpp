// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

template <int B, int N>
struct pot {
    static const int value=B*pot<B,N-1>::value;
};

template <int B>
struct pot<B,1> {
    static const int value=B;
};

template <int N>
struct pot<1,N> {
    static const int value=1;
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    
    cout << "01|    2^3: " << pot<2,3>::value << endl; 
    cout << "02|    3^4: " << pot<3,4>::value << endl; 
    cout << "03|    1^5: " << pot<1,5>::value << endl; 

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

 
