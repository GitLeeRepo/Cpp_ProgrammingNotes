// class_ex1
//
// Class example based on "The C++ Programming Language" by Bjarne Stroustrup
// with modifications by TK

#include <iostream>

class Vector {
public:
    // constructor - init elem & sz
    Vector(int s) :elem{new double[s]}, sz{s} {
        for (int i = 0; i < s; i++)
            elem[i] = 0;
    }

    // constructor - initialize with list, ex., Vector v =  { 1, 2, 3 }
    Vector(std::initializer_list<double> lst) 
        :elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())} {
        std::copy(lst.begin(), lst.end(), elem);
    }
    // destructor
    ~Vector() { 
        delete[] elem;
        std::cout << "Destructor invoked\n"; 
    }

    //subscripting access
    double& operator[](int i) { return elem[i]; }

    // provide for range-for syntax - for (double x : v)
    double* begin() {
        return &elem[0];
    }

    double* end() {
        return &elem[sz];
    }

    int size() { return sz; }

private:
    double* elem;  // pointer to the elements
    int sz;        // number of elements
};

int main() {
    using namespace std;

    Vector v(5);
    for (auto i = 0; i < v.size(); i++)
        v[i] = (11 * i) + ((double) (i + 1) / 10);

    double sum = 0.0;
    for (auto i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
        sum += v[i];
    }
    cout << "sum = " << sum << endl;

    // initialize vector from a list
    Vector v2 = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    for (auto i = 0; i < v2.size(); i++)
        cout << v2[i] << endl;

    // range-for support through begin() & end()
    cout << "range-for output\n";
    for (double x : v) {
        cout << x << endl;
    }

    return 0;
}
