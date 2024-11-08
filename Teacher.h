#pragma once
#include <iostream>
#include <string>

using namespace std;

class Teacher
{
protected:
	string subject;
	double salary;
public:
	Teacher(string subj, double salary);
	Teacher();
	~Teacher();
};

