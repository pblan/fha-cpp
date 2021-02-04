// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::string;

class address
{
public:
    string s;

    address(const string &s) : s{s}
    { // (A)
        cout << "-a|      ctor(), s=" << s << endl;
        // if (s=="a4")
        //    throw 2;
    }

    ~address()
    { // (B)
        cout << "-b|      dtor(), s=" << s << endl;
        //if (s=="a4")
        //    throw 2;
    }
};

int main()
{
    cout << endl
         << "--- " << __FILE__ << " ---" << endl
         << endl;

    cout << "01|    start, vor if" << endl;

    {
        cout << "02|    vor a1" << endl;
        address a1{"a1"};
        cout << "03|    nach a1, vor a2" << endl;
        address a2{"a2"};
        cout << "04|    nach a2" << endl;
    }
    try
    {
        cout << "05|    vor a3" << endl;
        address a3{"a3"};
        // throw 1;
        cout << "06|    nach a3, vor a4" << endl;
        address a4{"a4"};
        // throw 1;
        cout << "07|    nach a4" << endl;
    }
    catch (int e)
    {
        cout << "08|    exception, e=" << e << endl;
    }

    cout << "09|    nach if, ende" << endl;

    cout << endl
         << "--- " << __FILE__ << " ---" << endl
         << endl;
    return 0;
}

/* Kommentierung
 *
 * (A)  Eine Exception im ctor führt dazu, dass das Objekt nicht vollständig
 *      initialisiert wurde. Ergo, wird der dtor auch nicht aufgerufen, denn
 *      dieser geht ja davon aus, dass das Objekt integer ist.
 *      Alle member-Variablen, die zuvor initialisiert wurden, werden aber
 *      durchaus wieder ordnungsgemäß zerstört (inkl. dtor).
 *
 * (B)  Eine Exception im dtor ist in vielen Fällen nicht mehr sinnvoll
 *      zu behandeln. Man denke an eine der geworfenen Exceptions ("throw 1"),
 *      die dazu führt, dass die bis dahin erzeugten Objekte wieder zerstört
 *      werden... und diese erzeugen dann beim "Aufräumen" im dtor
 *      eine weitere Exception... das kann nicht funktionieren!
 *      Daher gibt es nur einen Weg: Man darf in einem dtor keine
 *      Exceptions werfen! Ohne Ausnahme! Sonst crash!
 */
