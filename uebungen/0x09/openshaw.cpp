#include <iostream>
#include <memory>
#include <vector>
#include <string>

// Entwerfen Sie eine beliebige Klasse und [...]
struct beliebig
{
    std::string name;

    beliebig(std::string name)
        : name{name} {};
};

// unique- und shared-ptr
int main()
{
    // [...] füllen Sie (jeweils) einen std::vector

    // [...] mit Objekten Ihrer Klasse,
    std::vector<beliebig> v1;

    beliebig a1{"a1"}, a2{"a2"}, a3{"a3"};
    v1.push_back(a1);
    v1.push_back(a2);
    v1.push_back(a3);

    std::cout << "v1.size() = " << v1.size() << std::endl;

    for (auto &a : v1)
    {
        std::cout << a.name << std::endl;
    }

    v1.clear();
    std::cout << "v1.size() = " << v1.size() << std::endl;

    // [...] mit (raw) Zeigern auf dynamisch angelegte Objekte Ihrer Klasse, bzw.
    std::vector<beliebig *> v2;

    v2.push_back(new beliebig{"b1"});
    v2.push_back(new beliebig{"b2"});
    v2.push_back(new beliebig{"b3"});

    std::cout << "v2.size() = " << v2.size() << std::endl;

    for (auto &b : v2)
    {
        std::cout << b->name << std::endl;
        delete b;
    }

    v2.clear();
    std::cout << "v2.size() = " << v2.size() << std::endl;

    // [...] mit unique- und shared-ptr auf diese.
    std::vector<std::unique_ptr<beliebig>> v3;

    v3.push_back(std::make_unique<beliebig>("c1"));
    v3.push_back(std::make_unique<beliebig>("c2"));
    v3.push_back(std::make_unique<beliebig>("c3"));

    std::cout << "v3.size() = " << v3.size() << std::endl;

    for (auto &c : v3)
    {
        std::cout << c->name << std::endl;
    }

    v3.clear();
    std::cout << "v3.size() = " << v3.size() << std::endl;

    // Erweiterung:
    // Werden alle Elemente ordnungsgemäß zerstört, oder gibt es Memory Leaks?
    // Können Sie alle Elemente in einer Schleife ausgeben?
};