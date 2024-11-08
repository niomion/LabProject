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
   /*Admissions::prepareAdmission();
    University university("Standart University", 15, 5);
    Lecturer lecturer = HumanFactory::produceLecturer();
    university.admission.setExaminationController(lecturer);
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

    // Lab 5
     auto dummy = nullptr;
    Applicant** applicantdynamic = HumanFactory::Service_DynamicArr(5);
    Applicant *testman = HumanFactory::produceHumanDyn();
    Applicant* testman2 = HumanFactory::produceHumanDyn();
     HumanFactory::Service_InDynArr(dummy, testman, 5, 5);
     HumanFactory::Service_InDynArr(applicantdynamic, testman, 5, 5);
    HumanFactory::Service_InDynArr(applicantdynamic, testman, 5, 0);
    HumanFactory::Service_InDynArr(applicantdynamic, testman2, 5, 1);
    HumanFactory::Service_Dynamic(applicantdynamic, 5, "print");
    HumanFactory::Service_Dynamic(applicantdynamic, 5, "female");
    HumanFactory::Service_Dynamic(applicantdynamic, 5, "male");
    HumanFactory::Service_Dynamic(applicantdynamic, 5, "print");
    Applicant applicantstatic[5]; 
    applicantstatic[0] = HumanFactory::produceHumanStat();
    applicantstatic[1] = HumanFactory::produceHumanStat();
    HumanFactory::Service_Static(applicantstatic, 5, "print");
    HumanFactory::Service_Static(applicantstatic, 5, "female");
    HumanFactory::Service_Static(applicantstatic, 5, "male");
    HumanFactory::Service_Static(applicantstatic, 5, "print");

    Person *person = nullptr;
    Applicant applicanttest = HumanFactory::produceHumanStat();
    Lecturer lecturertest = HumanFactory::produceLecturer();
    lecturertest.doWork(); // раннього
    person = &applicanttest; 
    person->doWork(); // пізнього
    person = &lecturertest;
    person->doWork();
    HumanFactory::openMenu();

    Applicant Someone = HumanFactory::produceHumanStat();
    Applicant Someone2;
    HumanFactory::Service_Print(Someone);
    HumanFactory::Service_Write(Someone);
    HumanFactory::Service_Read(Someone2);
    HumanFactory::Service_Print(Someone2);
    return 0;
}