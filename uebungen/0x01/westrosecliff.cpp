#include <iostream>

int main()
{
    // Lesen Sie eine ganze Zahl 'n' vom Typ 'int' und ein Zeichen 'c' vom Typ 'char' ein.
    int n;
    std::cout << "Ëingabe n (int)" << std::endl;
    std::cin >> n;

    char c;
    std::cout << "Ëingabe c (char)" << std::endl;
    std::cin >> c;

    // Testen Sie, ob die Zahl 'n' größer als 0 ist und ob das Zeichen 'c' ein Großbuchstabe ist.
    // Definieren Sie bool'sche Variablen mit den Testergebnissen und geben diese aus.

    bool is_positive = n > 0;
    bool is_capital = (int)c >= (int)'A' && (int)c <= (int)'Z';

    std::cout << "n ist groesser 0: " << (is_positive ? "Ja" : "Nein") << std::endl;
    std::cout << "c ist Grossbuchstabe: " << (is_capital ? "Ja" : "Nein") << std::endl;

    // Erweiterung:
    // Nutzen Sie einmal, wenn möglich, den '?'-Operator anstelle einer if-Abfrage.

    return 0;
}