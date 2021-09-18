#include <iostream>
#include <memory>
#include <vector>

// Definieren Sie eine Klasse 'window'.
// Sie dient als Superklasse und besitzt [...]
class window {
protected:
  // [...] eine id, [...]
  size_t id;
  bool visible;

public:
  window(size_t id) : id{id}, visible{false} {
    std::cout << "class: window, ctor" << std::endl;
    std::cout << id << std::endl;
  };

  // [...] Methoden zum Anzeigen ('show') [...]
  void show() {
    std::cout << "class: window, method: show" << std::endl;
    visible = true;
  }

  // [...] und Verstecken ('hide'), [...]
  void hide() {
    std::cout << "class: window, method: hide" << std::endl;
    visible = false;
  }

  // [...] sowie eine rein virtuelle Methode 'draw'.
  virtual void draw() = 0;
};

// Leiten Sie öffentlich von 'window' eine Klasse 'button' und eine Klasse
// 'checkbox' ab. Beide definieren 'draw'.
class button : public window {
public:
  button(size_t id) : window(id) {
    std::cout << "class: button, ctor" << std::endl;
    std::cout << id << std::endl;
  };

  virtual void draw() { // (A)
    std::cout << "class: button, method: draw" << std::endl;
    std::cout << "id: " << id << std::endl;
  }
};

class checkbox : public window {
public:
  checkbox(size_t id) : window(id) {
    std::cout << "class: checkbox, ctor" << std::endl;
    std::cout << id << std::endl;
  };

  virtual void draw() { // (A)
    std::cout << "class: checkbox, method: draw" << std::endl;
    std::cout << "id: " << id << std::endl;
  }
};

int main() {
  // Erstellen Sie einen 'vector' von 'unique_ptr' und füllen Sie ihn mit je
  // einer Instanz von 'button' und 'checkbox'.
  // Nutzen Sie 'make_unique'.
  std::vector<std::unique_ptr<window>> vec;
  vec.push_back(std::make_unique<button>(2));
  vec.push_back(std::make_unique<checkbox>(3));

  // Rufen Sie auf allen Elementen des Vektors 'draw' auf und testen Sie, ob die
  // richtige Funktion aufgerufen wird.
  for (const auto &elem : vec) {
    elem->draw();
  }
}

/* Kommentierung
 *
 * (A)  Sei C++11 existiert das 'override' Keyword. Dieses sollte dann genutzt
 *      werden, wenn eine erbende Klasse eine virtuelle Funktion der Basisklasse
 *      überschreibt.
 *      Neben der geförderten Lesbarkeit kann der Compiler mit dem Keyword auch
 *      feststellen, ob die Methode korrekt überschrieben wurde, oder ob sich
 *      potentiell die Signatur der Funktion in der Basisklasse verändert hat.
 *      Im Beispiel würde die Signatur in der erbenden Klasse dann so aussehen:
 *      'void draw() override { ... }''
 *
 *      Siehe dazu auch:
 * https://en.cppreference.com/w/cpp/language/override
 */