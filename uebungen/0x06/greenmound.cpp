#include <iostream>

long mem_alloc{0};

size_t length(const char *s);
char *copy(const char *s);
void free(const char *s);

// new, Felder, C-Strings
int main()
{
    // Schreiben Sie Testcode, der Worte kopiert und ausgibt.
    const char *a{copy("Dies")}, *b{copy("ist")}, *c{copy("ein")}, *d{copy("Test")};
    std::cout << a << " " << b << " " << c << " " << d << std::endl;
    free(a);
    free(b);
    free(c);
    free(d);
}

// Programmieren Sie eine Funktion 'copy', die einen C-String als Parameter erhält,
// dynamischen Speicher mit 'new' anfordert, den übergebenen C-String dorthin inkl. des Null-Zeichens kopiert
// und den Zeiger auf den neuen Speicher zurückgibt.
char *copy(const char *s)
{
    size_t l{length(s) + 1};
    char *ptr = new char[l];
    mem_alloc += l;

    for (size_t i = 0; i < l; i++)
    {
        ptr[i] = s[i];
    }

    return ptr;
}

// Ermitteln Sie die Länge mit Hilfe einer eigenen Funktion.
size_t length(const char *s)
{
    size_t cnt{0};
    while (*(s + cnt) != '\0')
    {
        cnt++;
    }
    return cnt;
}

// Erweiterung:
// Schreiben Sie eine Funktion 'free' zum Freigeben des zuvor reservierten Speichers und nutzen Sie sie.
// Testen Sie ggf. mit Tools wie valgrind, ob Ihr Code Speicherlecks enthält.
void free(const char *s)
{
    size_t l{length(s) + 1};
    mem_alloc -= l;
    delete s;
}