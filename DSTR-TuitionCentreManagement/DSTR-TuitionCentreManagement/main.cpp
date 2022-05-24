#include "General.h"

string role = "";
string tuitionCentreCode = "TCBJ";
int student_id = -1;

int main() {

	//Login();
	setRole("Admin");
	DisplayAdminMenu();

}

string getRole() {
	return role;
}

void setRole(string r) {
	role = r;
}

string getTuitionCentreCode() {
	return tuitionCentreCode;
}

void setTuitionCentreCode(string code) {
	tuitionCentreCode = code;
}

int getStudentId() {
	return student_id;
}

void setStudentId(int id) {
	student_id = id;
}

string today() {

	//get current datetime
	time_t t = time(NULL);

	//input into struct
	struct tm today;
	localtime_s(&today, &t);

	int day, month, year;

	year = today.tm_year + 1900;
	month = today.tm_mon + 1;
	day = today.tm_mday;

	//put into format
	stringstream ss_day, ss_month;
	ss_day << setw(2) << setfill('0') << day;
	string result = ss_day.str();

	result += "/";
	
	ss_month << setw(2) << setfill('0') << month;
	result = result + ss_month.str();
	result += "/" + to_string(year);

	return result;
}

