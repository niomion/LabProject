#pragma once
#include <iostream>
#include <string>
#include "Applicant.h"
#include <vector>
#include "Lecturer.h"
#include "HumanFactory.h"
using namespace std;

class Admissions
{
private:
	static int totalID;
	static int totalApplications;
	const int quotaFirst;
	const int quotaSecond;
	vector<string> faculties = {
   "ComputerScience", "Physics", "Mathematics", "Biology", "Chemistry",
   "Engineering", "Law", "Medicine", "Economics", "Psychology",
   "Philosophy", "History", "Art", "Linguistics", "Sociology"
	};
	
	Lecturer ExaminationController;

public:
	vector<Applicant> applicants;
	vector<Applicant> applicantsOnline;
	vector<Applicant> students;
	static void prepareAdmission();
	static void printTotalApplicants();
	static int getTotalID();

	Admissions(int firstQuo, int secondQuo);
	Admissions(const Admissions& admission);
	Admissions();

	~Admissions();
	template<typename T>
	auto maxAge(T& x, T& y) {
		return (x.getAge() > y.getAge()) ? x : y;
	}
	Admissions& operator*=(vector<Applicant>& list);
	Admissions& operator+=(Applicant& applicant);
	Admissions& operator-=(Applicant& applicant);
	Admissions& operator=(Applicant& applicant);
	Admissions& operator--(int);
	Admissions& operator++(int);

	void setExaminationController(Lecturer& lecturer);
	void passedExam(Lecturer controller, vector<Applicant> applicants, vector<Applicant> applicantsOnline);
	void registerApplicant(Applicant& applicant);
	void registerApplicant(Applicant& applicant, bool online);
	void listApplicants();
	void listApplicants(vector<Applicant> students);
	void applicantExams();
	vector<Applicant> appealGrades(vector<Applicant>& applicant);
	void enrollment();
	void passedExams();
	void writeToFile(vector<Applicant> applicants);
	void writeToFile(int totalApplications, int totalID);
	void fillStudents();
	int checkQuota(string filename);


	int getQuotaFirst();
	int getQuotaSecond();
	int getTotalApplications();
	void setTotalApplications(int i);
	string getFaculty(int i);
};

