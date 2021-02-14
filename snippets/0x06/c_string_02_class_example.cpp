// author: a.voss@fh-aachen.de

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

class string1 {                                             // (A)
    char * p;

public:
    string1(const char* Src) : p(new char [strlen(Src)+1]) {// (B)
        strcpy(p,Src); 
    }
    
    string1(const string1& s) : p(new char [strlen(s.p)+1]) { 
        strcpy(p,s.p); 
    }
    
    ~string1() { delete [] p; }

    string1 & operator=(const string1 & s) {                // (C)
        if (this!=&s) {
            delete [] p;
            p = new char [strlen(s.p)+1];
            strcpy(p,s.p); 
        }
        return *this;
    }
    
    friend ostream & operator<<(ostream & os, string1 const& s ) {
        os << s.p; 
        return os;
    }
};

class string2 {
    char * p;
    
public:
    
    string2(const char* Src) : p(new char [strlen(Src)+1]) { 
        strcpy(p,Src); 
    }
    
    string2(const string2& s) : string2(s.p) { }            // (D)
    
    ~string2() { delete [] p; }

    // s1 = s2      s1.op=(s2)
    string2 & operator=(string2 s) {                        // (E)
        swap(p,s.p);                     
        return *this;
    }
    
    string2 & operator+=(const string2 & rhs) {
		char* q = new char [strlen(p)+strlen(rhs.p)+1];
		strcat(strcpy(q,p),rhs.p);
		swap(p,q);
		delete [] q;
		return *this;
	}
	
	friend const string2 operator+(string2 lhs, const string2 & rhs) {	
		return lhs+=rhs;
	}
    
    friend ostream & operator<<(ostream & os, const string2 & s ) {
        os << s.p; return os;
    }
};


int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    string1 s1{"S1"};
    string1 s2{"S2"};

    // s1 = s2;

    cout << "01|    s1='" << s1 << "'" << endl;
    cout << "02|    s2='" << s2 << "'" << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  a naive approach
 * 
 * (B)  Was fällt an den ctors auf?
 * 
 * (C)  Es gibt zwei Probleme hier:
 *          - ist "if (this!=... " notwendig und für welchen Fall?
 *          - Was kann in dem Code schiefgehen?
 * 
 * (D)  Keine Code-Duplikate, da anderer ctor verwendet wird.
 * 
 * (E)  Dadurch, dass es ein copy-by-value ist, gibt es entweder ein
 *      gültiges Argument (und kein out-of-mem.) oder nicht. In jedem
 *      Fall wird der alte Speicher nur verändert, wenn die Kopie gültig
 *      ist. Dann wird der Speicher des Parameters weiterverwendet und 
 *      an seiner statt der alte Speicher freigegeben.
 *      Gleiches Prinzip in op+.
 * 
 */
 
