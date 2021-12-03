#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include "Faculty.h"

class Student{

private:
    static int lastStudentID;
    int studentID;
    std::string studentName;
    std::string studentLevel;
    std::string studentMajor;
    double studentGPA;
    int studentAdvisorID;

public:
    //static methods
    static int getNextStudentID();
    static void setLastStudentID(int lastSID);
    //object methods
    Student();
    Student(int sID, std::string sName, std::string sLevel, std::string sMajor);
    Student(std::string sBuff);
    ~Student();
    std::string toString();
    std::string toDisplay();
    int getStudentID();
    std::string getStudentName();
    std::string getStudentLevel();
    std::string getStudentMajor();
    double getStudentGPA();
    void setStudentGPA(double sGPA);
    int getStudentAdvisorID();
    void setStudentAdvisorID(int sAdvisorID);
    //operators
    bool operator<(const Student& studentB);
    Student& operator=(const Student& studentB);
    bool operator==(const Student& studentB);

};

#endif 