#include <iostream>

int fib_iter(int n);
int fib_rec(int n);

int main()
{
    // Berechnung der Fibonacci-Folge (f_i):
    // Lesen Sie eine ganze Zahl 'n' von der Konsole ein.

    int n;
    std::cout << "Eingabe n (int): " << std::endl;
    std::cin >> n;

    // Berechnen Sie die ersten 'n' Fibonaccizahlen f_i iterativ, d.h. in einer Schleife (also nicht rekursiv) und geben Sie sie aus.
    // Die Vorschrift lautet: f_i = f_{i-1} + f_{i-2} mit f_0 = f_1 = 1
    std::cout << "f_n (iterativ): " << fib_iter(n) << std::endl;

    // Erweiterung:
    // Berechnen Sie die Zahlen f_i jeweils rekursiv.
    std::cout << "f_n (rekursiv): " << fib_rec(n) << std::endl;

    // Überlegen Sie: Welcher Ansatz ist (vermutlich) schneller und warum?
    return 0;
}

int fib_iter(int n)
{
    if (n == 0 || n == 1)
        return 1;
    int fi, fi_minus_1{1}, fi_minus_2{1};

    while (n > 1)
    {
        fi = fi_minus_1 + fi_minus_2;
        fi_minus_2 = fi_minus_1;
        fi_minus_1 = fi;
        --n;
    }
    return fi;
}

int fib_rec(int n)
{
    return n <= 1 ? 1 : fib_rec(n - 1) + fib_rec(n - 2);
}