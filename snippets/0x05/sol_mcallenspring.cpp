// author: a.voss@fh-aachen.de

#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::hex;

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;

    int n{0x12345678};
    cout << "01|    n=0x" << hex << n << endl;
    
    uint8_t* pc{(uint8_t*)&n};
    cout << "02|    n[0]=0x" << hex << +pc[0] 
        << ", n[1]=0x" << +pc[1]    // small trick: + to var to use as number
        << ", n[2]=0x" << +pc[2]
        << ", n[3]=0x" << +pc[3] << endl;
        
    pc[1]=0xab;
    pc[2]=0xcd;
    cout << "03|    n[0]=0x" << hex << +pc[0] 
        << ", n[1]=0x" << +pc[1]
        << ", n[2]=0x" << +pc[2]
        << ", n[3]=0x" << +pc[3] << endl;

    cout << "-----" << endl;
    
    int i{1}, j{2};
    int* p{&i};

    cout << "04|    i=" << i << ", j=" << j << ", *p=" << *p << endl;
    *(p+1) = 3;
    cout << "05|    i=" << i << ", j=" << j << ", *p=" << *p << endl;
      
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
