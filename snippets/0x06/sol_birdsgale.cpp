// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

void out(const char* a[], const int dim) {
    cout << "01|    dim=" << dim << endl;
    for (int i=dim-1; i>=0; --i)
        cout << "02|      a[i]=" << a[i] << endl;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    const int dim{4};
    const char* a[dim] = {
        "Dies", "ist", "ein", "Satz"
    };
    out(a,dim);

    cout << "-----" << endl;
    
    for (int i=0; i<dim/2; ++i) {
        const char* p = a[i];
        a[i] = a[dim-1-i];
        a[dim-1-i] = p;
    }
    out(a,dim);
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
