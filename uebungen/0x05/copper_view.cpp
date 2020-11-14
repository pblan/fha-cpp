#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
    int a{5};
    float b{3.5}; 

    int* ap{&a};
    float* bp{&b};

    cout << "*ap: " << *ap << ", a: " << a << endl;
    cout << "*bp: " << *bp << ", b: " << b << endl;

    *ap += 1;
    *bp /= 2;

    cout << "*ap: " << *ap << ", a: " << a << endl;
    cout << "*bp: " << *bp << ", b: " << b << endl;

    int** app{&ap};
    
    cout << "*app: " << **app << ", *ap: " << *ap << ", a: " << a << endl;

    return 0;
}
