#ifndef STUDENTDATABASE_H
#define STUDENTDATABASE_H

#include "Student.h"
#include "Faculty.h"
#include "BST.h"

class StudentDatabase{
private:
    BST<Student> *studentDbPtr;
    BST<Faculty> *facultyDbPtr;
    

public:
    StudentDatabase();
    ~StudentDatabase();
    bool startUp(); 
    bool shutDown();
    //student functions
    void addStudent();
    void displayStudent(int studentID);
    void deleteStudent(int studentID);
    void printAllStudents(); //ascending ID#
    void printStudentAdvisor(int studentID);
    void changeAdvisorID(int studentID, int facultyID);
    //faculty functions
    void addFaculty();
    void displayFaculty(int facultyID);
    void deleteFaculty(int facultyID);
    void printAllFaculty(); //ascending ID#
    void printAdvisees(int facultyID);
    void removeAdvisee(int studentID);
    //program functions
    void fileProcessor();
    void Rollback();
    void exit();






};

#endif