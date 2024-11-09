#pragma once
#include "Student.h"
#include "Lecturer.h"
#include "Aspirant.h"
#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Faculty
{
private:
	vector<T> students;
public:
	Faculty();
	~Faculty();
	void registerStudents(T& person);
	void printAll();
};

	template<typename T>
	Faculty<T>::~Faculty() {
		cout << "Faculty has been destroyed" << endl;
	}

	template<typename T>
	Faculty<T>::Faculty() {
		cout << "Faculty has been created" << endl;
	}

	template<typename T>
	void Faculty<T>::registerStudents(T& person) {
		students.push_back(person);
	}
	template<typename T>
	void Faculty<T>::printAll() {
		for (auto& someone : students) {
			someone.displayInfo();
		}
	}


