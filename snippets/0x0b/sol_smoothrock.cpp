// author: a.voss@fh-aachen.de

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;

// für kleine Textdateien, ohne Fehlerbehandlung

vector<string> read_all_lines(const string& file_in) {

    vector<string> lines;

    ifstream ifs_file_in(file_in+".txt");
    if (ifs_file_in) {
        string line;
        while (getline(ifs_file_in,line)) {
            lines.push_back(line);
        }
        ifs_file_in.close();
    } else {
        cout << "-a|      file open error" << endl;
    }

    return lines;
//

}

void write_all_lines(const string& file_out, const vector<string>& lines) {
    ofstream ofs_file_out(file_out+"_copy.txt");
    if (ofs_file_out) {
        for (const string & line : lines) {
            ofs_file_out << line << endl;
        }
        ofs_file_out.close();
    }
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01|    starte Lesen und Schreiben" << endl;

    cout << "-----" << endl;
    
    string fileName("../sixlines");
    auto lines = read_all_lines(fileName);
    for (size_t i=0; i<lines.size(); ++i)
        cout << "02|    line:" << i << " '" << lines[i] << "'" << endl;

    write_all_lines(fileName,lines);

    cout << "-----" << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}


