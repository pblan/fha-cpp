// author: a.voss@fh-aachen.de

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::vector;
using std::out_of_range;
using std::runtime_error;

class states {
    vector<string> m_states;
    size_t pos;
    
public:
    states() : pos(0) {}

    states& operator=(size_t pos) {
        if (pos>=m_states.size())
            throw out_of_range("index wrong");
        this->pos = pos;
        return *this;
    }
    
    states& operator+=(const string& state) {
        m_states.push_back(state);
        return *this;
    }
    
    size_t operator()() const {
        return pos;
    }

    const string& operator[](size_t pos) const {
        if (pos>=m_states.size())
            throw runtime_error("no current state");
        return m_states[pos];
    }
    
    states& operator++() {
        if (m_states.size()==0)
            throw runtime_error("states empty");

        if (pos!=m_states.size()-1)
            ++pos;
        else
            pos=0;
        return *this;
    }

    states& operator--() {
        if (m_states.size()==0)
            throw runtime_error("states empty");

        if (pos==0)
            pos = m_states.size()-1;
        else
            --pos;
        return *this;
    }
    
    void clear() {
        m_states.clear();
        pos = 0;
    }
    
    friend ostream& operator<<(ostream& os, const states& s) {
        os << "{";
        for (size_t i{0}; i<s.m_states.size(); ++i) {
            os << ((i>0)?",":"") << s.m_states[i];
        }
        os << "}";
        return os;
    }
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    states s;

    cout << "01|    S: " << s << endl; 
    
    s+="unknown";
    cout << "02|    S: " << s << ", aktuell: '" << s[s()] << "'" << endl; 

    s+="connected";
    s+="disconnected";
    cout << "03|    S: " << s << ", aktuell: '" << s[s()] << "'" << endl; 

    cout << "-----" << endl;
    
    s = 1;
    cout << "04|    s=1, aktuell: '" << s[s()] << "'" << endl; 

    ++s;
    cout << "05|    ++s, aktuell: '" << s[s()] << "'" << endl; 
    ++s;
    cout << "06|    ++s, aktuell: '" << s[s()] << "'" << endl; 
    --s;
    cout << "07|    ++s, aktuell: '" << s[s()] << "'" << endl; 

    cout << "-----" << endl;

    s.clear();
    cout << "08|    S: " << s << endl; 

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
 
