//
//  Roster.h
//  C867 Final
//
//  Created by Jonathan Hunt on 4/5/24.
//
#ifndef roster_h
#define roster_h
#include "student.h"

class Roster{
public:
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int days0, int days1, int days2, DegreeProgram degreeProgram);
    void parse(string row);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    
private:
    Student* ClassRosterArray[];
    bool verifyEmail();
};
#endif /* Roster_h */
