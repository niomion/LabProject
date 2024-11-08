#include <iostream>
#include <string>

using namespace std;

#pragma once

class EducationalInstitution {
protected:
    string accreditation;
    string type; 
    string institutionName;
    int establishedYear;
    int totalStudents;
    string contactNumber;
    bool isPublic; // державний
public:
    EducationalInstitution(string acc, string instType, string name, int year, string contact, bool publicInstitution);
    void displayInstitutionInfo();
};