#include "General.h"

TuitionCentre::TuitionCentre(string code, string name, string address, string password) {

	this->code = code;
	this->name = name;
	this->address = address;
	this->password = password;
	this->next = NULL;
}


//void predefineTuitionCentre() {
//	struct TuitionCentre* newTuitionCentre = NULL;
//
//	newTuitionCentre->addTuitionCentre(&newTuitionCentre, new TuitionCentre("TCBJ", "eXcel Bukit Jalil", "Bukit Jalil", "tcbj123"));
//	newTuitionCentre->addTuitionCentre(&newTuitionCentre, new TuitionCentre("TCPUC", "eXcel Puchong", "Puchong", "tcpuc123"));
//	newTuitionCentre->addTuitionCentre(&newTuitionCentre, new TuitionCentre("TCSUB", "eXcel Subang", "Subang", "tcsub123"));
//
//	newTuitionCentre->printFile();
//
//}

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

void TuitionCentre::printInfo(int index) {
	cout << index << ". \t" << this->code << "\t" << this->name << endl;

}

string TuitionCentre::getCodeName() {
	string codename =  this->name + " (" + this->code + ")";
	return codename;
}

string TuitionCentre::getCode() {
	return this->code;
}


struct TuitionCentre** TuitionCentre::searchByIndex(int index) {
	struct TuitionCentre* node = this;
	struct TuitionCentre** result = NULL;

	if (this == NULL) return result;

	while (index > 1) {
		node = node->next;
		index--;
	}

	result = &node;

	return result;
}

bool TuitionCentre::passwordComparison(string pw) {
	return this->password == pw;
}

//Free up memory
void DeleteTuitionCentreList(struct TuitionCentre** head)
{
	if (*head == NULL) {
		return;
	}

	TuitionCentre* current = *head;
	TuitionCentre* next = NULL;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*head == NULL;
}

//External Functions (Not in Struct)
void RetrieveTuitionCentres(struct TuitionCentre **head) {
	ifstream inData;
	inData.open("TuitionCentre.txt");

	struct TuitionCentre* node = *head;

	int id;
	string code, name, address, password;

	while (inData >> code >> name >> address >> password) {

		cout << (password) << endl;

		struct TuitionCentre* inpTuitionCentre = new TuitionCentre(code, name, address, password);

		if (*head == NULL) {
			*head = inpTuitionCentre;
			node = *head;
		}
		else {
			node->next = inpTuitionCentre;
			node = node->next;

		}

	}

}

void DisplayTuitionCentres(struct TuitionCentre** head, int indexStart) {

	struct TuitionCentre* node = *head;

	if (*head == NULL) return;

	while (node != NULL) {
		node->printInfo(indexStart);
		node = node->next;
		indexStart++;
	}
}