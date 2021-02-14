// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

template <typename T, int DIM>                              // (A)
struct vector_special {
    static const size_t dim = DIM;
    T data[dim];
    
    T operator[](int i) const { return data[i]; }
    T& operator[](int i) { return data[i]; }
    
    template <typename S>                                   // (B)
    vector_special& operator=(const vector_special<S,DIM> & v) {
        for (size_t i=0; i<dim; ++i)
            data[i] = (T)(v.data[i]);                       // (C)
        return *this;
    }
};

template <typename T>                                       // (D)
struct vector_special<T,0> {
    static const size_t dim = 0;
    T data;
    
    T operator[](int) const { return data; }
    T& operator[](int) { return data; }
};

template<class T>                                           // (E)
using vector_special3d = vector_special<T,3>;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    vector_special<int,3> v3{1,2,3};
    vector_special<int,0> v0{4};

    cout << "01|    size(v3)=" << sizeof(v3) << ", v3[0]=" << v3[0] << endl;
    cout << "02|    size(v0)=" << sizeof(v0) << ", v0[0]=" << v0[0] << endl;
    
    vector_special<double,3> d3{};
    
    d3 = v3;
    cout << "03|    size(d3)=" << sizeof(d3) << ", d3[0]=" << d3[0] << endl;

    // v3 = v0;
    
    vector_special3d<char> c3{'a','b','c'};
    cout << "04|    size(c3)=" << sizeof(c3) << ", c3[0]='" << c3[0] << "'" << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Eine Vektorklasse analog zu STL-array mit Typ und Dimension.
 * 
 * (B)  Durch diesen Template-Operator ist es möglich, auch andere
 *      Vektoren gleicher Dimension (deshalb nur ein Template-Parameter)
 *      zu kopieren, wenn die Elemente zu kopieren sind.
 * 
 * (C)  Siehe (B), hier findet die elementweise Kopie statt.
 * 
 * (D)  Eine Spezialisierung für den Fall dim=0.
 * 
 * (E)  Ein templatisiertes typedef sozusagen, bei dem z.B. die Dimension
 *      festgelegt ist.
 * 
 */
 
