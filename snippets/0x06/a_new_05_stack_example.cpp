// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class stack {                                               // (A)
    size_t m_size;
    int* m_data;                                            // (B)
    size_t m_next;
    
public:    
    stack() : m_size{3}, m_data{new int[m_size]}, m_next{0} { 
    }

    ~stack() { 
        delete [] m_data;                                   // (C)
    }

    void push(int n) {                                      // (D)
        if (m_next==m_size) {
            m_size*=2;
            int* data{new int[m_size]};
            for (size_t i=0; i<m_next; ++i)
                data[i]=m_data[i];
            delete [] m_data;
            m_data=data;
        }
        m_data[m_next++]=n;
    }

    int pop() {
        if (m_next==0)
            throw "stack empty";
        return m_data[--m_next];
    }

    friend ostream& operator<<(ostream& os, const stack& s);
};

ostream& operator<<(ostream& os, const stack& s) {
    os << "[";
    for (size_t i=0; i<s.m_next; ++i)
        os << ((i>0)?",":"") << s.m_data[i];        
    os << "](" << s.m_size << ")";
    return os;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    stack s;
    cout << "01|    s=" << s << endl;
   
    s.push(1);
    cout << "02|    s=" << s << endl;

    s.push(2);
    s.push(3);

    s.push(4);
    cout << "03|    s=" << s << endl;
 
    cout << "-----" << endl;

    stack t{s};
    cout << "04|    t=" << t << endl;
 
    t.push(11);
    cout << "05|    t=" << t << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
                                                            // (E)
}

/* Kommentierung
 * 
 * (A)  Eine einfache Stack-Klasse, die sich allerdings dynamisch
 *      vergrößern kann, wenn viele Datan abgelegt werden.
 * 
 * (B)  Hier ist der Datenpuffer der Länge m_size, zu Beginn =3.
 * 
 * (C)  Nicht vergessen: delete mit [].
 * 
 * (D)  Dynamisch Vergrößern heißt: Länge verdoppeln und alten
 *      Puffer kopieren.
 * 
 * (E)  Am Ende des Programms tritt ein Fehler auf, warum?
 * 
 */
 
