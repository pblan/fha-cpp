// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::string;

class car {
    string brand_;
    string sign_;
    unsigned int seats_;
    unsigned int max_velocity_;
    
public:
    car(const string& brand, const string& sign, unsigned int seats)
        : brand_{brand}, sign_{sign},
          seats_{seats}, max_velocity_{(brand_ == "ferrari") ? 300u : 250u}
    { }
    
    string brand() const { return brand_; }
    string sign() const { return sign_; }
    unsigned int seats() const { return seats_; }
    unsigned int max_velocity() const { return max_velocity_; }

    void set_sign(const string& value) { sign_ = value; }

    // [s] = [t]*[s/t]
    int max_distance(int time) const {
        return time * max_velocity_;
    }
    
    // [t] = [s]/[s/t]
    double min_time(int distance) const {
        return (double)distance/(double)max_velocity_;
    }
};

ostream& operator<<(ostream& os, const car& c) {
    os << "[" << c.brand() << " '" << c.sign() << "'"
        << " (" << c.seats() << "," << c.max_velocity() << ")]";
    return os;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    car c1("bmw","ac-h 1234",4);
    car c2("ferrari","ac-h 6789",2);
 
    cout << "01|    c1:" << c1 << endl;    
    cout << "02|    c2:" << c2 << endl;

    cout << "-----" << endl;
    
    c1.set_sign("ac-dc 6666");
    cout << "03|    c1:" << c1 << endl;    

    cout << "-----" << endl;

    cout << "04|    max Strecke im BMW nach 2h: " 
         << c1.max_distance(2) << "km" << endl;    

    cout << "05|    min. Zeit für 600km im Ferrari: " 
         << c2.min_time(600) << "h" << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
