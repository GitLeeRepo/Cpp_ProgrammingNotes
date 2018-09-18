// vector_ex1.cpp
//
// Demonstrates the standard library vector class using an int type.

#include <iostream>
#include <vector>

int main() {
    using namespace std;

    vector<int> v;

    // add to the back of the list
    v.push_back(3);
    v.push_back(5);
    v.push_back(9);
    v.push_back(11);
    v.push_back(13);

    // using the range-for notation
    for (auto x : v) {
        cout << x << "  ";
    }
    cout << endl;

    v.pop_back(); // remove the last element

    // using begin and end methods - note needed dereference
    for (auto x = v.begin(); x != v.end(); x++) {
        cout << *x << "  ";
    }
    cout << endl;

    // reversing with rbegin and rend methods
    for (auto x = v.rbegin(); x != v.rend(); x++) {
        cout << *x << "  ";
    }
    cout << endl;

    v.insert(v.begin(), 2, 1);  // insert 2 number 1s on the front of the list

    // using standard indexing
    for (unsigned int i = 0; i < v.size(); i++) {
        cout << v[i] << "  ";
    }
    cout << endl;

    v.erase(v.begin()+1);  // remove the 2nd element

    for (auto x : v) {
        cout << x << "  ";
    }
    cout << endl;

    v.clear();  // remove all elements 
    cout << "after v.clear() the v.size() is " << v.size() << endl;
}
