#include "General.h"

string hrPass = "hr12345";

void loginAsHr();
void loginAsAdmin();
void loginAsStudent();

void Login() {

	string input;
	int option = -1;

	try {
		cout << "Pick a role to login or press \"0\" to exit system." << endl;
		cout << "0. System exit" << endl;
		cout << "1. HR" << endl;
		cout << "2. Admin" << endl;
		cout << "3. Student" << endl;

		cin >> input;

		option = stoi(input);
	}
	catch (exception) {
		Login();
	}

	if (option == -1) {
		Login();
	}

	switch (option) {
	default:
	case 0: exit(0);
		break;
	case 1: loginAsHr();
		break;
	case 2: loginAsAdmin();
		break;
	case 3: loginAsStudent();
		break;
	}
}

void loginAsHr() {
	string password;
	cout << "Enter the HR's password:";
	cin >> password;

	if (password == "0") {
		Login();
	}
	else {
		if (password == hrPass) {
			cout << "Welcome back HR!" << endl;
			setRole("HR");
			//TODO: display menu
		}
		else {
			cout << "Incorrect HR password!" << endl;
			loginAsHr();
		}
	}
}

void loginAsStudent() {

}

void loginAsAdmin() {

}
