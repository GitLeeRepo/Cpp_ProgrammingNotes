// array_ex1
//
// C++ arrays

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
