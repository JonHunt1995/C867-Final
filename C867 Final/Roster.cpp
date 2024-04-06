//
//  Roster.cpp
//  C867 Final
//
//  Created by Jonathan Hunt on 4/5/24.
//
#include "Roster.h"
using namespace std;

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysIncourse0,int daysInCourse1, int daysInCourse2, DegreeProgram degreeProgram) {

}
void Roster::parse(string row) {
    // Parse Student ID
    size_t rhs = row.find(",");
    string studentID = row.substr(0, rhs);
    size_t lhs = rhs + 1;
    // Parse First Name
    rhs = row.find(",", lhs);
    string firstName = row.substr(lhs, rhs - lhs);
    // Parse Last Name
    rhs = row.find(",", lhs);
    string lastName = row.substr(lhs, rhs - lhs);
    // Parse Email Address
    rhs = row.find(",", lhs);
    string emailAddress = row.substr(lhs, rhs - lhs);
    // Parse Age
    rhs = row.find(",", lhs);
    int age = stoi(row.substr(lhs, rhs - lhs));
    // Parse Days in Course Array size 3
    rhs = row.find(",", lhs);
    int daysInCourse0 = stoi(row.substr(lhs, rhs - lhs));
    rhs = row.find(",", lhs);
    int daysInCourse1 = stoi(row.substr(lhs, rhs - lhs));
    rhs = row.find(",", lhs);
    int daysInCourse2 = stoi(row.substr(lhs, rhs - lhs));
    rhs = row.find(",", lhs);
    // Parse Degree Program
    rhs = row.find(",", lhs);
    string strDegree = row.substr(lhs, rhs - lhs);

    DegreeProgram degreeProgram = DegreeProgram::SECURITY;
    if (strDegree == "NETWORK") {
        degreeProgram = NETWORK;
    } else if (strDegree == "SOFTWARE") {
        degreeProgram = SOFTWARE;
    }
    cout << studentID << firstName << lastName << emailAddress << age << daysInCourse0 << daysInCourse1 << daysInCourse2 << degreeProgram << endl;



};

void Roster::remove(string studentID) {

}
void Roster::printAverageDaysInCourse(string studentID) {

}
void Roster::printInvalidEmails() {

}
void Roster::printAll() {

}

