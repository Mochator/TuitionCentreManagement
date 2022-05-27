#include "General.h"

TuitionCentre::TuitionCentre() {};

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

void TuitionCentre::printCodeName(int index) {
	cout << index << ". \t" << this->code << "\t" << this->name << endl;

}

void TuitionCentre::printCodeNameAddress(int index) {
	cout << index << ". \t" << this->code << "\t" << this->name << "\t" << this->address << endl;

}

string TuitionCentre::getCodeName() {
	string codename = this->name + " (" + this->code + ")";
	return codename;
}

string TuitionCentre::getCode() {
	return this->code;
}

string TuitionCentre::getInfo() {
	return this->name + "(" + this->code + ") - " + this->address ;
}


int TuitionCentre::searchByIndex(int index) {
	struct TuitionCentre* node = this;
	int result = -1;

	if (this == NULL) return result;
	int count = 0;

	while (index > 1) {
		count++;
		index--;
	}

	result = count;

	return result;
}

struct TuitionCentre** TuitionCentre::searchByCode(string code) {
	struct TuitionCentre* node = this;
	struct TuitionCentre** result = NULL;

	if (node == NULL) return result;

	while (node != NULL) {
		if (node->code == code) {
			result = &node;
			return result;
		}
		else {
			node = node->next;
		}
	}

	return result;
}

bool TuitionCentre::passwordComparison(string pw) {
	return this->password == pw;
}

void TuitionCentre::displayTuitionCentres(int indexStart, bool withAddress, int size) {
	system("CLS");

	struct TuitionCentre* node = this;

	if (node == NULL) return;


	while (indexStart - 1 < size) {
		if (withAddress) {
			node[indexStart - 1].printCodeNameAddress(indexStart);
		}
		else {
			node[indexStart - 1].printCodeName(indexStart);
		}
		indexStart++;
	}
}

//Free up memory
void TuitionCentre::deleteTuitionCentreList()
{
	if (this == NULL) return;

	TuitionCentre* node = this;

	delete[3] node;

}

//External Functions (Not in Struct)
void DisplayAllTuitionCentres() {
	system("CLS");

	struct TuitionCentre* tuitionCentreList = NULL;
	RetrieveTuitionCentres(&tuitionCentreList);

	if (tuitionCentreList == NULL) return;

	cout << "All Tuition Centre:" << endl;
	int size = 3;
	tuitionCentreList->displayTuitionCentres(1, true, size);
	cout << endl;

	//free up memory
	tuitionCentreList->deleteTuitionCentreList();

}

void RetrieveTuitionCentres(struct TuitionCentre** head) {
	ifstream inData;
	inData.open("TuitionCentre.txt");

	struct TuitionCentre* node = *head;

	string code, name, address, password;

	int count = 0;

	while ((inData >> code >> name >> address >> password) && count < 3) {

		struct TuitionCentre inpTuitionCentre = TuitionCentre(code, name, address, password);

		node[count] = inpTuitionCentre;

		count++;
	}
}
