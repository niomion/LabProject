#include <iostream>
#include <string>

using namespace std;

#pragma once
class Building
{
protected:
    int yearConstructed;
    string buildingType;
    string address;
    int area; 
    int floors;
    bool isOccupied;
    int numberOfRooms;

public: 
    Building(string addr, int area, int floors, int year, string bType, bool occupied, int rooms);
    void displayBuildingInfo();
};

