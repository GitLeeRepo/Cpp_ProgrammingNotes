// cin_ex1.cpp
//
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
