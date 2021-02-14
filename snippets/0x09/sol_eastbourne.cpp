// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

template <typename T>
class point {
    public:
        point() {}
        
    private:
        T x{},y{};
        
    public:
    friend ostream & operator<<(ostream& os, const point& p) { 
        os << "(" << p.x << "," << p.y << ")"; 
        return os; 
    }
};

template <>
class point<bool> {
    point(){}
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    
    point<int> p1;
    cout << "01|    p1: " << p1 << endl; 

    // point<bool> p2;
    // cout << "02|    p2: " << p2 << endl; 

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

 
