#ifndef STUDENTDATABASE_H
#define STUDENTDATABASE_H

#include "Student.h"
#include "Faculty.h"
#include "BST.h"

class StudentDatabase{
private:
    static const std::string studentFileName; //declare class constant
    static const std::string facultyFileName;
    BST<Student> *masterStudentPtr;
    BST<Faculty> *masterFacultyPtr;
    
public:
    StudentDatabase();
    ~StudentDatabase();
    bool startUp(); 
    bool shutDown();
    //student functions
    void addStudent(int studentID, std::string studentName, std::string studentLevel, std::string studentMajor, double GPA, int sAdvisorID);
    void displayStudent(int studentID);
    void deleteStudent(int studentID);
    void printAllStudents(); //ascending ID#
    void printStudentAdvisor(int studentID);
    void changeAdvisorID(int studentID, int facultyID);
    //faculty functions
    void addFaculty(int facultyID, std::string facultyName, std::string facultyLevel, std::string Department, std::vector<int> aList);
    void displayFaculty(int facultyID);
    void deleteFaculty(int facultyID);
    void printAllFaculty(); //ascending ID#
    void printAdvisees(int facultyID);
    void removeAdvisee(int facultyID, int studentID);
    std::vector<int> getAdviseeList(int facultyID);
    //program functions
    bool loadFromFiles();
    bool saveToFiles();
    void Rollback();
    void exit();
};

#endif