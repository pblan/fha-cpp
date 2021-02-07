#include <iostream>

void swap_a(double *ap, double *bp);
void swap_b(double &a, double &b);
void swap_ptr(double *&app, double *&bpp);

int main()
{
    // Testen Sie Ihren Code entsprechend.
    double a{1.5}, b{2.5};

    std::cout << "a: " << a << ", b: " << b << std::endl;

    swap_a(&a, &b);
    std::cout << "swap_a(&a, &b);" << std::endl;
    std::cout << "a: " << a << ", b: " << b << std::endl;

    swap_b(a, b);
    std::cout << "swap_b(a, b);" << std::endl;
    std::cout << "a: " << a << ", b: " << b << std::endl;

    double *ap{&a}, *bp{&b};
    std::cout << "ap: " << ap << "*ap: " << *ap << ", bp: " << bp << "*bp: " << *bp << std::endl;

    swap_ptr(ap, bp);
    std::cout << "swap_ptr(ap, bp);" << std::endl;
    std::cout << "ap: " << ap << "*ap: " << *ap << ", bp: " << bp << "*bp: " << *bp << std::endl;
}

// Swap.
// Schreiben Sie eine Funktion 'swap', die zwei übergebene 'double'-Zahlen tauscht.
// Implementieren Sie die Funktionen einmal über Zeiger und einmal über Referenzen.
void swap_a(double *ap, double *bp)
{
    double h{*ap};
    *ap = *bp;
    *bp = h;
}

void swap_b(double &a, double &b)
{
    double h{a};
    a = b;
    b = h;
}

// Erweiterung:
// Schreiben Sie eine weitere Funktion 'swap_ptr', die zwei übergebene 'double'-Zeiger tauscht (Zeiger und Referenzen).
void swap_ptr(double *&app, double *&bpp)
{
    double *h{app};
    app = bpp;
    bpp = h;
}