#define _CRT_SECURE_NO_WARNINGS
#include "Applicant.h"
#include "Admissions.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

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
	this->setMathGrade(35 + rand() % 66);
	this->setGeographyGrade(35 + rand() % 66);
	this->setHistoryGrade(35 + rand() % 66);
	this->setPhysicsGrade(35 + rand() % 66);
	this->setLanguageGrade(35 + rand() % 66);
	this->setAverageGrade(sumAverageGrade(this->getMathGrade(), this->getPhysicsGrade(), this->getLanguageGrade(), this->getHistoryGrade(), this->getGeographyGrade()));
	this->setCurrentStatus("Wroted the exams. Last update : " + getTime());
}

float Applicant::sumAverageGrade(int math, int physics, int language, int history, int geography) {
	return ((math + physics + language + history + geography) / 5.0);
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
	this->setMathGrade(65 + rand() % 36);
	this->setGeographyGrade(65 + rand() % 36);
	this->setHistoryGrade(65 + rand() % 36);
	this->setPhysicsGrade(65 + rand() % 36);
	this->setLanguageGrade(65 + rand() % 36);
	this->setAverageGrade(sumAverageGrade(this->getMathGrade(), this->getPhysicsGrade(), this->getLanguageGrade(), this->getHistoryGrade(), this->getGeographyGrade()));
	this->setCurrentStatus("Reviewed the exams. Last update : " + getTime());
	return applicants;
}

int Applicant::getUserID() { return userID; }
string Applicant::getFirstName() { return firstName; }
string Applicant::getLastName() { return lastName; }
string Applicant::getFaculty() { return faculty; }
string Applicant::getDateOfRegistration() { return dateOfRegistration; }
string Applicant::getCurrentStatus() { return currentStatus; }
float Applicant::getAverageGrade() { return averageGrade; }
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
void Applicant::setAverageGrade(float grade) { this->averageGrade = grade; }
void Applicant::setPassedExam(int status) { this->passedExam = status; }
void Applicant::setAge(int age) { this->age = age; }

int Applicant::getMathGrade() { return grades.math; }
int Applicant::getLanguageGrade()  { return grades.language; }
int Applicant::getPhysicsGrade()  { return grades.physics; }
int Applicant::getHistoryGrade()  { return grades.history; }
int Applicant::getGeographyGrade()  { return grades.geography; }

void Applicant::setMathGrade(int grade) { grades.math = grade; }
void Applicant::setLanguageGrade(int grade) { grades.language = grade; }
void Applicant::setPhysicsGrade(int grade) { grades.physics = grade; }
void Applicant::setHistoryGrade(int grade) { grades.history = grade; }
void Applicant::setGeographyGrade(int grade) { grades.geography = grade; }