// module_ex1a
//
// Demonstrates linking a class in another module (module_ex1b.cpp)
// with the class interface declared in Vector.h.  Refer to the
// Makefile for linking info

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Vector.h"

int main() {
    using namespace std;

    srand(time(nullptr)); // use current time as seed

    Vector v(8);
    for (auto i = 0; i < v.size(); i++)
        v[i] = (rand() % 100) / (double) (rand() % 100);

    double sum = 0.0;
    for (auto i = 0; i < v.size(); i++) {
        cout.precision(5);
        cout << v[i] << endl;
        sum += v[i];
    }
    cout << "sum = " << sum << endl;

    return 0;
}
