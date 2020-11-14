/*
 * author: a.voss@fh-aachen.de 
 */

#include <iostream>                                         // (A)
using namespace std;                                        // (B)

int main()                                                  // (C)
{
    cout << "Hallo Welt!" << endl;                          // (D)
       
    return 0;                                               // (E)
}

/* Kommentierung
 * 
 * (A)  Standard-Defs. global bekannt machen:
 *          #include <file>
 *      hier speziell die Funktionen und Objekte rund um die Ausgabe, 
 *      d.h. "cout" und "endl", siehe (B) und (D).
 * 
 * (B)  Insbesondere sind diese Objekte (z.B. "cout") nicht global bekannt,
 *      sondern in sogenannten namespaces (Namensraum) organisiert, damit 
 *      es nicht so schnell zu Verwechslungen kommt. 
 *      Um diese namespaces hier nicht immer explizit angeben zu müssen, 
 *      verweisen wir auf den Standard-namespace "std" mit "using" und 
 *      können dann für alle Ojekte aus diesem namespace den vollen Namen, 
 *      d.h. "std::cout" zu "cout" verkürzen. 
 *      Aber Achtung, das ist in dieser Globalität nicht immer gewünscht!
 * 
 * (C)  "main" ist eine Funktion und der Startpunkt des Programms. Die
 *      Funktion gibt einen Fehlercode zurueck. Dabei bedeutet der Wert 0,
 *      dass kein Fehler aufgetreten ist, ansonsten ist der Wert !=0 
 *      der Fehlercode. Besser wäre eigentlich die Konstante 'EXIT_SUCCESS'.
 *      Der Fehlercode ist der Wert, der in der Kommandozeile ausgewertet
 *      werden kann, z.B. von make in "make && a.out".
 *      Der Aufbau der Funktionssignatur ist identisch zu Java.
 * 
 * (D)  Ausgabe in console (cout), Argumente werden mit << verbunden,
 *      einen Zeilenumbruch erzeugt man mit "endl". Da diese Objekte  
 *      global verfuegbar sind, muessen sie nicht ueber den sogenannten 
 *      namespace "std" angesprochen werden, also "std::cout", sondern
 *      "cout" reicht aus - siehe (B).
 * 
 * (E)  Rueckgabewert von "main", siehe (C)
 */

