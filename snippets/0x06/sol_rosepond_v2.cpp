// author: a.voss@fh-aachen.de

#include <iostream>
#include <unordered_map>
#include <memory>
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::unique_ptr;
using std::make_unique;

struct address {
    string name;
    string number;
    
    address(const string& name, const string& number)
        : name(name), number(number) {}
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    unordered_map<int,unique_ptr<address>> map;
    
    map[1] = make_unique<address>("Max","112");
    map[2] = make_unique<address>("Mini","110");
    map[3] = make_unique<address>("Jane","911");
    
    cout << "01|    size map=" << map.size() << endl;
    
    for (auto& a:map) {
        cout << "02|      {id:" << a.first 
            << ", name:" << a.second->name 
            << ", number:" << a.second->number << "}" << endl;
    }

    cout << "-----" << endl;
    
    map.clear();
    cout << "03|    size map=" << map.size() << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
