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

    for (auto i : a)
    {
        cout << "a: " << i << endl;  
    }

    for (auto i : v)
    {
        cout << "v: " << i << endl;  
    }

    return 0;
}