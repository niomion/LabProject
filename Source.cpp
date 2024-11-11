#include <iostream>
#include <string>
#include "Applicant.h"
#include "HumanFactory.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <map>
#include "Person.h"
#include "Functor.h"

using namespace std;

void printMap(multimap<int, Applicant>& map, int i) {
    cout << "Map " << i << endl;
    for (auto it = map.begin(); it != map.end(); it++) {
        cout << it->first << " -> " << it->second.getFirstName() << endl;
    }
    cout << "----------" << endl;
}

bool argument(const pair<const int, Applicant>& mapElement) {
    return mapElement.second.getFirstName() == "James";
}

void change(pair<const int, Applicant>& mapElement) {
    mapElement.second.setFirstName("Changed");  
}

int main() {
    srand(time(NULL));
    /* Lab 7 */
    multimap<int, Applicant> map;
    multimap<int, Applicant> map2;
    for (int i = 0; i < 5; i++) {
        map.insert({ i, HumanFactory::produceHumanStat() });
        map2.insert({ i, HumanFactory::produceHumanStat() });
    }
    cout << "Is multimap empty: " << map.empty() << endl;
    map.insert({ 1, HumanFactory::produceHumanStat() });
    printMap(map, 1); printMap(map2, 2);
    map.erase(4);
    map.swap(map2);
    printMap(map, 1); printMap(map2, 2);

    auto it = map.find(1);
    if (it != map.end()) {
        cout << it->first << " => " << it->second.getFirstName() << endl;
    }
    
    int count = count_if(map.begin(), map.end(), argument);
    cout << "Elements with name 'James': " << count << endl;
    for_each(map.begin(), map.end(), change);
    printMap(map, 1);

    // 
    
    Functor<int> func;
    cout << func(10, '+', 5) << endl;
    cout << func(10, '/', 0) << endl;
    cout << func(10, "<", 15) << endl; cout << func(10, "!=", 15) << endl; cout << func(10, "==", 10) << endl;
    cout << func.boolean.logical_and(true, true) << endl;  cout << func.boolean.logical_or(false, false) << endl;
    return 0;
}