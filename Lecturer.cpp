#include "Lecturer.h"

int Lecturer::getAge() { return age; }

Lecturer::Lecturer(int lectureHours, string first, string middle, string last, string gen, int age,
	string dob, string nation, string addr, string subj, double salary) 
	: Person(first, middle, last, gen, age, dob, nation, addr), Teacher(subj, salary), lectureHours(lectureHours) {}

Lecturer::Lecturer() {}

Lecturer::~Lecturer() {
	cout << "Lecturer " << this->firstName << " " << this->lastName << " was destroyed." << endl;
}

void Lecturer::doWork() {
	cout << "Lecturer doing his work now" << endl;
}