#include "General.h"


Tutor::Tutor(int id, string firstname, string lastname, char gender, string phone, string address, string date_Joined, string date_Terminated, string subject_Code, string tuition_Centre_code, float rating) {
	this->id = id;
	this->firstname = firstname;
	this->lastname = lastname;
	this->gender = gender;
	this->phone = phone;
	this->address = address;
	this->date_Joined = date_Joined;
	this->date_Terminated = date_Terminated;
	this->subject_Code = subject_Code;
	this->tuition_Centre_code = tuition_Centre_code;
	this->rating = rating;
	this->next = NULL;
}

Tutor::Tutor() {}

//std::string genPhoneNo() {
//	string result = "01";
//
//	for (int i = 0; i < 8; i++) {
//		result += to_string(rand() % 10);
//	}
//	return result;
//}

//void predefineTutor() {
//	int i = 1;
//	struct Tutor* newTutor = NULL;
//
//	newTutor->addTutor(&newTutor, new Tutor(i++, "Charlie", "Puth", 'M', genPhoneNo(), "USA", "15/4/20", "15/4/25", "1", "1", 0.0f));
//	newTutor->addTutor(&newTutor, new Tutor(i++, "Helena", "Patel", 'F', genPhoneNo(), "Singapore", "20/8/20", "20/8/26", "1", "2", 4.8f));
//	newTutor->addTutor(&newTutor, new Tutor(i++, "Aniela", "Gibbs", 'F', genPhoneNo(), "Grenada", "13/10/20", "0/0/0", "2", "3", 4.9f));
//	newTutor->addTutor(&newTutor, new Tutor(i++, "Caelan", "Adamson", 'M', genPhoneNo(), "Malawi", "1/3/19", "15/4/25", "2", "1", 5.0f));
//	newTutor->addTutor(&newTutor, new Tutor(i++, "Kristian", "Reyna", 'F', genPhoneNo(), "Bermuda", "29/11/21", "0/0/0", "3", "2", 4.7f));
//	newTutor->addTutor(&newTutor, new Tutor(i++, "Kaden", "Mccann", 'M', genPhoneNo(), "El Salvador", "5/5/20", "5/5/26", "4", "3", 4.9f));
//	newTutor->addTutor(&newTutor, new Tutor(i++, "Ariel", "Choi", 'F', genPhoneNo(), "Syria", "11/4/21", "0/0/0", "5", "1", 4.8f));
//	newTutor->addTutor(&newTutor, new Tutor(i++, "Chad", "Hogg", 'M', genPhoneNo(), "Liberia", "3/10/22", "0/0/0", "5", "2", 3.5f));
//	newTutor->addTutor(&newTutor, new Tutor(i++, "Orion", "Flynn", 'M', genPhoneNo(), "Azerbajian", "14/12/20", "14/12/25", "6", "3", 3.7f));
//	newTutor->addTutor(&newTutor, new Tutor(i++, "Pamela", "Rubio", 'F', genPhoneNo(), "Eritrea", "23/12/21", "0/0/0", "7", "1", 3.8f));
//	newTutor->addTutor(&newTutor, new Tutor(i++, "Shahid", "Donald", 'M', genPhoneNo(), "Swenden", "30/11/22", "30/11/24", "7", "2", 3.9f));
//	newTutor->addTutor(&newTutor, new Tutor(i++, "Dawn", "Findlay", 'F', genPhoneNo(), "Indonesia", "24/8/21", "0/0/0", "8", "3", 4.5f));
//	newTutor->addTutor(&newTutor, new Tutor(i++, "Jimmie", "Wynn", 'M', genPhoneNo(), "Scotland", "12/7/20", "12/7/23", "9", "1", 5.0f));
//	newTutor->addTutor(&newTutor, new Tutor(i++, "Neha", "Magana", 'F', genPhoneNo(), "Portugal", "8/11/21", "8/11/25", "10", "2", 4.3f));
//	newTutor->addTutor(&newTutor, new Tutor(i++, "Oskar", "Carney", 'M', genPhoneNo(), "South Korea", "18/5/22", "0/0/0", "10", "3", 4.2f));
//
//	newTutor->printFile();
//
//}

