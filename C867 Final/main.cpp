//
//  main.cpp
//  C867 Final
//
//  Created by Jonathan Hunt on 4/5/24.
//
#include <iostream>
#include <string>
#include "Roster.h"
using namespace std;


int main() {
    // Declarations
    string myName ="\tName: Jonathan Hunt\n";
    string myCourse ="Course Number C867: Scripting and Programming Apps";
    string myLang ="\tLanguage: C++\t";
    string myStudentNum  = "ID: 012098248";
    const string studentData[] =
{"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Jonathan,Hunt,jhun728@wgu.edu,28, 25,32,47,SOFTWARE"}; // Input Data For Application
    Roster classRoster; // Roster Object to Manipulate, Query, and Organize Student Data
    
    cout << myCourse << myLang << myStudentNum << myName;
   
// Application Operations
    
    for (int i = 0; i < 5; ++i) {
        classRoster.parse(studentData[i]);
    }
    classRoster.printAll();
    
    classRoster.printInvalidEmails();
    
    classRoster.printAverageDaysInCourse();
    
    classRoster.printByDegreeProgram(SOFTWARE);
  
    classRoster.remove("A3");
    
    // Use Destructor to Release Allocated Memory
    
    return 0;
}
