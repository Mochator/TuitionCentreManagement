#include "General.h"

Student::Student() {}

Student::Student(int id, string firstname, string lastname, string username, string password, string contact) {
	this->id = id;
	this->firstname = firstname;
	this->lastname = lastname;
	this->username = username;
	this->password = password;
	this->contact = contact;
	this->next = NULL;
}


void Student::displayStudents() {
	//struct Student* node = *head;

	if (this == NULL) return;

	struct Student* node = this;

	while (node != NULL) {
		node->printInfo();
		node = node->next;
	}
}


void Student::printInfo() {
	cout << this->id << "\t" << this->firstname << " " << this->lastname << " (" << this->username << ")" << endl;

}

struct Student** Student::searchByUsername(string username) {
	struct Student* node = this;
	struct Student* result = NULL;

	if (node == NULL) return &result;

	int count = 0;

	while (node != NULL) {
		if (node->username == username) {
			result = &node[count];
			return &result;
		}

		count++;
	}

	return &result;
}

struct Student** Student::retrieveById(int id) {
	struct Student* node = this;
	struct Student* result = NULL;

	if (node == NULL) return &result;

	int count = 0;

	while (node != NULL) {
		if (node->id == id) {
			result = &node[count];
			return &result;
		}

		count++;
	}
	return &result;
}

bool Student::passwordComparison(string pw) {
	return password == pw;
}

string Student::getFullName() {
	string fullName = this->firstname + " " + this->lastname;
	return fullName;
}

int Student::getId() {
	return this->id;
}

void Student::deleteStudentList() {

	if (this == NULL) return;

	Student* node = this;

	delete[50] node;
}

//External Functions (Not in Struct)
//void AddStudent(struct Student** head, struct Student* newStudent) {
//	struct Student* node = *head;
//
//	if (*head == NULL) {
//		*head = newStudent;
//	}
//	else {
//		while (node->next != NULL) {
//			node = node->next;
//		}
//
//		node->next = newStudent;
//	}
//}
//
void RetrieveStudents(struct Student** head) {
	ifstream inData;
	inData.open("Students.txt");

	struct Student* node = *head;

	int id;
	string strid, firstname, lastname, username, contact, password;
	int count = 0;

	while ((inData >> strid >> firstname >> lastname >> username >> password >> contact) && count < 50) {
		id = stoi(strid);
		struct Student inpStudent = Student(id, firstname, lastname, username, password, contact);

		node[count] = inpStudent;
		count++;

	}

}

//[dyanmic]
void AddStudentToLast(struct Student** head, struct Student* newStudent) {
	struct Student* node = *head;

	if (node == NULL) {
		*head = newStudent;
	}
	else {
		while (node->next != NULL) {
			node = node->next;
		}

		node->next = newStudent;
	}

}

//remove not delete node [dynamic]
void RemoveStudentFromList(struct Student** head, int id) {
	struct Student* toDelete = *head;
	struct Student* prev_node = NULL;
	struct Student* next_node = NULL;

	if (*head == NULL) return;

	while (toDelete != NULL) {
		if (toDelete->getId() != id) {
			prev_node = toDelete;
			toDelete = toDelete->next;
			continue;
		}

		//delete current node
		next_node = toDelete->next;
		if (prev_node != NULL) {
			prev_node->next = next_node;
		}
		else {
			*head = next_node;
		}
		toDelete = next_node;
	}
}



