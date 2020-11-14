// author: a.voss@fh-aachen.de

#include <iostream>
#include <vector>
#include <unordered_map>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::unordered_map;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;
    
    vector<int> v{1,2,3,4,5};
    int pattern{2};

    cout << "01|    suche " << pattern << " in 'v' und ab da (max.) drei Elemente" << endl;

    size_t i{0};
    auto itv{v.cbegin()};
    while (itv!=v.cend() && i<=3) {                         // (A)
        if (0==i && *itv==pattern) {
            i=1;
            cout << "02|      gefunden!" << endl;
        }
        if (i>0) {
            cout << "03|      element " << i << " =" << *itv << endl;
            ++i;
        }
        ++itv;
    }
    
    unordered_map<int,string> m{ {1,"Eins"},{2,"Zwei"},{3,"Drei"},{4,"Vier"},{5,"Fünf"} };

    cout << "-----" << endl;

    cout << "04|    suche " << pattern << " in 'm'" << endl;
    
    auto itm{m.find(pattern)};
    if (itm!=m.cend()) {
        cout << "05|      gefunden! " << (*itm).first << "->'" << (*itm).second << "'" << endl;
    }

    cout << "-----" << endl;

    cout << "06|    lösche alles > " << pattern << " in 'm'" << endl;
    
    for (auto it=m.begin(); it!=m.end(); ) {
        if (it->first>pattern) {                            // (B)
            cout << "07|      lösche " << (*it).first << "->'" << (*it).second << "'" << endl;
            it = m.erase(it);
        } else {
            ++it;
        }
    }

    cout << "08|    m: { ";
    for (auto it=m.cbegin(); it!=m.cend(); ++it) {
        cout << "{" << (*it).first << "->'" << (*it).second << "'} ";
    }
    cout << "}" << endl;
    
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Später werden wir auch noch Standard-Algorithmen in <algorithm>
 *      betrachten.
 * 
 * (B)  (*it).first ist gleich it->first
 */
