#include "Teacher.h"

Teacher::Teacher(string subj, double salary) 
	: subject(subj), salary(salary) {}

Teacher::Teacher() {}

Teacher::~Teacher() {
		cout << "Class Teacher was destroyed." << endl;
}