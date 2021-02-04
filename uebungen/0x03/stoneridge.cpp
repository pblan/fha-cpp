#include <iostream>

// Eine Klasse 'punkt' mit 'x'- und 'y'-Koordinate entwerfen.
// Verwenden Sie so oft wie möglich 'const'.
class punkt
{
private:
    double x_;
    double y_;

public:
    // Implementieren Sie einen default-ctor und einen dtor.
    punkt()
        : x_{}, y_{} {};
    ~punkt() = default;

    // Implementieren Sie einen weiteren ctor, der einen x- und einen y-Wert vom Typ 'double' übergeben bekommt.
    // Benutzen Sie ':' zur Initialisierung.
    punkt(double x, double y)
        : x_{x}, y_{y} {};

    // Implementieren Sie 'getter' und 'setter' für 'x' und 'y'.
    double x() const { return x_; };
    double y() const { return y_; };
    void set_x(double x) { x_ = x; }
    void set_y(double y) { y_ = y; }

    // Erweiterung:
    // Implementieren Sie einen copy-ctor.
    punkt(const punkt &p) = default;
};

// Implementieren Sie einen operator '<<' zur Ausgabe.
std::ostream &operator<<(std::ostream &os, const punkt &p)
{
    os << "(" << p.x() << ", " << p.y() << ")";
    return os;
}

int main()
{
    // Schreiben Sie aussagekräftigen Testcode.
    punkt p1;
    punkt p2(3.3, 4.4);
    punkt p3{p2};

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

    const punkt &rp{p1};
    double x{rp.x()}, y{rp.y()};

    std::cout << "x: " << x << ", y: " << y << std::endl;
}