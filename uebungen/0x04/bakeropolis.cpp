#include <iostream>

// Klasse zu Template erweitern.
// Erweitern Sie die Klasse 'punkt' aus Übung 'Stone Ridge' zu einem Template.
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

  punkt(const punkt &pkt) = default;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const punkt<T> &pkt) {
  os << "(" << pkt.x() << ", " << pkt.y() << ")";
  return os;
}

int main() {
  // Testen Sie Ihre generische Klasse mit unterschiedlichen Datentypen.
  punkt<int> punkt1_int;
  punkt<int> punkt2_int(3, 4);
  punkt<int> punkt3_int{punkt2_int};

  std::cout << punkt1_int << std::endl;
  std::cout << punkt2_int << std::endl;
  std::cout << punkt3_int << std::endl;

  punkt1_int.set_x(1);
  punkt1_int.set_y(2);

  punkt3_int.set_x(5);
  punkt3_int.set_y(6);

  std::cout << punkt1_int << std::endl;
  std::cout << punkt2_int << std::endl;
  std::cout << punkt3_int << std::endl;

  const punkt<int> &punkt_int_ref{punkt1_int};
  int x_int{punkt_int_ref.x()};
  int y_int{punkt_int_ref.y()};

  std::cout << "x: " << x_int << ", y: " << y_int << std::endl;

  std::cout << "----------------" << std::endl;

  punkt<float> punkt1_float;
  punkt<float> punkt2_float(3.3, 4.4);
  punkt<float> punkt3_float{punkt2_float};

  std::cout << punkt1_float << std::endl;
  std::cout << punkt2_float << std::endl;
  std::cout << punkt3_float << std::endl;

  punkt1_float.set_x(1.1);
  punkt1_float.set_y(2.2);

  punkt3_float.set_x(5.5);
  punkt3_float.set_y(6.6);

  std::cout << punkt1_float << std::endl;
  std::cout << punkt2_float << std::endl;
  std::cout << punkt3_float << std::endl;

  const punkt<float> &punkt_float_ref{punkt1_float};
  float x_float{punkt_float_ref.x()};
  float y_float{punkt_float_ref.y()};

  std::cout << "x: " << x_float << ", y: " << y_float << std::endl;
}