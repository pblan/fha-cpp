#include <iostream>
#include <cmath>
#include <string>

void cut(double &a, double &b);
void shift(std::string &a, std::string &b, std::string &c);

int main()
{
    double a, b;
    std::cout << "Eingabe a (double): ";
    std::cin >> a;
    std::cout << "Eingabe b (double): ";
    std::cin >> b;

    std::cout << " a: " << a << ", b: " << b << std::endl;
    cut(a, b);
    std::cout << "cut(a, b)" << std::endl;
    std::cout << " a: " << a << ", b: " << b << std::endl;

    std::string x, y, z;
    std::cout << "Eingabe x (string): ";
    std::cin >> x;
    std::cout << "Eingabe y (string): ";
    std::cin >> y;
    std::cout << "Eingabe z (string): ";
    std::cin >> z;

    std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
    shift(x, y, z);
    std::cout << "shift(x, y, z)" << std::endl;
    std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
}

// Schreiben Sie eine Funktion 'cut', die bei zwei per Referenz übergebenen 'double'-Zahlen jeweils die Nachkommastellen auf 0 setzt.
// Nutzen Sie die Funktion 'floor' aus 'cmath'.
void cut(double &a, double &b)
{
    a = floor(a);
    b = floor(b);
}

// Schreiben Sie eine Funktion 'shift', die drei per Referenz übergebene Strings 'der Reihe nach' tauscht [...].
void shift(std::string &x, std::string &y, std::string &z)
{
    std::string help{x};
    x = y;
    y = z;
    z = help;
}