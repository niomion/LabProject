#pragma once
#include <iostream>
#include <string>
#include "Applicant.h"
#include <vector>
#include "Lecturer.h"

using namespace std;

class Admissions
{
private:
	static int totalID;
	static int totalApplications;
	const int quotaFirst;
	const int quotaSecond;
	string faculties[15] = {
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

