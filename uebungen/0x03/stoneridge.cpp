#include <iostream>

// Eine Klasse 'punkt' mit 'x'- und 'y'-Koordinate entwerfen.
// Verwenden Sie so oft wie möglich 'const'.
class punkt {
private:
  double x_{};
  double y_{};

public:
  // Implementieren Sie einen default-ctor und einen dtor.
  punkt() = default;  // (A)
  ~punkt() = default; // (B)

  // Implementieren Sie einen weiteren ctor, der einen x- und einen y-Wert vom
  // Typ 'double' übergeben bekommt. Benutzen Sie ':' zur Initialisierung.
  punkt(double x, double y) : x_{x}, y_{y} {}; // (C)

  // Implementieren Sie 'getter' und 'setter' für 'x' und 'y'.
  double x() const { return x_; };
  double y() const { return y_; };
  void set_x(double x) { x_ = x; }
  void set_y(double y) { y_ = y; }

  // Erweiterung:
  // Implementieren Sie einen copy-ctor.
  punkt(const punkt &p) = default;
};

// Implementieren Sie einen operator '<<' zur Ausgabe.
std::ostream &operator<<(std::ostream &os, const punkt &p) {
  os << "(" << p.x() << ", " << p.y() << ")";
  return os;
}

int main() {
  // Schreiben Sie aussagekräftigen Testcode.
  punkt punkt1;
  punkt punkt2(3.3, 4.4);
  punkt punkt3{punkt2};

  std::cout << punkt1 << std::endl;
  std::cout << punkt2 << std::endl;
  std::cout << punkt3 << std::endl;

  punkt1.set_x(1.1);
  punkt1.set_y(2.2);

  punkt3.set_x(5.5);
  punkt3.set_y(6.6);

  std::cout << punkt1 << std::endl;
  std::cout << punkt2 << std::endl;
  std::cout << punkt3 << std::endl;

  const punkt &punktref{punkt1};
  double x{punktref.x()};
  double y{punktref.y()};

  std::cout << "x: " << x << ", y: " << y << std::endl;
}

/* Kommentierung (analog zu Ravencastle)
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