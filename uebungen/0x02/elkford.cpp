#include <iostream>

// Beispielstruktur 'polynom':

// Definieren Sie eine globale Variable 'dim' mit Wert 3.
const int dim = 3;

// Definieren Sie eine Struktur 'polynom', die ein Feld der Größe 'dim' von Koeffizienten 'coeffs' enthält.
struct polynom
{
    double coeffs[dim];
};

// Erweiterung:
// Implementieren Sie einen Operator '<<' zur Ausgabe [...].
std::ostream &operator<<(std::ostream &os, const polynom &p)
{
    os << p.coeffs[0]
       << "+" << p.coeffs[1] << "x"
       << "+" << p.coeffs[2] << "x^2";
    return os;
}

double eval(polynom &p, const double &x);

int main()
{
    // Schreiben Sie aussagekräftigen Testcode.
    polynom p{2.0, 3.0, 4.0};
    std::cout << "p: " << p << std::endl;
    std::cout << "eval(p, 4.0): " << eval(p, 4.0) << std::endl;
}

// Programmieren Sie eine globale Funktion 'eval', um ein Polynom 'p' an einer Stelle 'x' auszuwerten.
// Übergeben Sie das Polynom  ('call-by-ref') und die Stelle der Funktion.
double eval(polynom &p, const double &x)
{
    return p.coeffs[0] + x * (p.coeffs[1] + x * p.coeffs[2]);
}