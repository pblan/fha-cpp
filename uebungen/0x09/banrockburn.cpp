#include <iostream>
#include <memory>
#include <string>

// Entwerfen Sie eine Template-Klasse node für die Daten und einen Zeiger auf
// das nächste Element, und einen auf das vorhergehende Element, sowie eine
// Template-Klasse list für die Liste mit einem root Zeiger auf das erste, und
// einem tail-Zeiger auf das letzte Element.
template <typename T> class node {
public:
  node(const T &value) : value{value} {
    std::cout << "[ctor node] value = " << value << std::endl;
  };

  T value;

  std::shared_ptr<node<T>> next;
  std::weak_ptr<node<T>> last;
};

// Implementieren Sie eine generische doppelt verkettete Liste mit smart-Zeigern
// anstelle von raw-Zeigern.
template <typename T> class linked_list {
public:
  std::shared_ptr<node<T>> root{nullptr};
  std::shared_ptr<node<T>> tail{nullptr};

  linked_list() { std::cout << "[ctor linked_list] empty" << std::endl; };

  linked_list(const node<T> &root) : root{root} {
    std::cout << "[ctor linked_list] root = " << root.value << std::endl;

    std::shared_ptr<node<T>> it = root;
    while (it->next != nullptr) {
      it = it->next;
    }

    tail = it;
  };

  // Implementieren Sie einen += Operator zum Anhängen neuer Elemente.
  linked_list &operator+=(std::shared_ptr<node<T>> elem) {
    if (!root) {
      root = elem;
      tail = elem;
    } else {
      std::weak_ptr<node<T>> old_tail = tail;

      tail->next = elem;
      tail = tail->next;
      tail->next = nullptr;

      tail->last = old_tail;
    }
    return *this;
  };
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const linked_list<T> &list) {
  std::shared_ptr<node<T>> it = list.root;

  std::string delim;

  std::cout << "<";
  while (it) {
    std::cout << delim << it->value;
    delim = ", ";
    it = it->next;
  }
  std::cout << ">";

  return os;
}

// Anwendung shared-ptr ggf. weak-ptr
int main() {
  // Schreiben Sie aussagefähigen Testcode und iterieren Sie über Ihre Liste
  // (vorwärts und rückwärts).
  linked_list<int> list;

  list += std::make_shared<node<int>>(1);
  list += std::make_shared<node<int>>(2);
  list += std::make_shared<node<int>>(3);

  std::cout << "list: " << list << std::endl;
  std::cout << "list.root: " << list.root
            << ", list.root->value: " << list.root->value << std::endl;
  std::cout << "list.tail: " << list.tail
            << ", list.tail->value: " << list.tail->value << std::endl;

  std::weak_ptr<node<int>> it = list.tail;
  std::shared_ptr<node<int>> it_ptr;

  std::string delim;

  std::cout << "<";
  while ((it_ptr = it.lock())) {
    std::cout << delim << it_ptr->value;
    delim = ", ";
    it = it_ptr->last;
  }
  std::cout << "> : list" << std::endl;
};