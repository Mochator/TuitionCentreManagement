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

//Tutor


//Menu
void TutorManagementMenu();


//Subjects
void displaySubjects();

//Tuition Centre
void displayTuitionCentre();

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
	Tutor(int id, string firstname, string lastname, char gender, string phone, string address, string date_Joined, string date_Terminated, string subject_Code, string tuition_Centre_code, float rating);
	void addTutor(struct Tutor** head, struct Tutor* newTutor);
	void editTutor(struct Tutor** head, string field, string data);
	void terminateTutor(struct Tutor** head);
	void deleteTutor(struct Tutor** head);
	void predefineTutor();
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
	Student(int id, string firstname, string lastname, string username, string password, string contact);
	void addStudent(struct Student** head, struct Student* newStudent);
	void printFile();
	void printInfo();
};

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

struct Tuition {
	int id;
	int tutor_Id;
	int hour;
	string date;

	struct Tuition* next;

};

struct Rating {
	int tuition_Id;
	int tutor_Id;
	int student_Id;
	int rating;

	struct Rating* next;
};


#endif