// author: a.voss@fh-aachen.de

// leere Funktion
void g() { }


// Argument x und lokale Variablen auf dem Stack
int f(int x) {
    int n1=0x11223344, n2=0x55667788, n3=0x6699ccff;
    g();
    return 0x12345678;
}


int main() 
{
    f(0x336699aa);
    return 0;
}

/* Kommentierung
 *
 * //https://lldb.llvm.org/use/map.html
 *
 * Disassembler main, f, g:
 * di -n main -m -b
 * di -n f -m -b
 * di -n g -m -b
 *
 * Register read:
 * register read rip
 * register read edi
 * register read sp
 * register read rbp
 *
 * Memory read:
 * me read -s4 -fx -c12 $SP-0x10
 * me read -s4 -fx -c12 0x00007ffeefbd0a20
 *
 * Steps:
 * si
 * ni
 */