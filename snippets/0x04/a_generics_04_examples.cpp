// author: a.voss@fh-aachen.de

#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::initializer_list;
using std::out_of_range;

typedef double math_type;                                   // (A)
const math_type PI{3.1415926};

template<typename T>                                        // (B)
struct point {
    typedef T value_type;
    value_type x, y;
};

template<typename T>                                        // (C)
size_t calc_size_in_bits(T x=T{}) { return 8*sizeof(x); }

template<typename T1, typename T2>                          // (D)
class pair {
    pair(const T1& first, const T2& second) : first(first), second(second) {};

    template<typename S1, typename S2>
    friend pair<S1,S2> make_pair(const S1& first, const S2& second);
public:
    typedef T1 first_type;
    typedef T2 second_type;
    first_type first;
    second_type second;
};

template<typename S1, typename S2>                          // (E)
pair<S1,S2> make_pair(const S1& first, const S2& second) { return pair<S1,S2>{first,second}; }

template<typename T1, typename T2>                          // (F)
ostream &operator<<(ostream &os, const pair<T1,T2> &p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template<typename T, unsigned int DIM>                      // (G)
class array {
public:
    static unsigned int size() { return DIM; }
    typedef T value_type;

    array() = default;
    array(const initializer_list<value_type>& l) {
        size_t i{0};
        for (auto& x : l) {
            if (i>=size())
                throw out_of_range("list too long");
            data[i++] = x;
        }
    }

    value_type operator[](size_t n) const { return data[n]; }
    value_type& operator[](size_t n) { return data[n]; }

private:
    value_type data[DIM];
};

template<typename T, typename S>                            // (H)
auto sum(T t, S s) { return t+s; }

int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    math_type A{PI*3.0*3.0};
    cout << "01|    area=" << A << endl;

    cout << "-----" << endl;

    point<char> ptc{'a', 'b'};                              // (I)
    point<char>::value_type x{ptc.x};
    cout << "02|    ptc=(" << ptc.x << "," << ptc.y << "), x=" << x << endl;

    point<int> pti{1, 2};
    auto y{pti.y};
    cout << "03|    pti=(" << pti.x << "," << pti.y << "), y=" << y << endl;

    cout << "-----" << endl;

    cout << "04|    size_bits(int)=" << calc_size_in_bits<int>() << endl;
    cout << "05|    size_bits(int)=" << calc_size_in_bits(4) << endl;
    cout << "06|    size_bits(char)=" << calc_size_in_bits<char>() << endl;
    cout << "07|    size_bits(char)=" << calc_size_in_bits<char>('A') << endl;

    cout << "-----" << endl;

    // pair<int,int> p0{1, 2};                              // (J)

    auto p1 = make_pair<int,int>(1, 2);
    cout << "08|    p1=" << p1 << endl;

    auto p2 = make_pair(3, 4);
    cout << "09|    p2=" << p2 << endl;

    auto p3 = make_pair<string,string>("Hello", "World");   // (K)
    cout << "10|    p3=" << p3 << endl;

    cout << "-----" << endl;

    array<int,3> a{2,3,5};
    cout << "11|    a=[";
    for (size_t i = 0; i < a.size(); ++i)
        cout << " " << a[i];
    cout << " ], size=" << a.size() << endl;

    cout << "-----" << endl;

    auto d = sum(5,1.5);
    cout << "12|    sum=" << d << ", sizeof(d)=" << sizeof(d) << endl;
    auto n = sum(5,1);
    cout << "13|    sum=" << n << ", sizeof(n)=" << sizeof(n) << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 *
 * (A)  'typedef' definiert einen konkreten Datentyp unter einem
 *      neuen Namen, hier als Beispiel 'math_type' für einen Typ, mit
 *      dem Berechnungen angestellt werden (float, double, long double).
 *      Der Name ist frei wählbar, es finden sich häufig aber die
 *      Endungen '.._type' oder '.._t'.
 *
 * (B)  Eine template Klasse (struct) 'point' mit Datentyp T. In
 *      älterem Code auch oft als 'template<class T>' zu finden.
 *      Wir merken uns den template-Datentyp in value_type, um ihn
 *      vielleicht später zu verwenden.
 *
 * (C)  Es gibt nicht nur generische, also Template-Klassen, sondern
 *      auch Funktionen. calc_size_in_bits ist eine globale Funktion,
 *      bei der T noch nicht festgelegt ist.
 *      Man beachte, dass T implizit aus dem Datentyp des Parameters
 *      abgeleitet werden kann.
 *
 * (D)  pair ist ein Template mit zwei Typparametern. Zusätzlich haben wir
 *      hier den Konstuktor privat gelassen, um die Funktion make_pair zu
 *      zeigen. Damit diese wiederum den Konstruktor aufrufen darf, ist
 *      sie ein "Freund" der Klasse, denn diese dürfen private Teile der
 *      Klasse verwenden wie Memberfunktionen. Und sie ist selber eine
 *      Template-Fnktion, daher sind S1 und S2 die Typparameter von make_pair.
 *      pair merkt sich diese Typen in first_type und second_type, sie sind
 *      per 'pair::' verwendbar.
 *
 * (E)  Siehe (D).
 *
 * (F)  Der Ausgabe-Operator für eine pair-Instanz. Die Typparameter werden
 *      aus dem Aufruf heraus ermittelt, siehe main.
 *
 * (G)  Als Beispiel eine einfache raw-Array-Klasse analog zu array aus der
 *      STL. size ist eine statische, also eine Klassenfunktion und gibt
 *      die Dimension zurück. So verbraucht sie keinen Speicher in jeder
 *      Instanz.
 *      Hier haben wir die []-Operatoren schon einmal definiert, so kann
 *      das Feld selbst, also data, privat bleiben.
 *      Des Weiteren gibt es hier eine sogenannte initializer_list. Der
 *      Compiler kann so Konstruktoraufrufe mit einer beliebig langen
 *      Liste von Argumenten behandeln, siehe main. Der Ausdruck
 *          array<int,3> a{1,2,3}
 *      wird ohne diesen ctor nicht akzeptiert.
 *
 * (H)  Mehrere Template-Parameter, welchen Rückgabetyp besitzt sum?
 *      Hier nutzen wir den Compiler und auto, damit der Typ automatisch
 *      aus dem Ausdruck t+s ermittelt wird.
 *
 * (I)  Ein point mit chars und einer mit int. Wichtig ist hier die
 *      Anmerkung, dass das dann auch zwei verschiedene Klassen sind!
 *
 * (J)  ctor von pair ist private!
 *
 * (K)  Eine kleine technische Schwierigkeit. "text" ist kein String!
 *      Es ist ein Array von chars, dazu mehr bei Zeigern/Pointern.
 *      Aber das ist der Grund, warum die Template-Parameter string
 *      explizit angegeben sind.
 *
 */
 
