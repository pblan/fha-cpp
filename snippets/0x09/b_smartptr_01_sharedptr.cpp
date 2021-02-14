// author: a.voss@fh-aachen.de

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

struct C {
    int id;

    C(int id) : id(id) { cout << "-1|      C(), id=" << id << ", this=" << this << endl; }
    C(const C& c) : id(c.id) { cout << "-2|      C(C), id=" << id << endl; }
    ~C() { cout << "-3|      ~C(), id=" << id << endl; }
    
    friend ostream & operator<<(ostream& os, const C& c) { 
        os << c.id; 
        return os; 
    }
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01|    shared_ptr<C>" << endl;

    shared_ptr<C> p1 = make_shared<C>(1);
    shared_ptr<C> p2 = p1;

    cout << "-----" << endl;
    
    cout << "02|    *p1=" << (*p1) << ", p1.get=" << p1.get() 
         << ", p1.use_cnt: " << p1.use_count() << endl;
    cout << "03|    *p2=" << (*p2) << ", p2.get=" << p2.get() 
         << ", p2.use_cnt: " << p2.use_count() << endl;
 
    cout << "-----" << endl;

    p1.reset(); 
    cout << "04|    *p1=" << "-" << ", p1.get=" << p1.get() 
         << ", p1.use_cnt: " << p1.use_count() << endl;
    cout << "05|    *p2=" << (*p2) << ", p2.get=" << p2.get() 
         << ", p2.use_cnt: " << p2.use_count() << endl;

    cout << "-----" << endl;

    p2.reset(); 
    cout << "06|    *p1=" << "-" << ", p1.get=" << p1.get() 
         << ", p1.use_cnt: " << p1.use_count() << endl;
    cout << "07|    *p2=" << "-" << ", p2.get=" << p2.get() 
         << ", p2.use_cnt: " << p2.use_count() << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

// why make_unique?
// f(make_unique<T>(), make_unique<U>());
// f(unique_ptr<T>(new T()), unique_ptr<U>(new U())); 
// or
// f(unique_ptr<T>(new T), function_that_can_throw());
// compiler is allowed to call (in order): 
//     new T, function_that_can_throw(), unique_ptr<T>(...)
