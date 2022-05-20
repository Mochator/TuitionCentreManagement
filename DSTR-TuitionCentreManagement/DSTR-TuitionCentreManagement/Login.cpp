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
		cout << "0. \tSystem exit" << endl;
		cout << "1. \tHR" << endl;
		cout << "2. \tAdmin" << endl;
		cout << "3. \tStudent" << endl << endl;

		cout << "Enter your choice: ";

		cin >> input;

		cout << endl;

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
	cout << "Enter the HR's password: ";
	cin >> password;

	if (password == "0") {
		Login();
	}
	else {
		if (password == hrPass) {
			cout << "Welcome back HR!" << endl;
			setRole("HR");
			DisplayHRMenu();
		}
		else {
			cout << "Incorrect HR password!" << endl;
			loginAsHr();
		}
	}
}

void loginAsStudent() {
	string username, password;
	cout << "Enter the your username: ";
	cin >> username;

	cout << "Enter your password: ";
	cin >> password;

	//Retrieve students
	struct Student* studentList = NULL;
	RetrieveStudents(&studentList);

	//Find student based on username
	struct Student** studentPtr = studentList->searchByUsername(username);

	if (studentPtr != NULL) {
		struct Student* student = *studentPtr;
		if (student->passwordComparison(password)) {
			setRole("Student");
			cout << "Welcome back " << student->getFullName() << " !";

			//free up memory space
			DeleteStudentList(&studentList);

			DisplayStudentMenu();
			return;
		}
		else {
			cout << "Invalid username or password!" << endl;
		}
	}
	else {
		cout << "Invalid username or password!" << endl;
	}

	Login();

}

void loginAsAdmin() {
	string strTuitionCentre, password;

	//Retrieve tuition centres
	struct TuitionCentre *tuitionCentreList = NULL;
	RetrieveTuitionCentres(&tuitionCentreList);

	DisplayTuitionCentres(&tuitionCentreList, 1);

	cout << "Enter the index: ";
	cin >> strTuitionCentre;

	cout << "Enter the password: ";
	cin >> password;

	int idxTuitionCentre = 0;

	try {
		int idxTuitionCentre = stoi(strTuitionCentre);

	}
	catch (exception) {
		loginAsAdmin();
		return;
	}

	if (idxTuitionCentre != 0) {
		//Find tuition centre based on index
		struct TuitionCentre** tuitionCentrePtr = tuitionCentreList->searchByIndex(idxTuitionCentre);

		if (tuitionCentrePtr != NULL) {
			struct TuitionCentre* tuitionCentre = *tuitionCentrePtr;

			if (tuitionCentre->passwordComparison(password)) {
				setRole("Admin");
				setTuitionCentreCode(tuitionCentre->getCode());
				cout << "Welcome back Admin - " << tuitionCentre->getCodeName() << " !" << endl;

				//free up memory space
				DeleteTuitionCentreList(&tuitionCentreList);

				//Display admin menu
				DisplayAdminMenu();

				return;
			}
			else {
				cout << "Invalid centre or password!" << endl;
			}
		}
		else {
			cout << "Invalid centre or password!" << endl;
		}

		//free up memory space
		DeleteTuitionCentreList(&tuitionCentreList);
		Login();
	}
}
