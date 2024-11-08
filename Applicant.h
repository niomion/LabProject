#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include "Person.h"
using namespace std;

class Applicant : public Person
{
private:
	int userID;
	string faculty;
	int passedExam = 0;
	struct Grades {
		int math;
		int language;
		int physics;
		int history;
		int geography;
	};
	Grades grades;
	int randNum(int i); 
public: 
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

	void doWork() override;
	void eleminateApplicant(); // 3 пункт
	using Person::displayInfo;
	void printUser();
	void printUser(Applicant applicant);
	void passExams();
	float sumAverageGrade(int math, int physics, int language, int history, int geography);
	Applicant reviewGrades(Applicant& applicants);
	// get set

	int getUserID();
	string getFirstName();
	string getLastName();
	string getFaculty();
	int getAge();
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
	void setAverageGrade(float grade);
	void setPassedExam(int status);

	int getMathGrade();
	int getLanguageGrade();
	int getPhysicsGrade();
	int getHistoryGrade();
	int getGeographyGrade();
	float getAverageGrade();

	void setMathGrade(int grade);
	void setLanguageGrade(int grade);
	void setPhysicsGrade(int grade);
	void setHistoryGrade(int grade);
	void setGeographyGrade(int grade);
};

