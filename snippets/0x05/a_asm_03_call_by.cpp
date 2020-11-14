// author: a.voss@fh-aachen.de


void reset_v1(int n) {
    n = 0x12345678;
}


void reset_v2(int* pn) {
    *pn = 0x12345678;
}


void reset_v3(int& n) {
    n = 0x12345678;
}


int main() 
{
    int n;

    n = 0x11001100;
    reset_v1(n);
    n = 0x22002200;
    reset_v2(&n);
    n = 0x33003300;
    reset_v3(n);

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
 * me write -s4 0x00007ffeef3a1a28 0x12345678
 *
 * Steps:
 * si
 * ni
 */