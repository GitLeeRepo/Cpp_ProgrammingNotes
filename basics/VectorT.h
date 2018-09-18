#include <initializer_list>
#include <string>
// Vector.h
//
// Class definition for Vector class implemented in module_ex1b to demo classes
// defined in a separate module.  This example based on "The C++ Programming 
// Language" by Bjarne Stroustrup with modifications by TK.  Refer to 
// module_ex1a.cpp for the main() function which uses this
//namespace tlk {
    template <class T>
    class Vector {
    public:
        Vector(int s);
        Vector(std::initializer_list<T>);
        T& operator[](int i);
        T* begin();
        T* end();
        int size();
    private:
        T* elem;
        int sz;     
    };
//}
