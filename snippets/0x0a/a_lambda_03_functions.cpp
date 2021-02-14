// author: a.voss@fh-aachen.de

#include <iostream>
#include <functional>
#include <cmath>
using std::cout;
using std::endl;
using std::string;
using std::function;
using std::asin;

typedef double (*function_t)(double x);                     // (A)

double evalf(function_t f, double x) {                      // (B)
	return f(x);
}

double x2(double x) {                                       // (C)
    return x*x; 
}

double x3(double x) { 
    return x*x*x; 
}

double evalg(function<double(double)> g, double x) {        // (D)
	return g(x);
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    
    cout << "01|    3^2=" << evalf(x2,3.0) << endl;         // (E)
    
    function_t f3{x3};                                      // (F)
    cout << "02|    2^3=" << evalf(f3,2.0) << endl;         // (G) 

    auto l4a = [](double x){return x*x*x*x;};               // (H)
    cout << "03|    1^4=" << evalf(l4a,1.0) << endl;
    
    function_t l4b = [](double x) -> double {return x*x*x*x;};
    cout << "04|    1^4=" << evalf(l4b,1.0) << endl;

    cout << "05|    1^4="                                   // (I)
         << evalf([](double x) -> double {return x*x*x*x;}, 1.0) << endl;

    cout << "-----" << endl;

    function_t g1 = asin;                                   // (J)
    cout << "06|    2asin(0)=" << 2*evalg(g1,1.0) << endl;

    // function<double(double)> g2 = asin;                  // (K)
    // cout << "07|    2asin(0)=" << 2*evalg(g2,1.0) << endl;

    double(*g3)(double) = asin;                             // (L)
    cout << "08|    2asin(0)=" << 2*evalg(g3,1.0) << endl;

    function<double(double)> g4 = (double(*)(double))asin;  // (M)
    cout << "09|    2asin(0)=" << 2*evalg(g4,1.0) << endl;

    function<double(double)> g5 = [](double x) -> double {return asin(x);};
    cout << "10|    2asin(0)=" << 2*evalg(g5,1.0) << endl;

    cout << "11|    2asin(0)=" 
         << 2*evalg([](double x) -> double {return asin(x);},1.0) << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Das ist der Datentyp "Funktionszeiger". Variablen diesen Typs
 *      koennen Zeiger auf Funktionen sein (wie etwa in der vtbl), sie
 *      enthalten im Wesentlichen die Adresse des Funktionsanfangs im
 *      Speicher. Der Datentyp heisst "function_t".
 *      Mit diesem Datentyp koennen wir nun Funktionen definieren, die
 *      einen Funktionszeiger uebergeben bekommen, etwa zur Auswertung...
 * 
 * (B)  ... wie fuer die Funktion evalf, die die uebergebe Funktion f
 *      auf das Argument x anwenden soll.
 * 
 * (C)  Das wird eine unserer Polynomfunktionen, x->x^2.
 * 
 * (D)  Da die Uergabe einer Funktion ein haeufiger Anwendungsfall ist,
 *      gibt es vordefinierte Templates, z.B. "function".
 * 
 * (E)  Auswertung der Funktion x^2 an x=3.0.
 * 
 * (F)  Eine Variable "f3", als Kopie der Funktion x^3...
 * 
 * (G)  ... die wir auch auswerten koennen.
 * 
 * (H)  Es gibt keinen expliziten Datentyp fuer lambda-Ausdruecke, aber
 *      ein Lambda-Ausdruck kann ohne Probleme in einen Funktionszeiger
 *      konvertiert werden (Aufruf von evalf) oder auch in den Datentyp
 *      "function_t".
 * 
 * (I)  Natuerlich koennen wir den lambda-Ausdruck auch direkt verwenden.
 *
 * (K)  Hier liegt die Problematik vor, dass der Compiler aus den verschiedenen
 *      möglichen Überladungen nicht die "richtig" Funktion aussuchen kann, auch
 *      wenn das für uns offensichtlich ist. Man kann helfen mit einem
 *      cast und das gibt (M).
 *
 * (J)..(M)  Funktionszeiger koennen mit verschiedenen Typen angelegt
 *      werden. "function<>" funktionieren bei reinen Funktionszeigern
 *      ohne Casting nicht.
 *      Insbes. bei (L) ist zu sehen, dass die Verwendung von typedefs
 *      den Code leserlicher macht.
 */
 
