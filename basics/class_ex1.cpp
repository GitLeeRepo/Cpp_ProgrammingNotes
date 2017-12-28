// class_ex1
//
// Class example based on "The C++ Programming Language" by Bjarne Stroustrup
// with modifications by TK

#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

class Vector {
public:
    // constructor - init elem & sz
    Vector(int s) :elem{new double[s]}, sz{s} {}

    //subscripting access
    double& operator[](int i) { return elem[i]; }

    int size() { return sz; }

private:
    double* elem;  // pointer to the elements
    int sz;        // number of elements
};

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
