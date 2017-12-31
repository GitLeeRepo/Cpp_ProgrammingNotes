# Overview

Notes on the C++ programming language

# Reference

* [cplusplus.com](http://www.cplusplus.com/)

## Books

* [C++ Programming Language 4th Edition](https://www.amazon.com/C-Programming-Language-Bjarne-Stroustrup-ebook/dp/B00DUW4BMS) by Bjarne Stroustrup 

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

## Compound Type - Array

In general the Vector class in the C++ standard library should be chosen over the C style array illustrated here, since the Vector class can guard against out of bounds conditions (buffer overflows) and can be resized.

```c++
#include <iostream>
#include <iomanip>

int main() {
    using namespace std;

    const int SIZE = 5;
    int nums1[] = { 34, 22, 45, 17, 2 };
    int nums2[SIZE] = { 0 };  // initialize all elements to zero
    int nums3[SIZE] = {};    // in C++11 this also initializes all elements to zero
    int multi[SIZE][SIZE] = {{ 1, 2, 3, 4, 5 },
                             { 2, 3, 4, 5, 6 },
                             { 3, 4, 5, 6, 7 },
                             { 4, 5, 6, 7, 8 },
                             { 5, 6, 7, 8, 9 }};

    for (unsigned int i = 0; i < (sizeof(nums1) / sizeof(int)); i++) {
        nums1[i] *= 10;
        cout << setw(4) << nums1[i];
    }
    cout << endl;

    for (unsigned int i = 0; i < SIZE; i++) {
        nums2[i] += i;
        cout << setw(4) << nums2[i];
    }
    cout << endl;

    for (unsigned int i = 0; i < SIZE; i++) {
        cout << setw(4) << nums3[i];
    }
    cout << endl;

    for (unsigned int i = 0; i < SIZE; i++) {
        for (unsigned int j = 0; j < SIZE; j++)
            cout << setw(4) << multi[i][j];
        cout << endl;
    }
    return 0;
}
```

## Compound Type - String

Two primary string types in C++:
* C Style strings
* String Class

### C Style Strings

```c++
#include <iostream>
#include <iomanip>
#include <cstring>     // C string functions

int main() {
    using namespace std;

    char str1[80] = "Hello, World!"; // buffer bigger than the string, it can safely be filled up to 80 chars 
                                     // (include null terminator)
    char str2[] = "Hello, World!";   // buffer (14 bytes) the same size as the string, including null terminator
    //char *str3 = "Hello, World!";  // valid in C, but C++ displays compiler warning
    char str4[80] = "";              // empty string, the first byte is set to null ('\0')
    char str5[80] = { 0 };           // the entire buffer is filled with nulls ('\0')
    char strArray[3][20] = { "Array", "of", "strings" };
    char *strPtrs[4];

    cout << "Sizeof str1: " << sizeof str1 << "; strlen: " << strlen(str1) << ": " << str1 << endl;
    cout << "Sizeof str2: " << sizeof str2 << "; strlen: " << strlen(str2) << ": " << str2 << endl;
    cout << "Sizeof str4: " << sizeof str4 << "; strlen: " << strlen(str4) << ": " << str4 << endl;
    cout << "Sizeof str5: " << sizeof str5 << "; strlen: " << strlen(str5) << ": " << str5 << endl;

    if (strcmp(str1, str2) == 0)
        cout << "str1 and str2 are equal (content wise)" << endl;
    if (str1 != str2)
        cout << "but they are not the same string (different memory locations)" << endl;

    strcat(str1, "  How are you? (after strcat())");
    cout << "Sizeof str1: " << sizeof str1 << "; strlen: " << strlen(str1) << ": " << str1 << endl;
    strcpy(str4, "str4 not empty now (after strcpy())");
    cout << "Sizeof str4: " << sizeof str4 << "; strlen: " << strlen(str4) << ": " << str4 << endl;
    strcpy(str5, "str5 not empty now (after strcpy())");
    cout << "Sizeof str5: " << sizeof str5 << "; strlen: " << strlen(str5) << ": " << str5 << endl;

    for (unsigned int i = 0; i < 3; i++)
        cout << strArray[i] << endl;

    cout << "\nNow with the strings referenced in an array of string pointers:" << endl;
    strPtrs[0] = str1;
    strPtrs[1] = str2;
    strPtrs[2] = str4;
    strPtrs[3] = str5;
    for (unsigned int i = 0; i < 4; i++)
        cout << strPtrs[i] << endl;

    return 0;
}
```

## String Class

The following example shows some of the features and advantages of string classes, contrasting them with C style strings.

```c++
#include <iostream>
#include <iomanip>
#include <string>     // C++ class string support
#include <cstring>    // C style string functions

int main() {
    using namespace std;

    char cStr1[] = "C style strings ";
    char cStr2[] = "test";
    char cStr3[80] = {0};
    string str1 = "string class strings ";
    string str2 = "are an improvement over ";   
    string str3 = "";
    string str4 = "";

    // You can concatenate string classes, including concatenating
    // a C style string to a string class 
    str3 = str1 + str2 + cStr1;
    cout << str3 << endl;                                  

    // But you can't concatenate C style strings with each other,
    // you must instead use the strcat() function (and need to 
    // make sure the destination is big enough)
    //cStr3 = cStr1 + cStr2;  // not allowed
    strcat(cStr3, cStr1);
    strcat(cStr3, cStr2);
    cout << cStr3 << endl;

    // string class strings also have built-in methods available
    cout << "The length of str3 is " << str3.size() << endl; 

    if (str4.empty())
        cout << "str4 is currently empty" << endl;

    // get a substring
    cout << "'" + str1.substr(0, 12) + "' is a substring of '" + str1 + "'" << endl;

    // find, replace, insert and erase
    int index = str3.find("an improvement over", 0);
    str3.replace(index, 19, "better than");
    str3.insert(index, "much ");
    cout << str3 << endl;
    str3.erase(index, 5);
    cout << str3 << endl;

    // using compare method
    str1 = "car";
    str2 = "house";
    str3 = "car";
    if (str1.compare(str3) == 0)
        cout << str1 + " == " + str3 << endl;
    if (str1.compare(str2) != 0)
        cout << str1 + " != " + str2 << endl;

    // when reading input from cin, it is not necessary to limit
    // the string length like you should with a C style string
    // since a string class will resize to whatever is needed.
    // Note that the string class uses getline(cin, str) rather
    // than the cin.getline(str, size) method used by C style
    // strings, since this method doesn't support string classes.
    cout << "Enter whatever you want" << endl;
    getline(cin, str4);
    cout << str4 << endl;

    // for single word/number entry this works the same as C strings
    cout << "Enter a single integer" << endl;
    cin >> str4;
    int num = stoi(str4); // to int (throws an exception if not a num)
    cout << num << endl;

    return 0;
}
```

## Compound Type - Structure

The following example shows the creation of a structure on the stack, along with an array of dynamically allocated structures stored on the heap.  It also uses an enum.  Note that the **. (dot)** is used to access the non-dynamic structure and the **->** operator is used to access members dynamically allocated.

```c++
#include <iostream>
#include <cstring>

enum Gender { male = 'M', female = 'F' };

struct Person {
    char name[30];
    int age;
    Gender gender;
};

// dynamically allocate a new person
Person *addPerson(const char name[], int age, Gender gender) {
    Person *person = new Person;

    strcpy(person->name, name);
    person->age = age;
    person->gender = gender;
    return person;
}

int main() {
    using namespace std;

    // create a person on the local stack
    Person person;
    strcpy(person.name, "Billy Bob");
    person.age = 33;
    person.gender = male;

    cout << person.name << endl;
    cout << person.age << endl;
    cout << (person.gender == male ? "Male" : "Female") << endl;
    cout << endl;

    // create an array of dynamically created persons
    Person *persons[3];
    persons[0] = addPerson("Cindy Mindi", 22, female);
    persons[1] = addPerson("Mikey Likey", 42, male);
    persons[2] = addPerson("Mary Harry", 63, female);

    for (int i = 0; i < 3; i++) {
        cout << persons[i]->name << endl;
        cout << persons[i]->age << endl;
        cout << (persons[i]->gender == male ? "Male" : "Female") << endl;
        cout << endl;
    }
    return 0;
}
```

## Pointers and Pointer Arithmetic

### nullptr

A  **nullptr** should be used in comparisons rather than the older **NULL** when making comparisons or assignments since it makes it clear that you are dealing with pointer values rather than integer.

```c++
int* ptr = nullptr;
...
if (ptr == nullptr)
   return 0;
```

### References vs Pointers

A reference is similar to a pointer but you don't need to dereference the variable with a **\*** prefix

### Pointer Arithmetic using Increment Operator

```c++
    int ar[] = { 1, 2, 3 };
    int* ptr = ar;
    
    for (; *ptr != 3; ptr++ )
        cout << *ptr << endl;
```

# Memory Allocation and Deallocation

C++ uses the **new** operator to allocate memory from the **free store**, a.k.a, the **heap** or more generally **dynamic memory**.  The **new** operator should generally be used to allocate memory rather than C's **malloc**.

Any **new** statement should have a corresponding **delete** statement to free the memory when you are done with the object.  In addition, you should avoid, where possible, the use of **new** and **delete** statements scattered throughout code, since if these are not properly paired you will have **memory leaks**.  It is a much better practice to put these allocation/deallocation statements in class **constructors and destructors**, since this is much more reliable in that the **destructor** will automatically be called when the object goes out of scope.

Here is an example of pairing **new** and **delete** operations (refer to the **Classes** section for examples that use the preferred way of handling this in constructors and destructors):

```c++
    int *p = new int[2];
    p[0] = 1;
    p[1] = 2;
    ...
    delete[] p;
```

# Operators and Expressions

TBD

# Conditionals

## Immediate If

C++ supports the immediate if, for example:

```c++
    int myInt = 123456;
    long myLong = 123456789;
    
    cout << (myInt < myLong ? "True" : "False") << endl;
    cout << (myInt > myLong ? "True" : "False") << endl;
```

**Output:**

```
True
False
```

# Loops

## Standard for Statement

```c++
    int ar[3] = { 1, 2, 3 };

    for (auto i = 0; i < 3; i++)
        cout << ar[i] << endl;
```

## Range-for Statements

Range-for statements allow you to iterate over a list:

```c++
    int ar[] = { 1, 2, 3 };

    for (auto x: ar)
        cout << x << endl;
    for (auto x: { 3, 2, 1 })
        cout << x << endl;
```
Refer to the Classes section of adding range-for support to custom classes

## for Statement using Pointer Arithmetic

Using the increment operator to traverse through the elements of an array pointer.  Note, for loops don't always need an initializer.

```c++
    int ar[] = { 1, 2, 3 };
    int* ptr = ar;
    
    for (; *ptr != 3; ptr++ )
        cout << *ptr << endl;
```

# Functions

## Passing by Reference vs by Value

C++ uses the **&** (ampersand) following the type designator for the reference variable in the called functions parameter list.  For example:

```c++
#include <iostream>

int funcByRef(int& times2) {
    times2 *= 2;  // change reflected after the function returns
    return times2;
}

// function called with a parameter by value which won't be changed on return
int funcByVal(int times2) {
    times2 *= 2;   // only changed locally
    return times2;
}

int main() {
    using namespace std;
    int x = 2;
    int result = 0;

    // x passed by value, so unchanged by the function
    cout << "x before calling funcByVal(): " << x << endl;
    result = funcByVal(x);
    cout << "funcByVal() returns " << result << " and x is still " << x <<endl;

    // x passed by reference, so it is changed by the function
    cout << "x before calling funcByRef(): " << x << endl;
    result = funcByRef(x);
    cout << "funcByRef() returns " << result << " and x was changed to " << x <<endl;
}
```

**Output:**

```
x before calling funcByVal(): 2
funcByVal() returns 4 and x is still 2
x before calling funcByRef(): 2
funcByRef() returns 4 and x was changed to 4
```

# Classes & Object Oriented Programming

Three important types of class concepts:
* **Concrete classes** - smaller classes which contain their own data (as opposed to pointers to other data).  They do not contain any **pure virtual functions**, although they can override ones in a base class.  They are closer in representation to built-in data types, and are typically allocated statically or on the stack.
* **Abstract classes** - provide interfaces to data and methods rather than implementations them.  They are key in providing a base from which other classes can be derived that provide the implementation, doing so in an abstract way that provides the basis for **polymorphic** behaviors.  They provide **virtual functions** that can, and are often required, to be **overridden** by **inheriting** classes.  An abstract class has at least one **pure virtual function**.  You cannot create an object from an abstract class, but you can reference them through references and pointers.
* **Hierarchical classes**  - an ordered hierarchy of **derived classes** inheriting from **base classes**, often with an **abstract** class or classes at the lowest level.  They provide **is a** relationships, a dog is an animal, and an animal is a life form, or a square is a rectangle, and a rectangle is a shape.  They are typically allocated dynamically being accessed through references and pointers, allowing for polymorphic behaviors, assuming the appropriate class hierarchy design.

Other class concepts:

* **abstract function** - refer to **pure virtual function**. 
* **default constructor** - a default constructor has no arguments
* **implicit copy constructor** - if a copy constructor is not declared, an implicit one is created
* **implicit default constructor** - if a default constructor is not created an implicit constructor is used, which is equivalent to a constructor with no initializers and no function body.
* **implicit default destructor** - is created if no default destructor is declared.  It is equivalent to a destructor without a function body.  If the base class destructor is virtual, the implicit destructor will also be virtual.
* **non-virtual functions** - this is the default for member functions that are not preceded by the **virtual** keyword or which have not override a virtual function in a base class (which optionally may be marked virtual or not).  Non-virtual functions can not be overridden, they can only be hidden.  They do not allow **polymorphic behavior**.
* **overridden function qualifiers**
  * **virtual keyword** - the function may be overridden, but it is not required (as long as there is no **=0**)
  * **override keyword** - the function is meant to override a function in a base class (use this if you want to be explicit)
  * **final keyword** - the function is not meant to be overridden.  Once added to a function in a class hierarchy, no further virtual functions can override, and in fact no further classes can be derived from that class.
  * **=0** - the virtual function must be overridden
* **polymorphic behavior** - in order to get polymorphic behavior between classes, the member functions must be virtual and the objects must be accessed through pointers or references.
* **pure virtual function** - use the **=0** specifier on a **virtual function** definition to create a **pure virtual function**.  You can still provide a definition for a pure virtual function, just not in the class declaration, but in its absence it must be overridden.
* **static data member** - there is a single instance of a static data member, regardless of the number of class instance.
* **static member functions** - declared with the **static** keyword.  They don't have a **this** pointer, and cannot be **virtual**.  They are referenced by their name within the class, and with the **classname.function()** notation outside the class (note that is class name, not an implemented object name)
* **virtual function** -a nonstatic member function can be declared as a virtual function, using the **virtual** keyword.  A virtual function can be **overridden** in a **derived class** by giving it the same name and parameter signature.  The return type is the same but doesn't have to be.  The **virtual** keyword is optional in the derived class.  Destructors can be virtual, but constructors cannot.  Virtual functions make **polymorphism** possible.  Where virtual functions override the base class function, non-virtual  functions do not override, they hide the base function, which does not provide polymorphic behavior.

## Resource Management through Constructors and Destructors

As mentioned previously in the Memory Allocation and Deallocation section, classes with their **constructors** and **destructors** provide a means of controlling the allocation and deallocation of resources such as memory.  These type of operations are best handled through this mechanism, as opposed to outside the class hierarchy in procedural code, because you can more consistently ensure that an object allocated with **new** will be deallocated with **delete**.  A key part of this is that the **destructors** are automatically called when the object starts to go out of scope.

## Example Vector Class

Note: this example is based on [C++ Programming Language 4th Edition](https://www.amazon.com/C-Programming-Language-Bjarne-Stroustrup-ebook/dp/B00DUW4BMS) by Bjarne Stroustrup with some modifications by me.  Since the C++ standard library provides its own vector class that should be used when vectors are needed.  The Vector class here and in other examples is only used for illustrating class development and other techniques. 

Note the use of two different **constructors**, one of which allows the Vector to be initialized from a list, **Vector v2 = { 1.1, 2.2, 3,3, 4.4, 5.5 }** by using **std::initializer_list**.  Also note the inclusion of the **~Vector destructor**.  This is important, in that any class constructors that allocate memory with **new** should be paired with a **destructor** to free the memory.  It is important that this memory allocation and deallocation takes place in the class itself, rather than outside the class in main(), since it can be handled much more reliably and automatically in the class, rather than having scattered **new** statements that may or may not have a corresponding **delete** statement. An output statement was placed in the destructor simply to illustrate that it is automatically called at the end of main() when it goes out of scope (in this case twice, once for each initialization).

```c++
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
```

**Output:**

```
0.1
11.2
22.3
33.4
44.5
sum = 111.5
1.1
2.2
3.3
4.4
5.5
range-for output
0.1
11.2
22.3
33.4
44.5
Destructor invoked
Destructor invoked
```

# Namespace

## Accessing Namespaces

Use the **::** scope resolution operator.

```c++
std::cout << "Hello" << std:: endl;
```
Uses cout and endl in the std namespace.

## Using an existing namespace

The most common namespace is **std** for the standard library namespace.  Every function, class, etc. in the standard library is within this namespace

```c++
using namespace std;

// or for just select items
using std::cout;
using std::endl;
```

## Creating Your Own Namespace

```c++
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

// to then use this namespace, qualify it with tlk::
tlk::Vector v(5);
```

# Modules

## Example using the Vector Class from the Prior Classes Section

Note: these examples are based on [C++ Programming Language 4th Edition](https://www.amazon.com/C-Programming-Language-Bjarne-Stroustrup-ebook/dp/B00DUW4BMS) by Bjarne Stroustrup with some modifications by me.

Note the use of the tlk namespace in these examples is not required for modules, but is a good practice for custom library code.

**module_ex1a.cpp** - the module with the main function

```c++
#include <iostream>
#include "Vector.h"

int main() {
    using namespace std;

    tlk::Vector v(8);
    for (auto i = 0; i < v.size(); i++)
        v[i] = (11 * i) + ((double) (i + 1) / 10);

    double sum = 0.0;
    for (auto i = 0; i < v.size(); i++) {
        cout.precision(5);
        cout << v[i] << endl;
        sum += v[i];
    }
    cout << "sum = " << sum << endl;

    // range-for support through begin() & end()
    cout << "range-for output\n";
    for (double x : v) {
        cout << x << endl;
    }
    return 0;
}
```

**Vector.h** - the header file that defines the Vector class

```c++
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
```

**module_ex1b.cpp** - the module that implements the Vector class

```c++
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

    // provide for range-for syntax - for (double x : v)
    double* Vector::begin() {
        return &elem[0];
    }

    double* Vector::end() {
        return &elem[sz];
    }

    int Vector::size()
    {
        return sz;
    }
}
```
Note how the class implementation is separated from the class definition, which is now in Vector.h

# Templates

Concepts
* To declare a template precede either a class or function with **template\<class T\>** or **template\<typename T\>**, either of which works since they are synonymous.  The class version applies equally to function templates as it does to class templates.  They can be used interchangeably.
* With a template the data type itself is passed at the parameter, often specified as **T** by convention, but it can be whatever you want.
* Templates are the C++ means of supporting generic programming.
* Templates are resolved at compile time, as opposed to C# and Java generics which are resolved at run time.  The compiler will generate the appropriate code for the types your template uses, it doesn't generate anything for types that are not used.
* Members of a class that are part of a class declared as a template class with **template\<class T\>** are themselves templates, unless the implementation is separate, in which case you must precede each method with a template declaration.
* Members of a class template are defined exactly the same as in non-template classes, the only difference is using a template parameter such as T in place of another type such as double.
* Virtual members functions are NOT allowed.
* Templates stored in a separate module, such as your own template library, run into an issue with the linker trying to resolve the references, when the definition in a header is separate from the implementation in an object file, as is typically done with class libraries.  There are a couple of different ways of resolving this such as combining the implementation and declaration in the header, or including the cpp file (#include "mytemplatelib.cpp") in the source.  Other methods involve putting dummy function calls in the \*.cpp file that contains the template implementation, which calls each definition with the expected types.  The function itself doesn't need to be called, it just needs to exist for the linker to resolve the different type possibilities.
* When creating a template class or function, it is often easier to create the class or function using a specific type first, debug it, and then convert it to the template version.
* For the most part the rules for template classes and functions are the same.

## Example Class Template

This example is a conversion of the previous Vector class example based on code from [C++ Programming Language 4th Edition](https://www.amazon.com/C-Programming-Language-Bjarne-Stroustrup-ebook/dp/B00DUW4BMS) by Bjarne Stroustrup, with modifications by me.

```c++
#include <iostream>
#include <string>

template <typename T>
class Vector {
public:
    // constructor - init elem & sz
    Vector(int s) :elem{new T[s]}, sz{s} {
        for (int i = 0; i < s; i++)
            elem[i] = 0;
    }

    // constructor - initialize with list, ex., Vector v =  { 1, 2, 3 }
    Vector(std::initializer_list<T> lst)
        :elem{new T[lst.size()]}, sz{static_cast<int>(lst.size())} {
        std::copy(lst.begin(), lst.end(), elem);
    }
    // destructor
    ~Vector() {
        delete[] elem;
        std::cout << "Destructor invoked\n";
    }

    //subscripting access
    T& operator[](int i) { return elem[i]; }

    // provide for range-for syntax - for (double x : v)
    T* begin() {
        return &elem[0];
    }

    T* end() {
        return &elem[sz];
    }

    int size() { return sz; }

private:
    T* elem;  // pointer to the elements
    int sz;        // number of elements
};

int main() {
    using namespace std;

    Vector<double> vdbl(5);
    for (auto i = 0; i < vdbl.size(); i++)
        vdbl[i] = (11 * i) + ((double) (i + 1) / 10);

    double sum = 0.0;
    for (auto i = 0; i < vdbl.size(); i++) {
        cout << vdbl[i] << endl;
        sum += vdbl[i];
    }
    cout << "sum = " << sum << endl;

    // initialize vector from a list
    Vector<int> vint = { 1, 2, 3, 4, 5 };
    for (auto i = 0; i < vint.size(); i++)
        cout << vint[i] << endl;

    Vector<string> vstr = { "one", "two", "three" };
    // range-for support through begin() & end()
    cout << "range-for output\n";
    for (string x : vstr) {
        cout << x << endl;
    }

    return 0;
}
```

**Output:**

```
0.1
11.2
22.3
33.4
44.5
sum = 111.5
1
2
3
4
5
range-for output
one
two
three
Destructor invoked
Destructor invoked
Destructor invoked
```

# Input / Output

## cin Input

* **cin >> varName** - reads a word (delimited by a white space character).  If more than one word is entered the additional words remain in the input queue and will be picked up by the next input, which is normally not what is desired.

For C style strings:
* **cin.getline(str, size)** - reads an entire line of input up to the newline, it then discards the newline.
* **cin.get(str, size)** - reads an entire line of input up to the newline, but the newline will remain in the input buffer and will be read in by the next input statement.  You can consume the extra newline by chaining on an additional get(), for example, **cin.get(name, 20).get()**

For string classes:
* **getline(cin, str)** - like cin.getline() in that it gets the string up to the newline, but with string classes it is not necessary to enter a size since they will automatically resize to whatever is needed.

### cin.getline Example

```c++
//  using cin.getline() for input into C style strings

#include <iostream>
#include <cstring>

int main() {
    using namespace std;

    const int SIZE = 30;
    int inputSize = SIZE - 1;
    char name[SIZE] = { 0 };
    char street[SIZE] = { 0 };
    char cityStateZip[SIZE] = { 0 };
    char ageStr[4] = { 0 };
    int age;

    cout << "Enter first and last name, separated by a space" << endl;
    cin.getline(name, inputSize);
    cout << "Enter street address" << endl;
    cin.getline(street, inputSize);
    cout << "Enter City, State Zip" << endl;
    cin.getline(cityStateZip, inputSize);
    cout << "Enter age" << endl;
    cin.getline(ageStr, 3);
    age = atoi(ageStr);

    cout << name << endl;
    cout << street << endl;
    cout << cityStateZip << endl;
    cout << age << endl;

    return 0;
}
```

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

A container is an object that holds a collection of elements, such as a vector or a list.

# Exceptions

## Exception Examples

The following example uses the Vector class to trigger an out_of_range exception, and non-numeric user input to trigger an invalid_argument exception, with these two exception then being handled.

```c++
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
```


