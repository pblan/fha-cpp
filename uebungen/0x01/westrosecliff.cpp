#include <iostream>

int main() {
  // Lesen Sie eine ganze Zahl 'n' vom Typ 'int' ...
  int n; // (A)
  std::cout << "Ëingabe n (int)" << std::endl;
  std::cin >> n;

  // und ein Zeichen 'c' vom Typ 'char' ein.
  char c; // (A)
  std::cout << "Ëingabe c (char)" << std::endl;
  std::cin >> c;

  // Testen Sie, ob die Zahl 'n' größer als 0 ist ...
  bool is_n_greater_than_0 = n > 0;

  // ... und ob das Zeichen 'c' ein Großbuchstabe ist.
  bool is_c_a_uppercase_letter = c >= 'A' && c <= 'Z';

  // Definieren Sie bool'sche Variablen mit den Testergebnissen und geben diese
  // aus.

  // Erweiterung:
  // Nutzen Sie einmal, wenn möglich, den '?'-Operator anstelle einer
  // if-Abfrage.
  if (is_n_greater_than_0) {
    std::cout << "n ist größer als 0" << std::endl;
  } else {
    std::cout << "n ist kleiner als 0" << std::endl;
  }

  std::cout << c << " ist" << (is_c_a_uppercase_letter ? " " : "nicht ")
            << "ein Großbuchstabe" << std::endl;

  return 0;
}

/* Kommentierung
 *
 * (A)  Variablennamen sollten zur Lesbarkeit stets aus mindestens drei Zeichen
 *      bestehen. Es gibt natürlich Namen, die generell verstanden werden, wie
 *      z.B. 'os' (Output Stream), 'st' (Stack), ...
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/readability-identifier-length.html
 */