bool Tutor::printFile() {

	bool success = false;

	struct Tutor* node = this;

	if (node == NULL) {
		return success;
	}

	ofstream outData;
	outData.open("Tutors.txt");

	while (node != NULL) {
		outData << node->id << "\t" << node->firstname << "\t" << node->lastname << "\t" << node->gender << "\t" << node->phone << "\t" << node->address
			<< "\t" << node->date_Joined << "\t" << node->date_Terminated << "\t" << node->subject_Code << "\t" << node->tuition_Centre_code << "\t" << node->rating << endl;
		node = node->next;
	}

	success = true;

	return success;
}

int Tutor::getId() {
	return this->id;
}

void Tutor::printTutorFull() {
	cout << this->id << "\t" << this->firstname << " " << this->lastname << "\t\t" << this->subject_Code << "\t" << this->tuition_Centre_code << "\t\t" << this->rating << endl;
}

void Tutor::printTutorBrief() {
	cout << this->id << "\t" << this->firstname << " " << this->lastname << endl;

}

void Tutor::displayTutors(bool isBrief) {
	system("CLS");

	struct Tutor* node = this;

	if (this == NULL) return;

	if (isBrief) {
		cout << "ID" << "\t" << "Name" << endl;
	}
	else {
		cout << "ID" << "\t" << "Name" << "\t\t\t" << "Subject" << "\t" << "Tuition Centre" << "\t" << "Rating" << endl;
	}

	while (node != NULL) {

		//check termination status don't print if terminated
		if (node->isTerminated()) {
			node = node->next;
			continue;
		}

		if (isBrief) {
			node->printTutorBrief();
		}
		else {
			node->printTutorFull();
		}

		node = node->next;
	}

	cout << endl;
}

//view specific tutor all info

//retrieval
struct Tutor** Tutor::retrieveById(int id) {
	struct Tutor* node = this;
	struct Tutor** result = NULL;

	if (node == NULL) return result;

	while (node != NULL) {
		if (node->searchById(id)) {
			result = &node;
			return result;
		}
		else {
			node = node->next;
		}
	}

	return result;
}

//searches
bool Tutor::searchById(int id) {
	return (this->id == id);
}

bool Tutor::searchByRating(int min, int max) {
	return (this->rating >= min && this->rating <= max);
}

bool Tutor::searchByTuitionCentre(string code) {
	return (this->tuition_Centre_code == code);
}

bool Tutor::searchBySubject(string code) {
	return (this->subject_Code == code);
}

//sorting
bool Tutor::sortById() {
	return (this->id > this->next->id);
}

bool Tutor::sortByRating() {
	return (this->rating > this->next->rating);
}

bool Tutor::sortByHourlyPayRate(struct Subject** head) {
	bool result = false;

	float current_rate = 0, next_rate = 0;

	struct Subject** current_subject = (*head)->searchByCode(this->subject_Code);
	current_rate = current_subject == NULL ? 0 : (*current_subject)->getHourlyPayRate();

	struct Subject** next_subject = (*head)->searchByCode(this->next->subject_Code);
	next_rate = next_subject == NULL ? 0 : (*next_subject)->getHourlyPayRate();

	//compare hourly pay rate
	result = current_rate > next_rate;

	return result;
}

bool Tutor::isTerminated() {
	bool result = this->date_Terminated != no_termination_date;
	return result;
}

//terminate
void Tutor::terminateTutor() {
	this->date_Terminated = today();
}

//getLargestId
int Tutor::generateId() {
	int current = 1;

	struct Tutor* node = this;

	if (this == NULL) return current;

	while (node != NULL) {

		if (node->id > current) {
			current = node->id;
		}

		node = node->next;
	}

	return current + 1;
}

