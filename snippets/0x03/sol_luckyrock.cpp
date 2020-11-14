// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::string;

class kontakt {
    unsigned int age_;
    string name_;
    
public:
    kontakt() : age_{}, name_{} {}

    // ~kontakt() {}
    ~kontakt() = default;

    kontakt(unsigned int age, const string& name)
        : age_{age}, name_{name} {}

    // kontakt(const kontakt& k)
    //     : m_age{k.m_age}, m_name{k.m_name} {}
    kontakt(const kontakt& k) = default;

    [[nodiscard]] unsigned int age() const { return age_; }
    void set_age(unsigned int value) { age_ = value; }

    [[nodiscard]] string name() const { return name_; }
    void set_name(const string& value) { name_ = value; }
};

ostream& operator<<(ostream& os, const kontakt& k) {
    os << "(" << k.age() << ",'" << k.name() << "')";
    return os;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    kontakt k1;
    kontakt k2(2,"k2");
    kontakt k3{k2};
    
    cout << "01|    k1=" << k1 << endl;
    cout << "02|    k2=" << k2 << endl;
    cout << "03|    k3=" << k3 << endl;
    
    cout << "-----" << endl;

    k1.set_age(1); k1.set_name("k1");
    k3.set_age(3); k3.set_name("k3");

    cout << "04|    k1=" << k1 << endl;
    cout << "05|    k2=" << k2 << endl;
    cout << "06|    k3=" << k3 << endl;

    cout << "-----" << endl;
    
    const kontakt& rk{k1};
    unsigned int age{rk.age()};
    string name{rk.name()};
    cout << "07|    age=" << age << ", name='" << name << "'" << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
