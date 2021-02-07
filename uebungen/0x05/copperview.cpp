#include <iostream>

// Variablen über Zeiger modifizieren.
int main()
{
    // Legen Sie eine 'int'- und eine 'float'-Variable an und initialisieren Sie sie mit beliebigen Werten.
    int a{5};
    float b{3.5};

    // Legen Sie zwei Zeiger an und initialisieren Sie sie so, dass sie jeweils auf diese beiden Variablen zeigen.
    int *ap = &a;
    float *bp = &b;

    std::cout << "ap: " << ap << ", *ap: " << *ap << ", a: " << a << std::endl;
    std::cout << "bp: " << bp << ", *bp: " << *bp << ", b: " << b << std::endl;

    // Verändern Sie die Werte der Variablen mit Hilfe der Zeiger.
    *ap += 1;
    *bp *= 2;

    // Geben Sie jeweils den Zeiger, den Wert auf den er zeigt und die zugehörige Variable aus.
    std::cout << "ap: " << ap << ", *ap: " << *ap << ", a: " << a << std::endl;
    std::cout << "bp: " << bp << ", *bp: " << *bp << ", b: " << b << std::endl;

    // Erweiterung:
    // Legen Sie einen Zeiger auf den Zeiger auf 'int' an, initialisieren Sie ihn mit der Adresse Ihres 'int'-Zeigers und geben Sie den Wert der 'int'-Variablen hierüber aus.
    int **app = &ap;
    std::cout << "app: " << app << ", *app: " << *app << ", **app: " << **app << std::endl;
}