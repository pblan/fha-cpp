// author: a.voss@fh-aachen.de

#include <iostream>
#include <vector>
#include <memory>
using std::cout;
using std::endl;
using std::ostream;
using std::vector;
using std::unique_ptr;

struct data {
    int n{};
};


int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    
    vector<data*> v1;
    v1.push_back(new data());
    
    cout << "01|    v1.size: " << v1.size() << endl; 
    
    for (auto p : v1)
        delete p;
    v1.clear();
    
    //

    vector<unique_ptr<data>> v2;
    v2.push_back(std::make_unique<data>());
    
    cout << "02|    v2.size: " << v2.size() << endl; 
    
    v2.clear();

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

 
