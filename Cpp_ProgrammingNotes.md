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

* Fundamental Types
    * Integer types
    * Float types
* Compound Types
  * Arrays
  * Strings
  * Structures
  * Pointers

## Numeric Initializations and assignments

C++ is fairly lenient in allowing assignments from one numeric type to another.  When assigning to a larger data type (myLong = myInt) there shouldn't be any issues, but doing the opposite (myInt = myLong) could result in an invalid result if myLong is larger than what can fit in an int.  Also, when assigning a float/double to an integer type, the fractional portion will be truncated (myInt = 5.9 results in 5)

The C++11 standard introduced **list initialization** notation, that is not only for lists, but can be used to assign individual values in the initialization, using **braces** for the notation.  It has the advantage that it will not allows **narrowing** of values, i.e., it won't allow a value that is t0o big, or potentially too big to be assigned.  For example:

```c++
char mychar = {64};  // allowed since it fits in a char
char mychar2 = {512};  // compile error, not allowed since it is too big for a char
int x = 5;
char mychar3 = {x}; // compile warning, since x is an integer with the potential of being too big
```

## Fundamental Data Type Sizes and Limits

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

## Fundamental Data Type Examples

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

Refer to the **Fundamental Data Type Sizes and Limits** section above for the output of this program.
## Type Casting

All three of the following methods are legal ways to cast from one numeric type to another:

```c++
    int myInt1 = (int) 44.7;
    int myInt2 = int (44.7);
    int myInt3 = static_cast<int>(44.7);
```
Note that the **static_cast** tends to be more restrictive.

## Auto Declarations

The **C++11** standard introduced **auto** declarations in which the variable type is determined by the value assigned.

```c++
auto w = 512;        // w becomes an integer
auto x = 123456789L; // x becomes a long
auto y = 44.5;       // y becomes a double
auto z = 1.8e18L;    // z becomes a long double 
```

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

## cout Output Formatting

### Examples of various options

```c++
#include <iostream>
#include <iomanip>
#include <climits>
#include <locale>

int main() {
    using namespace std;

    int myIntMax = INT_MAX;

    // save original cout settings
    ios::fmtflags origSettings = cout.flags();


    // decimal, hexadecimal, and octal output
    cout << setw(24) << "Max int (decimal): " << setw(20) << myIntMax << endl;
    cout << hex;
    cout << setw(24) << "Max int (hexadecimal): " << setw(20) << myIntMax << endl;
    cout << oct;
    cout << setw(24) << "Max int (octal): " << setw(20) << myIntMax << endl;
    cout << dec;

    // set locale based on system settings
    // and use setw() for spacing and alignment
    cout.imbue(locale(""));  // use locale thousands separator
    cout << setw(24) << "Max int (sys settings): " << setw(20) << myIntMax << endl;
    cout.imbue(locale("C")); // reset to default no thousand separator
    // explicitly set the locale
    cout.imbue(locale("en_US.UTF-8"));  // use locale thousands separator
    cout << setw(24) << "Max int (explicit): " << setw(20) << myIntMax << endl;
    cout.imbue(locale("C"));

    // save current precision
    int origPrecision = cout.precision();

    // set the number of significant digits to display (rounded)
    // using both member function precision() and manipulator setprecision()
    cout.width(24); // set cout width for next operation
    cout.precision(12); // set cout precision for next operation
    cout << "Orig double: " << setw(20) << 3.14159265359 << setw(24) <<
          "setprecision(4): " << setprecision(4) << setw(12) << 3.14159265359 << endl;

    // by setting cout to fixed, the following precision settings will apply to
    // the number of decimals on the right, rather than total significant digits
    cout << fixed;
    // or cout.setf(ios::fixed, ios::floatfield);
    cout.width(24);
    cout.precision(12);
    cout << "Orig double (fixed): " << setw(20) << 3.14159265359 << setw(24) <<
          "setprecision(4): " << setprecision(4) << setw(12) << 3.14159265359 << endl;

    // set scientific notation
    cout.setf(ios::scientific, ios::floatfield);
    // or cout << scientific;
    cout.width(24);
    cout.precision(12);
    cout << "Scientific: " << setw(20) << (double) ULONG_MAX << endl;

    // restore precision
    cout.precision(origPrecision);

    // restore the original cout settings
    cout.flags(origSettings);
}
```

**Output:**

```
     Max int (decimal):           2147483647
 Max int (hexadecimal):             7fffffff
       Max int (octal):          17777777777
Max int (sys settings):        2,147,483,647
     Max int (explicit):        2,147,483,647
           Orig double:        3.14159265359       setprecision(4):        3.142
   Orig double (fixed):       3.141592653590       setprecision(4):       3.1416
            Scientific:   1.844674407371e+19
```

# File Handling

TBD

# Containers & Iterators

TBD

# Exceptions

TBD

