#include <iostream>
#include <memory>
#include <unordered_map>

// Implementieren Sie eine abstrakte Klasse 'matrix', die eine quadratische
// Matrix für ganze Zahlen darstellen soll. Wie die Daten gespeichert werden,
// entscheiden die abgeleiteten Klassen.

// Machen Sie ein Template aus der Klasse.
template <typename T> class matrix {
public:
  typedef T value_type;
  // using value_type = T;

  const size_t m_dim;

  // Der ctor bekommt die Dimension 'dim' übergeben und ein Member der Klasse
  // speichert sie.
  matrix(size_t dim) : m_dim{dim} {};

  // Sie besitzt rein virtuelle Methoden, um Elemente zu lesen und zu schreiben
  // ('at'), [...]
  virtual value_type at(size_t row, size_t col) const = 0;
  virtual value_type &at(size_t row, size_t col) = 0;

  // [...] sowie eine Methode, um die Matrix auf 0 zu setzen ('make_zero').
  virtual void make_zero() = 0;

  // Die Klasse besitzt eine weitere, nicht virtuelle Funktion zum Setzen der
  // Einheitsmatrix ('make_one'). Diese setzt die Matrix auf 0 und danach die
  // Diagonalelemente auf 1.
  void make_one() {
    make_zero();
    for (size_t i = 0; i < m_dim; ++i) {
      at(i, i) = 1;
    }
  }
};

// Leiten Sie die Klasse 'full_matrix' von 'matrix' ab.
template <typename T> class full_matrix : public matrix<T> {
  typedef matrix<T> matrix_type;
  // using matrix_type = matrix<T>;
  typedef typename matrix<T>::value_type value_type;
  // using value_type = typename matrix<T>::value_type;

protected:
  // Sie legt die Koeffizienten in einem dynamischen Feld von 'int' ab.
  // Implementieren Sie die fehlenden Methoden entsprechend und nutzen Sie
  // 'unique_ptr' für das Feld.
  std::unique_ptr<value_type[]> data;

public:
  full_matrix(size_t dim)
      : matrix<value_type>(dim), data{std::make_unique<value_type[]>(dim *
                                                                     dim)} {};

  virtual value_type at(size_t row, size_t col) const {
    return *(data.get() + matrix_type::m_dim * row + col);
  }

  virtual value_type &at(size_t row, size_t col) {
    return *(data.get() + matrix_type::m_dim * row + col);
  }

  virtual void make_zero() {
    for (size_t i = 0; i < (matrix_type::m_dim * matrix_type::m_dim); ++i) {
      at((i / matrix_type::m_dim), (i % matrix_type::m_dim)) = 0;
    }
  }
};

// Leiten Sie die Klasse 'sparse_matrix' von 'matrix' ab.
// Sie legt ihre Koeffizienten in einer 'unordered_map' ab.
// Der Schlüssel wird aus x und y zu y*dim+x gebildet, so dass man einen Eintrag
// findet, wenn er existiert. Sonst ist er 0.
template <typename T> class sparse_matrix : public matrix<T> {
  typedef matrix<T> matrix_type;
  // using matrix_type = matrix<T>;
  typedef typename matrix<T>::value_type value_type;
  // using value_type = typename matrix<T>::value_type;

protected:
  std::unordered_map<size_t, value_type> data;

public:
  sparse_matrix(size_t dim) : matrix<value_type>(dim){};

  virtual value_type at(size_t row, size_t col) const {
    auto it = data.find(col * matrix_type::m_dim + row);
    return (it != data.end()) ? it->second : 0;

    // C++20
    // return data.contains(col * matrix_type::m_dim + row) ? data.at(col *
    // matrix_type::m_dim + row) : 0;
  }

  virtual value_type &at(size_t row, size_t col) {
    auto rc = data.emplace(std::make_pair(col * matrix_type::m_dim + row, 0));
    return rc.first->second;
  }

  virtual void make_zero() { data.clear(); }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const matrix<T> &mat) {
  std::string delim;
  for (size_t i = 0; i < mat.m_dim; ++i) {
    delim = "";
    for (size_t j = 0; j < mat.m_dim; ++j) {
      os << delim << mat.at(i, j);
      delim = " ";
    }
    os << std::endl;
    delim = "";
  }
  return os;
}

int main() {
  full_matrix<double> matrix_a(5);

  matrix_a.make_zero();

  std::cout << matrix_a << std::endl;

  matrix_a.make_one();

  std::cout << matrix_a << std::endl;

  std::cout << matrix_a.at(1, 1) << std::endl;

  matrix_a.at(1, 1) = 3;

  std::cout << matrix_a << std::endl;

  sparse_matrix<double> matrix_b(5);

  matrix_b.make_zero();

  std::cout << matrix_b << std::endl;

  matrix_b.make_one();

  std::cout << matrix_b << std::endl;

  std::cout << matrix_b.at(1, 1) << std::endl;

  matrix_b.at(1, 1) = 3.5;

  std::cout << matrix_b << std::endl;
}