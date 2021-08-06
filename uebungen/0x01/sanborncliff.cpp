#include <iostream>

void copy(double a[], double b[], int dim);

int main() {
  const int dim{3};

  // Legen Sie ein Array der Länge 3 vom Typ 'double' an und initialisieren Sie
  // die ersten beiden Elemente mit den Werten 1.0 und 2.0.
  double a[dim]{1.0, 2.0}; // (A)

  // Speichern Sie die Summe in dem dritten Element.
  a[2] = a[0] + a[1]; // (B)

  // Geben Sie alle Elemente aus.
  std::cout << "a: ";
  for (size_t i{0}; i < dim; ++i) {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;

  // Legen Sie ein weiteres Array der gleichen Größe an und kopieren Sie das
  // erste in das zweite Array.
  double b[dim];
  for (size_t i = 0; i < dim; ++i) {
    b[i] = a[i];
  }

  return 0;
}

// Erweiterung:
// Übergeben Sie das Feld einer Funktion zur Ausgabe.
// Beachten Sie, dass Sie die Länge mit übergeben müssen.

void copy(const double a[], double b[], int dim) {
  for (size_t i = 0; i < dim; ++i) {
    b[i] = a[i];
  }
}

/* Kommentierung
 *
 * (A)  Es wird dazu geraten, statt C-style Arrays lieber std::array<> zu
 *      nutzen.
 *
 *      Siehe dazu auch:
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#slcon1-prefer-using-stl-array-or-vector-instead-of-a-c-array

 * (B)  Analog sollte auch auf bound-safe Alternativen zurückgegriffen werden (std::vector<>, std::array<>).

 *     Siehe dazu auch:
 * https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rsl-bounds
 */
