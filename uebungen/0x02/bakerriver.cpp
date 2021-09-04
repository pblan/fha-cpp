#include <cmath>
#include <iostream>
#include <string>

void cut(double &num_a, double &num_b);
void shift(std::string &str_x, std::string &str_y, std::string &str_z);

int main()
{
    double num_a;
    double num_b;

    std::cout << "Eingabe num_a (double): ";
    std::cin >> num_a;
    std::cout << "Eingabe num_b (double): ";
    std::cin >> num_b;

    std::cout << " num_a: " << num_a << ", num_b: " << num_b << std::endl;
    cut(num_a, num_b);
    std::cout << "cut(num_a, num_b)" << std::endl;
    std::cout << " num_a: " << num_a << ", num_b: " << num_b << std::endl;

    std::string str_x;
    std::string str_y;
    std::string str_z;

    std::cout << "Eingabe str_x: ";
    std::cin >> str_x;
    std::cout << "Eingabe str_y: ";
    std::cin >> str_y;
    std::cout << "Eingabe str_z: ";
    std::cin >> str_z;

    std::cout << "str_x: " << str_x << ", str_y: " << str_y << ", str_z: " << str_z << std::endl;
    shift(str_x, str_y, str_z);
    std::cout << "shift(str_x, str_y, str_z)" << std::endl;
    std::cout << "str_x: " << str_x << ", str_y: " << str_y << ", str_z: " << str_z << std::endl;
}

// Schreiben Sie eine Funktion 'cut', die bei zwei per Referenz übergebenen 'double'-Zahlen jeweils die Nachkommastellen auf 0 setzt.
// Nutzen Sie die Funktion 'floor' aus 'cmath'.
void cut(double &num_a, double &num_b)
{
    num_a = floor(num_a);
    num_b = floor(num_b);
}

// Schreiben Sie eine Funktion 'shift', die drei per Referenz übergebene Strings 'der Reihe nach' tauscht [...].
void shift(std::string &str_x, std::string &str_y, std::string &str_z)
{
    std::string help{str_x};
    str_x = str_y;
    str_y = str_z;
    str_z = help;
}