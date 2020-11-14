// author: a.voss@fh-aachen.de

#include <iostream>
#include <unordered_map>
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::unordered_map;

struct buch {
    string autor;
    string titel;
};

ostream& operator<<(ostream& os, const buch& b) {
    os << "{" << b.autor << ":" << b.titel << "}";
    return os;
}

typedef unordered_map<string,buch> katalog_t;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    katalog_t katalog;
    
    katalog["344245381X"]={"Walter Moers","Die 13 1/2 Leben des Käpt'n Blaubär"};
    katalog["3492241778"]={"Walter Moers","Rumo & Die Wunder im Dunkeln"};
    katalog["3492246885"]={"Walter Moers","Die Stadt der träumenden Bücher"};
    
    cout << "01|    katalog, lange Titel:" << endl;
    for (const auto& buch: katalog) {
        if (buch.second.titel.size()>30)
            cout << "02|      " << buch.first << "->" << buch.second << "'" << endl;
    }

    cout << "-----" << endl;

    cout << "03|    katalog, lange Titel:" << endl;
    for (katalog_t::const_iterator it = katalog.cbegin(); it!=katalog.cend(); ++it) {
        if ((*it).second.titel.size()>30)
        cout << "04|      " << (*it).first << "->" << (*it).second << "'" << endl;
    }
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
