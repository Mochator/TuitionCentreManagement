#include "General.h"

void DisplayHRMenu() {

	//Role Check
	if (getRole() != "HR") {
		setRole("");
		setTuitionCentreCode("");
		Login();
		return;
	}

	string input;
	int option = -1;

	try {
		cout << "Choose an option below:" << endl;
		cout << "0. Logout" << endl;
		cout << "1. Tutor Management Menu" << endl;
		cout << "2. View Subject" << endl;
		cout << "3. View Tuition Centre" << endl;

		cin >> input;
		option = stoi(input);

	}
	catch (exception) {
		DisplayHRMenu();
	}

	if (option == -1) {
		DisplayHRMenu();
	}

	switch (option) {
	default:
	case 0: 
		setRole("");
		setTuitionCentreCode("");
		Login();
		break;
	case 1: TutorManagementMenu();
		break;
	case 2: 
		DisplayAllSubjects();
		DisplayHRMenu();
		break;
	case 3: 
		DisplayAllTuitionCentres();
		DisplayHRMenu();
		break;
	}

}

void DisplayAdminMenu() {

}

void DisplayStudentMenu() {

}

void TutorManagementMenu() {
	string input;
	int option = -1;

	try {
		cout << "Choose an option below:" << endl;
		cout << "0. Back" << endl;
		cout << "1. Tutor List" << endl;
		cout << "2. Add Tutor" << endl;
		cout << "3. Edit Tutor" << endl;
		cout << "3. Terminate Tutor" << endl;

		cin >> input;
		option = stoi(input);

	}
	catch (exception) {
		TutorManagementMenu();
	}

	if (option == -1) {
		TutorManagementMenu();
	}

	switch (option) {
	default:
	case 0: getRole() == "HR" ? DisplayHRMenu() : Login();
		break;
	case 1: //TODO: add tutor
		break;
	case 2: //TODO: edit tutor
		break;
	case 3: //TODO: terminate tutor
		break;
	}
}


