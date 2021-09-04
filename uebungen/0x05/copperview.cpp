#include <iostream>

// Variablen über Zeiger modifizieren.
int main() {
  // Legen Sie eine 'int'- und eine 'float'-Variable an und initialisieren Sie
  // sie mit beliebigen Werten.
  int var1{5};
  float var2{3.5};

  // Legen Sie zwei Zeiger an und initialisieren Sie sie so, dass sie jeweils
  // auf diese beiden Variablen zeigen.
  int *ptr1 = &var1;
  float *ptr2 = &var2;

  std::cout << "ptr1: " << ptr1 << ", *ptr1: " << *ptr1 << ", var1: " << var1
            << std::endl;
  std::cout << "ptr2: " << ptr2 << ", *ptr2: " << *ptr2 << ", b: " << var2
            << std::endl;

  // Verändern Sie die Werte der Variablen mit Hilfe der Zeiger.
  *ptr1 += 1;
  *ptr2 *= 2;

  // Geben Sie jeweils den Zeiger, den Wert auf den er zeigt und die zugehörige
  // Variable aus.
  std::cout << "ptr1: " << ptr1 << ", *ptr1: " << *ptr1 << ", var1: " << var1
            << std::endl;
  std::cout << "ptr2: " << ptr2 << ", *ptr2: " << *ptr2 << ", var2: " << var2
            << std::endl;

  // Erweiterung:
  // Legen Sie einen Zeiger auf den Zeiger auf 'int' an, initialisieren Sie ihn
  // mit der Adresse Ihres 'int'-Zeigers und geben Sie den Wert der
  // 'int'-Variablen hierüber aus.
  int **ptrptr = &ptr1;
  std::cout << "ptrptr: " << ptrptr << ", *ptrptr: " << *ptrptr
            << ", **ptrptr: " << **ptrptr << std::endl;
}