// author: a.voss@fh-aachen.de

                                                            // (A)
#if !defined(C_FUNCTIONS)
#define C_FUNCTIONS 1

extern int n;                                               // (B)

void write_something(const string& s);                      // (D)

class C                                                     // (E)
{
public:
    C();
    
    int mal2(int n);
    
    static int m;
};
        
template <typename T>                                       // (F)
class D
{
public:
    D() { cout << "D::ctor" << endl; }
};

#endif

/* Kommentierung
 * 
 * (A)  include-guard: verhindert das doppelte include.
 * 
 * (B)  Es gibt beim Linken eine Variable vom Typ int namens n.
 * 
 * (D)  Analog zu (B), es gibt eine Funktion write_something.
 * 
 * (E)  Klasse C, die Member sind womöglich extern-
 * 
 * (F)  Analog (E).
 * 
 */
 

