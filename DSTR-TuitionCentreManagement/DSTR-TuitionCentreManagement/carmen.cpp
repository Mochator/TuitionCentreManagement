#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void predefineStudent();

struct Student {

private:
	int id;
	string firstname;
	string lastname;
	string username;
	string password;
	string contact;

public:
	struct Student* next;
	Student(int id, string firstname, string lastname, string username, string password, string contact);
	void addStudent(struct Student** head, struct Student* newStudent);
	void predefineStudent();
	void printFile();


};

Student::Student(int id, string firstname, string lastname, string username, string password, string contact) {
	this->id = id;
	this->firstname = firstname;
	this->lastname = lastname;
	this->username = username;
	this->password = password;
	this->contact = contact;
	this->next = NULL;
}

/*
int main() {
	predefineStudent();
}
*/

std::string genPhone() {
	string result = "01";

	for (int i = 0; i < 8; i++) {
		result += to_string(rand() % 10);
	}
	return result;
}

void predefineStudent() {
	int i = 1;
	struct Student* newStudent = NULL;

	newStudent->addStudent(&newStudent, new Student(i++, "Carmen", "Lim", "carmenlim", "apu12345", genPhone()));
	newStudent->addStudent(&newStudent, new Student(i++, "Keith", "Koh", "keithkoh", "apu12345", genPhone()));
	newStudent->addStudent(&newStudent, new Student(i++, "Ryan", "Lim", "ryanlim", "apu12345", genPhone()));
	newStudent->addStudent(&newStudent, new Student(i++, "Law", "LiYaw", "lawliyaw", "apu12345", genPhone()));
	newStudent->addStudent(&newStudent, new Student(i++, "David", "Tee", "davidtee", "apu12345", genPhone()));
	newStudent->addStudent(&newStudent, new Student(i++, "Ben", "Tan", "bentan", "apu12345", genPhone()));
	newStudent->addStudent(&newStudent, new Student(i++, "Jessi", "J", "jessij", "apu12345", genPhone()));
	newStudent->addStudent(&newStudent, new Student(i++, "Amanda", "Ooi", "amandaooi", "apu12345", genPhone()));
	newStudent->addStudent(&newStudent, new Student(i++, "Irene", "Tang", "irenetang", "apu12345", genPhone()));
	newStudent->addStudent(&newStudent, new Student(i++, "Grace", "Ong", "graceong", "apu12345", genPhone()));
	newStudent->addStudent(&newStudent, new Student(i++, "Boh", "Leong", "bohleong", "apu12345", genPhone()));
	newStudent->addStudent(&newStudent, new Student(i++, "Shawn", "Lee", "shawnlee", "apu12345", genPhone()));
	newStudent->addStudent(&newStudent, new Student(i++, "Bryan", "Lo", "bryanlo", "apu12345", genPhone()));
	newStudent->addStudent(&newStudent, new Student(i++, "Loh", "WeiWei", "lohweiwei", "apu12345", genPhone()));
	newStudent->addStudent(&newStudent, new Student(i++, "Ong", "Ann", "ongann", "apu12345", genPhone()));
	newStudent->addStudent(&newStudent, new Student(i++, "Teoh", "WeiQing", "teohweiqing", "apu12345", genPhone()));
	newStudent->addStudent(&newStudent, new Student(i++, "Park", "CheeYee", "parkcheeyee", "apu12345", genPhone()));
	newStudent->addStudent(&newStudent, new Student(i++, "Soon", "Nam", "soonnam", "apu12345", genPhone()));
	newStudent->addStudent(&newStudent, new Student(i++, "Prince", "Lee", "princelee", "apu12345", genPhone()));
	newStudent->addStudent(&newStudent, new Student(i++, "Kingsten", "Liew", "kingstenliew", "apu12345", genPhone()));

	newStudent->printFile();

}

void Student::addStudent(struct Student** head, struct Student* newStudent) {
	struct Student* node = *head;

	if (*head == NULL) {
		*head = newStudent;
	}
	else {
		while (node->next != NULL) {
			node = node->next;
		}

		node->next = newStudent;
	}

}

void Student::printFile() {

	struct Student* node = this;

	if (node == NULL) {
		return;
	}

	ofstream outData;
	outData.open("Students.txt");

	while (node != NULL) {
		outData << node->id << "\t" << node->firstname << "\t" << node->lastname << "\t" << node->username << "\t" << node->password << "\t" << node->contact << endl;
		node = node->next;
	}

}