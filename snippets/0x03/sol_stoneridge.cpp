// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class punkt {
    double x_;
    double y_;
    
public:
    punkt() : x_{}, y_{} {}
    ~punkt() = default;
    
    punkt(double x, double y) 
        : x_{x}, y_{y} {}

    punkt(const punkt& p) = default;

    // in fact, this class is a pure data class, i.e. we could
    // avoid setter and getter completely...

    double x() const { return x_; }
    void set_x(double value) { x_ = value; }

    double y() const { return y_; }
    void set_y(double value) { y_ = value; }
};

ostream& operator<<(ostream& os, const punkt& p) {
    os << "(" << p.x() << "," << p.y() << ")";
    return os;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    punkt p1;
    punkt p2(3.3,4.4);
    punkt p3{p2};
    
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
    
    const punkt& rp{p1};
    double x{rp.x()}, y{rp.y()};
    cout << "07|    x=" << x << ", y=" << y << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
