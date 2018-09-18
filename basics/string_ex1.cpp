// string_ex1
//
// C++ C style strings

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
