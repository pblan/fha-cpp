#include <array>
#include <iostream>
#include <string>

template <typename T, size_t DIM> class fastvector {
  typedef T value_type;
  // using value_type = T;
  static const size_t dim = DIM;

private:
  std::array<T, dim> vector;

public:
  // Implementieren Sie geeignete Operatoren bzw. Funktionen, so dass folgende
  // Codeschnipsel für eine 'fastvector'-Instanz 'v', bzw. 'v1' und 'v2',
  // funktionieren:

  // 'v = 1;' setzt alle Koeffizienten auf einen Wert, hier 1.
  fastvector &operator=(const value_type &val) {
    for (size_t i{0}; i < dim; ++i) {
      vector.at(i) = val;
    }
    return *this;
  }

  // '-v' negiert alle Koeffizienten.
  fastvector &operator-() {
    for (size_t i{0}; i < dim; ++i) {
      vector.at(i) *= (value_type)(-1);
    }
    return *this;
  }

  // 'v[i]' liest den i'ten Koeffizienten.
  const value_type &operator[](size_t index) const { return vector.at(index); }

  // 'v[i]' schreibt den i'ten Koeffizienten.
  value_type &operator[](size_t index) { return vector.at(index); }

  // 'cout << v;' gibt die Koeffizienten von 'v' aus.
  friend std::ostream &operator<<(std::ostream &os, const fastvector &fvec) {
    std::string delim;

    os << "<";
    for (size_t i = 0; i < dim; ++i) {
      os << delim << fvec.vector.at(i);
      delim = ", ";
    }
    os << ">";
    return os;
  }
};

// 'v1 + v2' addiert 'v1' und 'v2'.
template <typename T, size_t DIM>
fastvector<T, DIM> operator+(const fastvector<T, DIM> &fvec1,
                             const fastvector<T, DIM> &fvec2) {
  fastvector<T, DIM> res{};

  for (size_t i = 0; i < DIM; ++i) {
    res[i] = fvec1[i] + fvec2[i];
  }

  return res;
}

// 'v1 - v2' subtrahiert 'v2' von 'v2'.
template <typename T, size_t DIM>
fastvector<T, DIM> operator-(const fastvector<T, DIM> &fvec1,
                             const fastvector<T, DIM> &fvec2) {
  fastvector<T, DIM> diff{};

  for (size_t i = 0; i < DIM; ++i) {
    diff[i] = fvec1[i] - fvec2[i];
  }

  return diff;
}

// 'v*3' bzw. '3*v' multiplizieren v mit einem Skalar, hier 3.
template <typename T, size_t DIM>
fastvector<T, DIM> operator*(const fastvector<T, DIM> &fvec, const T &scalar) {
  fastvector<T, DIM> res{fvec};
  for (size_t i = 0; i < DIM; ++i) {
    res[i] *= scalar;
  }

  return res;
}

template <typename T, size_t DIM>
fastvector<T, DIM> operator*(const T &scalar, const fastvector<T, DIM> &fvec) {
  fastvector<T, DIM> res{fvec};
  for (size_t i = 0; i < DIM; ++i) {
    res[i] *= scalar;
  }

  return res;
}

int main() {
  // Testen Sie Ihren Code aussagekräftig.
  fastvector<int, 4> fvec1{};
  fastvector<int, 4> fvec2{};
  fastvector<int, 4> fvec3{};

  fvec1 = 1;

  std::cout << "fvec1 = 1: " << fvec1 << std::endl;

  fvec2 = 3;

  std::cout << "fvec2 = 3: "
            << "<" << fvec2[0] << ", " << fvec2[1] << ", " << fvec2[2] << ", "
            << fvec2[3] << ">" << std::endl;

  fvec3 = fvec1 + fvec2;

  std::cout << "fvec3 = fvec1 + fvec2: " << fvec3 << std::endl;

  fvec3 = fvec3 - fvec1;

  std::cout << "fvec3 = fvec3 - fvec1: " << fvec3 << std::endl;

  fvec3 = fvec3 * 2;

  std::cout << "fvec3 = fvec3 * 2: " << fvec3 << std::endl;

  fvec3 = 2 * fvec3;

  std::cout << "fvec3 = 2 * fvec3: " << fvec3 << std::endl;

  -fvec3;

  std::cout << "-fvec3: " << fvec3 << std::endl;
}