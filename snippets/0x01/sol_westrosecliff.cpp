// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl
         << endl;

    int n;
    cout << "01|    Eingabe n: "; cin >> n;

    char c;
    cout << "02|    Eingabe c: "; cin >> c;

    cout << "-----" << endl;
    
    // einmal mit if, einmal bool'sch
    if (n>0) {
        cout << "03|    n=" << n << " ist positiv" << endl;
    } else {
        cout << "04|    n=" << n << " ist nicht positiv" << endl;
    }
    
    bool isUpper = (c>='A' && c<='Z');
    cout << "05|    c='" << c << "' ein Grossbuchstabe? "
        << (isUpper ? "Ja" : "Nein") << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
