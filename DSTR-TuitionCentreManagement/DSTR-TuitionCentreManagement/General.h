#ifndef GENERAL_H
#define GENERAL_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


//---begin::All main method headers---
void Login();
string getRole();
void setRole(string);
string getTuitionCentreCode();
void setTuitionCentreCode(string);


//Tutor

//Students
//void DisplayStudentsOption(struct Student**);
void RetrieveStudents(struct Student**);
void DeleteStudentList(struct Student**);

//Menu
void DisplayHRMenu();
void DisplayStudentMenu();
void DisplayAdminMenu();
void TutorManagementMenu();


//Subjects
void displaySubjects();

//Tuition Centre
void RetrieveTuitionCentres(struct TuitionCentre**);
void DisplayTuitionCentres(struct TuitionCentre**, int);
void DeleteTuitionCentreList(struct TuitionCentre**);



//---end::All main method headers---

struct Tutor {

private:
	int id;
	string firstname;
	string lastname;
	char gender;
	string date_Joined;
	string date_Terminated;
	string subject_Code;
	string tuition_Centre_code;
	float rating;

public:
	string phone;
	string address;
	struct Tutor* next;
	struct Tutor* prev;

	//Tutor Constructor: id, firstname, lastname, gender, phone, address, date_Joined, date_Terminated, subject_Code, tuition_Centre_Code, rating
	struct Tutor(int id, string, string, char, string, string, string, string, string, string, float);

	//Functions
	void addTutor(struct Tutor**, struct Tutor*);
	void editTutor(struct Tutor**, string, string);
	void terminateTutor(struct Tutor**);
	void deleteTutor(struct Tutor**);
	//void predefineTutor();
	void printFile();

};

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

	//Student Constructor: id, firstname, lastname, username, password, contact
	struct Student(int, string, string, string, string, string);

	//Functions
	//void addStudent(struct Student**, struct Student*);
	void printFile();
	//void predefineStudent();
	void printInfo();
	void displayStudents();
	struct Student** searchByUsername(string);

	bool passwordComparison(string);
	string getFullName();
};

struct Subject {

private:
	string code;
	string name;
	float hourly_pay_rate;

public:
	struct Subject* next;

	//Subject Constructor: code, name, hourly_pay_rate
	struct Subject(string, string, float);

	//Functions
	void addSubject(struct Subject** head, struct Subject* newSubject);
	void printFile();


};

struct TuitionCentre {

private:
	string code;
	string name;
	string address;
	string password;

public:
	struct TuitionCentre* next;

	//Tuition Constructor: code, name, address, password
	struct TuitionCentre(string, string, string, string);

	~TuitionCentre() {};

	//Functions
	void addTuitionCentre(struct TuitionCentre** head, struct TuitionCentre* newTuitionCentre);
	//void predefineTuitionCentre();
	void printInfo(int);
	void printFile();
	struct TuitionCentre** searchByIndex(int);
	bool passwordComparison(string);
	string getCodeName();
	string getCode();

};

struct Tuition {
private:
	int id;
	int tutor_Id;
	int hour;
	string date;

public:
	struct Tuition* next;

	// Tuition Constructor : id, tutor_Id, hour, date
	struct Tuition(int, int, int, string);

	//Functions


};

struct Rating {
private:
	int tuition_Id;
	int tutor_Id;
	int student_Id;
	int rating;

public:
	struct Rating* next;

	// Rating Constructor : id, tutor_Id, hour, date
	struct Rating(int, int, int, int);

	//Functions
};


#endif