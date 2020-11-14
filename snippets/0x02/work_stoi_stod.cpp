// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    string s;
    
    cout << "01|    Eingabe Zahl: "; cin >> s;

    try {
        int n = std::stoi(s);
        cout << "02|    n=" << n << endl;
//        double d = std::stod(s);
//        cout << "02|    d=" << d << endl;
    } catch (const std::invalid_argument& e) {
        cout << "03|    invalid_argument, e=" << e.what() << endl;
    } catch (const std::out_of_range& e) {
        cout << "04|    out_of_range, e=" << e.what() << endl;
    } catch(...) {
        cout << "05|    unknown error" << endl;
    }
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
