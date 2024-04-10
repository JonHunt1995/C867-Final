//
//  Roster.cpp
//  C867 Final
//
//  Created by Jonathan Hunt on 4/5/24.
//
#include "Roster.h"
using namespace std;

Roster::Roster()
    {
    }
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysIncourse0, int daysInCourse1, int daysInCourse2, DegreeProgram degreeProgram) {
    
    classRosterArray[++index] = new Student(studentID, firstName, lastName, emailAddress, age, daysIncourse0, daysInCourse1, daysInCourse2, degreeProgram);
}
void Roster::parse(string row) {
    // Parse Student Data by Comma Separated Value Format
    size_t rhs = row.find(",");
    string studentID = row.substr(0, rhs);
    size_t lhs = rhs + 1;
    // Parse First Name
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string firstName = row.substr(lhs, rhs - lhs);
    // Parse Last Name
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string lastName = row.substr(lhs, rhs - lhs);
    // Parse Email Address
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string emailAddress = row.substr(lhs, rhs - lhs);
    // Parse Age
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int age = stoi(row.substr(lhs, rhs - lhs));
    // Parse Days in Course Array size 3
    // Course 0
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int daysInCourse0 = stoi(row.substr(lhs, rhs - lhs));
    // Course 1
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int daysInCourse1 = stoi(row.substr(lhs, rhs - lhs));
    // Course 2
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int daysInCourse2 = stoi(row.substr(lhs, rhs - lhs));
    // Parse Degree Program
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string strDegree = row.substr(lhs, rhs - lhs);

    DegreeProgram degreeProgram = DegreeProgram::SECURITY;
    if (strDegree == "NETWORK") {
        degreeProgram = NETWORK;
    } else if (strDegree == "SOFTWARE") {
        degreeProgram = SOFTWARE;
    }
    add(studentID, firstName, lastName, emailAddress, age, daysInCourse0, daysInCourse1, daysInCourse2, degreeProgram);
};

void Roster::remove(string studentID) {
    bool foundStudentID = false;
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i]->GetStudentID() == studentID) {
            foundStudentID = true;
            // delete classRosterArray[i];
            // classRosterArray[i] = new Student;
            // Could just use setters to change student to blank default values instead
            cout << "The student whose ID is " << studentID << " is deleted" << endl;
        }
    }
    if (foundStudentID == false) {
        cout << "Student " << studentID << " not found" << endl;
    }
}
void Roster::printAverageDaysInCourse(string studentID ) {
    for (int i = 0; i < 5; ++i) {
        int sum = 0;
        sum = classRosterArray[i]->GetDaysLeftForEachClass(0) + classRosterArray[i]->GetDaysLeftForEachClass(1) + classRosterArray[i]->GetDaysLeftForEachClass(2);
        int average = sum / 3;
        cout << "Average days in current Courses for Student ID: " << classRosterArray[i]->GetStudentID() << " is " << average << " days.\n";
    }
}
    
void Roster::printInvalidEmails() {
    for (int i = 0; i < 5; ++i) {
        if (verifyEmail(classRosterArray[i]->GetEmailAddress()) == false) {
            cout << classRosterArray[i]->GetEmailAddress() << endl;
        }
    }
}
void Roster::printAll() {
    for (int i = 0; i < 5; ++i) {
        classRosterArray[i]->Print();
    }
}
void Roster::printByDegreeProgram(DegreeProgram degree) {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i]->GetDegreeProgram() == degree) {
            classRosterArray[i]->Print();
        }
    }
}
// Hidden Private Function to Verify Student Emails by Ensuring there's No Spaces and There's an @ sign
bool Roster::verifyEmail(string email) {
    bool noWhiteSpaces = true;
    bool hasAtSign = true;
    bool hasAPeriod = true;
    if (email.find(".") == string::npos) {
        hasAPeriod = false;
    }
    if (email.find(" ") != string::npos) {
        noWhiteSpaces = false;
    }
    if (email.find("@") == string::npos) {
        hasAtSign = false;
    }
    if (noWhiteSpaces && hasAtSign && hasAPeriod) {
        return true;
    } else {
        return false;
    }
     
}
