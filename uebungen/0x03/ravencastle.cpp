#include <iostream>

// Eine Klasse 'bruch' ('fraction') entwerfen.
// Verwenden Sie so oft wie möglich 'const'.
class fraction {
private:
  int num_{};   // numerator
  int denom_{}; // denominator

public:
  // Implementieren Sie einen default-ctor und einen dtor.
  fraction() = default;  // (A)
  ~fraction() = default; // (B)

  // Implementieren Sie einen ctor, der Zähler und Nenner übergeben bekommt.
  // Nutzen Sie ':' zur Initialisierung.
  fraction(int num, int denom) : num_{num}, denom_{denom} {}; // (C)

  // Implementieren Sie 'getter' und 'setter' für (ganzzahlige) Zähler bzw.
  // Nenner.
  int num() const { return num_; }
  int denom() const { return denom_; }
  void set_num(int num) { num_ = num; }
  void set_denom(int denom) { denom_ = denom; }

  // Erweiterung:
  // Implementieren Sie einen copy-ctor.
  fraction(const fraction &frac) = default;
};

// Implemetieren Sie einen operator '<<' zur Ausgabe.
std::ostream &operator<<(std::ostream &os, const fraction &frac) {
  os << frac.num() << "/" << frac.denom();
  return os;
}

int main() {
  // Schreiben Sie aussagekräftigen Testcode.
  fraction frac1;
  fraction frac2{2, 3};
  fraction frac3{frac2};

  std::cout << frac1 << std::endl;
  std::cout << frac2 << std::endl;
  std::cout << frac3 << std::endl;

  frac1 = fraction{1, 2};
  frac3 = fraction{5, 6};

  std::cout << frac1 << std::endl;
  std::cout << frac2 << std::endl;
  std::cout << frac3 << std::endl;

  const fraction &fracref{frac1};
  int num{fracref.num()};
  int denom{fracref.denom()};
  std::cout << "num: " << num << ", denom" << denom << std::endl;
}

/* Kommentierung
 *
 * (A)  Natürlich würde ein ctor der Form `fraction() : num_{}, denom_{} {};`
 * das gleiche tun, wie der explizite default-ctor.
 * Es gibt allerdings einige (hier nicht weiter behandelte) Unterschiede.
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/modernize-use-default-member-init.html
 * https://stackoverflow.com/questions/20828907/the-new-syntax-default-in-c11
 *
 * (B)  Wenn eine Klasse einen nutzerdefinierten dtor, copy-ctor oder
 * copy-operator (später) benötigt, ist es in den allermeisten Fällen sinnvoll
 * alle drei zu definieren.
 *
 *      Siehe dazu auch:
 * https://en.cppreference.com/w/cpp/language/rule_of_three
 *
 * (C)  Mehrere Parameter des gleichen Typs können beim Funktionsaufruf leicht
 * vertauscht werden. Alternativ sollte man type-safe Konstrukte nutzen, wie
 * z.B. typedefs oder structs.
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/bugprone-easily-swappable-parameters.html
 */