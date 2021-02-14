// author: a.voss@fh-aachen.de

#include <iostream>
#include <iomanip>
#include <memory>
using std::cout;
using std::endl;
using std::ostream;
using std::unique_ptr;                                      // (A)
using std::make_unique;                                     // (B)

template <typename T>
class list {
public:
    typedef T value_type;
    struct node {
        value_type value;
        unique_ptr<node> next;
        
        public:
            node(const value_type& value) : value(value) {}
    };
    
    list() : count{0} {}
        
    void add(const value_type& value) {
        auto n = make_unique<node>(value);
        if (root==nullptr) {
            root = std::move(n);
        } else {
            n->next = std::move(root);
            root = std::move(n);
        }
        ++count;
    }
    
    void clear() {
        root.reset();
    }
    
    friend ostream& operator<<(ostream& os, const list& l) {
        os << "[";
        
        bool first{true};
        auto* p=&(l.root);
        while (p->get()!=nullptr) {
            if (first) { first=false; } else { os << ","; }
            os << (*p)->value;
            p = &((*p)->next);
        }
        os << "](" << l.count << ")";
        
        return os;
    }
    
private:
    unique_ptr<node> root;
    size_t count;
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    list<int> l;
    cout << "01|    p='" << endl;
    
    l.add(1);
    l.add(2);
    l.add(3);
    cout << "01|    p='" << l << endl;
    
    l.clear();
    cout << "01|    p='" << l << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
