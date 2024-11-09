#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Teacher
{
protected:
	vector<string> subjects;
	string subject;
	double salary;
public:
	Teacher(string subj, double salary);
	Teacher();
	~Teacher();
};

