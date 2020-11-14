// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

template <typename T>
class punkt {
    T x_;
    T y_;
    
public:
    punkt() : x_{}, y_{} {}
    ~punkt() {}
    
    punkt(const T& x, const T& y)
        : x_(x), y_(y) {}

    punkt(const punkt& p) 
        : x_{p.x_}, y_{p.y_} {}

    // ohne Kopie
    // [[nodiscard]] const T& x() const { return m_x; }
    // mit Kopie
    [[nodiscard]] T x() const { return x_; }
    void set_x(const T& value) { x_ = value; }

    [[nodiscard]] T y() const { return y_; }
    void set_y(const T& value) { y_ = value; }
};

template <typename T>
ostream& operator<<(ostream& os, const punkt<T>& p) {
    os << "(" << p.x() << "," << p.y() << ")";
    return os;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    punkt<double> p1;
    punkt<double> p2(3.3,4.4);
    punkt<double> p3{p2};
    
    cout << "01|    p1=" << p1 << endl;
    cout << "02|    p2=" << p2 << endl;
    cout << "03|    p3=" << p3 << endl;
    
    cout << "-----" << endl;

    p1.set_x(1.1); p1.set_y(2.2);
    p3.set_x(5.5); p3.set_y(6.6);

    cout << "04|    p1=" << p1 << endl;
    cout << "05|    p2=" << p2 << endl;
    cout << "06|    p3=" << p3 << endl;

    cout << "-----" << endl;
    
    const punkt<double>& rp{p1};
    double x{rp.x()}, y{rp.y()};
    cout << "07|    x=" << x << ", y=" << y << endl;

    cout << "-----" << endl;

    punkt<long double> p4(7.7l,8.8l);
    cout << "08|    p4=" << p4 << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
