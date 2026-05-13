#include "IntegrityManager.h"
#include <iomanip>

using namespace std;

IntegrityManager::IntegrityManager() {
    textEngine = new TextSimilarityEngine();
    aiEngine = new AIPatternEngine();
}

IntegrityManager::~IntegrityManager() {
    for (User* u : users) delete u;
    for (auto& pair : submissionMap) delete pair.second;
    delete textEngine;
    delete aiEngine;
}

void IntegrityManager::initializeSystem() {
    cout << "GuardianAI System Initialized..." << endl;
    // Add some dummy reference data for plagiarism checking
    textEngine->addReference("Wiki_Article_1", "Artificial intelligence is a wonderful field that is growing rapidly.");
    textEngine->addReference("Book_Source_1", "The quick brown fox jumps over the lazy dog.");
}

void IntegrityManager::addUser(User* newUser) {
    users.push_back(newUser);
}

void IntegrityManager::addStudentInteractive() {
    string id, name, email, major;
    cout << "Enter Student ID: "; cin >> id;
    cout << "Enter Name: "; cin >> name;
    cout << "Enter Email: "; cin >> email;
    cout << "Enter Major: "; cin >> major;

    Student* s = new Student(id, "123", name, email, true, major, 2024, 3.5, 0);
    addUser(s);
    cout << "Student Added Successfully!" << endl;
}

void IntegrityManager::addAssignmentInteractive() {
    string id, title, course;
    cout << "Enter Assignment ID: "; cin >> id;
    cout << "Enter Title: "; cin >> title;
    cout << "Enter Course Code: "; cin >> course;

    Assignment a(id, title, "2026-05-20", course, 100);
    assignments.push_back(a);
    cout << "Assignment Created!" << endl;
}

void IntegrityManager::addReferenceMaterial() {
    string id, content;
    cout << "Enter Reference ID (e.g., Source1): "; cin >> id;
    cout << "Enter Reference Text Content: ";
    cin.ignore(); // Clear buffer
    getline(cin, content);

    textEngine->addReference(id, content);
    cout << "Reference Material Added to Database." << endl;
}

void IntegrityManager::submitWorkInteractive() {
    string subID, stuID, assignID, content;

    cout << "Enter Submission ID: "; cin >> subID;
    cout << "Enter Student ID: "; cin >> stuID;
    cout << "Enter Assignment ID: "; cin >> assignID;

    cout << "Enter Submission Content (Text): " << endl;
    cin.ignore();
    getline(cin, content);

    Submission* sub = new Submission(subID, stuID, assignID, "2026-05-08");

    // Hack to inject content directly since loadFile reads from disk
    // We access private member via friend or public setter if available, 
    // but for this skeleton, we'll assume a public setter or modify class.
    // For now, let's assume we can't easily set private rawContent without a setter.
    // *Note: In a real scenario, add 'void setContent(string c)' to Submission.h*

    // Since we can't easily set private content in this strict skeleton without changing .h:
    // We will create a temporary file for the demo to work with loadFile
    ofstream tempFile("temp_submission.txt");
    tempFile << content;
    tempFile.close();

    sub->loadFile("temp_submission.txt"); // Load the content from temp file

    submissions.push_back(*sub);
    submissionMap[subID] = new Submission(*sub); // Store copy
    cout << "Work Submitted Successfully!" << endl;
}

void IntegrityManager::runAnalysisOnAll() {
    cout << "\n--- STARTING ANALYSIS ---" << endl;
    reports.clear();

    for (auto& sub : submissions) {
        cout << "Analyzing Submission: " << sub.getSubmissionID() << "..." << endl;

        // Run both engines
        AnalysisReport textReport = textEngine->analyze(sub);
        AnalysisReport aiReport = aiEngine->analyze(sub);

        // Combine scores (Weighted average: 70% Plagiarism, 30% AI)
        double finalScore = (textReport.getVerdict() == "Plagiarized" ? 100 : textReport.getVerdict() == "Suspicious" ? 50 : 0) * 0.7
            + (aiReport.getVerdict() == "Plagiarized" ? 100 : aiReport.getVerdict() == "Suspicious" ? 50 : 0) * 0.3;

        // Create a consolidated report
        AnalysisReport finalReport;
        finalReport.setRiskScore(finalScore);
        finalReport.generateVerdict();

        // Add details
        if (textReport.getVerdict() != "Clean") finalReport.addFlaggedSegment("Plagiarism Check: " + textReport.getVerdict());
        if (aiReport.getVerdict() != "Clean") finalReport.addFlaggedSegment("AI Check: " + aiReport.getVerdict());

        reports.push_back(finalReport);
    }
    cout << "--- ANALYSIS COMPLETE ---" << endl;
}

void IntegrityManager::viewReports() {
    if (reports.empty()) {
        cout << "No reports generated yet. Please run analysis first." << endl;
        return;
    }

    cout << "\n========================================" << endl;
    cout << "       INTEGRITY REPORTS                " << endl;
    cout << "========================================" << endl;

    for (size_t i = 0; i < reports.size(); ++i) {
        cout << "Report #" << (i + 1) << endl;
        cout << "Verdict: " << reports[i].getVerdict() << endl;
        cout << "Risk Score: " << fixed << setprecision(2) << reports[i].getRiskScore() << "%" << endl;
        cout << "----------------------------------------" << endl;
    }
}