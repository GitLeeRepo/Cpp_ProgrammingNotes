// vector_ex2.cpp
//
// More lambda examples, this time more as standalone code, that is outside
// function call parameters. 

#include <iostream>
#include <iomanip>
#include <climits>
#include <vector>
#include <algorithm>


int main() {
    using namespace std;

    unsigned long x = 8;

    auto squared = [](unsigned long n) -> unsigned long { return n * n; };
    cout << "x=" << x << " squared = " << squared(x) << endl;

    long double y = 2.0;
    auto squared2 = [](long double n) -> long double { return n * n; };
    
    while (y < 2e+300 && y > 0) {
        long double t = squared2(y);
        cout << "y=" << y << " squared = " << t << endl;
        y = t;
    }

    return 0;
}
