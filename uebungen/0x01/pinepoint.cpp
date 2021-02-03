#include <iostream>

bool isPrim(int n);

int main()
{
    // Primzahlberechnung:
    // Lesen Sie eine ganze Zahl 'n' von der Konsole ein.
    int n;
    std::cout << "Ëingabe n (int)" << std::endl;
    std::cin >> n;

    // Bestimmen Sie in einer Schleife über alle Zahlen 2 bis 'n', ob die jeweilige Zahl eine Primzahl ist oder nicht.
    // Geben Sie die jeweilige Zahl aus, wenn sie eine Primzahl ist.

    bool is_not_prim = false;
    for (size_t i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            is_not_prim = true;
            break;
        }
    }
    std::cout << n << (!is_not_prim ? " ist Prim!" : " ist nicht Prim.") << std::endl;

    std::cout << n << (isPrim(n) ? " ist Prim!" : " ist nicht Prim.") << std::endl;

    return 0;
}

// Erweiterung:
// Schreiben Sie eine Funktion 'isPrim', die eine Zahl übergeben bekommt und 'true' oder 'false' zurück gibt.
// Definieren Sie die Funktion 'isPrim' nach 'main' und geben Sie vor 'main' nur die Signatur an.

bool isPrim(int n)
{
    bool is_not_prim = false;
    for (size_t i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            is_not_prim = true;
            break;
        }
    }
    return !is_not_prim;
}