#include <iostream>

// Eine Klasse 'bruch' ('fraction') entwerfen.
// Verwenden Sie so oft wie möglich 'const'.
class fraction
{
private:
    int num_;   // numerator
    int denom_; // denominator

public:
    // Implementieren Sie einen default-ctor und einen dtor.
    fraction()
        : num_{}, denom_{} {};
    ~fraction() = default;

    // Implementieren Sie einen ctor, der Zähler und Nenner übergeben bekommt.
    // Nutzen Sie ':' zur Initialisierung.
    fraction(int num, int denom)
        : num_{num}, denom_{denom} {};

    // Implementieren Sie 'getter' und 'setter' für (ganzzahlige) Zähler bzw. Nenner.
    int num() const { return num_; }
    int denom() const { return denom_; }
    void set_num(int num) { num_ = num; }
    void set_denom(int denom) { denom_ = denom; }

    // Erweiterung:
    // Implementieren Sie einen copy-ctor.
    fraction(const fraction &f) = default;
};

// Implemetieren Sie einen operator '<<' zur Ausgabe.
std::ostream &operator<<(std::ostream &os, const fraction &f)
{
    os << f.num() << "/" << f.denom();
    return os;
}

int main()
{
    // Schreiben Sie aussagekräftigen Testcode.
    fraction f1;
    fraction f2{2, 3};
    fraction f3{f2};

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;

    f1 = fraction{1, 2};
    f3 = fraction{5, 6};

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;

    const fraction &rf{f1};
    int num{rf.num()}, denom{rf.denom()};
    std::cout << "num: " << num << ", denom" << denom << std::endl;
}