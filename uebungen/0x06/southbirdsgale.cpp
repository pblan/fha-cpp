#include <iostream>

const int dim{4};

void reverse(const char *arr[]);

std::ostream &operator<<(std::ostream &os, const char *arr[]);

// Zeiger, Felder
int main() {
  // Definieren Sie vier Worte 'Dies', 'ist', 'ein', 'Satz' in einem Feld mit
  // vier Zeigern.
  const char *arr[dim] = {"Dies", "ist", "ein", "Satz"};
  std::cout << arr << std::endl;

  // Übergeben Sie dieses Feld von Zeigern einer Funktion, um dort die Worte in
  // umgekehrter Reihenfolge auszugeben.
  reverse(arr);

  // Erweiterung:
  // Drehen Sie die Reihenfolge der Worte in dem Feld vor der Ausgabe um (nicht
  // die Worte selbst).
  // Drehen Sie auch die Worte selbst für die Ausgabe um.
  for (size_t i = 0; i < dim / 2; i++) {
    const char *h{arr[i]};
    arr[i] = arr[dim - 1 - i];
    arr[dim - 1 - i] = h;
  }
  reverse(arr);
}

std::ostream &operator<<(std::ostream &os, const char *arr[]) {
  os << "[";
  std::string delim;
  for (size_t i = 0; i < dim; i++) {
    os << delim << arr[i];
    delim = ", ";
  }
  os << "]";
  return os;
}

void reverse(const char *arr[]) {
  std::string delim;
  for (int i = dim - 1; i >= 0; i--) {
    std::cout << delim << arr[i];
    delim = " ";
  }
  std::cout << std::endl;
}
