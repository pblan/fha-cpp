#include <iostream>

template <typename T> class punkt {
private:
  T x_{};
  T y_{};

public:
  punkt() = default;
  ~punkt() = default;

  punkt(T x, T y) : x_{x}, y_{y} {};

  T x() const { return x_; };
  T y() const { return y_; };
  void set_x(T x) { x_ = x; }
  void set_y(T y) { y_ = y; }

  punkt(const punkt &p) = default;
};

// Nehmen Sie Ihre Punkt-Klasse, spezialisieren Sie sie für bool und machen dort
// den ctor privat, so dass Sie keine Instanz davon erzeugen können.
template <> class punkt<bool> {
private:
  punkt() = default;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const punkt<T> &pun) {
  os << "(" << pun.x() << ", " << pun.y() << ")";
  return os;
}

int main() {
  // alter Test:
  punkt<int> punkt_int_1;
  punkt<int> punkt_int_2(3, 4);
  punkt<int> punkt_int_3{punkt_int_2};

  std::cout << punkt_int_1 << std::endl;
  std::cout << punkt_int_2 << std::endl;
  std::cout << punkt_int_3 << std::endl;

  punkt_int_1.set_x(1);
  punkt_int_1.set_y(2);

  punkt_int_3.set_x(5);
  punkt_int_3.set_y(6);

  std::cout << punkt_int_1 << std::endl;
  std::cout << punkt_int_2 << std::endl;
  std::cout << punkt_int_3 << std::endl;

  const punkt<int> &punkt_int_ref{punkt_int_1};
  int x_int{punkt_int_ref.x()};
  int y_int{punkt_int_ref.y()};

  std::cout << "x_int: " << x_int << ", y_int: " << y_int << std::endl;

  std::cout << "----------------" << std::endl;

  punkt<float> punkt_float_1;
  punkt<float> punkt_float_2(3.3, 4.4);
  punkt<float> punkt_float_3{punkt_float_2};

  std::cout << punkt_float_1 << std::endl;
  std::cout << punkt_float_2 << std::endl;
  std::cout << punkt_float_3 << std::endl;

  punkt_float_1.set_x(1.1);
  punkt_float_1.set_y(2.2);

  punkt_float_3.set_x(5.5);
  punkt_float_3.set_y(6.6);

  std::cout << punkt_float_1 << std::endl;
  std::cout << punkt_float_2 << std::endl;
  std::cout << punkt_float_3 << std::endl;

  const punkt<float> &punkt_float_ref{punkt_float_1};
  float x_float{punkt_float_ref.x()};
  float y_float{punkt_float_ref.y()};

  std::cout << "x_float: " << x_float << ", y_float: " << y_float << std::endl;
}