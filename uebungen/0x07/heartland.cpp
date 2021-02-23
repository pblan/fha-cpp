#include <iostream>
#include <string>
#include <array>

template <typename T, size_t DIM>
class fastvector
{
    typedef T value_type;
    static const size_t dim = DIM;

private:
    std::array<T, dim> vector;

public:
    // Implementieren Sie geeignete Operatoren bzw. Funktionen, so dass folgende Codeschnipsel für eine 'fastvector'-Instanz 'v', bzw. 'v1' und 'v2', funktionieren:

    // 'v = 1;' setzt alle Koeffizienten auf einen Wert, hier 1.
    fastvector &operator=(const value_type &n)
    {
        for (size_t i{0}; i < dim; ++i)
        {
            vector.at(i) = n;
        }
        return *this;
    }

    // '-v' negiert alle Koeffizienten.
    fastvector &operator-()
    {
        for (size_t i{0}; i < dim; ++i)
        {
            vector.at(i) *= (value_type)(-1);
        }
        return *this;
    }

    // 'v[i]' liest den i'ten Koeffizienten.
    const value_type &operator[](size_t index) const
    {
        return vector.at(index);
    }

    // 'v[i]' schreibt den i'ten Koeffizienten.
    value_type &operator[](size_t index)
    {
        return vector.at(index);
    }

    // 'cout << v;' gibt die Koeffizienten von 'v' aus.
    friend std::ostream &operator<<(std::ostream &os, const fastvector &f)
    {
        std::string delim{""};

        os << "<";
        for (size_t i = 0; i < dim; ++i)
        {
            os << delim << f.vector.at(i);
            delim = ", ";
        }
        os << ">";
        return os;
    }
};

// 'v1 + v2' addiert 'v1' und 'v2'.
template <typename T, size_t DIM>
fastvector<T, DIM> operator+(const fastvector<T, DIM> &v1, const fastvector<T, DIM> &v2)
{
    fastvector<T, DIM> res;

    for (size_t i = 0; i < DIM; ++i)
    {
        res[i] = v1[i] + v2[i];
    }

    return res;
}

// 'v1 - v2' subtrahiert 'v2' von 'v2'.
template <typename T, size_t DIM>
fastvector<T, DIM> operator-(const fastvector<T, DIM> &v1, const fastvector<T, DIM> &v2)
{
    fastvector<T, DIM> res;

    for (size_t i = 0; i < DIM; ++i)
    {
        res[i] = v1[i] - v2[i];
    }

    return res;
}

// 'v*3' bzw. '3*v' multiplizieren v mit einem Skalar, hier 3.
template <typename T, size_t DIM>
fastvector<T, DIM> operator*(const fastvector<T, DIM> &v, const T &scalar)
{
    fastvector<T, DIM> res{v};
    for (size_t i = 0; i < DIM; ++i)
    {
        res[i] *= scalar;
    }

    return res;
}

template <typename T, size_t DIM>
fastvector<T, DIM> operator*(const T &scalar, const fastvector<T, DIM> &v)
{
    fastvector<T, DIM> res{v};
    for (size_t i = 0; i < DIM; ++i)
    {
        res[i] *= scalar;
    }

    return res;
}

int main()
{
    // Testen Sie Ihren Code aussagekräftig.
    fastvector<int, 4> v1, v2, v3;

    v1 = 1;

    std::cout << "v1 = 1: " << v1 << std::endl;

    v2 = 3;

    std::cout << "v2 = 3: "
              << "<" << v2[0] << ", " << v2[1] << ", " << v2[2] << ", " << v2[3] << ">" << std::endl;

    v3 = v1 + v2;

    std::cout << "v3 = v1 + v2: " << v3 << std::endl;

    v3 = v3 - v1;

    std::cout << "v3 = v3 - v1: " << v3 << std::endl;

    v3 = v3 * 2;

    std::cout << "v3 = v3 * 2: " << v3 << std::endl;

    v3 = 2 * v3;

    std::cout << "v3 = 2 * v3: " << v3 << std::endl;

    -v3;

    std::cout << "-v3: " << v3 << std::endl;
}