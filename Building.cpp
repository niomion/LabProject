#include "Building.h"

Building::Building(string addr, int area, int floors, int year, string bType, bool occupied, int rooms)
    : address(addr), area(area), floors(floors), yearConstructed(year), buildingType(bType), isOccupied(occupied), numberOfRooms(rooms) {}

void Building::displayBuildingInfo() {
    cout << "Address: " << address << endl;
    cout << "Area: " << area << " sq. meters" << endl;
    cout << "Floors: " << floors << endl;
    cout << "Year Constructed: " << yearConstructed << endl;
    cout << "Building Type: " << buildingType << endl;
    cout << "Is Occupied: " << (isOccupied ? "Yes" : "No") << endl;
    cout << "Number of Rooms: " << numberOfRooms << endl;
}