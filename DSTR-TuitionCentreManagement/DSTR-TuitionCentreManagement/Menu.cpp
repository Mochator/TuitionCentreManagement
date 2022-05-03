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
	case 0: 
		break;
	case 1: loginAsHr();
		break;
	case 2: loginAsAdmin();
		break;
	case 3: loginAsStudent();
		break;
	}

}

void DisplayAdminMenu() {

}

void DisplayStudentMenu() {

}

void TutorManagementMenu() {

}


