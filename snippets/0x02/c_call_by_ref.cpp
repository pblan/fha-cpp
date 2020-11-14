// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

struct pair {                                               // (A)
    int key;
    int value;
};

void init_val(pair p);
void init_ref(pair& p);
void read_const_ref(const pair& p);

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    pair p;

    p.key=1; p.value=2;
    cout << "01|    val: vorher p.key=" << p.key << ", p.value=" << p.value << endl;
    init_val(p);                                            // (B)
    cout << "02|    val: nachher p.key=" << p.key << ", p.value=" << p.value << endl;

    cout << "-----" << endl;

    p.key=1; p.value=2;
    cout << "03|    ref: vorher p.key=" << p.key << ", p.value=" << p.value << endl;
    init_ref(p);                                            // (C)
    cout << "04|    ref: nachher p.key=" << p.key << ", p.value=" << p.value << endl;

    cout << "-----" << endl;

    p.key=1; p.value=2;
    cout << "05|    const_ref: vorher p.key=" << p.key << ", p.value=" << p.value << endl;
    read_const_ref(p);                                      // (D)
    cout << "06|    const_ref: nachher p.key=" << p.key << ", p.value=" << p.value << endl;
       
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

void init_val(pair p) {                                     // (B)
    cout << "-a|      p.key=" << p.key << ", p.value=" << p.value << endl;
    p.key = p.value = 0;
    cout << "-b|      p.key=" << p.key << ", p.value=" << p.value << endl;
}

void init_ref(pair& p) {                                    // (C)
    cout << "-c|      p.key=" << p.key << ", p.value=" << p.value << endl;
    p.key = p.value = 0;
    cout << "-d|      p.key=" << p.key << ", p.value=" << p.value << endl;
}

void read_const_ref(const pair& p) {                        // (D)
    cout << "-e|      p.key=" << p.key << ", p.value=" << p.value << endl;
}

/* Kommentierung
 * 
 * (A)  pair dient nur als Beispiel einer nicht-trivialen Datenstruktur,
 *      bei der eine Kopie Zeit und Speicher kostet.
 * 
 * (B)  init_val setzt pair auf 0. In dieser Form ist es ein call-by-value, 
 *      d.h. der Parameter p wird kopiert und die Kopie wird auf 0 gesetzt.
 * 
 * (C)  init_ref setzt ebenfalls pair auf 0. In dieser Form ist es ein 
 *      call-by-ref (&), d.h. der aufrufende Parameter p wird auf 0 gesetzt 
 *      und es wird keine Kopie erzeugt.
 * 
 * (D)  read_const_ref ist ein Beispiel für eine Parameterübergabe einer
 *      komplexeren Datenstruktur, die nicht kopiert wird und die innerhalb
 *      der Funktion nicht verändert werden kann!
 *      Dazu muss der aufrufende Parameter nicht konstant sein!
 * 
 * !!!  Konvention: Wenn der Parameter nicht (!) als const deklariert ist,
 *      muss damit gerechnet werden, dass er verändert wird - denn sonst
 *      ist er als const gesetzt!
 * 
 */
 
