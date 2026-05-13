#include "Instructor.h"
Instructor::Instructor(string id, string pass,
	string name, string mail,
	bool active, string dept,
	int years)
	: User(id, pass, name, mail, active) {
	department = dept;
	yearsOfService = years;
}
string Instructor::getRole() const {
	return "Instructor";
}
void Instructor::createAssignment(const string& title,
	const string& deadline) {
	cout << "Assignment Created: " << title << endl;
}
void Instructor::reviewReport(const string& reportID) {
	cout << "Reviewing report: " << reportID << endl;
}
void Instructor::exportClassData(const string& courseCode) {
	cout << "Exporting data for: " << courseCode << endl;
}
void Instructor::displayProfile() const {
	User::displayProfile();
	cout << "Department: " << department << endl;
}
