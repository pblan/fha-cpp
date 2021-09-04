#include <array>
#include <iostream>
#include <vector>

// Definieren Sie einen eigenen Typ 'it_type' als 'const_iterator' des Vektors
// und [...] Beachten Sie: '*it' ist der Wert des Elements und 'cbegin' und
// 'cend' geben einen const_iterator zurück.
typedef std::vector<int>::const_iterator it_type; // (A)

// Erweitern Sie Übung 'Oakberg'.
int main() {
  std::array<int, 4> a{2, 3, 5, 7};

  std::cout << "std::array a: ";

  std::string delim{};
  for (auto val : a) {
    std::cout << delim << val;
    delim = ", ";
  }
  std::cout << std::endl;

  std::vector<int> v{2, 3, 5, 7};

  std::cout << "std::vector v: ";

  delim = "";
  for (auto val : v) {
    std::cout << delim << val;
    delim = ", ";
  }
  std::cout << std::endl;

  // Nutzen Sie 'auto&' in der 'range-based-for'-Schleife über den 'vector' 'v'
  // und verdoppeln Sie den Wert jedes Elements.
  for (auto &val : v) {
    val *= 2;
  }

  std::cout << "std::vector v: ";
  delim = "";
  for (auto val : v) {
    std::cout << delim << val;
    delim = ", ";
  }
  std::cout << std::endl;

  std::cout << "std::vector v (it_type): ";
  delim = "";

  // [...] geben Sie in einer Schleife über einen const_iterator 'it' das
  // jeweilige Element des Iterators aus.
  for (it_type it = v.cbegin(); it != v.cend(); it++) { // (B)
    std::cout << delim << *it;
    delim = ", ";
  }
  std::cout << std::endl;
}

/* Kommentierung
 *
 * (A)  Seit C++11 wird es empfohlen, statt `typedef` das Keyword `using` zu
 * nutzen. Eine "alias-declaration" mit `using` würde in diesem Fall so
 * aussehen: `using it_type = std::vector<int>::const_iterator;` Neben der
 * verbesserten Lesbarkeit hat die Alternative mit `using` auch Vorteile beim
 * Nutzen von Alias Templates.
 *
 *      Siehe dazu auch:
 * https://www.nextptr.com/tutorial/ta1193988140/how-cplusplus-using-or-aliasdeclaration-is-better-than-typedef
 * https://clang.llvm.org/extra/clang-tidy/checks/modernize-use-using.html
 *
 * (B)  Auch hier wäre in der Praxis wieder eine range-based for-Schleife zu
 * bevorzugen.
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/modernize-loop-convert.html
 */