// template_ex1
//
// Template class example based on "The C++ Programming Language" by Bjarne 
// Stroustrup with modifications by TK.  Tested here with doubles, ints,
// and strings

#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <cstdlib>

template <typename T>
class Vector {
public:
    // constructor - init elem & sz
    Vector(int s) :elem{new T[s]}, sz{s} {
        for (int i = 0; i < s; i++)
            elem[i] = 0;
    }

    // constructor - initialize with list, ex., Vector v =  { 1, 2, 3 }
    Vector(std::initializer_list<T> lst) 
        :elem{new T[lst.size()]}, sz{static_cast<int>(lst.size())} {
        std::copy(lst.begin(), lst.end(), elem);
    }
    // destructor
    ~Vector() { 
        delete[] elem;
        std::cout << "Destructor invoked\n"; 
    }

    //subscripting access
    T& operator[](int i) { return elem[i]; }

    // provide for range-for sytnax - for (double x : v)
    T* begin() {
        return &elem[0];
    }

    T* end() {
        return &elem[sz];
    }

    int size() { return sz; }

private:
    T* elem;  // pointer to the elements
    int sz;        // number of elements
};

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
