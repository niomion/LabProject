#include "University.h"

University::University(string name, int firstQuo, int secondQuo)
    : universityName(name), admission(firstQuo, secondQuo) {}

University::~University() {
        cout << "Class University was destroyed." << endl;
}