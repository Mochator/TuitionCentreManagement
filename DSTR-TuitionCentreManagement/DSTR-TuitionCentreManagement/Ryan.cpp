#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void predefineSubject();

struct Subject {

private:
	string code;
	string name;
	float hourly_pay_rate;

public:
	struct Subject* next;
	Subject(string code, string name, float hourly_pay_rate);
	void addSubject(struct Subject** head, struct Subject* newSubject);
	void printFile();


};

Subject::Subject(string code, string name, float hourly_pay_rate) {
	this->code = code;
	this->name = name;
	this->hourly_pay_rate = hourly_pay_rate;
	this->next = NULL;
}

int main() {
	predefineSubject();
}

void predefineSubject() {
	struct Subject* newSubject = NULL;

	newSubject->addSubject(&newSubject, new Subject("S001", "Science", 50));
	newSubject->addSubject(&newSubject, new Subject("S002", "Maths", 50));
	newSubject->addSubject(&newSubject, new Subject("S003", "Malay", 50));
	newSubject->addSubject(&newSubject, new Subject("S004", "English", 30));
	newSubject->addSubject(&newSubject, new Subject("S005", "Chinese", 30));

	newSubject->printFile();

}

void Subject::addSubject(struct Subject** head, struct Subject* newSubject) {
	struct Subject* node = *head;

	if (*head == NULL) {
		*head = newSubject;
	}
	else {
		while (node->next != NULL) {
			node = node->next;
		}

		node->next = newSubject;
	}

}

void Subject::printFile() {

	struct Subject* node = this;

	if (node == NULL) {
		return;
	}

	ofstream outData;
	outData.open("Subject.txt");

	while (node != NULL) {
		outData << node->code << "\t" << node->name << "\t" << node->hourly_pay_rate << "\t" << endl;
		node = node->next;
	}

}