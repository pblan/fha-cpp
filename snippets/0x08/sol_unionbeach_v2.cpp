// author: a.voss@fh-aachen.de

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <iomanip>
using namespace std;

template <typename T>
class matrix
{
public:
    typedef T value_type;
    
    matrix(size_t dim) : dim(dim) {}
    virtual ~matrix() {}

    virtual value_type at(size_t line, size_t col) const = 0;
    virtual value_type& at(size_t line, size_t col) = 0;
    
    virtual void make_zero() = 0;
    virtual void make_unit() {
        make_zero();
        for (size_t i=0; i<dim; ++i) {
            at(i,i)=1.0;
        }
    }

    const size_t dim;
};

template <typename T>
class full_matrix : public matrix<T>
{
public:
    typedef matrix<T> matrix_type;
    typedef typename matrix<T>::value_type value_type;

    full_matrix(size_t dim) 
        : matrix_type(dim), data(make_unique<value_type[]>(dim*dim)) {}

    virtual value_type at(size_t line, size_t col) const {
        return *(data.get()+line*matrix_type::dim+col);
    }

    virtual value_type& at(size_t line, size_t col) {
        return *(data.get()+line*matrix_type::dim+col);
    }

    virtual void make_zero() {
        value_type *p{data.get()},*p0{p+matrix_type::dim*matrix_type::dim};
        while (p!=p0) {
            *(p++) = 0;
        }
    }

protected:
    unique_ptr<value_type[]> data;
};

template <typename T>
class sparse_matrix : public matrix<T>
{
public:
    typedef matrix<T> matrix_type;
    typedef typename matrix<T>::value_type value_type;

    sparse_matrix(size_t dim) 
        : matrix_type(dim) {}
    
    virtual value_type at(size_t line, size_t col) const {
        auto it = data.find(line*matrix_type::dim+col);
        return (it!=data.end()) ? it->second : 0.0;
    }

    virtual value_type& at(size_t line, size_t col) {
        auto rc = data.emplace(make_pair(line*matrix_type::dim+col,0));
        return rc.first->second;
    }

    virtual void make_zero() {
        data.clear();
    }

protected:
    unordered_map<size_t,value_type> data;
};

template <typename T>
ostream& operator<<(ostream& os, const matrix<T>& M) {
        os << "[";
        for (size_t l=0; l<M.dim; ++l) {
            if (l>0) os << ",";
            os << "[";
            for (size_t c=0; c<M.dim; ++c) {
                if (c>0) os << ",";
                os << M.at(l,c);
            }
            os << "]";
        }
    return os;
//    return M.to_ostream(os);
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    
    full_matrix<long double> M(3); 

    M.make_zero();
    cout << "01|    M: " << M << endl; 
    
    M.make_unit();
    cout << "02|    M: " << M << endl; 

    cout << "-----" << endl;

    sparse_matrix<long double> S(3);
    
    S.make_zero();
    cout << "03|    S: " << S << endl; 

    S.make_unit();
    cout << "04|    S: " << S << endl; 

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 */
 
