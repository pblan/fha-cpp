// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class bruch {
    int zaehler_;
    int nenner_;
    
public:
    bruch() : zaehler_{}, nenner_{} {}
    ~bruch() = default;
    
    bruch(int zaehler, int nenner) 
        : zaehler_{zaehler}, nenner_{nenner} {}

    // bruch(const bruch& b)
    //     : m_zaehler{b.m_zaehler}, m_nenner{b.m_nenner} {}
    bruch(const bruch& b) = default;

    [[nodiscard]] int zaehler() const { return zaehler_; }
    [[nodiscard]] int nenner() const { return nenner_; }

    // no individual setter, use ctor
};

ostream& operator<<(ostream& os, const bruch& b) {
    os << "(" << b.zaehler() << "/" << b.nenner() << ")";
    return os;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    bruch b1;
    bruch b2(3,4);
    bruch b3{b2};
    
    cout << "01|    b1=" << b1 << endl;
    cout << "02|    b2=" << b2 << endl;
    cout << "03|    b3=" << b3 << endl;
    
    cout << "-----" << endl;

    b1 = bruch{1,2};
    b3 = bruch{5,6};

    cout << "04|    b1=" << b1 << endl;
    cout << "05|    b2=" << b2 << endl;
    cout << "06|    b3=" << b3 << endl;

    cout << "-----" << endl;
    
    const bruch& rb{b1};
    int z{rb.zaehler()}, n{rb.nenner()};
    cout << "07|    z=" << z << ", n=" << n << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
