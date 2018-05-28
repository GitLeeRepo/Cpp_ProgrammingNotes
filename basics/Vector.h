
// Vector.h
//
// Class definition for Vector class implemented in module_ex1b to demo classes
// defined in a separate module.  This example based on "The C++ Programming 
// Language" by Bjarne Stroustrup with modifications by TK.  Refer to 
// module_ex1a.cpp for the main() function which uses this
namespace tlk {
    class Vector {
    public:
        Vector(int s);
        double& operator[](int i);
        double* begin();
        double* end();
        int size();
    private:
        double* elem;
        int sz;     
    };
}
