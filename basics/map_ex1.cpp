// map_ex1.cpp
//
// Demonstrates the standard library map class which provides a dictionary/hash
// type data structure.

#include <iostream>
#include <map>

struct Person {
    int num;
    std::string name;
};

int main() {
    using namespace std;

    map<int, string> m;

    m[1] = "Bill";
    m[2] = "Tom";
    m[3] = "Sarah";

    for (auto x : m) {
        cout << x.first << "  " << x.second << endl;
    }

    // same group of people, but stored as an object (Person) instead
    Person p[] = { {1, "Bill"}, {2, "Tom"}, {3, "Sarah"} };
    map<int, Person> m2;

    for (auto x : p)
        m2[x.num] = x;

    for (auto x : m2) {
        cout << x.first << "  " << x.second.name << endl;
    }

    // locate by key using find
    auto found = m2.find(2);  // returns an interator, just as begin & end do
    cout << "Found: " << found->second.name << endl;

    // better yet locate by using key as an index
    cout << "Found: " << m2[2].name << endl;

}
