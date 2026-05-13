#include "AIPatternEngine.h"
#include <algorithm>
#include <cctype>

using namespace std;

AIPatternEngine::AIPatternEngine() {
    engineName = "AIPattern";
    // Common AI filler words/phrases
    aiMarkerKeywords = { "delve", "testament", "landscape", "crucial", "underscore", "meticulous", "in conclusion", "it is important to note" };
}

bool AIPatternEngine::containsUniformStructure(const string& text) {
    int count = 0;
    string lowerText = text;
    transform(lowerText.begin(), lowerText.end(), lowerText.begin(), ::tolower);

    for (const auto& keyword : aiMarkerKeywords) {
        if (lowerText.find(keyword) != string::npos) {
            count++;
        }
    }
    // If more than 2 AI markers found, flag it
    return count > 2;
}

double AIPatternEngine::computePerplexity(const string& text) {
    // Mock perplexity: Short text or very uniform text gets low perplexity (suspicious)
    if (text.length() < 50) return 100;
    return 50.0;
}

AnalysisReport AIPatternEngine::analyze(const Submission& sub) {
    AnalysisReport report;
    string content = sub.getContent();

    bool isUniform = containsUniformStructure(content);
    double perplexity = computePerplexity(content);

    double riskScore = 0.0;

    if (isUniform) riskScore += 40;
    if (perplexity < 60) riskScore += 30;

    report.setRiskScore(riskScore);
    if (isUniform) {
        report.addFlaggedSegment("Detected uniform sentence structure typical of AI generation.");
    }
    report.generateVerdict();
    return report;
}

string AIPatternEngine::getEngineType() const {
    return "AIPattern";
}