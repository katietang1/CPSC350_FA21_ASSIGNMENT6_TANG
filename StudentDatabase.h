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
    void printStudents(); //ascending ID#
    void displayStudent(int studentID);
    void printStudentFaculty(int studentID);
    void addStudent();
    void deleteStudent(int studentID);
    void changeAdvior(int studentID, int facultyID);
    //faculty functions
    void printFaculties(); //ascending ID#
    void displayFaculty(int facultyID);
    void printFacultyAdvisee(int facultyID);
    void addFaculty();
    void deleteFaculty(int facultyID);
    void removeAdvisee(int studentID);
    //program functions
    void Rollback();
    void exit();






};

#endif