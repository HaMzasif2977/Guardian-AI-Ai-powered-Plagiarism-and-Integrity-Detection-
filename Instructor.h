#pragma once
#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include "User.h"
#include <vector>
class Instructor : public User {
private:
	string department;
	vector<string> assignedCourses;
	int yearsOfService;
public:
	Instructor(string id, string pass,
		string name, string mail,
		bool active, string dept,
		int years);
	string getRole() const override;
	void createAssignment(const string& title,
		const string& deadline);
	void reviewReport(const string& reportID);
	void exportClassData(const string& courseCode);
	void displayProfile() const override;
};
#endif
