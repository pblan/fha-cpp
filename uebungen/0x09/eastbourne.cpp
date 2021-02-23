#include <iostream>

template <typename T>
class punkt
{
private:
    T x_;
    T y_;

public:
    punkt()
        : x_{}, y_{} {};
    ~punkt() = default;

    punkt(T x, T y)
        : x_{x}, y_{y} {};

    T x() const { return x_; };
    T y() const { return y_; };
    void set_x(T x) { x_ = x; }
    void set_y(T y) { y_ = y; }

    punkt(const punkt &p) = default;
};

// Nehmen Sie Ihre Punkt-Klasse, spezialisieren Sie sie für bool und machen dort den ctor privat, so dass Sie keine Instanz davon erzeugen können.
template <>
class punkt<bool>
{
    punkt(){};
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const punkt<T> &p)
{
    os << "(" << p.x() << ", " << p.y() << ")";
    return os;
}

int main()
{
    // alter Test:
    punkt<int> p1;
    punkt<int> p2(3.3, 4.4);
    punkt<int> p3{p2};

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;

    p1.set_x(1.1);
    p1.set_y(2.2);

    p3.set_x(5.5);
    p3.set_y(6.6);

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;

    const punkt<int> &rp{p1};
    int x{rp.x()}, y{rp.y()};

    std::cout << "x: " << x << ", y: " << y << std::endl;

    std::cout << "----------------" << std::endl;

    punkt<float> q1;
    punkt<float> q2(3.3, 4.4);
    punkt<float> q3{q2};

    std::cout << q1 << std::endl;
    std::cout << q2 << std::endl;
    std::cout << q3 << std::endl;

    q1.set_x(1.1);
    q1.set_y(2.2);

    q3.set_x(5.5);
    q3.set_y(6.6);

    std::cout << q1 << std::endl;
    std::cout << q2 << std::endl;
    std::cout << q3 << std::endl;

    const punkt<float> &rq{q1};
    float x2{rq.x()}, y2{rq.y()};

    std::cout << "x: " << x2 << ", y: " << y2 << std::endl;
}