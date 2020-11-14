// author: a.voss@fh-aachen.de

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    int a[] = {2,3,5,7};

    cout << "01|    a[]={2,3,5,7}" << endl;
    for (auto n : a) {
        cout << "02|      n=" << n << endl;
    }

    cout << "-----" << endl;
    
    vector<int> v{2,3,5,7};

    cout << "03|    v={2,3,5,7}" << endl;
    for (auto n : v) {
        cout << "04|      n=" << n << endl;
    }
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
