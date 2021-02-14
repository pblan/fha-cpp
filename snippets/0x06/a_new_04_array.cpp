// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    int n;
    cout << "01|    Eingabe n(>2): "; cin >> n;
    
    if (n>2 && n<100) {
        int* a = new int[n];                                // (A)
        
        a[0]=1;
        a[1]=1;
        for (int i=2; i<n; ++i) {
            a[i]=a[i-2]+a[i-1];                             // (B)
        }
        cout << "02|    fibs={1,1";
        for (int i=2; i<n; ++i) {
            cout << "," << a[i];
        }
        cout << "}" << endl;
        
        delete[] a;                                         // (C)
    } else {
        cout << "03|    Falsche Eingabe, n=" << n << endl;
    }
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Der Operator 'new Typ[n]' legt ein Feld von ints der Länge n
 *      an. Da ein Feld von ints durch die Angabe der Adresse des ersten
 *      ints ausreichend definiert ist, gibt er genau diese Adresse zurück
 *      und der Typ ist demnach 'int*'.
 *      Dieser Speicher kann zur Laufzeit angefordert werden (dynamisch)
 *      und liegt nicht (!) auf dem Stack, sondern in einem extra Bereich, 
 *      genannt Heap.
 * 
 * (B)  Hier werden die Fibonacci-Zahlen berechnet und in diesem Feld
 *      abgelegt. Wir können den Zeiger a wie ein Feld verwenden.
 * 
 * (C)  Legt man mit 'new Typ[n]' ein Feld dynamisch an, so ist es unbedingt
 *      notwendig, dieses auch wieder freizugeben. Das macht 'delete [] a'.
 *      Man beachte die '[]', da ein Feld angelegt wurde, also mehrere Elemente.
 * 
 */
 
