#include <iostream>
#include <stdexcept>

const int dim = 4;

// Überführen Sie die Struktur 'polynom' aus Übung 'Elkford' in eine Klasse
// 'polynom'.
class polynom {
private:
public:
  double coeffs[dim]; // (A)

  // Überführen Sie die Funktion 'eval' in eine Memberfunktion.
  double eval(double x) const {
    double res{0.0};
    for (int i = dim - 1; i >= 1; --i) {
      res = x * (coeffs[i] + res);
    }
    res += coeffs[0];
    return res;
  }

  // Implementieren Sie eine Memberfunktion 'at', die einen Index 'i' übergeben
  // bekommt und den i'ten Koeffizienten zurückgibt. Werfen Sie eine Ausnahme,
  // falls 'i' ungültig ist.
  double at(size_t i) const {
    if (i >= dim) {
      throw std::invalid_argument("invalid index");
    }
    return coeffs[i];
  }
};

std::ostream &operator<<(std::ostream &os, const polynom &pol) {
  os << pol.coeffs[0] << "+" << pol.coeffs[1] << "x"
     << "+" << pol.coeffs[2] << "x^2";
  return os;
}

// Erweiterung:
// Implementieren Sie eine globale Funktion 'add', um zwei Polynome zu addieren
// und geben Sie das Ergebnis zurück.
polynom add(const polynom &polynom1, const polynom &polynom2) {
  polynom res{};
  for (size_t i = 0; i < dim; i++) {
    res.coeffs[i] = polynom1.at(i) + polynom2.at(i);
  }
  return res;
}

int main() {
  // Nutzen Sie den Testcode aus 'Elkford' und testen Sie zusätzlich mit der
  // Dimension 4.
  polynom pol_p{2.0, 3.0, 4.0, 5.0};

  std::cout << "pol_p: " << pol_p << std::endl;
  std::cout << "pol_p.eval(4.0): " << pol_p.eval(4.0) << std::endl;

  polynom pol_q1{4.0, 5.0, 6.0};
  polynom pol_q2{1.0, 2.0, 3.0};

  std::cout << "pol_q1: " << pol_q1 << std::endl;
  std::cout << "pol_q2: " << pol_q2 << std::endl;

  polynom pol_q = add(pol_q1, pol_q2);

  std::cout << "pol_q = pol_q1 + pol_q2: " << pol_q << std::endl;

  try { // (B)
    double coeff_start{pol_p.at(0)};
    std::cout << "coeff_start: " << coeff_start << std::endl;
    double coeff_end{pol_p.at(dim)};
    std::cout << "coeff_end: " << coeff_end << std::endl;
  } catch (const std::invalid_argument &e) {
    std::cout << e.what() << std::endl;
  }
}

/* Kommentierung
 *
 * (A)  Data Members sollten in der Regel als private deklariert werden. Für den
 * Zugriff sollten Memberfunktionen genutzt werden.
 * Zum jetzigen Zeitpunkt ist das aber nötig, da der Ausgabeoperator auf coeffs
 * zugreifen muss. Mehr dazu später bei dem Keyword `friend`.
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/misc-non-private-member-variables-in-classes.html
 *
 * (B)  dtors, move-ctors, move-assignment Operatoren, main(), swap(),
 * Funktionen mit throw() oder noexcept sollten keine Exceptions werfen. Das
 * könnte zu undefiniertem Verhalten führen; ein gutes Beispiel wäre eine
 * Exception in einem dtor, wodurch Objekte potentiell nicht richtig abgeräumt
 * werden können.
 * Wenn man natürlich gründlich alle Exceptions fängt, braucht man sich
 * diesbezüglich natürlich keine Sorgen machen.
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/bugprone-exception-escape.html
 */