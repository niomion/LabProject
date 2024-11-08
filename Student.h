#pragma once
#include "Person.h"
#include <iostream>
#include <string>

class Student : public Person
{
public:
	string studentID;
	string faculty;
	int course;
	double averageGrade;

	Student(string first, string middle, string last, string gen, int age, string dob, string nation, string addr,
		string studentID, string faculty, int course, double averageGrade);
};

