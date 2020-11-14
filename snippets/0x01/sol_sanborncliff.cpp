// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

void out(double x[], int dim);

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    const int dim{3};
    cout << "01|    dim=" << dim << endl;
    
    double a[dim] = { 1.0, 2.0 };
    a[2] = a[0]+a[1];
    cout << "02|    a[0]=" << a[0] 
        << ", a[1]=" << a[1] 
        << ", a[2]=" << a[2] << endl;

    double b[dim];
    for (int i=0; i<dim; ++i)
        b[i]=a[i];
        
    out(b,dim);
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

void out(double x[], int dim) {
    cout << "03|    x[0]=" << x[0];
    for (int i=1; i<dim; ++i)
        cout << ", x[" << i << "]=" << x[i];
    cout << endl;
}
