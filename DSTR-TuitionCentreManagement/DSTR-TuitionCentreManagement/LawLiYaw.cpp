#include<iostream>
using namespace std;

struct Tutor 
{
private:
	int id;
	std::string firstname;
	std::string lastname;
	char gender;
	std::string date_Joined;
	std::string date_Terminated;
	std::string subject_Code;
	std::string tuition_Centre_code;
	float rating = 0;

public:
	string phone;
	string address;

	struct Tutor* prev;
	struct Tutor* next;

	//Constructors
	Tutor()
	{
		Tutor::id = id;
		Tutor::firstname = firstname;
		Tutor::lastname = lastname;
		Tutor::gender = gender;
		Tutor::date_Joined = date_Joined;
		Tutor::date_Terminated = date_Terminated;
		Tutor::subject_Code = subject_Code;
		Tutor::tuition_Centre_code = tuition_Centre_code;
		Tutor::rating = rating;
		Tutor::phone = phone;
		Tutor::address = address;
	}

	Tutor(int id, std::string firstname, std::string lastname, char gender, std::string date_Joined, std::string date_Terminated,
		std::string subject_Code, std::string tuition_Centre_code, float rating, std::string phone, std::string address) 
	{
		Tutor::id = id;
		Tutor::firstname = firstname;
		Tutor::lastname = lastname;
		Tutor::gender = gender;
		Tutor::date_Joined = date_Joined;
		Tutor::date_Terminated = date_Terminated;
		Tutor::subject_Code = subject_Code;
		Tutor::tuition_Centre_code = tuition_Centre_code;
		Tutor::rating = rating;
		Tutor::phone = phone;
		Tutor::address = address;
	};
	void addTutor();
};

struct Tutor* next = NULL;

void addTutor(struct Tutor **head, int val)
{
	struct Tutor* newTutor = new Tutor;
	struct Tutor* last = *head;

	newTutor->next = NULL;

	if (*head == NULL) {
		*head = newTutor;
		return;
	}

	while (last->next != NULL) {
		last = last->next;
	}

	last->next = newTutor;
};