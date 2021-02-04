#include <iostream>
#include <stdexcept>

const int dim = 4;

// Überführen Sie die Struktur 'polynom' aus Übung 'Elkford' in eine Klasse 'polynom'.
class polynom
{
private:
public:
    double coeffs[dim];

    // Überführen Sie die Funktion 'eval' in eine Memberfunktion.
    double eval(double x) const
    {
        double res{0.0};
        for (int i = dim - 1; i >= 1; --i)
            res = x * (coeffs[i] + res);
        res += coeffs[0];
        return res;
    }

    // Implementieren Sie eine Memberfunktion 'at', die einen Index 'i' übergeben bekommt und den i'ten Koeffizienten zurückgibt.
    // Werfen Sie eine Ausnahme, falls 'i' ungültig ist.
    double at(size_t i) const
    {
        if (i >= dim)
        {
            throw std::invalid_argument("invalid index");
        }
        return coeffs[i];
    }
};

std::ostream &operator<<(std::ostream &os, const polynom &p)
{
    os << p.coeffs[0]
       << "+" << p.coeffs[1] << "x"
       << "+" << p.coeffs[2] << "x^2";
    return os;
}

// Erweiterung:
// Implementieren Sie eine globale Funktion 'add', um zwei Polynome zu addieren und geben Sie das Ergebnis zurück.
polynom add(const polynom &p1, const polynom &p2)
{
    polynom p;
    for (size_t i = 0; i < dim; i++)
    {
        p.coeffs[i] = p1.at(i) + p1.at(i);
    }
    return p;
}

int main()
{
    // Nutzen Sie den Testcode aus 'Elkford' und testen Sie zusätzlich mit der Dimension 4.
    polynom p{2.0, 3.0, 4.0, 5.0};

    std::cout << "p: " << p << std::endl;
    std::cout << "p.eval(4.0): " << p.eval(4.0) << std::endl;

    polynom q1{4.0, 5.0, 6.0}, q2{1.0, 2.0, 3.0};

    std::cout << "q1: " << q1 << std::endl;
    std::cout << "q2: " << q2 << std::endl;

    polynom q = add(q1, q2);

    std::cout << "q = q1 + q2: " << q << std::endl;

    try
    {
        double c0{p.at(0)};
        std::cout << "c0: " << c0 << std::endl;
        double ce{p.at(dim)};
        std::cout << "ce: " << ce << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl;
    }
}