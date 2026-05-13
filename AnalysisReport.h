#pragma once
#ifndef ANALYSISREPORT_H
#define ANALYSISREPORT_H
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class AnalysisReport {
private:
	string reportID;
	string submissionID;
	double overallRiskScore;
	string verdict;
	string generationDate;
	vector<string> flaggedSegments;
public:
	AnalysisReport();
	void generateVerdict();
	void addFlaggedSegment(const string& segment);
	string getVerdict() const;
	void setRiskScore(double score);
	double getRiskScore();
	void saveToJSON(const string& filename);
};
#endif

