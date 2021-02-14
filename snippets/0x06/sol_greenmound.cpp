// author: a.voss@fh-aachen.de

#include <iostream>
using std::cout;
using std::endl;

long mem_allocated{0};

size_t length(const char* p) {
    const char* q{p};
    while (*(q++)) 
        ;
    return q-1-p;
}

char* copy(const char* p) {
    size_t l{length(p)+1};
    char* q = new char[l];
    mem_allocated += l;
    for (size_t i=0; i<l; ++i)
        q[i]=p[i];
    return q;
}

void free(const char* p) {
    size_t l{length(p)+1};
    mem_allocated -= l;
    delete p;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    const int dim {4};
    const char* p[dim] { copy("Dies"),copy("ist"),copy("ein"),copy("Satz") };

    cout << "01|    '" << p[0] << " " << p[1] 
        << " " << p[2] << " " << p[3] << "'" << endl;
    
    cout << "02|    allocated=" << mem_allocated << endl;

    cout << "-----" << endl;

    for (int i=0; i<dim; ++i)
        free(p[i]);

    cout << "03|    allocated=" << mem_allocated << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
