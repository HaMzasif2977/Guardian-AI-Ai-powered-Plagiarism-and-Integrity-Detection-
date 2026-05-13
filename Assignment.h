#pragma once
#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include <iostream>
#include <vector>
using namespace std;
class Assignment {
private:
	string assignmentID;
	string title;
	string dueDate;
	string courseCode;
	int maxScore;
public:
	Assignment(string id, string t,
		string due, string course,
		int score);
	bool isLate(const string& submissionDate) const;
	string getAssignmentID() const;
	void updateDeadline(const string& newDate);
	vector<string> getSubmittedStudentIDs() const;
};
#endif

