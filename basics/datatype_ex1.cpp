// datatypes_ex1
//
// Illustrates the various data types and their limits in C++

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
