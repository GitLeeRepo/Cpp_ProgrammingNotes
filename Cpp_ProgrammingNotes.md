# Overview

Notes on the C++ programming language

# Reference

* [cplusplus.com](http://www.cplusplus.com/)

## YouTube

* [C++ Programming](https://www.youtube.com/watch?v=Rub-JsjMhWY) - Derek Banas

# Concepts and Terminology

TBD

# Datatypes

# Basic Data Type Examples

```c++
#include <iostream>
#include <iomanip>
#include <limits>
#include <locale>

int main() {
    using namespace std;

    int myIntMin = numeric_limits<int>::min();
    int myIntMax = numeric_limits<int>::max();
    unsigned int myUIntMax = numeric_limits<unsigned int>::max();
    long myLongMin = numeric_limits<long>::min();
    long myLongMax = numeric_limits<long>::max();
    unsigned long myULongMax = numeric_limits<unsigned long>::max();
    double myDoubleMin = numeric_limits<double>::min();
    double myDoubleMax = numeric_limits<double>::max();
    signed char myCharMin = numeric_limits<char>::min();
    signed char myCharMax = numeric_limits<char>::max();
    unsigned char myUCharMax = numeric_limits<unsigned char>::max();
    bool isTrue = true;
    enum color { red, green, blue};
    color myColor = blue;

    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of long: " << sizeof(long) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of bool: " << sizeof(isTrue) << endl;
    cout << "Size of enum: " << sizeof(myColor) << endl;
    cout << endl;

    cout << setw(20) << "Min char: " << setw(26) << (int)myCharMin << endl;
    cout << setw(20) << "Max char: " << setw(26) << (int)myCharMax << endl;
    cout << setw(20) << "Max unsigned char: " << setw(26) << (int)myUCharMax << endl;
    std::cout.imbue(std::locale(""));  // use locale thousands separator
    cout << setw(20) << "Min int: " << setw(26) << myIntMin << endl;
    cout << setw(20) << "Max int: " << setw(26) << myIntMax << endl;
    cout << setw(20) << "Max Unsigned int: " << setw(26) << myUIntMax << endl;
    cout << setw(20) << "Min long: " << setw(26) << myLongMin << endl;
    cout << setw(20) << "Max long: " << setw(26) << myLongMax << endl;
    cout << setw(20) << "Max Unsigned Long: " << setw(26) << myULongMax << endl;
    std::cout.imbue(std::locale("C")); // reset to default no thousand separator
    cout << setw(20) << "Min double: " << setw(26) << myDoubleMin << endl;
    cout << setw(20) << "Max double: " << setw(26) << myDoubleMax << endl;
    return 0;
}
```

**Output:**

```bash
Size of int: 4
Size of long: 8
Size of double: 8
Size of char: 1
Size of bool: 1
Size of enum: 4

          Min char:                       -128
          Max char:                        127
 Max unsigned char:                        255
           Min int:             -2,147,483,648
           Max int:              2,147,483,647
  Max Unsigned int:              4,294,967,295
          Min long: -9,223,372,036,854,775,808
          Max long:  9,223,372,036,854,775,807
 Max Unsigned Long: 18,446,744,073,709,551,615
        Min double:               2.22507e-308
        Max double:               1.79769e+308
```

# Operators and Expresssions

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

