#include "Student.h"
Student::Student(string id, string pass, string name,
	string mail, bool active,
	string maj, int year,
	double gpa, int submissions)
	: User(id, pass, name, mail, active) {
	major = maj;
	enrollmentYear = year;
	currentGPA = gpa;
	totalSubmissions = submissions;
}
string Student::getRole() const {
	return "Student";
}
void Student::submitWork(const string& assignmentID,
	const string& filePath) {
	cout << "Submitting work for assignment: "
		<< assignmentID << endl;
}
void Student::viewReport(const string& reportID) {
	cout << "Viewing report: " << reportID << endl;
}
double Student::calculateStanding() const {
	return currentGPA;
}
void Student::displayProfile() const {
	User::displayProfile();
	cout << "Major: " << major << endl;
	cout << "GPA: " << currentGPA << endl;
}