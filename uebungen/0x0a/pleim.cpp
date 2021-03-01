#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> v)
{
    os << "<";
    std::for_each(v.begin(), v.end(), [&](T x) -> void { os << " " << x << " "; });
    os << ">";
    return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<T>> v)
{
    std::for_each(v.begin(), v.end(), [&](std::vector<T> x) -> void { os << x << std::endl; });
    return os;
}

// Algorithmen
int main()
{
    int n;
    std::cout << "n: ";
    std::cin >> n;

    // Generieren Sie einen Vektor mit den Werten (n über k) für festes n, also z.B. für n = 4: [1,4,6,4,1].
    // Nutzen Sie, abgesehen von der Ausgabe, nur Funktionen der Algorithmen-Bibliothek, also z.B. for_each oder generate und keine expliziten for-Schleifen.
    // Verwenden Sie den Datentyp vector.

    int cnt{0};
    std::vector<int> v(n + 1);

    std::function<int(int, int)> binomial = [&binomial](int n, int k) -> int {
        if (k == 0 || k == n)
            return 1;
        return (binomial(n - 1, k - 1) + binomial(n - 1, k));
    };

    std::generate(v.begin(), v.end(), [&]() -> int { return binomial(n, cnt++); });

    std::cout << v << std::endl;

    // Erweiterung:
    // Generieren Sie so das Pascalsche Dreieck bis zu einer Dimension n in einem vector von vector.

    std::vector<std::vector<int>> tri(n);

    cnt = 0;
    int i{0};
    std::for_each(
        tri.begin(), tri.end(), [&](std::vector<int> &v) -> void {
            v.resize(i + 1);
            std::generate(v.begin(), v.end(), [&]() -> int { return binomial(i, cnt++); });
            cnt = 0;
            ++i;
        });

    std::cout << tri << std::endl;
}