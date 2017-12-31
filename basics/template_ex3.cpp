// template_ex3
//
// Template specialization demo.  This example illustrates writing a
// separate specialized template class to handle a case that would
// not have been handled properly by the compiler generated one.  This
// is an over simplified example, and in this case there would be better
// solutions, such as operator overloading, but here it is used in order
// to illustrate the syntax and techniques for implementing specialization.
// In this example, the OneFiveStruct is the specialization case, the
// standard template handles the other cases of integers, strings, and
// enums. 

#include <iostream>
#include <string>

enum OneFiveEnum { one=1, two, three, four, five };

// struct used for the specialization case where we want to order by the
// number rather than the string.
struct OneFiveStruct {
    int num;
    std::string str;
};

// the standard non-specialized template class
template <class T>
class TwoValues {
public:
    TwoValues(T a, T b) : a{a}, b{b} {}
    void printMax() {
        std::cout << "For " << name << ": a = " << a << ", b = " << b <<
                             " and the max is " << (b > a ? b : a) << std::endl; 
    }

    void setName(std::string name) {
        this->name = name;
    }

private:
    T a;
    T b;
    std::string name;
};

// the specialized template class
template <>
class TwoValues<OneFiveStruct> {
public:
    TwoValues(OneFiveStruct a, OneFiveStruct b) : a{a}, b{b} {}
    void printMax() {
        std::cout << "For " << name << ": a = " << a.str << ", b = " << b.str << " and the max is " 
                            << (b.num > a.num ? b.str : a.str) << std::endl; 
    }

    void setName(std::string name) {
        this->name = name;
    }

private:
    OneFiveStruct a;
    OneFiveStruct b;
    std::string name;
};



int main() {
    using namespace std;

    // for the printMax() method this will be ordered by number rather than string
    OneFiveStruct oneFiveStructs[] = { {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}  };

    TwoValues<int> twoIntValues(1, 5);
    twoIntValues.setName("int");
    twoIntValues.printMax();

    TwoValues<string> twoStrValues("one", "five");
    twoStrValues.setName("string");
    twoStrValues.printMax();

    TwoValues<OneFiveEnum> twoEnumValues(one, five);
    twoEnumValues.setName("enum");
    twoEnumValues.printMax();

    TwoValues<OneFiveStruct> twoStructValues(oneFiveStructs[0], oneFiveStructs[4]);
    twoStructValues.setName("struct");
    twoStructValues.printMax();


    return 0;
}
