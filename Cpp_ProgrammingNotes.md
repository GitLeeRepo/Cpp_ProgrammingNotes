# Overview

Notes on the C++ programming language

# Reference

* [cplusplus.com](http://www.cplusplus.com/)

## YouTube

* [C++ Programming](https://www.youtube.com/watch?v=Rub-JsjMhWY) - Derek Banas

# Concepts and Terminology

TBD

# Built-in Data Types

While much of C++ involves creating your own data types, these data types are based on the built-in data types.

Two Categories of Built-in Data Types

* Fundemental Types
    * Integer types
    * Float types
* Compound Types
  * Arrays
  * Strings
  * Structures
  * Pointers
  
## Fundemental Data Type Sizes and Limits

From the output of the program in the following section.  Shows the size in bytes of these data types and their min max limits as they are found on a 64 bit Linux system.  It also shows the number of significant digits for float and double.

```bash
       Size of bool: 1
       Size of char: 1
      Size of short: 2
        Size of int: 4
       Size of enum: 4
       Size of long: 8
      Size of float: 4
     Size of double: 8

           Min char:                       -128
           Max char:                        127
  Max unsigned char:                        255
          Min short:                    -32,768
          Max short:                     32,767
 Max Unsigned short:                     65,535
            Min int:             -2,147,483,648
            Max int:              2,147,483,647
   Max Unsigned int:              4,294,967,295
           Min long: -9,223,372,036,854,775,808
           Max long:  9,223,372,036,854,775,807
  Max Unsigned Long: 18,446,744,073,709,551,615
          Min float:                1.17549e-38
          Max float:                3.40282e+38
   float sig digits:                          6
         Min double:               2.22507e-308
         Max double:               1.79769e+308
  double sig digits:                         15
    Min long double:               3.3621e-4932
    Max long double:              1.18973e+4932
long dbl sig digits:                         18
```

## Fundemental Data Type Examples

```c++
#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <locale>

int main() {
    using namespace std;

    bool isTrue = true;
    signed char myCharMin = CHAR_MIN;
    signed char myCharMax = CHAR_MAX;
    unsigned char myUCharMax = UCHAR_MAX;
    short myShortMin = SHRT_MIN;
    short myShortMax = SHRT_MAX;
    unsigned short myUShortMax = USHRT_MAX;
    int myIntMin = INT_MIN;
    int myIntMax = INT_MAX;
    unsigned int myUIntMax = UINT_MAX;
    long myLongMin = LONG_MIN;
    long myLongMax = LONG_MAX;
    unsigned long myULongMax = ULONG_MAX;
    float myFloatMin = FLT_MIN;
    float myFloatMax = FLT_MAX;
    double myDoubleMin = DBL_MIN;
    double myDoubleMax = DBL_MAX;
    long double myLongDoubleMin = LDBL_MIN;
    long double myLongDoubleMax = LDBL_MAX;
    enum color { red, green, blue};
    color myColor = blue;

    // data type sizes in bytes
    cout << setw(21) << "Size of bool: " << sizeof(isTrue) << endl;
    cout << setw(21) << "Size of char: " << sizeof(char) << endl;
    cout << setw(21) << "Size of short: " << sizeof(short) << endl;
    cout << setw(21) << "Size of int: " << sizeof(int) << endl;
    cout << setw(21) << "Size of enum: " << sizeof(myColor) << endl;
    cout << setw(21) << "Size of long: " << sizeof(long) << endl;
    cout << setw(21) << "Size of float: " << sizeof(float) << endl;
    cout << setw(21) << "Size of double: " << sizeof(double) << endl;
    cout << endl;

    // min, max and significant digits
    cout << setw(21) << "Min char: " << setw(26) << (int)myCharMin << endl;
    cout << setw(21) << "Max char: " << setw(26) << (int)myCharMax << endl;
    cout << setw(21) << "Max unsigned char: " << setw(26) << (int)myUCharMax << endl;
    std::cout.imbue(std::locale(""));  // use locale thousands separator
    cout << setw(21) << "Min short: " << setw(26) << myShortMin << endl;
    cout << setw(21) << "Max short: " << setw(26) << myShortMax << endl;
    cout << setw(21) << "Max Unsigned short: " << setw(26) << myUShortMax << endl;
    cout << setw(21) << "Min int: " << setw(26) << myIntMin << endl;
    cout << setw(21) << "Max int: " << setw(26) << myIntMax << endl;
    cout << setw(21) << "Max Unsigned int: " << setw(26) << myUIntMax << endl;
    cout << setw(21) << "Min long: " << setw(26) << myLongMin << endl;
    cout << setw(21) << "Max long: " << setw(26) << myLongMax << endl;
    cout << setw(21) << "Max Unsigned Long: " << setw(26) << myULongMax << endl;
    std::cout.imbue(std::locale("C")); // reset to default no thousand separator
    cout << setw(21) << "Min float: " << setw(26) << myFloatMin << endl;
    cout << setw(21) << "Max float: " << setw(26) << myFloatMax << endl;
    cout << setw(21) << "float sig digits: " << setw(26) << FLT_DIG << endl;
    cout << setw(21) << "Min double: " << setw(26) << myDoubleMin << endl;
    cout << setw(21) << "Max double: " << setw(26) << myDoubleMax << endl;
    cout << setw(21) << "double sig digits: " << setw(26) << DBL_DIG << endl;
    cout << setw(21) << "Min long double: " << setw(26) << myLongDoubleMin << endl;
    cout << setw(21) << "Max long double: " << setw(26) << myLongDoubleMax << endl;
    cout << setw(21) << "long dbl sig digits: " << setw(26) << LDBL_DIG << endl;
    return 0;
}
```

**Output:**

Refer to the **Fundemental Data Type Sizes and Limits** section above for the output of this program.

# Operators and Expressions

TBD

# Conditionals

TBD

# Loops

TBD

# Functions

TBD

# Classes & Object Oriented Programming

TBD

# Templates

TBD

# Input / Output

TBD

# File Handling

TBD

# Containers & Iterators

TBD

# Exceptions

TBD

