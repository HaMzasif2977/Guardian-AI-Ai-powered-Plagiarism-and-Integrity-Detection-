#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include "User.h"
class Student : public User {
private:
	string major;
	int enrollmentYear;
	double currentGPA;
	int totalSubmissions;
public:
	Student(string id, string pass, string name, string mail,
		bool active, string maj, int year,
		double gpa, int submissions);
	string getRole() const override;
	void submitWork(const string& assignmentID,
		const string& filePath);
	void viewReport(const string& reportID);
	double calculateStanding() const;
	void displayProfile() const override;
};
#endif
