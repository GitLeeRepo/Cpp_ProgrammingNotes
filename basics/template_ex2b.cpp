// module_ex1b.cpp
//
// Implementation of the class defined in Vector.h to demo classes defined in
// a separate module.  This example based on "The C++ Programming Language" 
// by Bjarne Stroustrup with modifications by TK.  Refer to module_ex1a.cpp
// for the main() function which uses this

#include <stdexcept>
#include "VectorT.h"
//namespace tlk {

    // constructor - init elem & sz
    template <typename T>
    Vector<T>::Vector(int s) 
        :elem {new T[s]}, sz{s} 
    {
    }

    // constructor - initialize with list, ex., Vector v =  { 1, 2, 3 }
    template <typename T>
    Vector<T>::Vector(std::initializer_list<T> lst) 
        :elem{new T[lst.size()]}, sz{static_cast<int>(lst.size())} {
        std::copy(lst.begin(), lst.end(), elem);
    }

    //subscripting access
    template <typename T>
    T& Vector<T>::operator[](int i)
    {
        if (i < 0 || size() <= i)
            throw std::out_of_range{"Vector::operator[]"};
        return elem[i]; 
    }

    // provide for range-for sytnax - for (double x : v)
    template <typename T>
    T* Vector<T>::begin() {
        return &elem[0];
    }

    template <typename T>
    T* Vector<T>::end() {
        return &elem[sz];
    }

    template <typename T>
    int Vector<T>::size() 
    { 
        return sz; 
    }
/*
void linkerFix() {
    Vector<double> vdbl(2);
    vdbl[0] = 0;
    Vector<int> vint(2);
    vint[0] = 0;
    Vector<int> vint2 = {1, 0 };
    vint2[0] = 0;
}*/

//} 
