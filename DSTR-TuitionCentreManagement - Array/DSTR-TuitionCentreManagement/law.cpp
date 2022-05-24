#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void predefineTutor();

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

std::string genPhoneNo() {
	string result = "01";

	for (int i = 0; i < 8; i++) {
		result += to_string(rand() % 10);
	}
	return result;
}

void predefineTutor() {
	int i = 1;
	struct Tutor* newTutor = NULL;

	newTutor->addTutor(&newTutor, new Tutor(i++, "Charlie", "Puth", 'M', genPhoneNo(), "USA", "15/4/20", "15/4/25", "1", "1", 0.0f));
	newTutor->addTutor(&newTutor, new Tutor(i++, "Helena", "Patel", 'F', genPhoneNo(), "Singapore", "20/8/20", "20/8/26", "1", "2", 4.8f));
	newTutor->addTutor(&newTutor, new Tutor(i++, "Aniela", "Gibbs", 'F', genPhoneNo(), "Grenada", "13/10/20", "0/0/0", "2", "3", 4.9f));
	newTutor->addTutor(&newTutor, new Tutor(i++, "Caelan", "Adamson", 'M', genPhoneNo(), "Malawi", "1/3/19", "15/4/25", "2", "1", 5.0f));
	newTutor->addTutor(&newTutor, new Tutor(i++, "Kristian", "Reyna", 'F', genPhoneNo(), "Bermuda", "29/11/21", "0/0/0", "3", "2", 4.7f));
	newTutor->addTutor(&newTutor, new Tutor(i++, "Kaden", "Mccann", 'M', genPhoneNo(), "El Salvador", "5/5/20", "5/5/26", "4", "3", 4.9f));
	newTutor->addTutor(&newTutor, new Tutor(i++, "Ariel", "Choi", 'F', genPhoneNo(), "Syria", "11/4/21", "0/0/0", "5", "1", 4.8f));
	newTutor->addTutor(&newTutor, new Tutor(i++, "Chad", "Hogg", 'M', genPhoneNo(), "Liberia", "3/10/22", "0/0/0", "5", "2", 3.5f));
	newTutor->addTutor(&newTutor, new Tutor(i++, "Orion", "Flynn", 'M', genPhoneNo(), "Azerbajian", "14/12/20", "14/12/25", "6", "3", 3.7f));
	newTutor->addTutor(&newTutor, new Tutor(i++, "Pamela", "Rubio", 'F', genPhoneNo(), "Eritrea", "23/12/21", "0/0/0", "7", "1", 3.8f));
	newTutor->addTutor(&newTutor, new Tutor(i++, "Shahid", "Donald", 'M', genPhoneNo(), "Swenden", "30/11/22", "30/11/24", "7", "2", 3.9f));
	newTutor->addTutor(&newTutor, new Tutor(i++, "Dawn", "Findlay", 'F', genPhoneNo(), "Indonesia", "24/8/21", "0/0/0", "8", "3", 4.5f));
	newTutor->addTutor(&newTutor, new Tutor(i++, "Jimmie", "Wynn", 'M', genPhoneNo(), "Scotland", "12/7/20", "12/7/23", "9", "1", 5.0f));
	newTutor->addTutor(&newTutor, new Tutor(i++, "Neha", "Magana", 'F', genPhoneNo(), "Portugal", "8/11/21", "8/11/25", "10", "2", 4.3f));
	newTutor->addTutor(&newTutor, new Tutor(i++, "Oskar", "Carney", 'M', genPhoneNo(), "South Korea", "18/5/22", "0/0/0", "10", "3", 4.2f));

	newTutor->printFile();

}

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