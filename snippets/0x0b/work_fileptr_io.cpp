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

void copy_all_lines(const string& file_name)
{    
    string file_in{file_name+".txt"};
    string file_out{file_name+"_copy_c.txt"};
    FILE *f_file_in = fopen(file_in.c_str(),"r"),           // (A)
         *f_file_out = fopen(file_out.c_str(),"w");
         
    if (NULL!=f_file_in && NULL!=f_file_out) {              // (B)
        int c;
        while ( (c=fgetc(f_file_in))!=EOF )                 // (C)
            fprintf(f_file_out,"%c",c);
    }

    if (NULL!=f_file_in)                                    // (D)
        fclose(f_file_in);
    if (NULL!=f_file_out)
        fclose(f_file_out);

    cout << "-a|      file ok" << endl;
}


void count_lines(const char* file_in)
{
    FILE *f_file_in = fopen(file_in,"r");
    int lines = -1;

    if (NULL!=f_file_in)
    {
        lines = 0;
        char *line = (char*)malloc(21);                     // (E)
        size_t n=20;
        ssize_t len;
        
        while ( (len=getline(&line, &n, f_file_in))>0 )     // (F)
            ++lines;

        free(line);
        fclose(f_file_in);
    }
    cout << "-b|      lines: " << lines << endl;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    cout << "01|    starte Kopieren, C-Style" << endl;

    cout << "-----" << endl;
    
    string fileName("../sixlines");
    copy_all_lines(fileName);
    //count_lines(fileName.c_str());

    cout << "-----" << endl;

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}


/* Kommentierung
 * 
 * (A)  Einlesen über FILE Struktur mit Namen und Attributen.
 * 
 * (B)  Datei konnte geöffnet werden, wenn FILE* auf Struktur zeigt.
 * 
 * (C)  Zeichen nacheinander lesen. 
 * 
 * (D)  Nach dem Lesen wieder schliessen.
 * 
 * (E)  Eine Zeile soll max. 20 Zeichen lang sein, das ist der Puffer dafür.
 * 
 * (F)  Zeichen in diesen Puffer lesen bis max. 20 Zeichen.
 * 
 */
 
