#include "HumanFactory.h"

Applicant* HumanFactory::Service_Static(Applicant arr[], int size, string mode) {
	if (mode == "female") {
		for (int i = 0; i < size; i++) {
			if (arr[i].getGender() == "Female") {
				arr[i] = Applicant();
			}
		}
		
	}
	else if (mode == "male") {
		for (int i = 0; i < size; i++) {
			if (arr[i].getGender() == "Male") {
				arr[i] = Applicant();
			}
		}
	}
	else if (mode == "print") {
		for (int i = 0; i < size; i++) {
			arr[i].displayInfo();
		}
		return arr;
		
	}
	else {
		cout << "Invalid argument." << endl;
		return arr;
	}
}

void HumanFactory::Service_Dynamic(Applicant** array, int size, string mode) {
	if (array == nullptr) {
		throw invalid_argument("Array is null.");
	}
	if (size <= 0) {
		throw out_of_range("Size must be greater than zero.");
	}
	try {
		if (mode == "female") {
			for (int i = 0; i < size; i++) {
				if (array[i] != nullptr && array[i]->getGender() == "Female") {
					delete array[i];
					array[i] = nullptr;
				}
			}
		} else if (mode == "male") {
			for (int i = 0; i < size; i++) {
				if (array[i] != nullptr && array[i]->getGender() == "Male") {
					delete array[i];
					array[i] = nullptr;
				}
			}
		}
		else if (mode == "print") {
			for (int i = 0; i < size; i++) {
				if (array[i] == nullptr) {
					cout << "Element at index " << i << " is empty." << endl;
				}
				else {
					array[i]->displayInfo();
				}
			}
		}
		else {
			throw invalid_argument("Invalid argument.");
		}
	}
	catch (invalid_argument& e) {
		cout << "Error: " << e.what() << endl;
	}
	catch (out_of_range& e) {
		cout << "Error: " << e.what() << endl;
	}
	catch (exception& e) {
		cout << "Unknown error: " << e.what() << endl;
	}
}

void HumanFactory::Service_InDynArr(Applicant** arr, Applicant* put, int size, int element) {

	try {
		if (rand() % 15 == 1) {
			throw exception("Something happened.");
		}
		if (arr == nullptr) {
			throw invalid_argument("Null pointer.");
		}
		if (element < 0 || element >= size) {
			throw out_of_range("Index is out of range.");
		}
		arr[element] = put;
	}

	catch (invalid_argument& e) {
		cout << "Error: " << e.what() << endl;
	}
	catch (out_of_range& e) {
		cout << "Error: " << e.what() << endl;
	}
	catch (exception& e) {
		cout << "Unknown error: " << e.what() << endl;
	}
}

void HumanFactory::Service_Write(Applicant& obj) {
	string filename; 
	cout << "Enter a filename to write: "; 
	cin >> filename;
	ofstream file(filename, ios::binary);
	if (!file) {
		throw runtime_error("Error opening file for writing.");
	}
	size_t length;
	try {
	length = (obj.getFirstName()).size();
	file.write(reinterpret_cast<char*>(&length), sizeof(length));
	file.write((obj.getFirstName()).c_str(), length);

	length = (obj.getMiddleName()).size();
	file.write(reinterpret_cast<char*>(&length), sizeof(length));
	file.write((obj.getMiddleName()).c_str(), length);

	length = (obj.getLastName()).size();
	file.write(reinterpret_cast<char*>(&length), sizeof(length));
	file.write(obj.getLastName().c_str(), length);

	length = (obj.getFaculty()).size();
	file.write(reinterpret_cast<char*>(&length), sizeof(length));
	file.write((obj.getFaculty()).c_str(), length);

	length = (obj.getGender()).size();
	file.write(reinterpret_cast<char*>(&length), sizeof(length));
	file.write((obj.getGender()).c_str(), length);

	int age = obj.getAge();
	file.write(reinterpret_cast<char*>(&age), sizeof(age));

	length = (obj.getDOB()).size();
	file.write(reinterpret_cast<char*>(&length), sizeof(length));
	file.write((obj.getDOB()).c_str(), length);

	length = (obj.getNationality()).size();
	file.write(reinterpret_cast<char*>(&length), sizeof(length));
	file.write((obj.getNationality()).c_str(), length);

	length = (obj.getAdress()).size();
	file.write(reinterpret_cast<char*>(&length), sizeof(length));
	file.write((obj.getAdress()).c_str(), length);
	cout << "Data successfully written to file: " << filename << endl;
	file.close();
	}
	catch (runtime_error &e) {
		cout << "Runtime error: " << e.what() << endl;
	}

	catch (const exception& e) {
		cout << "Error: " << e.what() << endl;
	}
}

