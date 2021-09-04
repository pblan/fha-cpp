#include <array>
#include <iostream>
#include <vector>

// Datencontainer 'range-based-for' durchlaufen und 'auto' verwenden.
int main() {
  // Definieren Sie ein 'int'-Feld 'a', initialisiert mit den Werten 2, 3, 5, 7,
  // ...
  std::array<int, 4> a{2, 3, 5, 7}; // int a[4] = {2, 3, 5, 7};
  // ... sowie einen 'vector' 'v', initialisiert mit den selben Werten.
  std::vector<int> v{2, 3, 5, 7};

  // Durchlaufen Sie 'a' und 'v' jeweils in einer 'range-based-for'-Schleife mit
  // 'auto' und geben Sie das jeweilige Element aus.

  std::cout << "std::array a: ";

  std::string delim{};
  for (auto x : a) {
    std::cout << delim << x;
    delim = ", ";
  }
  std::cout << std::endl;

  std::cout << "std::vector v: ";

  delim = "";
  for (auto x : v) {
    std::cout << delim << x;
    delim = ", ";
  }
  std::cout << std::endl;
}