#define _CRT_SECURE_NO_WARNINGS
#include "Applicant.h"
#include "Admissions.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

string Applicant::operator[](size_t index) {
	switch (index) {
	case 0:
		return this->getFirstName();
	case 1:
		return this->getMiddleName();
	case 2:
		return this->getLastName();
	case 3:
		return this->getFaculty();
	case 4:
		return to_string(this->getAge());
	case 5:
		return this->getGender();
	default:
		return ""; 
	}
}

Applicant& Applicant::operator--() {
	this->killPerson();
	return *this;
}

Applicant& Applicant::operator++() {
	this->ressurectPerson();
	return *this;
}

Applicant& Applicant::operator*(Lecturer& lecturer) {
	lecturer.doWork();
	this->passExams();
	return *this;
}

Applicant& Applicant::operator-(Applicant& someone) {
	if (rand() & 1) {
		--someone;
		cout << this->getFirstName() << " is winner!" << endl;
		return *this;
	}
	else {
		this->killPerson();
		cout << someone.getFirstName() << " is winner!" << endl;
		return someone;
	}
}

Applicant Applicant::operator+(Applicant& victim) {
	string fName = victim.getFirstName();
	string lName = this->getLastName();
	int age = (this->getAge() + victim.getAge());
	string dob = this->getDOB();
	string fac = (rand() % 2 == 0 ? this->getFaculty() : victim.getFaculty());
	string mName = (rand() % 2 == 0 ? this->getMiddleName() : victim.getMiddleName());
	string gender = (this->getGender() == victim.getGender() ? this->getGender() : "Unknown");
	string nat = (this->getNationality() == victim.getNationality() ? this->getNationality() : "Unknown");
	string add = (rand() % 2 == 0 ? this->getAdress() : victim.getAdress());
	this->killPerson();
	--victim;
	cout << "Amalgamation complete..." << endl;
	Applicant sample(fName, mName, lName, gender, age, dob, nat, add, fac);
	return sample;
}

Applicant::Applicant(string firstName, string middleName, string lastName, string gender,
	int age, string dob, string nationality, string address, string faculty)
	: Person(firstName, middleName, lastName, gender, age, dob, nationality, address),
	faculty(faculty) {
	this->userID = Admissions::getTotalID();
	this->quota = randNum(2);
	this->currentStatus = "Created by Applicant. Last update: " + getTime();
}

Applicant::Applicant(int id, string fName, string lName, string fac)
	: Person(fName, "", lName, "", 0, "", "", ""), userID(id), faculty(fac) {}

Applicant::Applicant()
	: Person("Unknown", "Unknown", "Unknown", "Unknown", 0, "Unknown", "Unknown", "Unknown"),
	userID(0), faculty("Unknown"), quota(0),
	currentStatus("Created by Applicant. Last update: " + getTime()) {}

Applicant::Applicant(const Applicant& applicant)
	: Person(applicant.firstName, applicant.middleName, applicant.lastName,
		applicant.gender, applicant.age, applicant.dateOfBirth,
		applicant.nationality, applicant.address), 
	userID(applicant.userID), faculty(applicant.faculty),
	dateOfRegistration(applicant.dateOfRegistration),
	quota(applicant.quota), currentStatus(applicant.currentStatus) {}

Applicant::~Applicant() {
	cout << "Applicant " << this->firstName << " " << this->lastName << " was destroyed" << endl;
}

void Applicant::passExams() {
	this->setMath(35 + rand() % 66);
	this->setGeography(35 + rand() % 66);
	this->setHistory(35 + rand() % 66);
	this->setPhysics(35 + rand() % 66);
	this->setLanguage(35 + rand() % 66);
	this->grades.calculateAverageGrade();
	setCurrentStatus("Wroted the exams. Last update : " + getTime());
}

int Applicant::randNum(int i) {
	if (i == 1) {
		return (100000 + rand() % 50001);
	}
	if (i == 2) {
		int num = rand() % 5;
		if (num == 4) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

string Applicant::getTime() {
	time_t now = time(0);
	tm* localTime = localtime(&now);
	char buffer[80];
	strftime(buffer, sizeof(buffer), "%d-%m-%Y", localTime);
	string formattedTime(buffer);
	return formattedTime;
}

void Applicant::printUser() {
	displayInfo();
}

void Applicant::doWork() {
	cout << "Applicant is studying to pass exams" << endl;
}

void Applicant::eleminateApplicant() {
	Person::killPerson();
}

void Applicant::printUser(Applicant applicant) {
	cout << applicant.userID << " " << this->firstName << " " << this->lastName << " " << this->faculty << endl;
}

Applicant Applicant::reviewGrades(Applicant& applicants) {
	this->setMath(65 + rand() % 36);
	this->setGeography(65 + rand() % 36);
	this->setHistory(65 + rand() % 36);
	this->setPhysics(65 + rand() % 36);
	this->setLanguage(65 + rand() % 36);
	this->grades.calculateAverageGrade();
	this->setCurrentStatus("Reviewed the exams. Last update : " + getTime());
	return applicants;
}

int Applicant::getUserID() { return userID; }
string Applicant::getFirstName() const { return firstName; }
string Applicant::getLastName() { return lastName; }
string Applicant::getFaculty() { return faculty; }
string Applicant::getDateOfRegistration() { return dateOfRegistration; }
string Applicant::getCurrentStatus() { return currentStatus; }
int Applicant::getQuota() { return quota; }
int Applicant::getPassedExam() { return passedExam; }
string Applicant::getGender() { return gender; }
string Applicant::getMiddleName() { return middleName; }
string Applicant::getDOB() { return dateOfBirth; }
string Applicant::getNationality() { return nationality; }
string Applicant::getAdress() { return address; }
int Applicant::getAge() { return age; }

void Applicant::setGender(string gender) { this->gender = gender; }
void Applicant::setNationality(string nationality) { this->nationality = nationality; }
void Applicant::setAdress(string adress) { this->address = adress; }
void Applicant::setDOB(string dob) { this->dateOfBirth = dob; }
void Applicant::setUserID(int userID) { this->userID = userID; }
void Applicant::setFirstName(string firstName)  { this->firstName = firstName; }
void Applicant::setMiddleName(string middleName) { this->middleName = middleName; }
void Applicant::setLastName(string lastName) { this->lastName = lastName; }
void Applicant::setFaculty(string faculty) { this->faculty = faculty; }
void Applicant::setDateOfRegistration(string date) { dateOfRegistration = date; }
void Applicant::setCurrentStatus(string status) { currentStatus = status; }
void Applicant::setQuota(int quota) { this->quota = quota; }
void Applicant::setPassedExam(int status) { this->passedExam = status; }
void Applicant::setAge(int age) { this->age = age; }

void Applicant::setMath(double grade) { grades.setMathGrade(grade); }
void Applicant::setLanguage(double grade) { grades.setLanguageGrade(grade); }
void Applicant::setPhysics(double grade) { grades.setPhysicsGrade(grade); }
void Applicant::setHistory(double grade) { grades.setHistoryGrade(grade); }
void Applicant::setGeography(double grade) { grades.setGeographyGrade(grade); }

double Applicant::getMath() { return grades.getMathGrade(); }
double Applicant::getLanguage() { return grades.getLanguageGrade(); }
double Applicant::getPhysics() { return grades.getPhysicsGrade(); }
double Applicant::getHistory() { return grades.getHistoryGrade(); }
double Applicant::getGeography() { return grades.getGeographyGrade(); }
double Applicant::getAverage() { return grades.getAverageGrade(); }
