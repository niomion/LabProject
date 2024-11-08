#include "EducationalInstitution.h"

EducationalInstitution::EducationalInstitution(string acc, string instType, string name, int year,
    string contact, bool publicInstitution)
    : accreditation(acc), type(instType), institutionName(name), establishedYear(year),
    contactNumber(contact), isPublic(publicInstitution), totalStudents(0) {}

void EducationalInstitution::displayInstitutionInfo() {
	cout << "Info about EI" << this->accreditation << " " << this->type << endl;
}