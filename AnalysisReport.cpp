#include "AnalysisReport.h"
AnalysisReport::AnalysisReport() {
	overallRiskScore = 0;
	verdict = "Clean";
}
void AnalysisReport::generateVerdict() {
	if (overallRiskScore >= 80)
		verdict = "Plagiarized";
	else if (overallRiskScore >= 40)
		verdict = "Suspicious";
	else
		verdict = "Clean";
}
void AnalysisReport::addFlaggedSegment(const string& segment) {
	flaggedSegments.push_back(segment);
}
string AnalysisReport::getVerdict() const {
	return verdict;
}
void AnalysisReport::setRiskScore(double score) {
	overallRiskScore = score;
}
double AnalysisReport::getRiskScore() {
	return overallRiskScore;
}
void AnalysisReport::saveToJSON(const string& filename) {
	ofstream file(filename);
	file << "{\n";
	file << " \"verdict\": \"" << verdict << "\"\n";
	file << "}\n";
	file.close();
}