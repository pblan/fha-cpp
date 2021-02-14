#include <iostream>

// C-String
int main()
{
    // Legen Sie einen C-String mit einem beliebigen Text an: char* str = "hallo";
    const char *str{"hallo"};

    // Legen Sie einen Zeiger auf char an und laufen Sie mit diesem durch das Feld str (einschließlich des Null-Zeichens),
    // um den jeweiligen Charakter, auf den der Zeiger zeigt, auszugeben.
    const char *ptr{str};

    // Geben Sie den jeweils aktuellen Charakter einmal als Charakter und einmal als ASCII Wert aus.
    // Tipp: (int)-cast für den ASCII-Wert.

    // Erweiterung:
    // Geben Sie zusätzlich auch den Wert des Zeigers, d.h. die Adresse aus.
    // Tipp: Geeigneter Cast.
    do
    {
        std::cout << (void *)ptr << ": " << *ptr << " [ASCII: " << (int)*ptr << "]" << std::endl;
    } while (*(ptr++) != '\0');
}