// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

int factorial(int n)                                        // (A)
{
	return (n>1) ? n*factorial(n-1) : 1;                    // (B)
}

int fib(int n);                                             // (C)

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
 
    const int n=9;
    cout << "01|    Ausgabe i! und i'te Fibonaccizahl f_i bis n=" 
        << n << ":" << endl;
    
 	int i{0};
	while ((++i)<=n) {                                      // (D)
        cout << "02|      i=" << i<< 
            ", " << i << "!=" << factorial(i) 
             << ", " << "f_" << i << ": " << fib(i) << endl;
	}

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

int fib(int n)                                              // (E)
{
	return (n<=1) ? n : fib(n-1)+fib(n-2);
}


/* Kommentierung
 * 
 * (A)  Aus Sicht des Compilers müssen alles Ausdrücke zumindest in
 *      Form und Datentyp, also die Deklaration, bekannt sein.
 *      Hier wird die Funktion 'factorial' definiert, danach kennt sie
 *      der Compiler und weiss, dass sie einen int als Parameter bekommt
 *      und einen int zurückgibt.
 * 
 * (B)  Der ?-Operator besteht aus drei Teilen und liefert, wenn der 
 *      erste bool'sche Ausdruck wahr ist den zweiten Ausdruck, sonst
 *      den dritten Ausdruck als Ergebnis.
 * 
 * (C)  Hier ist die Funktion 'fib' durch Angabe ihrer Signatur nur 
 *      deklariert. Sie muss an anderer Stelle noch definiert werden, aber 
 *      für den Compiler reicht ersteinmal, wenn er weiß, wie wie
 *      aufgerufen wird und was sie zurückliefert.
 * 
 * (D)  Man beachte das Inkrement von i im Ausdruck der while-Schleife.
 * 
 * (E)  Hier folgt jetzt die Definition der Funktion 'fib'.
 * 
 * Anmerkung: Man trennt normalerweise den Quellcode auf und packt nicht
 * alles in eine Datei. Das ist nur für die Presentation nicht vorteilhaft,
 * da dann ständig zwischen den Codes gesprungen wird. Das verwirrt
 * zusätzlich zum Inhalt doppelt. Deswegen sind die Snippets (fast) alle
 * in einer Datei vorhanden - Produktivcode wäre sinnvoll aufgeteilt!
 * 
 */
