// array_ex1
//
// Illustrates the various data types and their limits in C++

#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <locale>

int main() {
    using namespace std;

    const int SIZE = 5;

    int nums1[] = { 34, 22, 45, 17, 2 };
    int nums2[SIZE] = { 0 };  // initialize all elements to zero
    int nums3[SIZE] = {};    // in C++11 this also initializes all elements to zero

    for (unsigned int i = 0; i < (sizeof(nums1) / sizeof(int)); i++) {
        nums1[i] *= 10;
        cout << nums1[i] << endl;
    }

    for (unsigned int i = 0; i < SIZE; i++) {
        nums2[i] += i;
        cout << nums2[i] << endl;
    }

    for (unsigned int i = 0; i < SIZE; i++) {
        cout << nums3[i] << endl;
    }

    return 0;
}
