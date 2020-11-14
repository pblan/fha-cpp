// author: paddel@paddel.xyz

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <array>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::find;
using std::ostream;
using std::array;
using std::out_of_range;

int main() {
    int a[] = {2,3,5,7};
    vector<int> v{2,3,5,7};

    cout << "range-based-for (array):";
    for (auto i : a)
    {
        cout << " " << i << " ";  
    }
    cout << endl;

    cout << "ranged-based-for (vector):";
    for (auto i : v)
    {
        cout << " " << i << " ";
    }
    cout << endl;

    cout << "ranged-based for mit alias (vector)";
    for (auto& i : v)
    {
        i *= 2;
        cout << " " << i << " ";
    }
    cout << endl;

    cout << "it_type (vector<T>::const_iterator) (vector):";
    typedef vector<int>::const_iterator it_type;
    for (it_type it = v.cbegin(); it != v.cend(); ++it) {
        cout << " " << *it << " ";
    }
    cout << endl;

    return 0;
}