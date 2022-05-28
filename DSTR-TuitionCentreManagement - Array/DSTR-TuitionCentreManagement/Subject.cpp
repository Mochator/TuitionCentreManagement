#include "General.h"


Subject::Subject(string code, string name, float hourly_pay_rate) {
	this->code = code;
	this->name = name;
	this->hourly_pay_rate = hourly_pay_rate;
	this->next = NULL;
}

//void predefineSubject() {
//	struct Subject* newSubject = NULL;
//
//	newSubject->addSubject(&newSubject, new Subject("S001", "Science", 50));
//	newSubject->addSubject(&newSubject, new Subject("S002", "Maths", 50));
//	newSubject->addSubject(&newSubject, new Subject("S003", "Malay", 50));
//	newSubject->addSubject(&newSubject, new Subject("S004", "English", 30));
//	newSubject->addSubject(&newSubject, new Subject("S005", "Chinese", 30));
//
//	newSubject->printFile();
//
//}

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

//To predefine subject only not included in any functions
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

void Subject::printCodeName(int index) {
	cout << index << ". \t" << this->code << "\t" << this->name << endl;
}

void Subject::printCodeNamePay(int index) {
	cout << index << ". \t" << this->code << "\t" << this->name << "\t" << this->hourly_pay_rate << endl;
}


void Subject::displaySubjects(int indexStart, bool withPayRate) {
	system("CLS");

	struct Subject* node = this;

	if (this == NULL) return;

	while (node != NULL) {
		if (withPayRate) {
			node->printCodeNamePay(indexStart);
		}
		else {
			node->printCodeName(indexStart);
		}
		node = node->next;
		indexStart++;
	}
}

string Subject::getInfo() {
	return (this->name + "(" + this->code + ")");
}

struct Subject** Subject::searchByIndex(int index) {
	struct Subject* node = this;
	struct Subject** result = NULL;

	if (this == NULL) return result;

	while (index > 1) {
		node = node->next;
		index--;
	}

	result = &node;

	return result;
}

struct Subject** Subject::searchByCode(string code) {
	struct Subject* node = this;
	struct Subject** result = NULL;

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

//Free up memory
void Subject::deleteSubjectList()
{
	if (this == NULL) return;

	Subject* current = this;
	Subject* next = NULL;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

//External functions
void DisplayAllSubjects() {
	system("CLS");

	struct Subject* subjectList = NULL;
	RetrieveSubjects(&subjectList);

	if (subjectList == NULL) return;

	cout << "All Subjects:" << endl;
	subjectList->displaySubjects(1, true);

	cout << endl;

	//free up memory
	subjectList->deleteSubjectList();

}

void RetrieveSubjects(struct Subject** head) {
	ifstream inData;
	inData.open("Subject.txt");

	struct Subject* node = *head;

	string code, name, str_hourly_pay_rate;

	while (inData >> code >> name >> str_hourly_pay_rate) {

		float hourly_pay_rate = stof(str_hourly_pay_rate);

		struct Subject* inpSubject = new Subject(code, name, hourly_pay_rate);

		if (*head == NULL) {
			*head = inpSubject;
			node = *head;
		}
		else {
			node->next = inpSubject;
			node = node->next;

		}

	}

}
//
////Free up memory
//void DeleteSubjectList(struct Subject** head)
//{
//	if (*head == NULL) {
//		return;
//	}
//
//	Subject* current = *head;
//	Subject* next = NULL;
//
//	while (current != NULL)
//	{
//		next = current->next;
//		free(current);
//		current = next;
//	}
//}