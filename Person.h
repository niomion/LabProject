#include <iostream>
#include <string>

using namespace std;

#pragma once

class Person {
protected:
    string firstName;
    string middleName;
    string lastName;
    string gender;
    int age;
    string dateOfBirth;
    string address;
public:
    string nationality;
private:
    bool dead; 

public:
    virtual void doWork() = 0;
    virtual int getAge() = 0;
    Person(string first, string middle, string last, string gen, int age,
        string dob, string nation, string addr);
    Person(string first, string middle, string last, string gen, int age);
    Person();
    Person operator--();
    Person operator++();
    virtual ~Person();
    void killPerson();
    void ressurectPerson();
    void displayInfo();
};
