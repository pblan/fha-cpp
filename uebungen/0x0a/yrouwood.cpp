#include <iostream>
#include <functional>
#include <cmath>

// Schreiben Sie eine Funktion approx, die als Parameter einen Startwert x0, eine zu iterierende Funktion f, und ein eps erhält:
// approx berechnet x=f(x), mit x=x0 zu Anfang, solange, bis der neue x-Wert sich vom vorhergehenden um weniger als eps unterscheidet.
double approx(double x, double (*f)(double), double eps)
{
    double x_new = f(x);
    if (std::abs(x_new - x) < eps)
    {
        return x;
    }
    else
    {
        // Geben Sie den letzten berechneten Wert zurück.
        return approx(x_new, f, eps);
    }
};

// Nutzen Sie einmal Funktionszeiger und einmal das Template function in der Definition von approx.
double approx_t(double x, std::function<double(double)> f, double eps)
{
    double x_new = f(x);
    if (std::abs(x_new - x) < eps)
    {
        return x;
    }
    else
    {
        // Geben Sie den letzten berechneten Wert zurück.
        return approx_t(x_new, f, eps);
    }
};

double heron100(double x)
{
    return 0.5 * (x + (100 / x));
}

// Funktionszeiger, lambda-Ausdruck
int main()
{
    double eps{1e-10};
    // Testen Sie approx für das Heron-Verfahren (Wurzel-Berechnung, siehe Wikipedia; zunächst für feste a);
    auto one = [](double x) -> double { return 1.0; };
    std::cout << approx(1, one, eps) << std::endl;

    // Rufen Sie approx sowohl mit Funktionszeigern als auch mit Lambda-Ausdrücken auf.
    auto heron2 = [](double x) -> double { return 0.5 * (x + (2 / x)); };
    std::cout << "sqrt(2) = " << approx(3, heron2, eps) << std::endl;

    std::cout << "sqrt(100) = " << approx(3, heron100, eps) << std::endl;
};