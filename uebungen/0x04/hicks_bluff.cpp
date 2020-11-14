// author: paddel@paddel.xyz

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <array>
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::find;
using std::ostream;
using std::array;
using std::out_of_range;

int main() {
    vector<int> v{1,2,3,4,5};

    int print{3};
    int i{0};
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        if (*it == 2 && i == 0) {
            cout << "Element gefunden!" << endl;
            i = 1;
        }

        if (i > 0 && i <= print) {
            cout << " " << *it << " ";
            i++;
        }
    }
    cout << endl;

    unordered_map<int, string> map{{1, "Eins"}, {2, "Zwei"}, {3, "Drei"}, {4, "Vier"}, {5, "Fünf"}};
    
    for (auto x : map) {
        if (x.first == 2) cout << "Gefunden!" << endl;
    }

    for (auto it = map.begin(); it != map.end(); ) // Drittes Feld leer!!
    {
        if ((*it).first > 2) it = map.erase(it);
        else ++it;
    }
    cout << endl;
    

    for (auto x : map) {
        cout << "{" << x.first << "," << x.second << "} ";
    }
    cout << endl;

    return 0;
}