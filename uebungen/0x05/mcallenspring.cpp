#include <iostream>

// Illegal - beachten Sie auch das Snippet zum Thema...
int main()
{
    // Versuchen Sie, durch Verwendung von Zeigern einzelne Bytes von lokalen 'int'-Variablen zu manipulieren.
    int a{0x12345678};
    int *ap{&a};

    // Nutzen Sie dafür casts in 'char*'.
    char *cp{(char *)&a};

    std::cout << "a: " << std::hex << a << std::endl;
    std::cout << "+cp[0]: " << +cp[0] << std::endl;
    std::cout << "+cp[1]: " << +cp[1] << std::endl;
    std::cout << "+cp[2]: " << +cp[2] << std::endl;
    std::cout << "+cp[3]: " << +cp[3] << std::endl;

    // Verändern Sie einzelne Bytes eines Texts der Form: char* p = "huhu";
    // Was passiert?
    cp[0] = 0x00;
    cp[1] = 0x11;

    std::cout << "a: " << std::hex << a << std::endl;
    std::cout << "+cp[0]: " << +cp[0] << std::endl;
    std::cout << "+cp[1]: " << +cp[1] << std::endl;
    std::cout << "+cp[2]: " << +cp[2] << std::endl;
    std::cout << "+cp[3]: " << +cp[3] << std::endl;

    // Erweiterung:
    // Versuchen Sie, über Zeiger-Manipulationen lokale Variablen gezielt auf dem Stack zu verändern, ohne diese direkt zu adressieren.
    int i{1}, j{2};

    // Tipp: Ermitteln Sie zunächst die Adresse einer lokalen Variablen.
    // Die anderen liegen 'in der Nähe'.
    int *ip{&i};

    std::cout << "i: " << i << ", j: " << j << std::endl;
    *(ip + 1) = 3;
    std::cout << "i: " << i << ", j: " << j << std::endl;
}