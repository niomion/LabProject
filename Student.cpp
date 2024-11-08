#include "Student.h"

Student::Student(string first, string middle, string last, string gen, int age, string dob, string nation, string addr,
    const string studentID, const string faculty, int course, double averageGrade)
    : Person(first, middle, last, gen, age, dob, nation, addr), studentID(studentID), faculty(faculty), course(course), averageGrade(averageGrade) {}