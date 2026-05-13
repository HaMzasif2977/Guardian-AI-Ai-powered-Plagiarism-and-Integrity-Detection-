#pragma once
#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
using namespace std;
class User {
protected:
	string userID;
	string passwordHash;
	string fullName;
	string email;
	bool isActive;
public:
	User(string id, string pass, string name, string mail, bool active);
	virtual ~User();
	virtual string getRole() const = 0;
	bool authenticate(const string& inputPass) const;
	void updateEmail(const string& newEmail);
	string getUserID() const;
	virtual void displayProfile() const;
};
#endif
