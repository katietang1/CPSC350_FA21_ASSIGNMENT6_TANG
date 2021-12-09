/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 6: Student Database
*/
#ifndef STUDENTDATABASE_H
#define STUDENTDATABASE_H

#include <iostream>
#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include <stdlib.h>

class StudentDatabase{
private:
    static const std::string studentFileName; //declare class constant
    static const std::string facultyFileName;
    BST<Student> *masterStudentPtr;
    BST<Faculty> *masterFacultyPtr;
    bool loadStudentsFromFile(std::string fileName);
    bool saveStudentsToFile(std::string fileName);
    bool loadFacultyFromFile(std::string fileName);
    bool saveFacultyToFile(std::string fileName);
    
public:
    StudentDatabase();
    ~StudentDatabase();
    bool startUp(); 
    bool shutDown();
    //student functions
    int addStudent(std::string studentName, std::string studentLevel, std::string studentMajor, double GPA, int facultyID);
    void displayStudent(int studentID);
    void deleteStudent(int studentID);
    void printAllStudents(); //ascending ID#
    void printStudentAdvisor(int studentID);
    void changeAdvisorID(int studentID, int facultyID);
    //faculty functions
    int addFaculty(int facultyID, std::string facultyName, std::string facultyLevel, std::string Department, std::vector<int> aList);
    void displayFaculty(int facultyID);
    void deleteFaculty(int facultyID);
    void printAllFaculty(); //ascending ID#
    void printAdvisees(int facultyID);
    void removeAdvisee(int facultyID, int studentID);
    std::vector<int> getAdviseeList(int facultyID);
    //program functions
    bool loadFromFiles();
    bool saveToFiles();
    void exit();
};

#endif