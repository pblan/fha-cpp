#include <iostream>
#include <memory>
#include <string>
#include <vector>

// Entwerfen Sie eine beliebige Klasse und [...]
struct beliebig {
  std::string name;

  beliebig(std::string name) : name{name} {};
};

// unique- und shared-ptr
int main() {
  // [...] füllen Sie (jeweils) einen std::vector

  // [...] mit Objekten Ihrer Klasse,
  std::vector<beliebig> vec1;

  beliebig bel1{"bel1"};
  beliebig bel2{"bel2"};
  beliebig bel3{"bel3"};

  vec1.push_back(bel1);
  vec1.push_back(bel2);
  vec1.push_back(bel3);

  std::cout << "vec1.size() = " << vec1.size() << std::endl;

  for (auto &val : vec1) {
    std::cout << val.name << std::endl;
  }

  vec1.clear();
  std::cout << "v1.size() = " << vec1.size() << std::endl;

  // [...] mit (raw) Zeigern auf dynamisch angelegte Objekte Ihrer Klasse, bzw.
  std::vector<beliebig *> vec2;

  vec2.push_back(new beliebig{"bel4"});
  vec2.push_back(new beliebig{"bel5"});
  vec2.push_back(new beliebig{"bel6"});

  std::cout << "vec2.size() = " << vec2.size() << std::endl;

  for (auto &val : vec2) {
    std::cout << val->name << std::endl;
    delete val;
  }

  vec2.clear();
  std::cout << "vec2.size() = " << vec2.size() << std::endl;

  // [...] mit unique- und shared-ptr auf diese.
  std::vector<std::unique_ptr<beliebig>> vec3;

  vec3.push_back(std::make_unique<beliebig>("bel7"));
  vec3.push_back(std::make_unique<beliebig>("bel8"));
  vec3.push_back(std::make_unique<beliebig>("bel9"));

  std::cout << "vec3.size() = " << vec3.size() << std::endl;

  for (auto &val : vec3) {
    std::cout << val->name << std::endl;
  }

  vec3.clear();
  std::cout << "vec3.size() = " << vec3.size() << std::endl;

  // Erweiterung:
  // Werden alle Elemente ordnungsgemäß zerstört, oder gibt es Memory Leaks?
  /*
    $ valgrind ./openshaw.out
    ==25643== HEAP SUMMARY:
    ==25643==     in use at exit: 0 bytes in 0 blocks
    ==25643==   total heap usage: 17 allocs, 17 frees, 74,256 bytes allocated
    ==25643==
    ==25643== All heap blocks were freed -- no leaks are possible
    ==25643==
    ==25643== For lists of detected and suppressed errors, rerun with: -s
    ==25643== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
  */

  // Können Sie alle Elemente in einer Schleife ausgeben?
};