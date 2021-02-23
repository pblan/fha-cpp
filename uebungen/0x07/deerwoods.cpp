#include <iostream>

// Implementieren Sie eine generische Klasse 'nullable', die einen mathematischen Wert modelliert, der auch 'null' sein kann.
template <typename T>
class nullable
{
    typedef T value_type;

private:
    // Nutzen Sie intern ein Attribut vom Datentyp, der durch den Template-Parameter bestimmt wird, [...]
    value_type value;
    // [...] sowie einen 'bool', welcher angibt, ob der Wert 'null' ist oder nicht.
    bool is_null;

public:
    nullable() : is_null{true} {};

    nullable(const value_type &val) : value{val}, is_null{false} {};

    nullable(const nullable &val) : value{val.value}, is_null{val.is_null} {};

    // 'n = 1;' setzt alle Koeffizienten auf einen Wert, hier 1.
    nullable &operator=(const value_type &n)
    {
        value = n;
        is_null = false;
        return *this;
    }

    // 'n.reset();' bedeutet, 'n' auf 'null' zu setzen.
    void reset()
    {
        is_null = true;
    }

    // 'n+=3;' addiert einen Wert zu 'n', hier 3.
    nullable &operator+=(const value_type &n)
    {
        if (!is_null)
        {
            value += n;
        }

        return *this;
    }

    // '!n' testet auf 'null' und ist wahr, wenn nicht.
    bool operator!() const
    {
        return !is_null;
    }

    // '(int)n;' wandelt in den konkreten Datentyp um, hier 'int'.
    operator T() const
    {
        return value;
    }

    // 'cout << n;' gibt den Wert von 'n' aus.
    friend std::ostream &operator<<(std::ostream &os, const nullable &n)
    {
        if (n.is_null)
        {
            os << "NULL";
        }
        else
        {
            os << n.value;
        }

        return os;
    }
};

// 'n1 + n2' addiert 'n1' und 'n2'.
template <typename T>
nullable<T> operator+(const nullable<T> &n1, const nullable<T> &n2)
{
    nullable<T> res{n1};

    return res += n2;
}

// Operatoren
int main()
{
    nullable<int> n0, n1(23), n2(n1);

    std::cout << "n0:" << n0 << ", n1:" << n1 << ", n2:" << n2 << std::endl;

    n0 = 0;
    n1 = 1;
    n2.reset();

    std::cout << "n0:" << n0 << ", n1:" << n1 << ", n2:" << n2 << std::endl;

    n0 += 10;
    n1 += 10;
    n2 += 10;

    std::cout << "n0:" << n0 << ", n1:" << n1 << ", n2:" << n2 << std::endl;
    std::cout << "!n0:" << !n0 << ", !n1:" << !n1 << ", !n2:" << !n2 << std::endl;

    n0 = 0;
    n1 = 1;
    n2 = 2;

    std::cout << "n0:" << n0 << ", n1:" << n1 << ", n2:" << n2 << std::endl;
    std::cout << "(int)n2:" << (int)n2 << std::endl;
    std::cout << "n1+n2:" << n1 + n2 << std::endl;
}