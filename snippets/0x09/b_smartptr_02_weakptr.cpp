// author: a.voss@fh-aachen.de

#include <iostream>
#include <vector>
#include <memory>
using std::cout;
using std::endl;
using std::ostream;
using std::shared_ptr;
using std::weak_ptr;
using std::make_shared;
using std::vector;
using std::string;

#define USE_WEAK

struct member;
struct group;

struct group {
    vector<shared_ptr<member>> members;
    string name;

    group(const string& name) : name(name) {
        cout << "-1|      group ctor, name=" << name << endl; 
    }
    ~group() {
        cout << "-2|      ~group dtor, name=" << name << endl; 
    }
};

struct member {
    
#if defined(USE_WEAK)
    vector<weak_ptr<group>> groups;
#else
    vector<shared_ptr<group>> groups;
#endif
    string name;
    
    member(const string& name) : name(name) {
        cout << "-3|      member ctor, name=" << name << endl; 
    }
    ~member() {
        cout << "-4|      ~member dtor, name=" << name << endl; 
    }
};

void operator+=(shared_ptr<group>& g, shared_ptr<member>& m) {
    g->members.push_back(m);
    m->groups.push_back(g);
}

ostream & operator<<(ostream& os, const shared_ptr<group>& g) { 
    os << "group:'" << g->name << "'(" << g.use_count() << "), members:{";
    for (size_t i{0}; i<g->members.size(); ++i) {
        os << ((i>0)?",'":"'") << g->members[i]->name << "'"
           << "(" << g->members[i].use_count() << ")"; 
    }
    os << "}";
    return os; 
}

ostream & operator<<(ostream& os, const shared_ptr<member>& m) { 
    os << "member:'" << m->name << "'(" << m.use_count() << "), groups:{";
    for (size_t i{0}; i<m->groups.size(); ++i) {
#if defined(USE_WEAK)
        shared_ptr<group> g = m->groups[i].lock();
#else
        shared_ptr<group>& g = m->groups[i];
#endif
        os << ((i>0)?",'":"'") << g->name << "'"
           << "(" << g.use_count() << ")"; 
    }
    os << "}";
    return os; 
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01|    create groups and members" << endl;

    {
        shared_ptr<group> g1 = make_shared<group>("Men");
        shared_ptr<group> g2 = make_shared<group>("Woman");
        shared_ptr<group> g3 = make_shared<group>("Mixed");

        shared_ptr<member> m1 = make_shared<member>("Peter");
        shared_ptr<member> m2 = make_shared<member>("Paul");
        shared_ptr<member> m3 = make_shared<member>("Mary");
    
        g1+=m1;
        g1+=m2;

        g2+=m3;

        g3+=m1;
        g3+=m3;

        cout << "02|    g1: " << g1 << endl;
        cout << "03|    g2: " << g2 << endl;
        cout << "04|    g3: " << g3 << endl;

        cout << "-----" << endl;

        cout << "05|    m1: " << m1 << endl;
        cout << "06|    m2: " << m2 << endl;
        cout << "07|    m3: " << m3 << endl;
    }
    
    cout << "08|    all done" << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

 
