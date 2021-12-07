/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 6: Student Database
*/
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include <ostream>
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
    static int getLastStudentID();
    static void setLastStudentID(int lastSID);
    //object methods
    Student();
    Student(int sID, std::string sName, std::string sLevel, std::string sMajor);
    Student(std::string sBuff);
    ~Student();
    std::string toString() const;
    std::string toDisplay() const;
    int getStudentID();
    std::string getStudentName();
    std::string getStudentLevel();
    std::string getStudentMajor();
    double getStudentGPA();
    bool setStudentGPA(double sGPA);
    int getStudentAdvisorID();
    void setStudentAdvisorID(int sAdvisorID);
    //operators
    bool operator<(const Student& studentB);
    Student& operator=(const Student& studentB);
    bool operator==(const Student& studentB);
    friend std::ostream& operator<<(std::ostream &os, const Student &s);
};
#endif 