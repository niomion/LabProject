#include <iostream>
#include <string>
#include "Faculty.h"
#include "Admissions.h"
using namespace std;

#pragma once
class University
{
protected:
	string universityName;
public:
	vector<Faculty> faculties;
	Admissions admission;

	University(string name, int firstQuo, int secondQuo);
	~University();
};

