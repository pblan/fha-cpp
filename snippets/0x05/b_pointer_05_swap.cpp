// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

// #pragma GCC diagnostic ignored "-Wunused-but-set-parameter"

void init1(int n);                                          // (A)
void init2(int& n);
void init3(int* n);
void swap1(int n, int m);
void swap2(int& n, int& m);
void swap3(int* n, int* m);

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    int n{}, m{};
    
    n=1; init1(n);                                          // (B)
    cout << "01|    n=" << n << endl;

    n=2; init2(n);
    cout << "02|    n=" << n << endl;

    n=3; init3(&n);
    cout << "03|    n=" << n << endl;

    cout << "-----" << endl;

    n=1; m=-1; swap1(n,m);
    cout << "04|    n=" << n << ", m=" << m << endl;
    n=2; m=-2; swap2(n,m);
    cout << "05|    n=" << n << ", m=" << m << endl;
    n=3; m=-3; swap3(&n,&m);
    cout << "06|    n=" << n << ", m=" << m << endl;
    
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

void init1(int n) {
    n=0;
}

void init2(int& n) {
    n=0;
}

void init3(int* n) {
    *n=0;
}

void swap1(int n, int m) {
    int k = n;
    n = m;
    m = k;
}

void swap2(int& n, int& m) {
    int k = n;
    n = m;
    m = k;
}

void swap3(int* n, int* m) {
    int k = *n;
    *n = *m;
    *m = k;
}

/* Kommentierung
 * 
 * (A)  Es gibt zwei Funktionen 'init' und 'swap'. Die erste soll das
 *      aufrufende Argument auf 0 setzen, die zweite soll die Argumente
 *      tauschen - und zwar jeweils die Originalparameter vom Aufruf!
 *      Das klappt nicht immer, waum?
 *      Beide Funktionen gibt es in jeweils drei Varianten: 
 *      In der ersten wird die Funktion 'call-by-value'
 *      aufgerufen, in der zweiten und dritten 'call-by-ref' einmal
 *      mit Referenzen und einmal mit Zeigern.
 *      Die Frage lautet immer: was steht nach dem Aufruf in den Parametern
 *      bzw. wurden sie verändert oder nicht?
 * 
 * (B)  Wie beschrieben, zuerst setzen wir Werte, damit man sieht, ob sich
 *      was verändert hat oder nicht.
 *      Die Lösung ist, dass beim Aufruf 'call-by-value' die Parameter kopiert
 *      werden und daher die Originalparameter vom Aufruf nicht verändert werden.
 *      Bei 'call-by-ref' dagegen werden die Originalparameter verändert,
 *      entweder weil es sich um Referenzen, also Aliase, handelt oder
 *      weil über die Zeiger auch die Originalparameter im Zugriff sind.
 * 
 */
 
