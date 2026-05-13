#pragma once
#ifndef DETECTIONENGINE_H
#define DETECTIONENGINE_H
#include "Submission.h"
#include "AnalysisReport.h"
class DetectionEngine {
protected:
	string engineName;
	double confidenceThreshold;
	bool isEnabled;
public:
	DetectionEngine();
	virtual ~DetectionEngine();
	virtual AnalysisReport analyze(const Submission& sub) = 0;
	virtual string getEngineType() const = 0;
	void setThreshold(double thresh);
	bool isActive() const;
};
#endif
