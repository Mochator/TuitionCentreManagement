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

std::string genPhoneNo() {
	string result = "01";

	for (int i = 0; i < 8; i++) {
		result += to_string(rand() % 10);
	}
	return result;
}

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

void Tutor::addTutor(struct Tutor** head, struct Tutor* newTutor) {
	struct Tutor* node = *head;

	if (*head == NULL) {
		*head = newTutor;
	}
	else {
		while (node->next != NULL) {
			node = node->next;
		}

		node->next = newTutor;
	}

}

void Tutor::printFile() {

	struct Tutor* node = this;

	if (node == NULL) {
		return;
	}

	ofstream outData;
	outData.open("Tutors.txt");

	while (node != NULL) {
		outData << node->id << "\t" << node->firstname << "\t" << node->lastname << "\t" << node->gender << "\t" << node->phone << "\t" << node->address
			<< "\t" << node->date_Joined << "\t" << node->date_Terminated << "\t" << node->subject_Code << "\t" << node->tuition_Centre_code << "\t" << node->rating << endl;
		node = node->next;
	}

}

int Tutor::getId() {
	return this->id;
}

void Tutor::editTutor(struct Tutor** head, string field, string newData) {

}

void Tutor::printIdName() {
	cout << this->id << "\t" << this->firstname << " " << this->lastname << "\t\t" << this->subject_Code << "\t" << this->tuition_Centre_code << "\t\t" << this->rating << endl;
}

void Tutor::displayTutors() {
	system("CLS");

	struct Tutor* node = this;

	if (this == NULL) return;

	cout << "ID" << "\t" << "Name" << "\t\t\t" << "Subject" << "\t" << "Tuition Centre" << "\t" << "Rating" << endl;

	while (node != NULL) {
		node->printIdName();
		node = node->next;
	}

	cout << endl;
}

//view specific tutor all info


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
	tutorList->displayTutors();
	TutorListMenu(&tutorList);

}

void RetrieveTutors(struct Tutor** head) {
	ifstream inData;
	inData.open("Tutors.txt");

	struct Tutor* node = *head;

	int id;
	string str_id, firstname, lastname, phone, address, date_Joined, date_Terminated, subject_Code, tuition_Centre_Code;
	char gender;


	while (inData >> str_id >> firstname >> lastname >> gender >> phone >> address >> date_Joined >> date_Terminated >> subject_Code >> tuition_Centre_Code) {

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

		input->printIdName();

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
		node->displayTutors();
		return;
	}

	while (node != NULL) {
		if (node->searchById(id)) {
			node->printIdName();
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
		node->displayTutors();
		return;
	}

	while (node != NULL) {
		if (node->searchByRating(min, max)) {
			node->printIdName();
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
		node->displayTutors();
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
		node->displayTutors();
		return;
	}

	if (tc_ptr == NULL) {
		tc_node->deleteTuitionCentreList();
		node->displayTutors();
		return;
	}

	string tc_code = (*tc_ptr)->getCode();
	tc_node->deleteTuitionCentreList();

	while (node != NULL) {
		if (node->searchByTuitionCentre(tc_code)) {
			node->printIdName();
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
		node->displayTutors();
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
		node->displayTutors();
		return;
	}

	if (sub_ptr == NULL) {
		sub_node->deleteSubjectList();
		node->displayTutors();
		return;
	}

	string sub_code = (*sub_ptr)->getCode();
	sub_node->deleteSubjectList();

	while (node != NULL) {
		if (node->searchBySubject(sub_code)) {
			node->printIdName();
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

	(*head)->displayTutors();
	
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

	(*head)->displayTutors();

}

void SortTutorByHourlyPayRate(struct Tutor** head) {
	if (*head == NULL) return;

	struct Tutor* node = *head;

	//retrieve subjects
	struct Subject* subjectList = NULL;
	RetrieveSubjects(&subjectList);

	if (subjectList == NULL) {
		subjectList->deleteSubjectList();
		node->displayTutors();
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

	(*head)->displayTutors();

}