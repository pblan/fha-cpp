#include <iostream>
#include <unordered_map>
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::unordered_map;

struct buch
{
    string autor;
    string titel;
};

ostream& operator<<(ostream& os, const buch& b) {
    os << "{" << b.autor << ": " << b.titel << "}";
    return os;
}

typedef unordered_map<string, buch> katalog_t;

int main() {

    katalog_t katalog;
    
    katalog["978-3-598-21500-1"]={"Autor 1", "Buch 1"};
    katalog["978-3-598-21501-8"]={"Autor 2", "Buch 2"};
    katalog["978-3-598-21502-5"]={"Autor 3", "Buch 3"};

    for (const auto& x : katalog) {
        if (x.second.titel.size() > 3) cout << x.first << ", " << x.second << endl;
    }

    return 0;
}