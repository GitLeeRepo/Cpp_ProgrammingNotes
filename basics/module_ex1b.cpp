// module_ex1b.cpp
//
// Implementation of the class defined in Vector.h to demo classes defined in
// a separate module.  This example based on "The C++ Programming Language" 
// by Bjarne Stroustrup with modifications by TK.  Refer to module_ex1a.cpp
// for the main() function which uses this

#include <stdexcept>
#include "Vector.h"
namespace tlk {

    // constructor - init elem & sz
    Vector::Vector(int s) 
        :elem {new double[s]}, sz{s} 
    {
    }

    //subscripting access
    double& Vector::operator[](int i)
    {
        if (i < 0 || size() <= i)
            throw std::out_of_range{"Vector::operator[]"};
        return elem[i]; 
    }

    int Vector::size() 
    { 
        return sz; 
    }

} 
