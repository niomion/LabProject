#include "Aspirant.h"

Aspirant::Aspirant(string first, string middle, string last,
    string gen, int age, string dob,
    string nation, string addr,
    string studentID, string faculty,
    int yearOfStudy, double GPA,
    string subject, double salary,
    string researchTopic, int publications) : Student(first, middle, last, gen, age, dob, nation, addr, studentID, faculty, course, averageGrade),
    Teacher(subject, salary),
    researchTopic(researchTopic), publications(publications) {}