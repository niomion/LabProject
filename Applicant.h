#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include "Person.h"
#include "Lecturer.h"
#include "Grades.h"
using namespace std;

class Applicant : public Person
{
private:
	int userID;
	string faculty;
	int passedExam = 0;
	int randNum(int i); 
public: 
	Grades<double> grades; // Пункт 5
	string dateOfRegistration;
	string currentStatus;
	int quota;
	float averageGrade;
	string getTime();

	Applicant(string firstName, string middleName, string lastName, string gender,
		int age, string dob, string nationality, string address, string faculty);
	Applicant(int id, string fName, string lName, string fac);
	Applicant();
	Applicant(const Applicant& applicant);
	~Applicant() override;
	string operator[](size_t index);
	Applicant& operator--();
	Applicant& operator++();
	Applicant& operator*(Lecturer& lecturer);
	Applicant operator+(Applicant& applicant);
	Applicant& operator-(Applicant& applicant);
	void doWork() override;
	void eleminateApplicant(); 
	using Person::displayInfo;
	void printUser();
	void printUser(Applicant applicant);
	void passExams();
	Applicant reviewGrades(Applicant& applicants);
	// get set

	int getUserID();
	string getFirstName() const;
	string getLastName();
	string getFaculty();
	int getAge() override;
	string getDateOfRegistration();
	string getCurrentStatus();
	int getQuota();
	int getPassedExam();
	string getGender();
	string getMiddleName();
	string getDOB();
	string getNationality();
	string getAdress();

	void setGender(string gender);
	void setNationality(string nationality);
	void setAdress(string adress);
	void setDOB(string dob);
	void setUserID(int userID);
	void setFirstName(string firstName);
	void setMiddleName(string middleName);
	void setLastName(const string lastName);
	void setFaculty(const string faculty);
	void setAge(int age);
	void setDateOfRegistration(string date);
	void setCurrentStatus(string status);
	void setQuota(int quota);
	void setPassedExam(int status);

	void setMath(double grade);
	void setLanguage(double grade);
	void setPhysics(double grade);
	void setHistory(double grade);
	void setGeography(double grade);

	double getMath();
	double getLanguage();
	double getPhysics();
	double getHistory();
	double getGeography();
	double getAverage();
};