void HumanFactory::Service_Read(Applicant& obj) {
	string filename;
	cout << "Enter the filename to read from: ";
	cin >> filename;

	ifstream file(filename, ios::binary);
	try {
		if (!file) {
			throw runtime_error("Error opening file for reading.");
			return;
		}

		size_t length;
		string tempString;
		int age;

		file.read(reinterpret_cast<char*>(&length), sizeof(length));
		tempString.resize(length);
		file.read(&tempString[0], length);
		obj.setFirstName(tempString);

		file.read(reinterpret_cast<char*>(&length), sizeof(length));
		tempString.resize(length);
		file.read(&tempString[0], length);
		obj.setMiddleName(tempString);

		file.read(reinterpret_cast<char*>(&length), sizeof(length));
		tempString.resize(length);
		file.read(&tempString[0], length);
		obj.setLastName(tempString);

		file.read(reinterpret_cast<char*>(&length), sizeof(length));
		tempString.resize(length);
		file.read(&tempString[0], length);
		obj.setFaculty(tempString);

		file.read(reinterpret_cast<char*>(&length), sizeof(length));
		tempString.resize(length);
		file.read(&tempString[0], length);
		obj.setGender(tempString);

		file.read(reinterpret_cast<char*>(&age), sizeof(age));
		obj.setAge(age);

		file.read(reinterpret_cast<char*>(&length), sizeof(length));
		tempString.resize(length);
		file.read(&tempString[0], length);
		obj.setDOB(tempString);

		file.read(reinterpret_cast<char*>(&length), sizeof(length));
		tempString.resize(length);
		file.read(&tempString[0], length);
		obj.setNationality(tempString);

		file.read(reinterpret_cast<char*>(&length), sizeof(length));
		tempString.resize(length);
		file.read(&tempString[0], length);
		obj.setAdress(tempString);
		file.close();
		cout << "Data successfully read from file: " << filename << endl;
	}
	catch (runtime_error& e) {
		cout << "Runtime error: " << e.what() << endl;
	}
	catch (const exception& e) {
		cout << "Error: " << e.what() << endl;
	}

}

void HumanFactory::Service_Print(Applicant& obj) {
	cout << "First Name: " << obj.getFirstName() << endl;
	cout << "Middle Name: " << obj.getMiddleName() << endl;
	cout << "Last Name: " << obj.getLastName() << endl;
	cout << "Faculty: " << obj.getFaculty() << endl;
	cout << "Gender: " << obj.getGender() << endl;
	cout << "Age: " << obj.getAge() << endl;
	cout << "Date of Birth: " << obj.getDOB() << endl;
	cout << "Nationality: " << obj.getNationality() << endl;
	cout << "Address: " << obj.getAdress() << endl;
}


/*int HumanFactory::Service_Menu(Applicant& obj) {
	int choice;
	while (true) {
		cout << "Service menu:" << endl;
		cout << "1. Write to File" << endl;
		cout << "2. Read from File" << endl;
		cout << "3. Print current object" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			HumanFactory::Service_Write(obj);
			break;
		case 2:
			HumanFactory::Service_Read(obj);
			break;
		case 3:

			break;
		case 4:

			return 0;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	}
} */

int HumanFactory::openMenu() {
	Person* person = nullptr;
	int choice;
	while (true) {
		cout << "Menu:" << endl;
		cout << "1. Create Applicant" << endl;
		cout << "2. Destroy Applicant" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Creating applicant..." << endl;
			person = new Applicant(HumanFactory::produceHumanStat());
			person->displayInfo();
			person->doWork();
			break;
		case 2:
			if (person != nullptr) {
				cout << "Deleting applicant..." << endl;
				delete person;
				person = nullptr;
			}
			else {
				cout << "No person to destroy!" << endl;
			}
			break;
		case 3:
			if (person != nullptr) {
				delete person;
			}
			cout << "Exiting program." << endl;
			return 0;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	}
}

