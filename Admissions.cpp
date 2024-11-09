#include "Admissions.h"
#include <iostream>
#include "Applicant.h"
#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>
#include <vector>

int Admissions::totalApplications = 0;
int Admissions::totalID = 0;

Admissions::Admissions() 
    : quotaFirst(15), quotaSecond(5) {}

Admissions::Admissions(int firstQuo, int secondQuo) 
: quotaFirst(firstQuo), quotaSecond(secondQuo) {}

Admissions::Admissions(const Admissions& admission) 
    : quotaFirst(admission.quotaFirst), quotaSecond(admission.quotaSecond),
    applicants(admission.applicants), applicantsOnline(admission.applicantsOnline), students(admission.students) {}

Admissions::~Admissions() {
    cout << "Admission was destroyed" << endl;
    writeToFile(Admissions::totalApplications, Admissions::totalID);
}

void Admissions::setExaminationController(Lecturer& lecturer) {
    ExaminationController = lecturer; 
}

Admissions& Admissions::operator*=(vector<Applicant>& list) {
    for (auto& applicant : list) {
        applicants.push_back(applicant);
        cout << "Applicant " << applicant.getFirstName() << " " << applicant.getLastName()
            << " has been registered." << endl;
    }
    return *this;
}

Admissions& Admissions::operator=(Applicant& applicant) {
    int tid = applicant.getUserID();
    for (auto& applicant : applicants) {
        if (applicant.getUserID() == tid) {
            cout << "Applicant " << applicant.getFirstName() << " " << applicant.getLastName()
                << " has been found in the list." << endl;
            return *this;
        }
    }
    cout << "Applicant was not found in the list" << endl;
    return *this;
}

Admissions& Admissions::operator-=(Applicant& applicant) {
    int tid = applicant.getUserID();
    for (int i = 0; i < applicants.size(); i++) {
        if (applicant.getUserID() == tid) {
            cout << "Applicant " << applicant.getFirstName() << " " << applicant.getLastName()
                << " has been deleted from the list." << endl;
            applicants.erase(applicants.begin() + i);
            return *this;
        }
    }
    cout << "Applicant was not found in the list" << endl;
    return *this;
}

Admissions& Admissions::operator+=(Applicant& applicant) {
    applicants.push_back(applicant);
    cout << "Applicant " << applicant.getFirstName() << " " << applicant.getLastName()
        << " has been registered." << endl;
    return *this;
}

Admissions& Admissions::operator--(int) {
    if (!applicants.empty()) {
        Applicant temp = applicants.back();
        applicants.pop_back();
        cout << "Applicant " << temp.getFirstName() << " " << temp.getLastName()
            << " has been deleted from the list." << endl;
    }
    else {
        cout << "List of applicants is empty" << endl;
    }

    return *this;
}

Admissions& Admissions::operator++(int) {
    Applicant temp = HumanFactory::produceHumanStat();
    applicants.push_back(temp);
    cout << "Applicant " << temp.getFirstName() << " " << temp.getLastName()
        << " has been registered." << endl;
    return *this;
}

void Admissions::prepareAdmission() {
    ifstream file("Applicants.dat");
    if (file.is_open()) {
        file >> totalApplications >> totalID;
        file.close();
    }
}

void Admissions::printTotalApplicants() {
    cout << "Total applicants count: " << Admissions::totalApplications << endl;
}

int Admissions::getTotalID() {
    totalID++;
    return totalID;
}

void Admissions::registerApplicant(Applicant& applicant, bool online) {
    if (online) {
        applicantsOnline.push_back(applicant);
    }
    else {
        applicants.push_back(applicant);
    }
    cout << "Applicant " << applicant.getFirstName() << " " << applicant.getLastName()
        << " has been registered." << endl;
    setTotalApplications(1);
}

void Admissions::registerApplicant(Applicant& applicant) {
    students.push_back(applicant);
}

void Admissions::listApplicants() {
    if (!applicants.empty()) {
        for (auto& applicant : applicants) {
            applicant.printUser();
        }
    }
    else {
        cout << "List is empty!" << endl;
    }

        for (auto& applicant : applicantsOnline) {
            applicant.printUser();
        }
}

void Admissions::listApplicants(vector<Applicant> students) {
    for (auto& student : students) {
        student.printUser(student);
    }
}

