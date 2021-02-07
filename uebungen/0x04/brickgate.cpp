#include <iostream>
#include <vector>
#include <array>

// Definieren Sie einen eigenen Typ 'it_type' als 'const_iterator' des Vektors und [...]
// Beachten Sie: '*it' ist der Wert des Elements und 'cbegin' und 'cend' geben einen const_iterator zurück.
typedef std::vector<int>::const_iterator it_type;

// Erweitern Sie Übung 'Oakberg'.
int main()
{
    std::array<int, 4> a{2, 3, 5, 7}; //int a[4] = {2, 3, 5, 7};
    std::cout << "std::array a: ";
    std::string delim{};
    for (auto x : a)
    {
        std::cout << delim << x;
        delim = ", ";
    }
    std::cout << std::endl;

    std::vector<int> v{2, 3, 5, 7};
    std::cout << "std::vector v: ";
    delim = "";
    for (auto x : v)
    {
        std::cout << delim << x;
        delim = ", ";
    }
    std::cout << std::endl;

    // Nutzen Sie 'auto&' in der 'range-based-for'-Schleife über den 'vector' 'v' und verdoppeln Sie den Wert jedes Elements.
    for (auto &x : v)
    {
        x *= 2;
    }

    std::cout << "std::vector v: ";
    delim = "";
    for (auto x : v)
    {
        std::cout << delim << x;
        delim = ", ";
    }
    std::cout << std::endl;

    std::cout << "std::vector v (it_type): ";
    delim = "";
    // [...] geben Sie in einer Schleife über einen const_iterator 'it' das jeweilige Element des Iterators aus.
    for (it_type it = v.cbegin(); it != v.cend(); it++)
    {
        std::cout << delim << *it;
        delim = ", ";
    }
    std::cout << std::endl;
}