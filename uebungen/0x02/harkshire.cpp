#include <iostream>

const size_t stack_dim{3};

// Beispielstruktur 'stack':
// Informieren Sie sich, wie ein 'Stack' funkt.
// https://de.wikipedia.org/wiki/Stapelspeicher
// Definieren Sie eine Struktur 'stack', die ein Feld fester Länge (z.B. 3) von
// 'int' enthält, sowie eine Variable 'next' für die nächste freie Position im
// Feld.
struct stack {
  int buffer[stack_dim];
  size_t next{0};
};

std::ostream &operator<<(std::ostream &os, const stack &st) {
  std::string delim;                       // (A)
  for (size_t i = 0; i < stack_dim; i++) { // (B)
    os << delim << st.buffer[i];
    delim = ", ";
  }
  return os;
}

// Erweiterung:
// Werfen Sie eine eigene Exception, wenn der Stack voll ist.
struct stack_exception {
  std::string what;
  char level;
};

int pop(stack &st);
void push(stack &st, int n);
void reset(stack &st);

int main() {
  // Schreiben Sie aussagekräftigen Testcode.
  stack st;
  std::cout << "st: " << st << std::endl;
  reset(st);
  std::cout << "st after reset: " << st << std::endl;

  try {
    push(st, 2);
    std::cout << "st: " << st << std::endl;

    push(st, 3);
    std::cout << "st: " << st << std::endl;

    push(st, 5);
    std::cout << "st: " << st << std::endl;

    push(st, 7);
    std::cout << "st: " << st << std::endl;
  } catch (const stack_exception &e) {
    std::cerr << e.what << std::endl;
  }

  int num;

  try {
    num = pop(st);
    std::cout << "st: " << st << ", num: " << num << std::endl;

    num = pop(st);
    std::cout << "st: " << st << ", num: " << num << std::endl;

    num = pop(st);
    std::cout << "st: " << st << ", num: " << num << std::endl;

    num = pop(st);
    std::cout << "st: " << st << ", num: " << num << std::endl;
  } catch (const stack_exception &e) {
    std::cerr << e.what << std::endl;
  }
}

// Implementieren Sie Funktionen 'pop' und 'push', die Daten vom Stack holen,
// bzw. dort ablegen (wenn Platz ist).
int pop(stack &st) {
  if (st.next <= 0) {
    throw stack_exception{"stack empty", 'E'};
  }
  return st.buffer[--st.next];
}

void push(stack &st, int n) {
  if (st.next >= stack_dim) {
    throw stack_exception{"stack full", 'E'};
  }
  st.buffer[st.next++] = n;
}

void reset(stack &st) {
  for (size_t i = 0; i < stack_dim; ++i) {
    st.buffer[i] = 0;
  }
}

/* Kommentierung
 *
 * (A)  Per default wird ein std::string mit "" initialisiert.
 *      std::string delim = "";
 *      wuerde natuerlich funktionieren, wird aber nicht empfohlen.
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/fuchsia-overloaded-operator.html
 *
 * (B)  Generell sind ranged-based for-loops zu bevorzugen. Das spielt hier aber
 * erstmal eine geringere Rolle.
 *
 *      Siehe dazu auch:
 * https://clang.llvm.org/extra/clang-tidy/checks/modernize-loop-convert.html
 */