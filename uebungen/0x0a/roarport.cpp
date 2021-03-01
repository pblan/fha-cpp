#include <iostream>

// Lambda-Ausdruck
int main()
{
    // Schreiben Sie jeweils einen Lambda-Ausdruck, der
    // drei übergebene double-Werte addiert und zurückgibt.
    auto add_3 = [](double a, double b, double c) -> double { return a + b + c; };
    std::cout << "add_3(1.0, 2.0, 3.5) = " << add_3(1.0, 2.0, 3.5) << std::endl;

    // testet, ob ein übergebener int-Wert in einem Intervall [a,b] liegt (dabei sind a und b lokale Variablen);
    int a{1}, b{5}, x{6};
    auto is_within = [&](int x) -> bool { return (a <= x && x <= b); };

    std::cout << x << " ist " << (is_within(x) ? "" : "nicht ") << "in [" << a << "," << b << "]" << std::endl;

    // keine Argumente hat, aber eine lokale int-Variable z auf -z setzt (akademisches Bsp.).
    int z{3};
    auto neg_z = [&]() -> void { z *= -1; };

    std::cout << "z = " << z << std::endl;
    neg_z();
    std::cout << "z = " << z << std::endl;
}