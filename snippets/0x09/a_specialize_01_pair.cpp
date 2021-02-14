// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

template <typename T1, typename T2>                         // (A)
struct pair_special {
    T1 key;
    T2 value;
    
    pair_special(T1 t1, T2 t2) : key(t1), value(t2) {}
    
    friend ostream& operator<<(ostream& os, const pair_special& p) {
        os << "[" << p.key << ":" << p.value << "] <T1,T2>";
        return os;
    }
};

template <typename T2>                                      // (B)
struct pair_special<int,T2> {
    long key;
    T2 value;
    
    friend ostream& operator<<(ostream& os, const pair_special& p) {
        os << "[" << p.key << ":" << p.value << "] <int,T2>";
        return os;
    }
};

template <typename T1>                                      // (C)
struct pair_special<T1,T1> {
    T1 key;
    T1 value;
   
    friend ostream& operator<<(ostream& os, const pair_special& p) {
        os << "[" << p.key << ":" << p.value << "] <T1,T1>";
        return os;
    }
};

template <>                                                 // (D)
struct pair_special<bool,bool> {
    int n;
    
    pair_special(bool b1, bool b2) : n( ((b1)?1:0) + ((b2)?2:0) ) {}
    
    friend ostream& operator<<(ostream& os, const pair_special& p) {
        os << "[" << (p.n&1) << ":" << (p.n>>1) << "] <bool,bool>";
        return os;
    }
};

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    pair_special<short,int> p_s1{1u,2};                     // (E)
    cout << "01|    p_s1=" << p_s1 << endl;
    pair_special p_s2{1u,2}; 
    cout << "02|    p_s2=" << p_s2 << endl;
    
    cout << "-----" << endl;

    pair_special<int,double> p_i1{2,3.4};
    cout << "03|    p_i1=" << p_i1 << endl;
    pair_special p_i2{2,3.4};
    cout << "04|    p_i2=" << p_i2 << endl;

    cout << "-----" << endl;

    pair_special<float,float> p_f1{5.1f,6.2f};
    cout << "05|    p_f1=" << p_f1 << endl;
    pair_special p_f2{5.1f,6.2f};
    cout << "06|    p_f2=" << p_f2 << endl;

    cout << "-----" << endl;

    pair_special<bool,bool> p_b1{true,false};
    cout << "07|    p_b1=" << p_b1 << endl;
    pair_special p_b2{true,false};
    cout << "08|    p_b2=" << p_b2 << endl;
     
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Eine allgemeine template Klasse pair mit Datentypen T1 und T2. 
 * 
 * (B)  Eine Spezialisierung, d.h. fuer den Fall, dass der erste Parameter ein
 *      int ist, nimmt der Compiler diese Klasse.
 * 
 * (C)  Noch eine Spezialisierung für den Fall, dass beide Datentypen 
 *      übereinstimmen (T1=T2).
 * 
 * (D)  Noch eine Spezialisierung für den Fall, dass beide Datentypen 
 *      vom Typ bool sind.
 * 
 * (E)  Die Datentypen können auch automatisch deduziert werden. Der ctor
 *      hilft bei der Auswahl zwischen den Spezialisierungen.
 * 
 * In den template Parametern stehen nur die noch "freien" Typen, oder
 * wenn alles angegeben ist, auch keine mehr (template <>).
 * 
 */
 