string HumanFactory::fNames[15] = {
	"John", "Emily", "Michael", "Sophia", "James",
	"Olivia", "David", "Emma", "Daniel", "Isabella",
	"Matthew", "Mia", "Joshua", "Charlotte", "Benjamin"
};

string HumanFactory::lNames[15] = {
	"Smith", "Johnson", "Williams", "Brown", "Jones",
	"Garcia", "Miller", "Davis", "Rodriguez", "Martinez",
	"Hernandez", "Lopez", "Gonzalez", "Wilson", "Anderson"
};

string HumanFactory::faculties[15] = {
	"ComputerScience", "Physics", "Mathematics", "Biology", "Chemistry",
	"Engineering", "Law", "Medicine", "Economics", "Psychology",
	"Philosophy", "History", "Art", "Linguistics", "Sociology"
};

string HumanFactory::mNames[15] = {
	"Alexander", "Grace", "Ethan", "Avery", "William",
	"Madison", "Joseph", "Chloe", "Samuel", "Sofia",
	"Liam", "Harper", "Elijah", "Zoe", "Noah"
};

string HumanFactory::genders[2] = { "Male", "Female" };
string HumanFactory::nationalities[3] = { "American", "Canadian", "British" };
string HumanFactory::addresses[5] = { "123 Maple St.", "456 Oak Ave.", "789 Pine Blvd.", "101 Birch Ln.", "202 Elm Rd." };

Applicant* HumanFactory::produceHumanDyn() {
	string firstName = fNames[rand() % 15];
	string middleName = mNames[rand() % 15];
	string lastName = lNames[rand() % 15];
	string faculty = faculties[rand() % 15];
	string gender = genders[rand() % 2];
	int age = 18 + rand() % 10;
	string dob = "01/01/2000";
	string nationality = nationalities[rand() % 3];
	string address = addresses[rand() % 5];
	try {
		if (firstName.empty() || lastName.empty()) {
			throw invalid_argument("First or last name cannot be empty.");
		}
		Applicant* newApplicant = new Applicant(firstName, middleName, lastName, gender, age, dob, nationality, address, faculty);
		return newApplicant;
	}

	catch (const bad_alloc& e) {
		cout << "Memory allocation failed: " << e.what() << endl;
		return nullptr;
	}

	catch (const invalid_argument& e) {
		cout << "Invalid argument: " << e.what() << endl;
		return nullptr;
	}

	catch (exception& e) {
		cout << "Unknown error: " << e.what() << endl;
	}
}

Applicant** HumanFactory::Service_DynamicArr(int size) {
	try {
		if (size >= 9999) {
			throw invalid_argument("Big number");
		}
		Applicant** arr = new Applicant* [size];
		for (int i = 0; i < size; i++) {
			arr[i] = nullptr;
		}
		return arr;
	}
	catch (invalid_argument& e) {
		cout << "Error: " << e.what() << endl;
	}
	catch (const bad_alloc& e) {
		cout << "Memory allocation failed: " << e.what() << endl;
	}
	catch (exception& e) {
		cout << "Unknown error: " << e.what() << endl;
	}
}

Applicant HumanFactory::produceHumanStat() {
	string firstName = fNames[rand() % 15];
	string middleName = mNames[rand() % 15];
	string lastName = lNames[rand() % 15];
	string faculty = faculties[rand() % 15];
	string gender = genders[rand() % 2];
	int age = 18 + rand() % 10;
	string dob = "01/01/2000";
	string nationality = nationalities[rand() % 3];
	string address = addresses[rand() % 5];
	return Applicant(firstName, middleName, lastName, gender, age, dob, nationality, address, faculty);
}

Lecturer HumanFactory::produceLecturer() {
	int lectureHours = 10 + (rand() % 30);
	string firstName = fNames[rand() % 15];
	string middleName = mNames[rand() % 15];
	string lastName = lNames[rand() % 15];
	string gender = genders[rand() % 2];
	int age = 25 + (rand() % 20);
	string dob = "01/01/1970";
	string nationality = nationalities[rand() % 3];
	string address = addresses[rand() % 5];
	string subject = faculties[rand() % 15];
	double salary = 30000 + (rand() % 20000);

	return Lecturer(lectureHours, firstName, middleName, lastName, gender, age, dob, nationality, address, subject, salary);
}