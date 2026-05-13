#pragma once
#ifndef INTEGRITYMANAGER_H
#define INTEGRITYMANAGER_H

#include "Student.h"
#include "Instructor.h"
#include "Assignment.h"
#include "Submission.h"
#include "AnalysisReport.h"
#include "TextSimilarityEngine.h"
#include "AIPatternEngine.h"
#include <map>
#include <vector>
#include <iostream>

using namespace std;

class IntegrityManager {
private:
    vector<User*> users;
    vector<Assignment> assignments;
    vector<Submission> submissions;
    vector<AnalysisReport> reports;

    // Map to quickly find submissions by ID
    map<string, Submission*> submissionMap;

    TextSimilarityEngine* textEngine;
    AIPatternEngine* aiEngine;

public:
    IntegrityManager();
    ~IntegrityManager();

    void initializeSystem();

    // Menu Actions
    void addStudentInteractive();
    void addAssignmentInteractive();
    void submitWorkInteractive();
    void addReferenceMaterial();
    void runAnalysisOnAll();
    void viewReports();

    void addUser(User* newUser);
};

#endif