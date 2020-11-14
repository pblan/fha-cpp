// author: a.voss@fh-aachen.de


int main() 
{
    int n{0x11223344};
    int* pn{nullptr};

    n = 0x22446688;
    pn = &n;
    *pn = 0x336699aa;
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