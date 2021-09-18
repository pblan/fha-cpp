#include <functional>
#include <iostream>

// Definieren Sie einen Funktionszeigertyp für eine Funktion, die zwei ints x, y
// bekommt und einen double zurückgibt.
typedef double (*funktion_t)(int x, int y);
// using funktion_t = double (*)(int x, int y);

// Implementieren Sie eine (klassische) Funktion Q, die aus übergebenen Werten x
// und y den Wert x/y berechnet.
double Q(int x, int y) { return 1.0 * x / y; };

// Funktionszeiger, function
int main() {
  // Initialisieren Sie einen Funktionszeiger mit Q und rufen Q über diesen auf.
  funktion_t Q_ptr{Q};
  std::cout << Q_ptr(1, 2) << std::endl;

  // Verwenden Sie statt des Funktionszeigertyps das Template function.
  std::function<double(int, int)> Q_template{Q};
  std::cout << Q_template(1, 2) << std::endl;

  // Erweiterung:
  // Definieren Sie einen Funktionszeiger direkt, d.h. analog zu oben, aber ohne
  // Verwendung Ihrer Typdefinition und ohne das Template function.
  double (*Q_direct)(int, int){Q};
  std::cout << Q_direct(1, 2) << std::endl;
};