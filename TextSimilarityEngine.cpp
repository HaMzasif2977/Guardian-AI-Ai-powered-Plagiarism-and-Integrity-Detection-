#include "TextSimilarityEngine.h"
#include <sstream>
#include <algorithm>
#include <set>
#include <cctype>

using namespace std;

TextSimilarityEngine::TextSimilarityEngine() {
    minTokenLength = 3;
    engineName = "TextSimilarity";
}

// Helper to split string into lowercase words
vector<string> tokenize(const string& text) {
    vector<string> tokens;
    istringstream stream(text);
    string word;
    while (stream >> word) {
        // Remove punctuation
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        if (word.length() >= 3) {
            // Convert to lowercase
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            tokens.push_back(word);
        }
    }
    return tokens;
}

double TextSimilarityEngine::calculateJaccard(const string& text1, const string& text2) {
    vector<string> tokens1 = tokenize(text1);
    vector<string> tokens2 = tokenize(text2);

    if (tokens1.empty() || tokens2.empty()) return 0.0;

    set<string> set1(tokens1.begin(), tokens1.end());
    set<string> set2(tokens2.begin(), tokens2.end());

    vector<string> intersection;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(intersection));

    vector<string> unionSet;
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(unionSet));

    if (unionSet.empty()) return 0.0;

    return (double)intersection.size() / (double)unionSet.size();
}

void TextSimilarityEngine::addReference(const string& id, const string& content) {
    referenceDatabase[id] = content;
}

AnalysisReport TextSimilarityEngine::analyze(const Submission& sub) {
    AnalysisReport report;
    string subContent = sub.getContent();
    double maxSimilarity = 0.0;
    string matchedSource = "None";

    // Compare against all references in database
    for (const auto& pair : referenceDatabase) {
        double sim = calculateJaccard(subContent, pair.second);
        if (sim > maxSimilarity) {
            maxSimilarity = sim;
            matchedSource = pair.first;
        }
    }

    // Convert similarity (0-1) to Risk Score (0-100)
    double riskScore = maxSimilarity * 100;

    report.setRiskScore(riskScore);
    if (riskScore > 50) {
        report.addFlaggedSegment("High similarity found with source: " + matchedSource);
    }
    report.generateVerdict();
    return report;
}

string TextSimilarityEngine::getEngineType() const {
    return "TextSimilarity";
}
