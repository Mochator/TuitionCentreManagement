#include "General.h"

string role = "";
string tuitionCentreCode = "";

int main() {
	Login();

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