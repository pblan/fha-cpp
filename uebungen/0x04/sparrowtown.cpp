#include <iostream>

// Klasse zu Template erweitern.
// Erweitern Sie die Klasse 'bruch' bzw. 'fraction' aus Übung 'Ravencastle' zu
// einem Template.
template <typename T> class fraction {
private:
  T num_{};   // numerator
  T denom_{}; // denominator

public:
  fraction() = default;
  ~fraction() = default;

  fraction(T num, T denom) : num_{num}, denom_{denom} {};

  T num() const { return num_; }
  T denom() const { return denom_; }
  void set_num(T num) { num_ = num; }
  void set_denom(T denom) { denom_ = denom; }

  fraction(const fraction &frac) = default;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const fraction<T> &frac) {
  os << frac.num() << "/" << frac.denom();
  return os;
}

int main() {
  // Testen Sie Ihre generische Klasse mit unterschiedlichen Datentypen.
  fraction<int> frac1_int;
  fraction<int> frac2_int{2, 3};
  fraction<int> frac3_int{frac2_int};

  std::cout << frac1_int << std::endl;
  std::cout << frac2_int << std::endl;
  std::cout << frac3_int << std::endl;

  frac1_int = fraction<int>{1, 2};
  frac3_int = fraction<int>{5, 6};

  std::cout << frac1_int << std::endl;
  std::cout << frac2_int << std::endl;
  std::cout << frac3_int << std::endl;

  const fraction<int> &frac_int_ref{frac1_int};
  int num{frac_int_ref.num()};
  int denom{frac_int_ref.denom()};
  std::cout << "num: " << num << ", denom: " << denom << std::endl;

  std::cout << "----------------" << std::endl;

  fraction<float> frac1_float;
  fraction<float> frac2_float{2.5, 3.5};
  fraction<float> frac3_float{frac2_float};

  std::cout << frac1_float << std::endl;
  std::cout << frac2_float << std::endl;
  std::cout << frac3_float << std::endl;

  frac1_float = fraction<float>{1.5, 2.5};
  frac3_float = fraction<float>{5.5, 6.5};

  std::cout << frac1_float << std::endl;
  std::cout << frac2_float << std::endl;
  std::cout << frac3_float << std::endl;

  const fraction<float> &frac_float_ref{frac1_float};
  float num2{frac_float_ref.num()};
  float denom2{frac_float_ref.denom()};
  std::cout << "num: " << num2 << ", denom: " << denom2 << std::endl;
}