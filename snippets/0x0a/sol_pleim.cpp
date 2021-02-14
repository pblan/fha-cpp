// author: a.voss@fh-aachen.de

#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::endl;
using std::ostream;
using std::vector;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& a) {
    os << "[ ";
    for (auto x : a) {
        os << x << " ";
    }   
    os << "]";
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& a) {
    os << "[" << endl;
    for (auto x : a) {
        os << "  " << x << endl;
    }   
    os << "]" << endl;
    return os;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    
    const unsigned int dim{5};
    vector<int> v(dim+1);
    
    struct nk {
        nk(int n): n{n},k{0} { }
        int operator()() { 
            if (k==0) { ++k; return 1; }
            else if (k==1) { a=n; b=1; ++k; return n;}
            else if (k<n) { a*=(n-k+1); b*=k; ++k; return a/b; }
            else if (k==n) { ++k; return 1; }
            else { return -1; }
        }
        int n,k,a,b;
    };
    std::generate(v.begin(), v.end(), nk(dim));

    cout << "01|    dim: " << dim << ", v: " << v << endl; 

    cout << "-----" << endl;

    vector<vector<unsigned int>> A(dim);

    unsigned int i=0;
    std::for_each(A.begin(), A.end(), 
        [&A,&i](vector<unsigned int>& v){ 
            v.resize(i+1); 
            std::generate(v.begin(), v.end(), nk(i));
            ++i;
        } );

    cout << "02|    dim: " << dim << ", A: " << endl << A << endl; 
 
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

 
