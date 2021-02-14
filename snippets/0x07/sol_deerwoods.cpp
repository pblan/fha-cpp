// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

template <typename T>
class nullable {
public:
    typedef T value_type;
    
private:
    value_type m_value;
    bool m_isNull;
    
public:
    nullable() : m_isNull(true) {}
    
    nullable(const nullable& n) : m_value(n.m_value), m_isNull(n.m_isNull) {}

    nullable(const value_type& value) : m_value(value), m_isNull(false) {}
 
    bool operator!() const {
        return !m_isNull;
    }
    
    void reset() {
        m_isNull = true;
    }
    
    operator T() const {
        return m_value;
    }
 
    nullable& operator+=(const nullable& n) { 
        if (!m_isNull)
            m_value += n.m_value;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const nullable& n) {
        if (!n) 
            os << n.m_value;
        else 
            os << "NULL";
        return os;
    }
    
    friend nullable operator+(const nullable& lhs, const nullable& rhs) {
        nullable res{lhs};
        return res+=rhs;
    }
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    nullable<int> n0,n1(23),n2(n1);

    cout << "01|    n0:" << n0 << ", n1:" << n1 << ", n2:" << n2 << endl; 
    
    n0 = 0;
    n1 = 1;
    n2.reset();
    cout << "02|    n0:" << n0 << ", n1:" << n1 << ", n2:" << n2 << endl; 

    cout << "-----" << endl;

    n0 += 10;
    n1 += 10;
    n2 += 10;    
    cout << "03|    n0:" << n0 << ", n1:" << n1 << ", n2:" << n2 << endl; 
    cout << "04|    !n0:" << !n0 << ", !n1:" << !n1 << ", !n2:" << !n2 << endl; 

    cout << "-----" << endl;

    n0 = 0; n1 = 1; n2 = 2;
    cout << "05|    n0:" << n0 << ", n1:" << n1 << ", n2:" << n2 
         << ", (int)n2:" << (int)n2 << endl; 
         
    cout << "06|    n1+n2:" << n1+n2 << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

