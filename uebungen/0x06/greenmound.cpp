#include <cstdint>
#include <iostream>

size_t mem_alloc{0}; // (A)

size_t length(const char *str);
char *copy(const char *str);
void free(const char *str);

// new, Felder, C-Strings
int main() {
  // Schreiben Sie Testcode, der Worte kopiert und ausgibt.
  const char *str_a{copy("Dies")};
  const char *str_b{copy("ist")};
  const char *str_c{copy("ein")};
  const char *str_d{copy("Test")};

  std::cout << str_a << " " << str_b << " " << str_c << " " << str_d
            << std::endl;

  free(str_a);
  free(str_b);
  free(str_c);
  free(str_d);
}

// Programmieren Sie eine Funktion 'copy', die einen C-String als Parameter
// erhält, dynamischen Speicher mit 'snew' anfordert, den übergebenen C-String
// dorthin inkl. des Null-Zeichens kopiert und den Zeiger auf den neuen Speicher
// zurückgibt.
char *copy(const char *str) {
  size_t len{length(str) + 1};
  char *ptr = new char[len];
  mem_alloc += len;

  for (size_t i = 0; i < len; i++) {
    ptr[i] = str[i];
  }

  return ptr;
}

// Ermitteln Sie die Länge mit Hilfe einer eigenen Funktion.
size_t length(const char *str) {
  size_t count{0};
  while (*(str + count) != '\0') {
    count++;
  }
  return count;
}

// Erweiterung:
// Schreiben Sie eine Funktion 'free' zum Freigeben des zuvor reservierten
// Speichers und nutzen Sie sie.
void free(const char *str) {
  size_t len{length(str) + 1};
  mem_alloc -= len;
  delete[] str; // (B)
}

// Testen Sie ggf. mit Tools wie valgrind, ob Ihr Code Speicherlecks enthält.

/*
$ valgrind ./greenmound.out
[...]

==21249== HEAP SUMMARY:
==21249==     in use at exit: 0 bytes in 0 blocks
==21249==   total heap usage: 6 allocs, 6 frees, 73,746 bytes allocated
==21249==
==21249== All heap blocks were freed -- no leaks are possible
*/

/* Kommentierung
 *
 * (A)  In der Regel sollten globale Variablen nicht non-const sein.
 *
 *      Siehe dazu auch:
 * https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Ri-global
 *
 * (B)  Es ist wichtig, den richtigen Deallocator für die jeweilige Operation zu
 *      nutzen: malloc / free, new / delete, new[] / delete[]
 *
 *      Siehe dazu auch:
 * https://stackoverflow.com/a/24405905/9055591
 */