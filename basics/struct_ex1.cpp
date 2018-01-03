// struct_ex1
//
// Structure examples, including local storage and dynamic free store storage
// examples.  This is meant to illustrate a simple POD (plain old data) style
// structure, rather than C++ style structures, which are classes differing 
// only in that the default data access is public rather than private.  The
// difference here with the POD style, is there are no explicit constructors
// or member functions.
//
// More than just illustrating a POD type structure, this example illustrates
// different methods of allocating memory for it, with some much more 
// desireable than others.  This includes showing the advantage over using
// a vector, rather than an array.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Gender { male = 'M', female = 'F' };

// more of a C style POD (plain old data) type of struct (no member functions)
// but it does use a newer C++ style string rather than C style string
struct Person {
    string name;
    int age;
    Gender gender;
};

// dynamically allocate a new person.  Note, it is generally not
// a good idea to allocate memory like this in a free function
// (one that is not part of a class) and then return it to another
// function.  The balancing of new with delete is not as clear and
// it is easy to forget the delete, leading to memory leaks.
Person *addPerson(const string& name, int age, Gender gender) {
    Person *person = new Person; 

    person->name = name;
    person->age = age;
    person->gender = gender;
    return person;
}

// better option when dynamically allocating in the free store isn't needed, by
// using a reference instead
Person& addPersonByRef(Person& person, const string& name, int age, Gender gender) {
    person.name = name;
    person.age = age;
    person.gender = gender;
    return person;
}

void printPerson(Person& person) {
        cout << person.name << endl;
        cout << person.age << endl;
        cout << (person.gender == male ? "Male" : "Female") << endl;
        cout << endl;
}

int main() {

    // create a person on the local stack
    Person person;
    person.name = "Billy Bob";
    person.age = 33;
    person.gender = male;

    printPerson(person);

    // create an array in which to add dynamically created persons
    // the least desirable because individual new allocations done
    // inside the addPerson function
    int numPersons = 3; // also used for freeing memory at the end
    Person *persons[numPersons];
    persons[0] = addPerson("Cindy Mindi", 22, female);
    persons[1] = addPerson("Mikey Likey", 42, male);
    persons[2] = addPerson("Mary Berry", 63, female);

    for (int i = 0; i < numPersons; i++) 
        printPerson(*(persons[i]));

    // free the memory allocated, in this case the individual elements of an
    // array. The array itself was locally allocate so it is not deleted -
    // refer to the note for the addPerson function to explain why this 
    // technique is not desirable
    for(int i=0; i < numPersons; i++)
        delete persons[i];

    Person persons2[numPersons];
    addPersonByRef(persons2[0], "Willy Nilly", 33, male);
    addPersonByRef(persons2[1], "Tommy Romey", 29, male);
    addPersonByRef(persons2[2], "Sarah Farah", 27, female);

    for (int i = 0; i < numPersons; i++) 
        printPerson(persons2[i]);
    // note the person2 elements don't need to be deleted.

    // Finally, the best option, which is using a vector instead of an array, 
    // which is a better and safer option, and more flexible if the number of 
    // elements is expected to grow.  Also, the elements themselves will be
    // stored on the heap, with the non-data portion of the vector stored
    // here locally on the stack (as declared here).  But the vast majority
    // (the data portion) will be on the heap and not limited by stack size,
    // particularly with a more realistic structure larger than this one.
    vector<Person> personsV;
    personsV.push_back({ "Kimmy Gimmy", 44, female });
    personsV.push_back({ "Joey Snowy", 55, male });
    personsV.push_back({ "Tina Leana", 39, female });

    for (int i = 0; i < numPersons; i++) 
        printPerson(personsV[i]);
    // note the person2 elements don't need to be deleted.

    return 0;
}
