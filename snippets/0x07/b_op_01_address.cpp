// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

class address {
    int n{23};

public:
    address() { 
        cout << "-a|      ctor(), n=" << n << endl;
    }
    
    int test() { return n; }
        
    address* operator&() const { return nullptr; }
    // pa = std::addressof(a);
    
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01|    start" << endl;
    
    address a;

    cout << "02|    test1: " << a.test() << endl;
    
    address* pa = &a;

    cout << "03|    test2: " << pa << " " << endl;
    cout << pa->test() << endl;

    cout << "04|    stop" << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 *
 * Vorsicht beim Umgang mit Operatoren
 */

