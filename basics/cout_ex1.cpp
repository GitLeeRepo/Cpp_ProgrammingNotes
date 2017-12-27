// cout_ex1.cpp
//
// Shows various cout formatting options

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
    cout << setw(24) << "Max int (explict): " << setw(20) << myIntMax << endl;
    cout.imbue(locale("C")); 

    // save current precision
    int origPrecision = cout.precision();

    // set the number of significant digits to display (rounded) 
    // using both member function precision() and maniplator setprecision()
    cout.width(24); // set cout width for next operation
    cout.precision(12); // set cout precision for next operation
    cout << "Orig double: " << setw(20) << 3.14159265359 << setw(24) << 
          "setprecision(4): " << setprecision(4) << setw(12) << 3.14159265359 << endl;

    // by setting cout to fixed, the following precisions settings will apply to
    // the number of decimals on the right, rather than total signficant digits
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
