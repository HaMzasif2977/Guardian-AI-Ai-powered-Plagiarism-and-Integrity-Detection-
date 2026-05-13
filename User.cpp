#include "User.h"
User::User(string id, string pass, string name, string mail, bool active) {
	userID = id;
	passwordHash = pass;
	fullName = name;
	email = mail;
	isActive = active;
}
User::~User() {}
bool User::authenticate(const string& inputPass) const {
	return inputPass == passwordHash;
}
void User::updateEmail(const string& newEmail) {
	email = newEmail;
}
string User::getUserID() const {
	return userID;
}
void User::displayProfile() const {
	cout << "ID: " << userID << endl;
	cout << "Name: " << fullName << endl;
	cout << "Email: " << email << endl;
}
