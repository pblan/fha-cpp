// author: a.voss@fh-aachen.de

#include <iostream>
#include <array>
using std::cout;
using std::endl;
using std::ostream;
using std::array;

template <typename T, size_t DIM>
class fastvector {
public:
    typedef T value_type;
    static const size_t dim = DIM;
    
private:
    array<T,dim> m_data;
    
public:

    fastvector& operator=(const value_type& c) {
        for (size_t i{0}; i<dim; ++i) {
            m_data[i]=c;
        }
        return *this;
    }
    
    const value_type& operator[](size_t pos) const {
        return m_data[pos];
    }

    value_type& operator[](size_t pos) {
        return m_data[pos];
    }
    
    fastvector& operator+=(const fastvector& v) { 
        for (size_t i{0}; i<dim; ++i) {
            m_data[i]+=v.m_data[i];
        }
        return *this;
    }

    fastvector& operator-=(const fastvector& v) { 
        for (size_t i{0}; i<dim; ++i) {
            m_data[i]-=v.m_data[i];
        }
        return *this;
    }

    fastvector& operator*=(const value_type& c) { 
        for (size_t i{0}; i<dim; ++i) {
            m_data[i]*=c;
        }
        return *this;
    }

    fastvector& operator-() { 
        fastvector res{*this};
        for (size_t i{0}; i<dim; ++i) {
            m_data[i]*=(value_type)(-1);
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const fastvector& v) {
        os << "{";
        for (size_t i{0}; i<v.dim; ++i) {
            os << ((i>0)?",":"") << v.m_data[i];
        }
        os << "}";
        return os;
    }
};

template <typename T, size_t DIM>
fastvector<T,DIM> operator+(const fastvector<T,DIM>& lhs, const fastvector<T,DIM>& rhs) {
    fastvector<T,DIM> res{lhs};
    return res+=rhs;
}

template <typename T, size_t DIM>
fastvector<T,DIM> operator-(const fastvector<T,DIM>& lhs, const fastvector<T,DIM>& rhs) {
    fastvector<T,DIM> res{lhs};
    return res-=rhs;
}

template <typename T, size_t DIM>
fastvector<T,DIM> operator*(const fastvector<T,DIM>& lhs, const T& rhs) {
    fastvector<T,DIM> res{lhs};
    return res*=rhs;
}

template <typename T, size_t DIM>
fastvector<T,DIM> operator*(const T& lhs, const fastvector<T,DIM>& rhs) {
    return rhs*lhs;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    fastvector<int,3> v0,v1,v2;

    cout << "01|    v0:" << v0 << ", v1:" << v1 << ", v2:" << v2 << endl; 
    
    v0=0; v1=1; v2=2;
    cout << "02|    v0:" << v0 << ", v1:" << v1 << ", v2:" << v2 << endl; 

    cout << "-----" << endl;
    
    cout << "03|    v1+v2:" << (v1+v2) << endl;
    cout << "04|    v1-v2:" << (v1-v2) << endl;
    cout << "05|    v2*3:" << (v2*3) << endl;
    cout << "06|    4*v2:" << (4*v2) << endl;
    cout << "07|    -v1:" << (-v1) << endl;
    
    cout << "-----" << endl;

    fastvector<int,3> v3;
    const fastvector<int,3>& v22{v2};
    for (size_t i{0}; i<v2.dim; ++i) {
        v3[i] = v1[i]+v22[i];
    }    
    cout << "08|    v3:" << v3 << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

