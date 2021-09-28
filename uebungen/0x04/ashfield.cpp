#include <iostream>
#include <unordered_map>

// Implementieren Sie ein 'struct' 'buch', welches (vereinfacht) einen Autor und
// einen Titel enthält.
struct buch {
  std::string autor;
  std::string titel;
};

// Definieren Sie einen eigenen Typ 'katalog_t' durch eine 'unordered_map', die
// einen 'string' (ISBN) auf ein 'buch' abbildet. [...]

typedef std::unordered_map<std::string, buch> katalog_t;
// using katalog_t = std::unordered_map<std::string, buch>;

// Mapping von ISBN-Nummer zu Büchern.
int main() {
  // [...] Legen Sie eine Variable 'katalog' deses Typs an.
  katalog_t katalog;

  // Füllen Sie 'katalog' mit drei echten Büchern (und ISBN) Ihrer Wahl.
  katalog["9781338345728"] = {
      "Rowling, J.K.", "Harry Potter Books 1-7 Special Edition Boxed Set"};
  katalog["9780593157718"] = {
      "Soule, Charles", "Star Wars: Light of the Jedi (The High Republic)"};
  katalog["9780358439196"] = {"Tolkien, J.R.R.",
                              "The Lord of the Rings Boxed Set"};

  // Suchen Sie in einer Schleife mit 'const auto&' alle Bücher, deren Titel
  // länger als 30 Zeichen ist und geben Sie diese aus.
  for (const auto &val : katalog) {
    if (val.second.titel.size() > 30) {
      std::cout << val.second.autor << ": " << val.second.titel << std::endl;
    }
  }
}