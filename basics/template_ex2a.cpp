// template_ex1
//
// Template class example based on "The C++ Programming Language" by Bjarne 
// Stroustrup with modifications by TK.  Tested here with doubles, ints,
// and strings

#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
//#include "VectorT.h"
#include "template_ex2b.cpp"

int main() {
    using namespace std;

    srand(time(nullptr)); // use current time as seed

    Vector<double> vdbl(5);
    for (auto i = 0; i < vdbl.size(); i++)
        vdbl[i] = (rand() % 100) / (double) (rand() % 100);

    double sum = 0.0;
    for (auto i = 0; i < vdbl.size(); i++) {
        cout.precision(5);
        cout << vdbl[i] << endl;
        sum += vdbl[i];
    }
    cout << "sum = " << sum << endl;

    // initialize vector from a list
    Vector<int> vint = { 1, 2, 3, 4, 5 };
    for (auto i = 0; i < vint.size(); i++)
        cout << vint[i] << endl;

    Vector<string> vstr = { "one", "two", "three" };
    // range-for support through begin() & end()
    cout << "range-for output\n";
    for (string x : vstr) {
        cout << x << endl;
    }

    return 0;
}
