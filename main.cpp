#include "IntegrityManager.h"
#include <iostream>
#include <limits>
#include <string>
using namespace std;

void showMenu() {
    cout << "\n========================================" << endl;
    cout << "   GUARDIANAI - ACADEMIC INTEGRITY      " << endl;
    cout << "========================================" << endl;
    cout << "1. Register New Student" << endl;
    cout << "2. Create New Assignment" << endl;
    cout << "3. Add Reference Material (For Plagiarism DB)" << endl;
    cout << "4. Submit Student Work" << endl;
    cout << "5. RUN PLAGIARISM & AI DETECTION" << endl;
    cout << "6. View Analysis Reports" << endl;
    cout << "0. Exit System" << endl;
    cout << "========================================" << endl;
    cout << "Enter Choice: ";
}

int main() {
    IntegrityManager manager;
    manager.initializeSystem();

    int choice;
    while (true) {
        showMenu();

        if (!(cin >> choice)) {
            // Handle invalid input (non-integer)
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            manager.addStudentInteractive();
            break;
        case 2:
            manager.addAssignmentInteractive();
            break;
        case 3:
            manager.addReferenceMaterial();
            break;
        case 4:
            manager.submitWorkInteractive();
            break;
        case 5:
            manager.runAnalysisOnAll();
            break;
        case 6:
            manager.viewReports();
            break;
        case 0:
            cout << "Exiting GuardianAI. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid Option. Try again." << endl;
        }
    }
    return 0;
}