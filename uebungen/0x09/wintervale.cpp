#include <iostream>

// Schreiben Sie eine Template-Klasse, die zur Compile-Zeit B^N (B hoch N) für zwei natürliche Zahlen B und N berechnet.
template <size_t B, size_t N>
struct potenz
{
    static const int res{B * potenz<B, N - 1>::res};
};

template <size_t B>
struct potenz<B, 1>
{
    static const int res{B};
};

// Erweiterung:
// Spezialisieren Sie Ihre Klasse für den Fall B=1.
template <size_t N>
struct potenz<1, N>
{
    static const int res{1};
};

// Metaprogrammierung
int main()
{
    std::cout << potenz<2, 12>::res << std::endl;
};