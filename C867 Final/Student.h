//
//  Student.h
//  C867 Final
//
//  Created by Jonathan Hunt on 4/5/24.
//
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "degree.h"
#include <iostream>

using namespace std;

class Student {

public:
    // Constructor
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int day0, int day1, int day2,
            DegreeProgram degreeProgram);

    // Destructor
    ~Student();
    // Printer
    void Print();

    // Getters
    string GetStudentID() const;
    string GetFirstName() const;
    string GetLastName() const;
    string GetEmailAddress() const;
    int GetAge() const;
    int GetDaysLeftForEachClass(int position) const;
    DegreeProgram GetDegreeProgram() const;
    // Setters
    void SetStudentID(string studentID);
    void SetFirstName(string firstName);
    void SetLastName(string lastName);
    void SetEmailAddress(string emailAddress);
    void SetAge(int age);
    void SetDaysLeftForEachClass(int position, int value);
    void SetDegreeProgram(DegreeProgram degreeProgram);

private:
    string m_studentID;
    string m_firstName;
    string m_lastName;
    string m_emailAddress;
    int m_age;
    int m_daysLeftforEachClass0;
    int m_daysLeftforEachClass1;
    int m_daysLeftforEachClass2;
    DegreeProgram m_degreeProgram;

};

#endif //STUDENT_H
