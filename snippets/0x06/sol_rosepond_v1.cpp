// author: a.voss@fh-aachen.de

#include <iostream>
#include <unordered_map>
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

struct address {
    string name;
    string number;
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    unordered_map<int,address*> map;
    
    map[1] = new address{"Max","112"};
    map[2] = new address{"Mini","110"};
    map[3] = new address{"Jane","911"};
    
    cout << "01|    size map=" << map.size() << endl;
    
    for (auto a:map) {
        cout << "02|      {id:" << a.first 
            << ", name:" << a.second->name 
            << ", number:" << a.second->number << "}" << endl;
    }

    cout << "-----" << endl;

    unordered_map<int,address*>::iterator it{map.begin()};
    while (it!=map.end()) {
        delete it->second;
        // it = map.erase(it);  // C++11
        map.erase(it++);        // < C++11
    }

    // for (auto a:map) {       // all
    //     delete a.second;
    // }
    // map.clear();
    cout << "03|    size map=" << map.size() << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
