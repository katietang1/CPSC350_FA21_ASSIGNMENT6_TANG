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
    bool loadStudentsFromFile(std::string fileName);
    bool saveStudentsToFile(std::string fileName);

private:
    static int getNextStudentID();
    static void setLastStudentID(int lastSID);

};

#endif 