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

bool Rating::printFile() {

	struct Rating* node = this;

	if (node == NULL) {
		return false;
	}

	ofstream outData;
	outData.open("Ratings.txt");

	while (node != NULL) {
		outData << node->tuition_id << "\t" << node->tutor_id << "\t" << node->student_id << "\t" << node->rating << endl;
		node = node->next;
	}

	return true;
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

void AddRatingToLast(struct Rating** head, struct Rating* newRating) {
	struct Rating* node = *head;

	if (node == NULL) {
		*head = newRating;
	}
	else {
		while (node->next != NULL) {
			node = node->next;
		}

		node->next = newRating;
	}

}