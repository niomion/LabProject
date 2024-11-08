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
    cout << "This " << this->firstName << " " << this->lastName << " is dead now..." << endl;
    dead = true; 
}

int Person::getAge() {
    return age;
}


void Person::displayInfo() {
    cout << "Name: " << this->firstName << ", Age: " << this->age
        << ", Gender: " << this->gender << ", Nationality: " << this->nationality
        << endl; 
}
