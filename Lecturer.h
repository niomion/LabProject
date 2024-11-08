#pragma once
#include "Person.h"
#include "Teacher.h"
#include <iostream>
#include <string>
class Lecturer : public Person, public Teacher
{
private:
	int lectureHours;
public: 
	Lecturer(int lectureHours, string first, string middle, string last, string gen, int age,
		string dob, string nation, string addr, string subj, double salary);
	Lecturer();
	void doWork() override;
	~Lecturer() override;
};

