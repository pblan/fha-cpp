// author: a.voss@fh-aachen.de

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

#include "d_link_01_extern.hpp"

int n = 23;

void write_something(const string& s)
{
    cout << "'" << s << "', n=" << n << endl;
}

C::C() { cout << "ctor" << endl; }

int C::mal2(int n) { return n+n; }

int C::m = 42;

