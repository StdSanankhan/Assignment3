#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
    string name;

public:
    // Base class constructor
    Animal(string n) : name(n) {
        cout << "Animal constructor called. Name: " << name << endl;
    }

    void setName(string n) {
        name = n;
    }

    string getName() const {
        return name;
    }
};

class Mammal : public Animal {
protected:
    int numberOfLegs;

public:
    // Derived class constructor
    Mammal(string n, int legs) : Animal(n), numberOfLegs(legs) {
        cout << "Mammal constructor called. Number of legs: " << numberOfLegs << endl;
    }

    void setNumberOfLegs(int legs) {
        numberOfLegs = legs;
    }

    int getNumberOfLegs() const {
        return numberOfLegs;
    }
};

class Dog : public Mammal {
public:
    // Derived class constructor
    Dog(string n, int legs) : Mammal(n, legs) {
        cout << "Dog constructor called." << endl;
    }

    void bark() const {
        cout << name << " is barking!" << endl;
    }
};

int main() {
    // Creating a Dog object
    Dog myDog("Buddy", 4);

    // Accessing members of all classes
    cout << "\nAccessing Dog details:" << endl;
    cout << "Name: " << myDog.getName() << endl;
    cout << "Number of legs: " << myDog.getNumberOfLegs() << endl;

    // Calling Dog-specific function
    myDog.bark();

    return 0;
}
