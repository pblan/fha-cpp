#include <iostream>

void swap_with_ptr(double *ptr1, double *ptr2);
void swap_with_ref(double &ref1, double &ref2);
void swap_ptr(double *&refptr1, double *&refptr2);

int main() {
  // Testen Sie Ihren Code entsprechend.
  double var1{1.5};
  double var2{2.5};

  std::cout << "var1: " << var1 << ", var2: " << var2 << std::endl;

  swap_with_ptr(&var1, &var2);
  std::cout << "swap_with_ptr(&var1, &var2);" << std::endl;
  std::cout << "var1: " << var1 << ", var2: " << var2 << std::endl;

  swap_with_ref(var1, var2);
  std::cout << "swap_with_ref(var1, var2);" << std::endl;
  std::cout << "var1: " << var1 << ", var2: " << var2 << std::endl;

  double *ptr1{&var1};
  double *ptr2{&var2};
  std::cout << "ptr1: " << ptr1 << "*ptr1: " << *ptr1 << ", ptr2: " << ptr2
            << "*ptr2: " << *ptr2 << std::endl;

  swap_ptr(ptr1, ptr2);
  std::cout << "swap_ptr(ptr1, ptr2);" << std::endl;
  std::cout << "ptr1: " << ptr1 << "*ptr1: " << *ptr1 << ", ptr2: " << ptr2
            << "*ptr2: " << *ptr2 << std::endl;
}

// Swap.
// Schreiben Sie eine Funktion 'swap', die zwei übergebene 'double'-Zahlen
// tauscht. Implementieren Sie die Funktionen einmal über Zeiger und einmal über
// Referenzen.
void swap_with_ptr(double *ptr1, double *ptr2) {
  double help{*ptr1};
  *ptr1 = *ptr2;
  *ptr2 = help;
}

void swap_with_ref(double &ref1, double &ref2) {
  double help{ref1};
  ref1 = ref2;
  ref2 = help;
}

// Erweiterung:
// Schreiben Sie eine weitere Funktion 'swap_ptr', die zwei übergebene
// 'double'-Zeiger tauscht (Zeiger und Referenzen).
void swap_ptr(double *&refptr1, double *&refptr2) {
  double *help{refptr1};
  refptr1 = refptr2;
  refptr2 = help;
}