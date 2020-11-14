// author: a.voss@fh-aachen.de

#include <iostream>
#include <stdexcept>
using std::cout;
using std::endl;
using std::runtime_error;

int readFile();

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01|    throw double 12.34" << endl;    
    try {
        throw 12.34;                                        // (A)
    } catch (...) {                                         // (B)
        cout << "02|    catch ..." << endl;
    }
    
    cout << "-----" << endl;

    cout << "03|    throw int 23" << endl;
    try {
        throw 23;
    } catch (double d) {                                    // (C)
        cout << "04|    catch double, d: " << d << endl;
    } catch (int n) {
        cout << "05|    catch int, n: " << n << endl;
    } catch (...) {
        cout << "06|    catch ..." << endl;
    }

    cout << "-----" << endl;

    cout << "07|    rethrow in readFile" << endl;
    try {
        readFile(); 
        // [...]
    } catch (const runtime_error& e) {                      // (D)
        cout << "08|    catch runtime_error, e: '" << e.what() << "'" << endl;
    } catch (...) {
        cout << "09|    catch ..." << endl;
    }
       
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

// Dummy-Funktion
int readFile() {
    try {
        cout << "-a|      throw runtime_error" << endl;
        throw runtime_error("file not found");
    } catch (...) {
        cout << "-b|      catch ..." << endl;
        throw;                                              // (E)
    }
    return 0;
}

/* Kommentierung
 * 
 * (A)  In C++ gibt es auch einen try-catch-Block und mit throw kann 
 *      jder möglihe Typ geworfen werden.
 * 
 * (B)  Der catch-Block kann entweder spezielle Typen fangen, oder
 *      mit '...' alle übrigen.
 * 
 * (C)  Hier sehen wir, dass der int-Block aktiv wird. 
 * 
 * (D)  Es gibt ein paar vordefinierte Ausnahmen/exceptions, die 
 *      hier aus 'readFile' geworfen und explizit gefangen werden.
 * 
 * (E)  Man beachte hier, dass die Ausnahme gefangen und weiter geworfen
 *      wird.
 * 
 */
 
