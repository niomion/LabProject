#include <iostream>
#include <string>
#include "Applicant.h"
#include "Admissions.h"
#include "HumanFactory.h"
#include "University.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Person.h"
#include "Lecturer.h"

using namespace std;

int main() {
    srand(time(NULL));
   Admissions::prepareAdmission();
   University university("Standart University", 15, 5);
   Lecturer lecturer = HumanFactory::produceLecturer();
    /* university.admission.setExaminationController(lecturer);
    for (int i = 0; i < 10; i++) {
        Applicant applicant = HumanFactory::produceHumanStat();
        university.admission.registerApplicant(applicant, (rand() % 2));
    } 
    
    university.admission.listApplicants();
    university.admission.applicantExams();
    university.admission.appealGrades(university.admission.applicants);
    university.admission.enrollment();
    university.admission.listApplicants();
    university.admission.fillStudents();
    university.admission.listApplicants(university.admission.students);*/

    /* Lab 6 */
    university.admission++; // Пункт 1
    university.admission--;
    university.admission--; 

    Applicant testMan = HumanFactory::produceHumanStat();
    Applicant testMan2 = HumanFactory::produceHumanStat();
    vector<Applicant> test = {HumanFactory::produceHumanStat(), HumanFactory::produceHumanStat(), HumanFactory::produceHumanStat()};
    ++testMan; --testMan; --testMan; ++testMan;

    testMan.displayInfo(); // Пункт 2
    testMan2.displayInfo();
    Applicant abomination = testMan + testMan2;
    abomination.displayInfo();
    Applicant winner = ++testMan - abomination; 

    university.admission += abomination; // Пункт 3
    university.admission = abomination;
    university.admission -= abomination;
    university.admission = abomination;
    university.admission -= abomination;
    university.admission.listApplicants();
    university.admission *= test;
    university.admission.listApplicants();
    abomination = abomination * lecturer;
    cout << abomination[0] << endl;
    
    testMan.displayInfo(); testMan2.displayInfo(); // Пункт 4
    cout << (university.admission.maxAge(testMan, testMan2)).getAge() << endl;

    Student someone = HumanFactory::produceStudent(); // Пункт 6
    university.faculties.registerStudents(someone);
    university.faculties.printAll();

    return 0;
}