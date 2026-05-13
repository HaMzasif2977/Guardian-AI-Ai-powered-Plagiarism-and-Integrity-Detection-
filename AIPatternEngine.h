#pragma once
#ifndef AIPATTERNENGINE_H
#define AIPATTERNENGINE_H
#include "DetectionEngine.h"
#include <vector>
class AIPatternEngine : public DetectionEngine {
private:
	vector<string> aiMarkerKeywords;
	double perplexityScore;
public:
	AIPatternEngine();
	AnalysisReport analyze(const Submission& sub) override;
	string getEngineType() const override;
	double computePerplexity(const string& text);
	bool containsUniformStructure(const string& text);
};
#endif