vector<Applicant> Admissions::appealGrades(vector<Applicant>&applicant) {
    for (auto& applicant : applicants) {
        if ((1 + (rand() % 5)) == 1) {
            applicant.reviewGrades(applicant);
        }
    }
    return applicant;
}

void Admissions::applicantExams() {
    for (auto& applicant : applicants) {
        applicant.passExams();
    }
    for (auto& applicant : applicantsOnline) {
        applicant.passExams();
    }
}

void Admissions::passedExam(Lecturer controller, vector<Applicant> applicants, vector<Applicant> applicantsOnline) {
    for (auto& applicant : applicants) {
        if (applicant.getAverage() >= 55) {
            applicant.setPassedExam(1);
            applicant.setCurrentStatus("Passed exams. Last update : " + applicant.getTime());
        }
        else {
            applicant.setPassedExam(2);
            applicant.setCurrentStatus("Doesn't pass exams. Last update : " + applicant.getTime());
        }
    }
    for (auto& applicant : applicantsOnline) {
        if (applicant.getAverage() >= 55) {
            applicant.setPassedExam(1);
            applicant.setCurrentStatus("Passed exams. Last update : " + applicant.getTime());
        }
        else {
            applicant.setPassedExam(2);
            applicant.setCurrentStatus("Doesn't pass exams. Last update : " + applicant.getTime());
        }
    }
}

void Admissions::writeToFile(vector<Applicant> applicants) {
    for (auto& applicant : applicants) {
        string filename = "ApplicantsList/" + (applicant.getFaculty() + to_string(applicant.getQuota())) + ".dat";
        int applicantCount = checkQuota(filename);
        if ((applicant.getQuota() == 0 && applicantCount >= this->getQuotaFirst()) || (applicant.getQuota() == 1 && applicantCount >= this->getQuotaSecond())) {
            ofstream file("ApplicantsList/Failed.dat", ios::app);
            file << applicant.getUserID() << " " << applicant.getFirstName() << " " << applicant.getLastName() << " " << applicant.getFaculty()
                << " " << applicant.getQuota() << endl;
            file.close();
            applicant.setCurrentStatus("All quota are filled. Last Update : " + applicant.getTime());
        }
        else {
            ofstream file(filename, ios::app);
            file << applicant.getUserID() << " " << applicant.getFirstName() << " " << applicant.getLastName() << " " << applicant.getFaculty()
                << " " << applicant.getQuota() << endl;
            file.close();
            applicant.setCurrentStatus("successfully enrolled in the " + applicant.getFaculty() + ".Last Update : " + applicant.getTime());
        }
    }
}

void Admissions::writeToFile(int TotalApplications, int TotalID) {
    ofstream file("Applicants.dat");
    if (file.is_open()) {
        file << TotalApplications << " " << TotalID;
        file.close();
    }
}

string Admissions::getFaculty(int i) {
    if (i > 0 && i <= faculties.size()) {
        return faculties[i - 1];  
    }
    return "Invalid faculty index";
}

void Admissions::fillStudents() {
    for (int i = 0; i < (faculties.size()-1); i++) {
        for (int j = 0; j < 2; j++) {
            string filename = "ApplicantsList/" + getFaculty(i + 1) + to_string(j) + ".dat";
            ifstream file(filename);
            string line;
            while (getline(file, line)) {
                if (!line.empty()) {
                    istringstream iss(line);
                    int id;
                    string firstName, lastName, faculty;
                    iss >> id >> firstName >> lastName >> faculty;
                    Applicant applicant(id, firstName, lastName, faculty);
                    registerApplicant(applicant);
                }
            }
        }
    }
}

int Admissions::checkQuota(string filename) {
    int applicantCount = 0;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        ++applicantCount;
    }
    return applicantCount;
}

void Admissions::enrollment() {
    Admissions::passedExam(ExaminationController ,applicants, applicantsOnline);
    Admissions::writeToFile(Admissions::applicants);
    Admissions::writeToFile(Admissions::applicantsOnline);
    applicants.clear();
    applicants.shrink_to_fit();
    applicantsOnline.clear();
    applicantsOnline.shrink_to_fit();
}

int Admissions::getQuotaFirst() { return quotaFirst; }
int Admissions::getQuotaSecond() { return quotaSecond; }
int Admissions::getTotalApplications() { return totalApplications; }
void Admissions::setTotalApplications(int i) { this->totalApplications = this->totalApplications + i; }