// author: a.voss@fh-aachen.de

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::istringstream;
using std::ostringstream;

// analog zu file_io

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01|    über alle Zeilen..." << endl;

    string lines = "S1 123\nS2 456";
    istringstream is1(lines);           // alle Zeilen

    string S1, S2;
    int n1, n2;
    is1 >> S1 >> n1 >> S2 >> n2;
    cout << "02|    S1:" << S1 << ", n1:" << n1 
         << ", S2:" << S2 << ", n2:" << n2 << endl << endl;

    cout << "03|    je Zeile..." << endl;

    istringstream is2(lines);
    if (is2) {
        string line;
        while (getline(is2,line)) { 
            cout << "04| -a   line: '" << line << "'" << endl;
            istringstream sline(line);
            string s;
            int n;
            sline >> s >> n;
            cout << "04| -b   s:" << s << ", n:" << n << endl;
        }
    }
    cout << endl;

    cout << "05|    und zurück..." << endl;
    ostringstream os;
    os << "06|    " << 123 << ", 0x" << std::hex << 0x1234 << std::dec
       << ", "  << 124 
       << ", |" << std::setfill('-') << std::setw(10) << std::setprecision(5) << 12.345678 << "|" << endl;
    cout << os.str() << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}


