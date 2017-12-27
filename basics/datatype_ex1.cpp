// datatypes_ex1
//
// Illustrates the various data types and their limits in C++

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
    std::cout.imbue(std::locale("en_US.UTF-8"));  // use locale thousands separator
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
