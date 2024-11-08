#pragma once
#include <iostream>
#include <string>
#include <fstream> 
#include "Applicant.h"
#include "Lecturer.h"

using namespace std;

class HumanFactory
{
private:
    static string fNames[15];      
    static string lNames[15];
    static string faculties[15];
    static string mNames[15];
    static string genders[2];
    static string nationalities[3];
    static string addresses[5];

public:
    static int openMenu();
    static Applicant** Service_DynamicArr(int size); 
    static Applicant produceHumanStat();
    static Applicant* produceHumanDyn();
    static Lecturer produceLecturer();
    static Applicant* Service_Static(Applicant array[], int size, string mode);
    static void Service_Dynamic(Applicant** array, int size, string mode);
    static void Service_InDynArr(Applicant** array, Applicant* put, int size, int element);

    static int Service_Menu(Applicant& applicant);
    static void Service_Write(Applicant& applicant);
    static void Service_Read(Applicant& applicant);
    static void Service_Print(Applicant& applicant);
};
