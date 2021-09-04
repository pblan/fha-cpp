#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

// Suchen und Löschen in Datencontainern mit Iteratoren.
int main() {
  // Suchen Sie in dem Vektor '{1, 2, 3, 4, 5}' das Element '2' und geben Sie
  // die nächsten drei Elemente (inkl.) aus (wenn vorhanden).
  std::vector<int> vec{1, 2, 3, 4, 5};
  // auto pos = std::find(v.begin(), v.end(), 2);
  size_t i{0};
  std::vector<int>::const_iterator it{vec.cbegin()};

  while (it != vec.cend() && i <= 3) {
    if (*it == 2 || i != 0) {
      std::cout << *it << std::endl;
      ++i;
    }
    ++it;
  }

  // Legen Sie folgende 'unordered_map' an
  // '{1 -> 'Eins', ..., 5 -> 'Fünf'}' und suchen Sie dort nach dem Schlüssel
  // '2'.
  std::unordered_map<int, std::string> map{
      {1, "Eins"}, {2, "Zwei"}, {3, "Drei"}, {4, "Vier"}, {5, "Fünf"}};
  std::cout << map[2] << std::endl;

  for (auto it = map.begin(); it != map.end();) {
    if (it->first > 2) {
      it = map.erase(it);
    } else {
      ++it;
    }
  }

  for (auto &val : map) {
    std::cout << val.second << ' ';
  }
  std::cout << std::endl;
}