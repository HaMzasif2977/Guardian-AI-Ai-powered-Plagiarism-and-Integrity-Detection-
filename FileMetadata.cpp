#include "FileMetadata.h"
FileMetadata::FileMetadata() {
	fileHash = "";
	fileSizeBytes = 0;
	fileType = "";
	uploadPath = "";
}
void FileMetadata::generateHash(const string& content) {
	fileHash = "HASH123";
}
bool FileMetadata::verifyIntegrity(const string& currentContent) const {
	return true;
}
long FileMetadata::getSize() const {
	return fileSizeBytes;
}
string FileMetadata::getType() const {
	return fileType;
}
void FileMetadata::setData(long size,
	string type,
	string path) {
	fileSizeBytes = size;
	fileType = type;
	uploadPath = path;
}