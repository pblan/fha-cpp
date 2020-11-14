// author: paddel@paddel.xyz

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

template<typename T>
class bruch {
    T zaehler_;
    T nenner_;
    
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

ostream& operator<<(ostream& os, const bruch<T>& b) {
    os << "(" << b.zaehler() << "/" << b.nenner() << ")";
    return os;
}


int main()
{
    bruch<int> b1;
    bruch<int> b2(3,4);
    bruch<int> b3{b2};
    
    cout << "bruch<int> b1: " << b1 << endl;
    cout << "bruch<int> b2(3,4): " << b2 << endl;
    cout << "bruch<int> b3{b2}: " << b3 << endl;

    b1 = bruch<int>(1,2);
    b3 = bruch<int>(5,6);

    cout << "b1 = bruch<int>(1,2): " << b1 << endl;
    cout << "b3 = bruch<int>(5,6): " << b2 << endl;
    
    const bruch<int>& rb{b1};
    int z{rb.zaehler()}, n{rb.nenner()};
    cout << "07|    z=" << z << ", n=" << n << endl;

    cout << "-----" << endl;

    bruch<unsigned long> b4(7l,8l);
    cout << "08|    b4=" << b4 << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
