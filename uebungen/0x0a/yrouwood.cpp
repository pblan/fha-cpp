#include <cmath>
#include <functional>
#include <iostream>

// Schreiben Sie eine Funktion approx, die als Parameter einen Startwert x0,
// eine zu iterierende Funktion f, und ein eps erhält: approx berechnet x=f(x),
// mit x=x0 zu Anfang, solange, bis der neue x-Wert sich vom vorhergehenden um
// weniger als eps unterscheidet.
double approx_with_ptr(double x0, double (*f)(double), double eps) {
  double x_new = f(x0);
  if (std::abs(x_new - x0) < eps) {
    return x0;
  }
  // Geben Sie den letzten berechneten Wert zurück.
  return approx_with_ptr(x_new, f, eps);
};

// Nutzen Sie einmal Funktionszeiger und einmal das Template function in der
// Definition von approx.
double approx_with_template(double x0, std::function<double(double)> f,
                            double eps) {
  double x_new = f(x0);
  if (std::abs(x_new - x0) < eps) {
    return x0;
  }
  // Geben Sie den letzten berechneten Wert zurück.
  return approx_with_template(x_new, f, eps);
};

double heron100(double x) { return 0.5 * (x + (100 / x)); }

// Funktionszeiger, lambda-Ausdruck
int main() {
  double eps{1e-10};
  // Testen Sie approx für das Heron-Verfahren (Wurzel-Berechnung, siehe
  // Wikipedia; zunächst für feste a);
  auto one = [](double x) -> double { return 1.0; };
  std::cout << approx_with_ptr(1, one, eps) << std::endl;

  // Rufen Sie approx sowohl mit Funktionszeigern als auch mit Lambda-Ausdrücken
  // auf.
  auto heron2 = [](double x) -> double { return 0.5 * (x + (2 / x)); };
  std::cout << "sqrt(2) = " << approx_with_ptr(3, heron2, eps) << std::endl;

  std::cout << "sqrt(100) = " << approx_with_ptr(3, heron100, eps) << std::endl;
};