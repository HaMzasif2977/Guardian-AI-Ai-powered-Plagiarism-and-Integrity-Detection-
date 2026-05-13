#include "Submission.h"
#include <string>
Submission::Submission(string subID,
	string stuID,
	string assignID,
	string timestamp) {
	submissionID = subID;
	studentID = stuID;
	assignmentID = assignID;
	submissionTimestamp = timestamp;
}
void Submission::loadFile(const string& filePath) {
	ifstream file(filePath);
	string line;
	while (getline(file, line)) {
		rawContent += line + "\n";
	}
	file.close();
}
string Submission::getContent() const {
	return rawContent;
}
bool Submission::isValidFormat() const {
	return true;
}
string Submission::getSubmissionID() const {
	return submissionID;
}

