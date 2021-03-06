// module_ex1a
//
// Demonstrates linking a class in another module (module_ex1b.cpp)
// with the class interface declared in Vector.h.  Refer to the
// Makefile for linking info

#include <iostream>
#include "Vector.h"

int main() {
    using namespace std;

    tlk::Vector v(8);
    for (auto i = 0; i < v.size(); i++)
        v[i] = (11 * i) + ((double) (i + 1) / 10);

    double sum = 0.0;
    for (auto i = 0; i < v.size(); i++) {
        cout.precision(5);
        cout << v[i] << endl;
        sum += v[i];
    }
    cout << "sum = " << sum << endl;

    // range-for support through begin() & end()
    cout << "range-for output\n";
    for (double x : v) {
        cout << x << endl;
    }

    return 0;
}
