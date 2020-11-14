// author: a.voss@fh-aachen.de

#include <iostream>
using namespace std;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    short sh{1};                                            // (A)
    cout << "01|    sh=" << sh 
         << ", sizeof(short)=" << sizeof(short) << endl;

    long long ll{2};                                        // (B)
    cout << "02|    ll=" << ll
         << ", sizeof(long long)=" << sizeof(long long) << endl;

    cout << "-----" << endl;

    int8_t i1{3};                                           // (C)
    uint16_t u2{4};
    int32_t i4{5};
    uint64_t u8{6};
    cout << "03|    i1=" << +i1                             // (D)
         << ", sizeof(int8_t)=" << sizeof(int8_t) << endl;
    cout << "04|    u2=" << u2 
         << ", sizeof(uint16_t)=" << sizeof(uint16_t) << endl;
    cout << "05|    i4=" << i4 
         << ", sizeof(int32_t)=" << sizeof(int32_t) << endl;
    cout << "06|    u8=" << u8 
         << ", sizeof(uint64_t)=" << sizeof(uint64_t) << endl;

    cout << "-----" << endl;

    long double ld{1};                                      // (E)
    cout << "07|    ld=" << ld 
         << ", sizeof(long double)=" << sizeof(long double) << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/* Kommentierung
 * 
 * (A)  Datentyp 'short', 2 Bytes, ganzzahlig, signed und unsigned.
 * 
 * (B)  Datentyp 'long long', 8 Bytes, ganzzahlig, signed und unsigned.
 * 
 * (C)  Datentyp 'int8_t', 'uint8_t', 'int16_t', 'uint16_t' ... bis 64,
 *      ganzzahlig, signed und unsigned, die Zahl gibt die garantierte
 *      Größe in Bits wieder.
 * 
 * (D)  Kleiner Trick: wenn man die Variable 'i1' ausgibt, so wird sie
 *      zunächst als 'char' erkannt, aber der +-Operator davor sorgt
 *      dafür, dass sie als Zahl ausgegeben wird.
 * 
 * (E)  Datentyp 'long double', Fliesskommazahl, 16 Bytes, 
 * 
 */
 
