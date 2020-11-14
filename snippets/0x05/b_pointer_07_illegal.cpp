// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    int n1{23};
    int n2{42};
    cout << "01| n1=" << n1 << ", n2=" << n2 << endl;

    int* pn{&n1};   // Zeiger auf n1!!!
    *(pn-1)=123;    // verändert Wert in n2 über Zeiger auf n1!!!
    cout << "02| n1=" << n1 << ", n2=" << n2 << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

