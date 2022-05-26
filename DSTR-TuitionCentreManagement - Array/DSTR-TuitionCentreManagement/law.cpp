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
	this->prev = NULL;
}

Tutor::Tutor() {}

//getter and setter
int Tutor::getId() {
	return this->id;
}

string Tutor::getSubject() {
	return this->subject_Code;
}

string Tutor::getTuitionCentre() {
	return this->tuition_Centre_code;
}

string Tutor::getFullName() {
	return this->firstname + " " + this->lastname;
}

float Tutor::getRating() {
	return this->rating;
}

string Tutor::getTerminationDate() {
	return this->date_Terminated;
}

void Tutor::printTutorFull() {
	cout << this->id << "\t" << this->firstname << " " << this->lastname << "\t\t" << this->subject_Code << "\t" << this->tuition_Centre_code << "\t\t" << this->rating << endl;
}

void Tutor::printTutorBrief() {
	cout << this->id << "\t" << this->firstname << " " << this->lastname << endl;
}

//functions
void addTutor() {

	string firstname, lastname, phone, address, date_Joined, date_Terminated;
	char gender;
	Subject* subject;
	TuitionCentre *centre;
	float rating;
	cout << "Input First Name: ";
	cin >> firstname;
	cout << "Input Last Name: ";
	cin >> lastname;
	cout << "Input Phone: ";
	cin >> phone;
	cout << "Input Address: ";
	cin >> address;
	cout << "Input Date Joined: ";
	cin >> date_Joined;
	cout << "Input Date Terminated: ";
	cin >> date_Terminated;
	cout << "Tutor Rating: ";
	cin >> rating;

	RetrieveSubjects();
	int choice = userChoice(1, 5, "Choose Subject: ");
	subject = &(subjectArray[choice - 1]);

	RetrieveTuitionCentres();
	choice = userChoice(1, 5,"Choose Centres: ");
	centre = &(tuitionCentreArray[choice - 1]);

	// Constructor to create new instance
	Tutor newTutor = Tutor(generateId(), string firstname, string lastname, char gender, string phone, string address, string date_Joined, string date_Terminated, string subject_Code, string tuition_Centre_code, float rating);
	//newTutor.setTutorDateJoined(getCurrentDate());
	//newTutor.setTutorDateTerminated(toTm(0, 0, 0));

	// Increaase tutor Array size by 1
	int count = sizeof(tutorArray);
	
	if(count >= 10)
	{
		cout << "Maximum number of tutors has reached!" << endl;
	} else {
		increaseArrSize(1);
	}

	// Set the last element (new element) as newTutor
	tutorArray[arrSize - 1] = newTutor;
	cout << "Tutor Succesfully Added!" << endl;

	//Print tutorArray into txt file
	ofstream myfile ("Tutors.txt");
	getTutorArray();
	if (myfile.is_open())
	{
		for(int count = 0; count < 10; count ++){
			myfile << tutorArray[count] << " " ;
		}
		myfile.close();
	}
	else cout << "Unable to open file";
	return 0;
}

void RetrieveSubjects() {
	subjectTableHead();
	for (int i = 0; i < 5; i++) {
		cout << setw(3)<<left<< i+1 << "|";
		subjectArray[i].toString();
		cout << board(10);
	}
}

void RetrieveTuitionCentres() {
	centreTableHead();
	for (int i = 0; i < 5; i++) {
		cout << setw(3) << left << i + 1 << "|";
		tuitionCentreArray[i].toString();
		cout << board(10);
	}
}

int generateId() {
	// Sort Array by Id then return last index id using random access
	Tutor* t = sortById(true);
	return (t[arrSize - 1].getTutorId())+1;
}

int getTutorId() {
	return id;
}

Tutor* getTutorArray() {
	return tutorArray;
}

TuitionCentre* getTuitionCentreArray() {
	return tuitionCentreArray;
}

Subject* getSubjectArray() {
	return subjectArray;
}

int getArrSize() {
	return arrSize;
}