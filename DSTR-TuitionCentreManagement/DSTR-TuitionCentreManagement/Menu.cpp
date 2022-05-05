#include <iostream>
#include <string>

using namespace std;

void DisplayHRMenu() {
	//TODO: role check
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
	case 0: role == "";
		Login();
		break;
	case 1: TutorManagementMenu();
		break;
	case 2: displaySubject();
		break;
	case 3: displayTuitionCentre();
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
	case 0: role == "HR" ? DisplayHRMenu() : Login();
		break;
	case 1: AddTutor();
		break;
	case 2: EditTutor();
		break;
	case 3: TerminateTutor();
		break;
	}
}


