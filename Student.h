#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
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
    Student(int sID, std::string sName, std::string sLevel, std::string sMajor);
    Student(std::string sBuff);
    ~Student();
    std::string toSString();
    std::string toSDisplay();
    int getStudentID();
    std::string getStudentName();
    std::string getStudentLevel();
    std::string getStudentMajor();
    double getStudentGPA();
    void setStudentGPA(double sGPA);
    int getStudentAdvisorID();
    void setStudentAdvisorID(int sAdvisorID);

private:
    static int getNextStudentID();
    static void setLastStudentID(int lastSID);

};

#endif 