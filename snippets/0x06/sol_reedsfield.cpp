// author: a.voss@fh-aachen.de

#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::hex;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    const char* p{"hallo"};
    cout << "01|    p='" << p << "'" << endl;

    const char* q{p};
    do {
        cout << "02|      *q='" << *q << "', =" << +*q 
            << ", q=" << hex << (void*)q << endl;
    } while (*(q++)!='\0');
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
