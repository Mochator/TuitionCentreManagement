#include "General.h"


Rating::Rating(int tuition_Id, int tutor_Id, int student_Id, int rating) {
	this->tuition_id = tuition_Id;
	this->tutor_id = tutor_Id;
	this->student_id = student_Id;
	this->rating = rating;
	this->next = NULL;
}

int Rating::getTutorId() {
	return this->tutor_id;
}

int Rating::getRating() {
	return this->rating;
}

//External function
float CalculateRatings(struct Rating** head, int tutor_Id) {

	float result = 0;

	if (*head == NULL) return result;

	struct Rating* node = *head;

	int total = 0, count = 0;

	while (node != NULL) {
		if (node->getTutorId() == tutor_Id) {
			total = total + node->getRating();
			count++;
		}
	}

	result = total / count;

	return result;
}

void RetrieveRatings(struct Rating** head) {
	ifstream inData;
	inData.open("Ratings.txt");

	struct Rating* node = *head;

	int tuition_id, tutor_id, student_id, rating;
	string str_tuition_id, str_tutor_id, str_student_id, str_rating;

	while (inData >> str_tuition_id >> str_tutor_id >> str_student_id >> str_rating) {

		tuition_id = stoi(str_tuition_id);
		tutor_id = stoi(str_tutor_id);
		student_id = stoi(str_student_id);
		rating = stoi(str_rating);

		struct Rating* input = new Rating(tuition_id, tutor_id, student_id, rating);

		if (*head == NULL) {
			*head = input;
			node = *head;
		}
		else {
			node->next = input;
			node = node->next;

		}

	}

}