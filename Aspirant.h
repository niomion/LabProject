#pragma once
#include <iostream>
#include <string>
#include "Student.h"
#include "Teacher.h"
class Aspirant : public Student, public Teacher
{
private:
	string researchTopic;
	int publications;
public:
	Aspirant(string first, string middle, string last, string gen, int age, string dob, string nation, string addr, string studentID, string faculty,
		int course, double averageGrade, string subject, double salary, string researchTopic, int publications);
};

