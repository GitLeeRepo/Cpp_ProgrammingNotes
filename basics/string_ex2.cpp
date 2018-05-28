// string_ex1
//
// C++ string class, with some C style strings for comparison.

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
