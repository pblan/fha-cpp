// author: paddel@paddel.xyz

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void out(double a[], int dim);

int main() {
    double a[3] = {1.0, 2.0 };
    a[2] = a[0] + a[1];

    cout << " " << a[0];
    cout << " " << a[1];
    cout << " " << a[2] << endl;

    double b[3];
    for (int i = 0; i < 3; i++)
    {
        b[i] = a[i];
    }
    out(b, 3);
    return 0;
}

void out(double a[], int dim) {
    for (int i = 0; i < dim; i++)
        cout << a[i] << endl;
}