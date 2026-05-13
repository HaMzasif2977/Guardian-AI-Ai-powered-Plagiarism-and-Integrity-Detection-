#pragma once
#ifndef TEXTSIMILARITYENGINE_H
#define TEXTSIMILARITYENGINE_H
#include "DetectionEngine.h"
#include <map>
class TextSimilarityEngine : public DetectionEngine {
private:
	map<string, string> referenceDatabase;
	int minTokenLength;
public:
	TextSimilarityEngine();
	AnalysisReport analyze(const Submission& sub) override;
	string getEngineType() const override;
	void addReference(const string& id,
		const string& content);
	double calculateJaccard(const string& text1,
		const string& text2);
};
#endif

