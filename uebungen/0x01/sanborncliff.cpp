#include <iostream>

void copy(double arr_a[], double arr_b[], int dim);

int main() {
  const int dim{3};

  // Legen Sie ein Array der Länge 3 vom Typ 'double' an und initialisieren Sie
  // die ersten beiden Elemente mit den Werten 1.0 und 2.0.
  double arr_a[dim]{1.0, 2.0}; // (A)

  // Speichern Sie die Summe in dem dritten Element.
  arr_a[2] = arr_a[0] + arr_a[1]; // (B)

  // Geben Sie alle Elemente aus.
  std::cout << "arr: ";
  for (size_t i{0}; i < dim; ++i) {
    std::cout << arr_a[i] << " ";
  }
  std::cout << std::endl;

  // Legen Sie ein weiteres Array der gleichen Größe an und kopieren Sie das
  // erste in das zweite Array.
  double arr_b[dim];
  for (size_t i = 0; i < dim; ++i) {
    arr_b[i] = arr_a[i];
  }

  return 0;
}

// Erweiterung:
// Übergeben Sie das Feld einer Funktion zur Ausgabe.
// Beachten Sie, dass Sie die Länge mit übergeben müssen.

void copy(const double arr_a[], double arr_b[], int dim) {
  for (size_t i = 0; i < dim; ++i) {
    arr_b[i] = arr_a[i];
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
