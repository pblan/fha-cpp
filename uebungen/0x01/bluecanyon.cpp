#include <iostream>

int pot(int base, int pow);

// Berechnung von b^n:
int main() {
  // Lesen Sie Variablen 'b' ...
  int b{0}; // (A)
  int n{0};

  std::cout << "Eingabe b (int): " << std::endl;
  std::cin >> b;

  // ... und 'n' eines geeigneten Typs ein.
  std::cout << "Eingabe n (int): " << std::endl;
  std::cin >> n;

  // Berechnen Sie 'b hoch n' in einer Schleife und geben Sie das Ergebnis aus.
  int res{1};
  for (int i{0}; i < n; ++i) {
    res *= b;
  }
  std::cout << "b^n (for):" << res << std::endl;

  std::cout << "b^n (while):" << pot(b, n) << std::endl;
  return 0;
}

// Erweiterung:
// Schreiben Sie eine Funktion 'pot', die 'b' und 'n' übergeben bekommt und
// das Ergebnis zurückgibt. Definieren Sie die Funktion 'pot' erst hinter main
// und geben Sie vor 'main' nur die Signatur an.
int pot(int base, int pow) {  // (A)
  int res{base};

  // Formulieren Sie die Schleife einmal als 'for' und einmal als
  // 'while'-Schleife.
  while (pow > 1) {
    res *= base;
    --pow;
  }
  return res;
}

/* Kommentierung
 *
 * (A)  Hier wäre es möglich, die Variablen 'b' und 'n' auch direkt in einer
 *      Zeile zu initialisieren.
 *      Für die Lesbarkeit ist es aber zu bevorzugen, die Variablendeklarationen
 *      zu isolieren.
 *
 *      Siehe dazu auch:
 https://clang.llvm.org/extra/clang-tidy/checks/readability-isolate-declaration.html
 */