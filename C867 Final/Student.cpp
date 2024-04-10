//
//  Student.cpp
//  C867 Final
//
//  Created by Jonathan Hunt on 4/5/24.
//
#include <iostream>
#include "Student.h"
#include <string>

using namespace std;

// Constructor
Student::Student() {
    m_studentID = "";
    m_firstName = "";
    m_lastName = "";
    m_emailAddress = "";
    m_age = 0;
    m_daysLeftforEachClass0 = 0;
    m_daysLeftforEachClass1 = 0;
    m_daysLeftforEachClass2 = 0;
    m_degreeProgram = NETWORK;
   
}
Student::Student(string studentID, string firstName , string lastName, string emailAddress, int age, int daysAtCourse0, int daysAtCourse1, int daysAtCourse2, DegreeProgram degreeProgram)
    :
    m_studentID(studentID),
    m_firstName(firstName),
    m_lastName(lastName),
    m_emailAddress(emailAddress),
    m_age(age),
    m_daysLeftforEachClass0(daysAtCourse0),
    m_daysLeftforEachClass1(daysAtCourse1),
    m_daysLeftforEachClass2(daysAtCourse2),
    m_degreeProgram(degreeProgram)
    {
    }
// Destructor
Student::~Student()
{
}
// Printer
void Student::Print() {
    
    string degreeString;
    if(m_degreeProgram == 0) {
        degreeString = "SECURITY";
    } else if (m_degreeProgram == 1) {
        degreeString = "NETWORK";
    } else {
        degreeString = "SOFTWARE";
    }
    cout << m_studentID << "\tFirst Name: " << m_firstName << "\tLast Name: " << m_lastName << "\tAge: " << m_age << "\tdays In Course: {" << m_daysLeftforEachClass0 << ", " << m_daysLeftforEachClass1 << ", " << m_daysLeftforEachClass2 << "}\tDegree Program: " << degreeString << endl;
}

// Getters
string Student::GetStudentID() const {
    return m_studentID;
}
string Student::GetFirstName() const {
    return m_firstName;
    }
string Student::GetLastName() const {
    return m_lastName;
    }
string Student::GetEmailAddress() const {
    return m_emailAddress;
    }
int Student::GetAge() const {
    return m_age;
    }
int Student::GetDaysLeftForEachClass(int position) const {
    switch(position) {
        case 0:
            return m_daysLeftforEachClass0;
            break;
        case 1:
            return m_daysLeftforEachClass1;
            break;
        case 2:
            return m_daysLeftforEachClass2;
            break;
        default:
            return m_daysLeftforEachClass0;
            break;
    }
    }
DegreeProgram Student::GetDegreeProgram() const {
    return m_degreeProgram;
}
// Setters

void Student::SetStudentID(string studentID) {
    m_studentID = studentID;
}
void Student::SetFirstName(string firstName) {
    m_firstName = firstName;
}
void Student::SetLastName(string lastName) {
    m_lastName = lastName;
}
void Student::SetEmailAddress(string emailAddress) {
    m_emailAddress = emailAddress;
}
void Student::SetAge(int age) {
    m_age = age;
}
void Student::SetDaysLeftForEachClass(int position, int value) {
    switch(position) {
        case 0:
            m_daysLeftforEachClass0 = value;
            break;
        case 1:
            m_daysLeftforEachClass1 = value;
            break;
        case 2:
            m_daysLeftforEachClass2 = value;
            break;
        default:
            m_daysLeftforEachClass0 = value;
            break;
    }
}
void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
    m_degreeProgram = degreeProgram;
}
