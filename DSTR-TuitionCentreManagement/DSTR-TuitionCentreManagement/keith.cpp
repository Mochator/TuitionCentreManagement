#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void predefineTuitionCentre();

struct TuitionCentre {

private:

	string code;
	string name;
	string address;
	string password;

public:
	struct TuitionCentre* next;
	TuitionCentre(string code, string name, string address, string password);
	void addTuitionCentre(struct TuitionCentre** head, struct TuitionCentre* newTuitionCentre);
	void predefineTuitionCentre();
	void printFile();


};

TuitionCentre::TuitionCentre(string code, string name, string address, string password) {

	this->code = code;
	this->name = name;
	this->address = address;
	this->password = password;
	this->next = NULL;
}


int main() {
	predefineTuitionCentre();
}




void predefineTuitionCentre() {
	struct TuitionCentre* newTuitionCentre = NULL;

	newTuitionCentre->addTuitionCentre(&newTuitionCentre, new TuitionCentre("TCBJ", "eXcel Bukit Jalil", "Bukit Jalil", "tcbj123"));
	newTuitionCentre->addTuitionCentre(&newTuitionCentre, new TuitionCentre("TCPUC", "eXcel Puchong", "Puchong", "tcpuc123"));
	newTuitionCentre->addTuitionCentre(&newTuitionCentre, new TuitionCentre("TCSUB", "eXcel Subang", "Subang", "tcsub123"));

	newTuitionCentre->printFile();

}

void TuitionCentre::addTuitionCentre(struct TuitionCentre** head, struct TuitionCentre* newTuitionCentre) {
	struct TuitionCentre* node = *head;

	if (*head == NULL) {
		*head = newTuitionCentre;
	}
	else {
		while (node->next != NULL) {
			node = node->next;
		}

		node->next = newTuitionCentre;
	}

}

void TuitionCentre::printFile() {

	struct TuitionCentre* node = this;

	if (node == NULL) {
		return;
	}

	ofstream outData;
	outData.open("TuitionCentre.txt");

	while (node != NULL) {
		outData << node->code << "\t" << node->name << "\t" << node->address << "\t" << node->password << endl;
		node = node->next;
	}

}