// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

template <typename T>
class bruch {
    T zaehler_;
    T nenner_;
    
public:
    bruch() : zaehler_{}, nenner_{} {}
    ~bruch() {}
    
    bruch(const T& zaehler, const T& nenner)
        : zaehler_{zaehler}, nenner_{nenner} {}

    bruch(const bruch& b) 
        : zaehler_{b.zaehler_}, nenner_{b.nenner_} {}

    T zaehler() const { return zaehler_; }
    T nenner() const { return nenner_; }
};

template <typename T>
ostream& operator<<(ostream& os, const bruch<T>& b) {
    os << "(" << b.zaehler() << "/" << b.nenner() << ")";
    return os;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    bruch<int> b1;
    bruch<int> b2(3,4);
    bruch<int> b3{b2};
    
    cout << "01|    b1=" << b1 << endl;
    cout << "02|    b2=" << b2 << endl;
    cout << "03|    b3=" << b3 << endl;
    
    cout << "-----" << endl;

    b1 = bruch<int>(1,2);
    b3 = bruch<int>(5,6);

    cout << "04|    b1=" << b1 << endl;
    cout << "05|    b2=" << b2 << endl;
    cout << "06|    b3=" << b3 << endl;

    cout << "-----" << endl;
    
    const bruch<int>& rb{b1};
    int z{rb.zaehler()}, n{rb.nenner()};
    cout << "07|    z=" << z << ", n=" << n << endl;

    cout << "-----" << endl;

    bruch<unsigned long> b4(7l,8l);
    cout << "08|    b4=" << b4 << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
