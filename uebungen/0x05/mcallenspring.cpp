#include <iomanip>
#include <iostream>

// Illegal - beachten Sie auch das Snippet zum Thema...
int main() {
  // Versuchen Sie, durch Verwendung von Zeigern einzelne Bytes von lokalen
  // 'int'-Variablen zu manipulieren.
  int var1{0x12345678};

  // Nutzen Sie dafür casts in 'char*'.
  char *charptr{(char *)&var1};

  std::cout << "var1: " << std::hex << var1 << std::endl;
  std::cout << "+charptr[0]: " << +charptr[0] << std::endl; // (A)
  std::cout << "+charptr[1]: " << +charptr[1] << std::endl;
  std::cout << "+charptr[2]: " << +charptr[2] << std::endl;
  std::cout << "+charptr[3]: " << +charptr[3] << std::endl;

  // Verändern Sie einzelne Bytes eines Texts der Form: char* p = "huhu";
  // Was passiert?
  charptr[0] = 0x00;
  charptr[1] = 0x11;

  std::cout << "var1: " << std::hex << var1 << std::endl;
  std::cout << "+charptr[0]: " << +charptr[0] << std::endl;
  std::cout << "+charptr[1]: " << +charptr[1] << std::endl;
  std::cout << "+charptr[2]: " << +charptr[2] << std::endl;
  std::cout << "+charptr[3]: " << +charptr[3] << std::endl;

  // Erweiterung:
  // Versuchen Sie, über Zeiger-Manipulationen lokale Variablen gezielt auf dem
  // Stack zu verändern, ohne diese direkt zu adressieren.
  int var2{1};
  int var3{2};

  // Tipp: Ermitteln Sie zunächst die Adresse einer lokalen Variablen.
  // Die anderen liegen 'in der Nähe'.
  int *ptr2{&var2};

  std::cout << "var2: " << var2 << ", var3: " << var3 << std::endl;
  *(ptr2 + 1) = 3;
  std::cout << "var2: " << var2 << ", var3: " << var3 << std::endl;
}

/* Kommentierung
 *
 * (A)  Der +-Operator sorgt in diesem Beispiel dafür, dass der eigentliche
 * char-Wert als int interpretiert wird.
 *
 *      Siehe dazu auch:
 * https://docs.microsoft.com/en-us/cpp/cpp/unary-plus-and-negation-operators-plus-and?view=msvc-160
 */
