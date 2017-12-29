// class_ex3
//
// Illustrates Abstract and Derived classes.  This differs from class_ex2
// in which a lot of the functionality was shared in the Base (non-Abstract)
// Animal class, with only one function overridden.  This version uses pure
// virtual functions which forces both the Cat and Dog classes to override
// the virtual functions.  Here they don't share base code, but do share
// a common interface and so they are able to be called polymorphically.


#include <iostream>
#include <string>

using namespace std;

class Animal {

public:
    virtual string getName() = 0;
    virtual void setName(string name) = 0;
    virtual string getSound() = 0;
    virtual string getFamily() = 0;
    virtual float getWeight() = 0;
    virtual void setWeight(float) = 0;
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    Dog(string name, float weight) : name{name}, weight{weight} {
        sound = "bark";
        family = "canine";
    } 

    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    string getSound() {
        return sound;
    }

    string getFamily() {
        return family;
    }

    float getWeight() {
        return weight;
    }

    void setWeight(float weight) {
        this->weight = weight;
    }

    ~Dog() {}

private:
    string name = "";
    string sound = "";
    string family = "";
    float weight = 0.0;
};

class Cat : public Animal {
public:
    Cat(string name, float weight) : name{name}, weight{weight} {
        sound = "meow";
        family = "feline";
    } 

    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    string getSound() {
        return sound;
    }

    string getFamily() {
        return family;
    }

    float getWeight() {
        return weight;
    }

    void setWeight(float weight) {
        this->weight = weight;
    }

    ~Cat() {}

private:
    string name = "";
    string sound = "";
    string family = "";
    float weight = 0.0;
};

// function to display the polymorphic behavior
void poly(Animal& a) {
    cout << "name: " << a.getName() << endl;
    cout << "family: " << a.getFamily() << endl;
    cout << "sound: " << a.getSound() << endl;
    cout << "weight: " << a.getWeight() << endl;
}

int main() {
    using namespace std;

    Dog d("Fido", 5.4);
    poly(d);
    Cat c("Fluffy", 2.2);
    poly(c);

    // make a copy of d
    Dog d2 = d;
    d2.setName("Pepper");
    d2.setWeight(12.6);
    poly(d2);

    return 0;
}
