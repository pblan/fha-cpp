#include <iostream>

// Eine Klasse 'kontakt' mit Alter und Namen entwerfen.
class kontakt
{
private:
    std::string name_;
    unsigned int alter_;

public:
    // Implementieren Sie einen default-ctor und dtor.
    kontakt()
        : name_{}, alter_{} {};
    ~kontakt() = default;

    // Implementieren Sie einen ctor, der ein ganzzahliges Alter vom Typ 'unsigned int' und einen Namen vom Typ 'string' übergeben bekommt.
    // Nutzen Sie ':' zur Initialisierung.
    kontakt(const std::string &name, unsigned int alter)
        : name_{name}, alter_{alter} {};

    // Implementieren Sie 'getter' und 'setter'.
    std::string name() const { return name_; };
    unsigned int alter() const { return alter_; };
    void set_name(const std::string &name) { name_ = name; };
    void set_alter(unsigned int alter) { alter_ = alter; };

    // Erweiterung:
    // Implementieren Sie einen copy-ctor.
    kontakt(const kontakt &k) = default;
};

// Implementieren Sie einen operator '<<' zur Ausgabe.
std::ostream &operator<<(std::ostream &os, const kontakt &k)
{
    os << "Name: " << k.name() << " (" << k.alter() << ")";
    return os;
}

int main()
{
    // Schreiben Sie aussagekräftigen Testcode.
    kontakt k1;
    kontakt k2("k2", 2);
    kontakt k3{k2};

    std::cout << k1 << std::endl;
    std::cout << k2 << std::endl;
    std::cout << k3 << std::endl;

    k1.set_name("k1");
    k1.set_alter(1);
    k3.set_name("k3");
    k3.set_alter(3);

    std::cout << k1 << std::endl;
    std::cout << k2 << std::endl;
    std::cout << k3 << std::endl;

    const kontakt &rk{k1};
    unsigned int alter{rk.alter()};
    std::string name{rk.name()};
    std::cout << "Name: " << name << ", Alter: " << alter << std::endl;
}