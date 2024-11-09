#include "Person.h"

Person::Person(string first, string middle, string last, string gen, int age,
    string dob, string nation, string addr)
    : firstName(first), middleName(middle), lastName(last), gender(gen), age(age),
    dateOfBirth(dob), nationality(nation), address(addr), dead(false) {} 

Person::Person(string first, string middle, string last, string gen, int age)
    : firstName(first), middleName(middle), lastName(last), gender(gen), age(age),
    dead(false) { 
    dateOfBirth = "Unknown";
    nationality = "Unknown";
    address = "Unknown";
}

Person::Person()
    : firstName("Unknown"), middleName("Unknown"), lastName("Unknown"),
    gender("Unknown"), age(0), dateOfBirth("Unknown"), nationality("Unknown"),
    address("Unknown"), dead(false) {} 

Person::~Person() {
    cout << "Class Person was destroyed." << endl;
}

void Person::killPerson() {
    if (!this->dead) {
        cout << "This " << this->firstName << " " << this->lastName << " is dead now..." << endl;
        dead = true;
    }
    else {
        cout << "This " << this->firstName << " " << this->lastName << " is already dead!" << endl;
    }
}

void Person::ressurectPerson() {
    if (this->dead) {
        cout << "This " << this->firstName << " " << this->lastName << " is alive now!" << endl;
        dead = false;
    }
    else {
        cout << "This " << this->firstName << " " << this->lastName << " is already alive!" << endl;
    }
}


void Person::displayInfo() {
    cout << "First name: " << this->firstName << ", Middle name: " << this->middleName << ", Last name: " << this->lastName << ", Age: " << this->age
        << ", Gender: " << this->gender << ", Nationality: " << this->nationality
        << endl; 
}