//Free up memory
void Tutor::deleteTutorList()
{
	if (this == NULL) return;

	Tutor* current = this;
	Tutor* next = NULL;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

//External functions
void DisplayAllTutors() {

	struct Tutor* tutorList = NULL;
	RetrieveTutors(&tutorList);

	//Display Tutor
	tutorList->displayTutors(false);
	TutorListMenu(&tutorList);

}

void RetrieveTutors(struct Tutor** head) {
	ifstream inData;
	inData.open("Tutors.txt");

	struct Tutor* node = *head;

	int id;
	string str_id, firstname, lastname, phone, address, date_Joined, date_Terminated, subject_Code, tuition_Centre_Code, str_rating;
	char gender;


	while (inData >> str_id >> firstname >> lastname >> gender >> phone >> address >> date_Joined >> date_Terminated >> subject_Code >> tuition_Centre_Code >> str_rating) {

		id = stoi(str_id);

		//Calculatate rating
		//-Retrieve-
		struct Rating* ratingList = NULL;
		RetrieveRatings(&ratingList);

		float rating = 0;

		if (ratingList != NULL) {
			//-Calculate-
			rating = CalculateRatings(&ratingList, id);
		}

		struct Tutor* input = new Tutor(id, firstname, lastname, gender, phone, address, date_Joined, date_Terminated, subject_Code, tuition_Centre_Code, rating);


		if (*head == NULL) {
			*head = input;
			node = *head;
		}
		else {
			node->next = input;
			node = node->next;

		}

	}

}

void SearchTutorById(struct Tutor** head) {

	if (*head == NULL) return;

	struct Tutor* node = *head;

	string input;
	int id = -1;

	cout << "Enter Tutor ID: ";
	cin >> input;

	try {
		id = stoi(input);
	}
	catch (exception) {
		cout << "Invalid Input!" << endl;
		node->displayTutors(false);
		return;
	}

	while (node != NULL) {
		if (node->searchById(id)) {
			node->printTutorFull();
			return;
		}

		node = node->next;
	}
}

void SearchTutorByRating(struct Tutor** head) {

	if (*head == NULL) return;

	struct Tutor* node = *head;

	string inp_min, inp_max;
	int min, max = -1;

	cout << "Enter Min. Rating (in whole number): ";
	cin >> inp_min;

	cout << "Enter Max. Rating (in whole number): ";
	cin >> inp_max;

	try {
		min = stoi(inp_min);
		max = stoi(inp_max);
	}
	catch (exception) {
		cout << "Invalid Input!" << endl;
		node->displayTutors(false);
		return;
	}

	while (node != NULL) {
		if (node->searchByRating(min, max)) {
			node->printTutorFull();
		}

		node = node->next;
	}
}

void SearchTutorByTuitionCentre(struct Tutor** head) {

	if (*head == NULL) return;

	struct Tutor* node = *head;

	string input;
	int option = -1;

	//Display tuition centres
	struct TuitionCentre* tc_node = NULL;
	RetrieveTuitionCentres(&tc_node);

	if (tc_node == NULL) {
		tc_node->deleteTuitionCentreList();
		node->displayTutors(false);
		return;
	}

	tc_node->displayTuitionCentres(1, false);

	cout << "Enter your option: ";
	cin >> input;

	struct TuitionCentre** tc_ptr = NULL;

	try {
		option = stoi(input);
		tc_ptr = tc_node->searchByIndex(option);
	}
	catch (exception) {
		tc_node->deleteTuitionCentreList();
		cout << "Invalid Input!" << endl;
		node->displayTutors(false);
		return;
	}

	if (tc_ptr == NULL) {
		tc_node->deleteTuitionCentreList();
		node->displayTutors(false);
		return;
	}

	string tc_code = (*tc_ptr)->getCode();
	tc_node->deleteTuitionCentreList();

	while (node != NULL) {
		if (node->searchByTuitionCentre(tc_code)) {
			node->printTutorFull();
		}

		node = node->next;
	}

}

void SearchTutorBySubject(struct Tutor** head) {

	if (*head == NULL) return;

	struct Tutor* node = *head;

	string input;
	int option = -1;

	//Display subjects
	struct Subject* sub_node = NULL;
	RetrieveSubjects(&sub_node);

	if (sub_node == NULL) {
		sub_node->deleteSubjectList();
		node->displayTutors(false);
		return;
	}

	sub_node->displaySubjects(1, false);

	cout << "Enter your option: ";
	cin >> input;

	struct Subject** sub_ptr = NULL;

	try {
		option = stoi(input);
		sub_ptr = sub_node->searchByIndex(option);
	}
	catch (exception) {
		sub_node->deleteSubjectList();
		cout << "Invalid Input!" << endl;
		node->displayTutors(false);
		return;
	}

	if (sub_ptr == NULL) {
		sub_node->deleteSubjectList();
		node->displayTutors(false);
		return;
	}

	string sub_code = (*sub_ptr)->getCode();
	sub_node->deleteSubjectList();

	while (node != NULL) {
		if (node->searchBySubject(sub_code)) {
			node->printTutorFull();
		}

		node = node->next;
	}

}


void SortTutorById(struct Tutor** head) {
	if (*head == NULL) return;

	bool pass = false;

	while (!pass) {

		pass = true;
		struct Tutor* current_node = *head;
		struct Tutor* next_node = current_node->next;
		struct Tutor temp_node;

		while (next_node != NULL) {

			if (current_node->sortById()) {
				pass = false;
				temp_node = *current_node;
				*current_node = *next_node;
				*next_node = temp_node;

				next_node->next = current_node->next;
				current_node->next = next_node;
			}

			current_node = current_node->next;
			next_node = current_node->next;
		}
	}

	(*head)->displayTutors(false);

}

void SortTutorByRating(struct Tutor** head) {
	if (*head == NULL) return;

	struct Tutor* node = *head;

	bool pass = false;

	while (!pass) {

		pass = true;
		struct Tutor* current_node = *head;
		struct Tutor* next_node = current_node->next;
		struct Tutor temp_node;

		while (next_node != NULL) {

			if (current_node->sortByRating()) {
				pass = false;
				temp_node = *current_node;
				*current_node = *next_node;
				*next_node = temp_node;

				next_node->next = current_node->next;
				current_node->next = next_node;
			}

			current_node = current_node->next;
			next_node = current_node->next;
		}
	}

	(*head)->displayTutors(false);

}

void SortTutorByHourlyPayRate(struct Tutor** head) {
	if (*head == NULL) return;

	struct Tutor* node = *head;

	//retrieve subjects
	struct Subject* subjectList = NULL;
	RetrieveSubjects(&subjectList);

	if (subjectList == NULL) {
		subjectList->deleteSubjectList();
		node->displayTutors(false);
		return;
	}

	bool pass = false;

	while (!pass) {

		pass = true;
		struct Tutor* current_node = *head;
		struct Tutor* next_node = current_node->next;
		struct Tutor temp_node;

		while (next_node != NULL) {

			if (current_node->sortByHourlyPayRate(&subjectList)) {
				pass = false;
				temp_node = *current_node;
				*current_node = *next_node;
				*next_node = temp_node;

				next_node->next = current_node->next;
				current_node->next = next_node;
			}

			current_node = current_node->next;
			next_node = current_node->next;
		}
	}

	//delete subject list
	subjectList->deleteSubjectList();

	(*head)->displayTutors(false);

}


void AddTutor() {

	struct Tutor* tutorList = NULL;
	RetrieveTutors(&tutorList);

	if (tutorList == NULL) {
		tutorList->deleteTutorList();
		return;
	}

	//count active tutors
	int count = 0;
	struct Tutor* node = tutorList;

	while (node != NULL) {

		if (!node->isTerminated()) count++;

		node = node->next;
	}

	if (count >= 10) {
		cout << "Maximum number of tutors has reached!" << endl;
		tutorList->deleteTutorList();
		return;
	}

	//free memory
	tutorList->deleteTutorList();


	//retrieve tuition centres
	string tuition_centre_code = "";
	struct TuitionCentre* tuitionCentreList = NULL;
	RetrieveTuitionCentres(&tuitionCentreList);

	if (tuitionCentreList == NULL) {
		tuitionCentreList->deleteTuitionCentreList();
		return;
	}

	//retrieve subjects
	string subject_code = "";
	struct Subject* subjectList = NULL;
	RetrieveSubjects(&subjectList);

	if (subjectList == NULL) {
		tuitionCentreList->deleteTuitionCentreList();
		subjectList->deleteSubjectList();
		return;
	}

	//select tuition centre & subject
	string str_input_tc, str_input_sub;
	int input_tc = -1, input_sub = -1;

	//-request tuition centre-
	tuitionCentreList->displayTuitionCentres(1, false);
	cout << "Enter the index: ";
	cin >> str_input_tc;

	//-process tuition centre-
	try {
		input_tc = stoi(str_input_tc);
	}
	catch (exception) {
		tuitionCentreList->deleteTuitionCentreList();
		subjectList->deleteSubjectList();
		system("CLS");
		cout << "Invalid Input!" << endl;
		return;
	}

	struct TuitionCentre** tuitionCentrePtr = NULL;

	if (input_tc > 0) {
		tuitionCentrePtr = tuitionCentreList->searchByIndex(input_tc);
	}

	//tuition centre retrieval check, if unavailable back to tutor management menu
	if (tuitionCentrePtr == NULL) {
		tuitionCentreList->deleteTuitionCentreList();
		subjectList->deleteSubjectList();
		system("CLS");
		cout << "Invalid Input!" << endl;
		return;
	}

	tuition_centre_code = (*tuitionCentrePtr)->getCode();
	tuitionCentreList->deleteTuitionCentreList();

	//-request subject-
	subjectList->displaySubjects(1, false);
	cout << "Enter the index: ";
	cin >> str_input_sub;

	//-process subject-
	try {
		input_sub = stoi(str_input_sub);
	}
	catch (exception) {
		subjectList->deleteSubjectList();
		system("CLS");
		cout << "Invalid Input!" << endl;
		return;
	}

	struct Subject** subjectPtr = NULL;

	if (input_sub > 0) {
		subjectPtr = subjectList->searchByIndex(input_sub);
	}

	//-subject retrieval check, if unavailable back to tutor management menu-
	if (subjectPtr == NULL) {
		subjectList->deleteSubjectList();
		system("CLS");
		cout << "Invalid Input!" << endl;
		return;
	}

	subject_code = (*subjectPtr)->getCode();
	subjectList->deleteSubjectList();

	string firstname, lastname, phone, address, date_joined, str_gender;
	char gender;
	date_joined = today();

	system("CLS");

	//request tutor's info
	cout << "Enter Tutor's First Name: ";
	cin >> firstname;

	cout << endl << "Enter Tutor's Last Name: ";
	cin >> lastname;

	cout << endl << "Enter Tutor's Phone: ";
	cin >> phone;

	//flush cin
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << endl << "Enter Tutor's Address: ";
	getline(cin, address);

	replace(address.begin(), address.end(), ' ', '_');

	//-gender request & process-
	cout << endl << "Select Tutor Gender" << endl;
	cout << "1. Male" << endl;
	cout << "2. Female" << endl << endl;
	cout << "Enter your option: ";
	cin >> str_gender;

	if (str_gender == "1") {
		gender = 'M';
	}
	else if (str_gender == "2") {
		gender = 'F';
	}
	else {
		system("CLS");
		cout << "Invalid Input!" << endl;
		return;
	}

	//re-retrieve tutor list
	tutorList = NULL;
	RetrieveTutors(&tutorList);

	//get id
	int id = tutorList->generateId();

	//create new struct
	struct Tutor* newTutor = new Tutor(id, firstname, lastname, gender, phone, address, date_joined, no_termination_date, subject_code, tuition_centre_code, 0.0f);

	//add to list
	AddTutorToLast(&tutorList, newTutor);

	system("CLS");

	//write to file
	if (tutorList->printFile()) {
		newTutor->printTutorBrief();
		cout << "Tutor is added!" << endl << endl;
	}
	else {
		cout << "Error adding new tutor!" << endl << endl;
	}

	//free memory space
	tutorList->deleteTutorList();

}

void AddTutorToLast(struct Tutor** head, struct Tutor* newTutor) {
	struct Tutor* node = *head;

	if (node == NULL) {
		*head = newTutor;
	}
	else {
		while (node->next != NULL) {
			node = node->next;
		}

		node->next = newTutor;
	}

}


void EditTutor() {
	struct Tutor* tutorList = NULL;
	RetrieveTutors(&tutorList);

	string str_tutor_id;
	int tutor_id = -1;

	tutorList->displayTutors(true);

	cout << "Enter a tutor ID to edit: ";
	cin >> str_tutor_id;

	try {
		tutor_id = stoi(str_tutor_id);
	}
	catch (exception) {
		tutorList->deleteTutorList();
		system("CLS");
		cout << "Invalid Input" << endl << endl;
		TutorManagementMenu();
		return;
	}


	//availability check
	struct Tutor** tutorPtr = tutorList->retrieveById(tutor_id);

	if (tutorPtr == NULL) {
		tutorList->deleteTutorList();
		system("CLS");
		cout << "Tutor not found!" << endl;
		return;
	}
	struct Tutor* tutorNode = *tutorPtr;

	//termination check
	if (tutorNode->isTerminated()) {
		tutorList->deleteTutorList();
		system("CLS");
		cout << "Tutor was already terminated!" << endl;
		return;
	}

	//edit field
	string input;
	int option = -1;

	try {
		cout << "Choose a sort-by option below:" << endl;
		cout << "0. Back" << endl;
		cout << "1. Address" << endl;
		cout << "2. Contact" << endl << endl;
		cout << "Enter your option: ";

		cin >> input;
		option = stoi(input);

	}
	catch (exception) {
		tutorList->deleteTutorList();
		cout << "Invalid Input!" << endl;
		return;
	}

	//flush cin
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	string newData;

	switch (option) {
	default:
	case 0:
		tutorList->deleteTutorList();
		return;
	case 1:
		system("CLS");
		cout << "Enter Tutor's New Address: " << endl;
		getline(cin, newData);
		replace(newData.begin(), newData.end(), ' ', '_');
		tutorNode->address = newData;
		break;
	case 2:
		system("CLS");
		cout << "Enter Tutor's New Contact: " << endl;
		cin >> newData;
		tutorNode->phone = newData;
		break;
	}

	//save to file
	system("CLS");

	if (tutorList->printFile()) {
		tutorNode->printTutorFull();
		cout << "Tutor's information updated!" << endl << endl;;
	}
	else {
		cout << "Error in updating tutor's information" << endl << endl;;
	}

	//free memory
	tutorList->deleteTutorList();

}

void TerminateTutor() {
	struct Tutor* tutorList = NULL;
	RetrieveTutors(&tutorList);

	string str_tutor_id;
	int tutor_id = -1;

	tutorList->displayTutors(true);

	cout << "Enter a tutor ID to terminate: ";
	cin >> str_tutor_id;

	try {
		tutor_id = stoi(str_tutor_id);
	}
	catch (exception) {
		tutorList->deleteTutorList();
		system("CLS");
		cout << "Invalid Input" << endl << endl;
		TutorManagementMenu();
		return;
	}


	//availability check
	struct Tutor** tutorPtr = tutorList->retrieveById(tutor_id);

	if (tutorPtr == NULL) {
		tutorList->deleteTutorList();
		system("CLS");
		cout << "Tutor not found!" << endl;
		return;
	}
	struct Tutor* tutorNode = *tutorPtr;

	//termination check
	if (tutorNode->isTerminated()) {
		tutorList->deleteTutorList();
		system("CLS");
		cout << "Tutor was already terminated!" << endl;
		return;
	}

	//edit field
	string input;
	int option = -1;

	try {
		cout << "Confirm to terminate tutor?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl << endl;
		cout << "Enter your option: ";

		cin >> input;
		option = stoi(input);

	}
	catch (exception) {
		tutorList->deleteTutorList();
		cout << "Invalid Input!" << endl;
		return;
	}

	string newData;

	switch (option) {
	case 2:
	default:
		system("CLS");
		cout << "Tutor was not terminated!" << endl << endl;
		tutorList->deleteTutorList();
		return;
	case 1:
		tutorNode->terminateTutor();
		break;
	}

	//save to file
	system("CLS");

	if (tutorList->printFile()) {
		tutorNode->printTutorFull();
		cout << "Tutor's has been terminated!" << endl << endl;;
	}
	else {
		cout << "Error in terminating tutor." << endl << endl;;
	}

	//free memory
	tutorList->deleteTutorList();
}
