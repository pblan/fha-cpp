#include <iostream>

int fib_iter(int n);
int fib_rec(int n);

// Berechnung der Fibonacci-Folge (f_i):
int main() {
  // Lesen Sie eine ganze Zahl 'n' von der Konsole ein.
  int n;
  std::cout << "Eingabe n (int): " << std::endl;
  std::cin >> n;

  // Berechnen Sie die ersten 'n' Fibonaccizahlen f_i iterativ, d.h. in einer
  // Schleife (also nicht rekursiv) und geben Sie sie aus. Die Vorschrift
  // lautet: f_i = f_{i-1} + f_{i-2} mit f_0 = f_1 = 1
  std::cout << "f_n (iterativ): " << fib_iter(n) << std::endl;

  // Erweiterung:
  // Berechnen Sie die Zahlen f_i jeweils rekursiv.
  std::cout << "f_n (rekursiv): " << fib_rec(n) << std::endl;

  // Überlegen Sie: Welcher Ansatz ist (vermutlich) schneller und warum?
  return 0;
}

int fib_iter(int n) {
  if (n == 0 || n == 1) { // (A)
    return 1;
  }

  int fi{0}; // (B)
  int fi_minus_1{1};
  int fi_minus_2{1};

  while (n > 1) {
    fi = fi_minus_1 + fi_minus_2;
    fi_minus_2 = fi_minus_1;
    fi_minus_1 = fi;
    --n;
  }
  return fi;
}

int fib_rec(int n) { return n <= 1 ? 1 : fib_rec(n - 1) + fib_rec(n - 2); }

/* Kommentierung
 *
 * (A)  Für die Lesbarkeit sollte man auch für einzeilige Statement-Bodies die
 *      geschweiften Klammern nicht weglassen.
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/readability-braces-around-statements.html
 *
 *
 * (B)  Die Variable 'fi' hätte hier auch noch nicht deklariert werden können.
 *      In komplizierteren Fällen könnte es aber sein, dass das Nutzen
 *      einer nicht-deklarierten Variable zu undefiniertem Verhalten führt.
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/cppcoreguidelines-init-variables.html
 *
 */