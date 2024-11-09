#include <iostream>
#include <string>
#include "Faculty.h"
#include "Admissions.h"
#include "Student.h"
using namespace std;

#pragma once
class University
{
protected:
	string universityName;
public:
	Faculty<Student> faculties;
	Admissions admission;

	University(string name, int firstQuo, int secondQuo);
	~University();
};

