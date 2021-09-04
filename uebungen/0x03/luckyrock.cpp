#include <iostream>

// Eine Klasse 'kontakt' mit Alter und Namen entwerfen.
class kontakt {
private:
  std::string name_{};
  unsigned int alter_{};

public:
  // Implementieren Sie einen default-ctor und dtor.
  kontakt() = default;
  ~kontakt() = default;

  // Implementieren Sie einen ctor, der ein ganzzahliges Alter vom Typ 'unsigned
  // int' und einen Namen vom Typ 'string' übergeben bekommt. Nutzen Sie ':' zur
  // Initialisierung.
  kontakt(const std::string &name, unsigned int alter) // (A)
      : name_{name}, alter_{alter} {};

  // Implementieren Sie 'getter' und 'setter'.
  std::string name() const { return name_; };
  unsigned int alter() const { return alter_; };
  void set_name(const std::string &name) { name_ = name; };
  void set_alter(unsigned int alter) { alter_ = alter; };

  // Erweiterung:
  // Implementieren Sie einen copy-ctor.
  kontakt(const kontakt &kon) = default;
};

// Implementieren Sie einen operator '<<' zur Ausgabe.
std::ostream &operator<<(std::ostream &os, const kontakt &kon) {
  os << "Name: " << kon.name() << " (" << kon.alter() << ")";
  return os;
}

int main() {
  // Schreiben Sie aussagekräftigen Testcode.
  kontakt kontakt1;
  kontakt kontakt2("kontakt2", 2);
  kontakt kontakt3{kontakt2};

  std::cout << kontakt1 << std::endl;
  std::cout << kontakt2 << std::endl;
  std::cout << kontakt3 << std::endl;

  kontakt1.set_name("kontakt1");
  kontakt1.set_alter(1);
  kontakt3.set_name("kontakt3");
  kontakt3.set_alter(3);

  std::cout << kontakt1 << std::endl;
  std::cout << kontakt2 << std::endl;
  std::cout << kontakt3 << std::endl;

  const kontakt &kontaktref{kontakt1};
  unsigned int alter{kontaktref.alter()};
  std::string name{kontaktref.name()};
  std::cout << "Name: " << name << ", Alter: " << alter << std::endl;
}

/* Kommentierung
 *
 * (A)  Mit der Einführung von `std::move` ist es (oft) effizienter ein Argument
 * per Value zu übergeben, statt einer const-reference, und dann zu kopieren.
 * Bei std::string ist es auf jeden Fall zu bevorzugen, spielt hier in der
 * Vorlesung aber eine geringere Rolle.
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/modernize-pass-by-value.html
 */