#include <iostream>

// Implementieren Sie eine generische Klasse 'nullable', die einen
// mathematischen Wert modelliert, der auch 'null' sein kann.
template <typename T> class nullable {
  typedef T value_type;
  // using value_type = T;

private:
  // Nutzen Sie intern ein Attribut vom Datentyp, der durch den
  // Template-Parameter bestimmt wird, [...]
  value_type value{};
  // [...] sowie einen 'bool', welcher angibt, ob der Wert 'null' ist oder
  // nicht.
  bool is_null{true};

public:
  nullable() = default;

  nullable(const value_type &val) : value{val}, is_null{false} {};

  nullable(const nullable &val) : value{val.value}, is_null{val.is_null} {};

  // 'n = 1;' setzt alle Koeffizienten auf einen Wert, hier 1.
  nullable &operator=(const value_type &val) {
    value = val;
    is_null = false;
    return *this;
  }

  // 'n.reset();' bedeutet, 'n' auf 'null' zu setzen.
  void reset() { is_null = true; }

  // 'n+=3;' addiert einen Wert zu 'n', hier 3.
  nullable &operator+=(const value_type &val) {
    if (!is_null) {
      value += val;
    }

    return *this;
  }

  // '!n' testet auf 'null' und ist wahr, wenn nicht.
  bool operator!() const { return !is_null; }

  // '(int)n;' wandelt in den konkreten Datentyp um, hier 'int'.
  operator T() const { return value; }

  // 'cout << n;' gibt den Wert von 'n' aus.
  friend std::ostream &operator<<(std::ostream &os, const nullable &num) {
    if (num.is_null) {
      os << "NULL";
    } else {
      os << num.value;
    }

    return os;
  }
};

// 'n1 + n2' addiert 'n1' und 'n2'.
template <typename T>
nullable<T> operator+(const nullable<T> &num1, const nullable<T> &num2) {
  nullable<T> res{num1};

  return res += num2;
}

// Operatoren
int main() {
  nullable<int> num0{};
  nullable<int> num1(23);
  nullable<int> num2(num1);

  std::cout << "num0:" << num0 << ", num1:" << num1 << ", num2:" << num2
            << std::endl;

  num0 = 0;
  num1 = 1;
  num2.reset();

  std::cout << "num0:" << num0 << ", num1:" << num1 << ", num2:" << num2
            << std::endl;

  num0 += 10;
  num1 += 10;
  num2 += 10;

  std::cout << "num0:" << num0 << ", num1:" << num1 << ", num2:" << num2
            << std::endl;
  std::cout << "!num0:" << !num0 << ", !num1:" << !num1 << ", !num2:" << !num2
            << std::endl;

  num0 = 0;
  num1 = 1;
  num2 = 2;

  std::cout << "num0:" << num0 << ", num1:" << num1 << ", num2:" << num2
            << std::endl;
  std::cout << "(int)num2:" << (int)num2 << std::endl;
  std::cout << "num1 + num2:" << num1 + num2 << std::endl;
}