#include <iostream>

int pot(int b, int n);

int main()
{
    // Berechnung von b^n:
    // Lesen Sie Variablen 'b' und 'n' eines geeigneten Typs ein.
    int b{0}, n{0}, res{1};
    std::cout << "Eingabe b (int): " << std::endl;
    std::cin >> b;
    std::cout << "Eingabe n (int): " << std::endl;
    std::cin >> n;

    // Berechnen Sie 'b hoch n' in einer Schleife und geben Sie das Ergebnis aus.
    for (int i = 0; i < n; ++i)
    {
        res *= b;
    }
    std::cout << "b^n (for):" << res << std::endl;

    // Erweiterung:
    // Schreiben Sie eine Funktion 'pot', die 'b' und 'n' übergeben bekommt und das Ergebnis zurückgibt.
    // Definieren Sie die Funktion 'pot' erst hinter main und geben Sie vor 'main' nur die Signatur an.
    // Formulieren Sie die Schleife einmal als 'for' und einmal als 'while'-Schleife.

    std::cout << "b^n (while):" << pot(b, n) << std::endl;
    return 0;
}

int pot(int b, int n)
{
    int res{b};
    while (n > 1)
    {
        res *= b;
        --n;
    }
    return res;
}