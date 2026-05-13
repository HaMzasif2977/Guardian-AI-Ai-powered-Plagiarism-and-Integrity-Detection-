#pragma once
#ifndef FILEMETADATA_H
#define FILEMETADATA_H
#include <iostream>
using namespace std;
class FileMetadata {
private:
	string fileHash;
	long fileSizeBytes;
	string fileType;
	string uploadPath;
public:
	FileMetadata();
	void generateHash(const string& content);
	bool verifyIntegrity(const string& currentContent) const;
	long getSize() const;
	string getType() const;
	void setData(long size, string type,
		string path);
};
#endif

