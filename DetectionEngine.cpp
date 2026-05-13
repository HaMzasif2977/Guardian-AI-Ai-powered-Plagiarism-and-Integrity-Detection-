#include "DetectionEngine.h"
DetectionEngine::DetectionEngine() {
	confidenceThreshold = 0.5;
	isEnabled = true;
}
DetectionEngine::~DetectionEngine() {}
void DetectionEngine::setThreshold(double thresh) {
	confidenceThreshold = thresh;
}
bool DetectionEngine::isActive() const {
	return isEnabled;
}
