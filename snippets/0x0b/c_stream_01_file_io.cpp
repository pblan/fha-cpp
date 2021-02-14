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

void copy_first_5_lines(const string& file_in) {

    vector<string> lines;

    ifstream ifs_file_in(file_in+".txt");                          // (A)
    if (ifs_file_in.is_open()) {                            // (B)
        string line;
        while (getline(ifs_file_in,line)) {                 // (C)
            lines.push_back(line);
            cout << "-a|      Zeile " << lines.size() << ": '" << line << "'" << endl;
            if (lines.size()>=5)
                break;
        }
        ifs_file_in.close();
    } else {
        cout << "-b|      file open error" << endl;
    }
    
    string file_out{file_in+"_copy_cpp.txt"};
    ofstream ofs_file_out(file_out);                        // (D)
    if (ofs_file_out) {                                     // (E)
        for (string & line : lines) {
            ofs_file_out << line << endl;                   // (F)
        }
        ofs_file_out.close();
    }

}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01|    starte Kopieren, C++-Style" << endl;

    cout << "-----" << endl;
    
    string fileName("../sixlines");
    copy_first_5_lines(fileName);

    cout << "-----" << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}


/* Kommentierung
 * 
 * (A)  Einlesen über input-file-stream.
 * 
 * (B)  Datei konnte geöffnet werden.
 * 
 * (C)  Nacheinander zeilenweise aus dem Stream in String auslesen.
 *      Beachte auch: eof() 
 * 
 * (D)  Analog zu (A), output-file-Stream öffnen.
 * 
 * (E)  Kurzvariante, ob es geklappt hat (analog fail()).
 * 
 * (F)  Schreiben in einen stream.
 * 
 */
 
