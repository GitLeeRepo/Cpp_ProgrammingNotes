// except_ex1.cpp
//
// use the Vector class to trigger an out_of_range exception, and
// non-numeric user input to trigger an invalid_argument exception. 

#include <iostream>
#include <string>
#include <stdexcept>

class Vector {
public:
    // constructor - init elem & sz
    Vector(int s) :elem{new double[s]}, sz{s} {}

    //subscripting access
    double& operator[](int i) { 
        // the class should throw its own exceptions for invalid values
        if (i < 0 || size() <= i)
            throw std::out_of_range{"Vector::operator[]"};
        return elem[i]; 
    }

    int size() { return sz; }

private:
    double* elem;  // pointer to the elements
    int sz;        // number of elements
};

int main() {
    using namespace std;

    int max = 5;    // max elements
    Vector v(max);
    int n = 4;
    string input = "";
    cout << "Enter an index between 0 and " << max - 1 << 
            " larger or smaller integers will throw an exception" << endl;

    try {
        // add to string first, adding to int will convert non-numeric to zero
        // which is not desired since that should be flagged as an exception
        cin >> input;    
        n = stoi(input);  // non-numeric will trigger exception here 
        v[n] = 1.1;
        cout << v[n] << " added to index " << n << " of Vector\n";
    }
    catch (out_of_range) {
        // this exception is thrown in the Vector class above
        cout << "'" << n << "' is out of range. Must be 0 to " << max - 1 << endl;
    }
    catch (invalid_argument) {
        cout << "input must be numeric\n";
    }
     
    return 0;
}
