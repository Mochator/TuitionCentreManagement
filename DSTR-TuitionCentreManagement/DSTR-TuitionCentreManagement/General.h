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
void RetrieveTutors(struct Tutor**);
void DisplayAllTutors();
void SearchTutorById(struct Tutor**);
void SearchTutorByRating(struct Tutor**);
void SearchTutorByTuitionCentre(struct Tutor**);
void SearchTutorBySubject(struct Tutor**);


//Students
//void DisplayStudentsOption(struct Student**);
void RetrieveStudents(struct Student**);
//void DeleteStudentList(struct Student**);

//Menu
void DisplayHRMenu();
void DisplayStudentMenu();
void DisplayAdminMenu();
void TutorManagementMenu();
void TutorListMenu(struct Tutor**);
void SearchMenu(struct Tutor**);
void SortMenu(struct Tutor**);


//Subjects
void RetrieveSubjects(struct Subject**);
//void DisplaySubjects(struct Subject**, int, bool);
//void DeleteSubjectList(struct Subject**);
void DisplayAllSubjects();


//Tuition Centre
void RetrieveTuitionCentres(struct TuitionCentre**);
//void DisplayTuitionCentres(struct TuitionCentre**, int, bool);
//void DeleteTuitionCentreList(struct TuitionCentre**);
void DisplayAllTuitionCentres();

//Rating
float CalculateRatings(struct Rating** , int);
void RetrieveRatings(struct Rating**);


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
	void printIdName();

	void displayTutors();
	void deleteTutorList();

	int getId();
	bool searchById(int);
	bool searchByRating(int, int);
	bool searchByTuitionCentre(string);
	bool searchBySubject(string);

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
	void printInfo();

	void displayStudents();
	void deleteStudentList();

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

	void displaySubjects(int, bool);
	void deleteSubjectList();

	void printFile();
	void printCodeName(int);
	void printCodeNamePay(int);

	struct Subject** searchByIndex(int);
	string getCode();

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

	void displayTuitionCentres(int, bool);
	void deleteTuitionCentreList();

	void printCodeName(int);
	void printCodeNameAddress(int);
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
	int tuition_id;
	int tutor_id;
	int student_id;
	int rating;

public:
	struct Rating* next;

	// Rating Constructor : id, tutor_Id, hour, date
	struct Rating(int, int, int, int);

	//Functions
	int getTutorId();
	int getRating();

};


#endif