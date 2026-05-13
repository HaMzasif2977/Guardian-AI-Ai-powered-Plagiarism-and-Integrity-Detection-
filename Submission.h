#pragma once
#ifndef SUBMISSION_H
#define SUBMISSION_H
#include "FileMetadata.h"
#include <fstream>
class Submission {
private:
	string submissionID;
	string studentID;
	string assignmentID;
	string submissionTimestamp;
	FileMetadata metadata;
	string rawContent;
public:
	Submission(string subID,
		string stuID,
		string assignID,
		string timestamp);
	void loadFile(const string& filePath);
	string getContent() const;
	bool isValidFormat() const;
	string getSubmissionID() const;
};
#endif
