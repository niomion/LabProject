#pragma once
#include "Student.h"
#include "Lecturer.h"
#include "Aspirant.h"
#include <iostream>
#include <string>
#include <vector>

class Faculty
{
protected:
	string facultyName;
public:
	vector<Student> students;
	vector<Lecturer> lecturers;
	vector<Aspirant> aspirants;
};

