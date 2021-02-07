#include <iostream>

// Klasse zu Template erweitern.
// Erweitern Sie die Klasse 'bruch' bzw. 'fraction' aus Übung 'Ravencastle' zu einem Template.
template <typename T>
class fraction
{
private:
    T num_;   // numerator
    T denom_; // denominator

public:
    fraction()
        : num_{}, denom_{} {};
    ~fraction() = default;

    fraction(T num, T denom)
        : num_{num}, denom_{denom} {};

    T num() const { return num_; }
    T denom() const { return denom_; }
    void set_num(T num) { num_ = num; }
    void set_denom(T denom) { denom_ = denom; }

    fraction(const fraction &f) = default;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const fraction<T> &f)
{
    os << f.num() << "/" << f.denom();
    return os;
}

int main()
{
    // Testen Sie Ihre generische Klasse mit unterschiedlichen Datentypen.
    fraction<int> f1;
    fraction<int> f2{2, 3};
    fraction<int> f3{f2};

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;

    f1 = fraction<int>{1, 2};
    f3 = fraction<int>{5, 6};

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;

    const fraction<int> &rf{f1};
    int num{rf.num()}, denom{rf.denom()};
    std::cout << "num: " << num << ", denom: " << denom << std::endl;

    std::cout << "----------------" << std::endl;

    fraction<float> g1;
    fraction<float> g2{2.5, 3.5};
    fraction<float> g3{g2};

    std::cout << g1 << std::endl;
    std::cout << g2 << std::endl;
    std::cout << g3 << std::endl;

    g1 = fraction<float>{1.5, 2.5};
    g3 = fraction<float>{5.5, 6.5};

    std::cout << g1 << std::endl;
    std::cout << g2 << std::endl;
    std::cout << g3 << std::endl;

    const fraction<float> &rg{g1};
    float num2{rg.num()}, denom2{rg.denom()};
    std::cout << "num: " << num2 << ", denom: " << denom2 << std::endl;
}