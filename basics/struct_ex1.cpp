// struct_ex1
//
// Structure examples, including static and dynamic.  Uses enum.

#include <iostream>
#include <cstring>

enum Gender { male = 'M', female = 'F' };

struct Person {
    char name[30];
    int age;
    Gender gender;
};

// dynamically allocate a new person
Person *addPerson(const char name[], int age, Gender gender) {
    Person *person = new Person;

    strcpy(person->name, name);
    person->age = age;
    person->gender = gender;
    return person;
}

int main() {
    using namespace std;

    // create a person on the local stack
    Person person;
    strcpy(person.name, "Billy Bob");
    person.age = 33;
    person.gender = male;

    cout << person.name << endl;
    cout << person.age << endl;
    cout << (person.gender == male ? "Male" : "Female") << endl;
    cout << endl;

    // create an array of dynamically created persons
    Person *persons[3];
    persons[0] = addPerson("Cindy Mindi", 22, female);
    persons[1] = addPerson("Mikey Likey", 42, male);
    persons[2] = addPerson("Mary Harry", 63, female);

    for (int i = 0; i < 3; i++) {
        cout << persons[i]->name << endl;
        cout << persons[i]->age << endl;
        cout << (persons[i]->gender == male ? "Male" : "Female") << endl;
        cout << endl;
    }
    return 0;
}
