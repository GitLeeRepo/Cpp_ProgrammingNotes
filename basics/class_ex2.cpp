// class_ex2
//
// Illustrates Base and Derived classes, and polymorphic behavior


#include <iostream>
#include <string>

using namespace std;

// Animal class
class Animal {
public:
    Animal(string name, float weight, string sound, string family) {
        this->name = name;
        this->weight = weight;
        this->sound = sound;
        this->family = family;
    } 

    virtual string getName() {
        return name;
    }

    virtual void setName(string name) {
        this->name = name;
    }

    virtual string getSound() {
        return sound;
    }

    virtual string getFamily() {
        return family;
    }

    virtual float getWeight() {
        return weight;
    }

    virtual void setWeight(float weight) {
        this->weight = weight;
    }

    // overridden in Cat & Dog for specific output for each
    // they call this for the common data item output
    virtual void print() {
        cout << "name: " << getName() << endl;
        cout << "family: " << getFamily() << endl;
        cout << "sound: " << getSound() << endl;
        cout << "weight: " << getWeight() << endl;
    }

    virtual ~Animal() {}

private:
    string name = "";
    string sound = "";
    string family = "";
    float weight = 0.0;
};

// Dog class
class Dog : public Animal {
public:
    Dog(string name, float weight) 
        : Animal(name, weight, "bark", "canine") {

        serviceDog = false;
    }

    virtual void print() {
        Animal::print(); // call the base function print()
        if (isServiceDog())
            cout << getName() << " is a service dog\n";
        else
            cout << getName() << " is just an ordinary dog\n"; 
        cout << endl;
    }

    bool isServiceDog() {
        return serviceDog;
    }

    bool isServiceDog(bool serviceDog) {
        this->serviceDog = serviceDog;
        return this->serviceDog;
    }

private:
    bool serviceDog = false;
};

// Cat class
class Cat : public Animal {
public:
    Cat(string name, float weight) 
        : Animal(name, weight, "meow", "feline") { }

    virtual void print() {
        Animal::print();  // call the base function print()
        cout << getName() << " is just an ordinary cat\n";
        cout << endl;
    }
};

// function to display the polymorphic behavior
void poly(Animal& a) {
    // polymorphism happens here.  Both Dog and Cat classes override the
    // virtual function print() in the Animal class.  They first call the
    // base print function in Animal, and then follow that with custom
    // information that is only available to them.
    a.print();
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
    d2.isServiceDog(true);
    poly(d2);
    // because d2.isServiceDog() is not in the Animal class, it was not 
    // directly accessible in the poly() function, but it is here.  However,
    // the poly() function was able to print service dog info using the
    // overridden print() function in the Dog class, which did have
    // access to service dog info.
    if (d2.isServiceDog() && !d.isServiceDog())
        cout << d2.getName() << " is a service dog but " << 
                                        d.getName() << " is not\n";

    return 0;
}
