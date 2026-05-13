#include "Assignment.h"
Assignment::Assignment(string id, string t,
	string due, string course,
	int score) {
	assignmentID = id;
	title = t;
	dueDate = due;
	courseCode = course;
	maxScore = score;
}
bool Assignment::isLate(const string& submissionDate) const {
	return submissionDate > dueDate;
}
string Assignment::getAssignmentID() const {
	return assignmentID;
}
void Assignment::updateDeadline(const string& newDate) {
	dueDate = newDate;
}
vector<string> Assignment::getSubmittedStudentIDs() const {
	vector<string> temp;
	return temp;
}