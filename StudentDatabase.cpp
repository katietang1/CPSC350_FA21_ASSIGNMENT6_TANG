#include "StudentDatabase.h"

StudentDatabase::StudentDatabase() {
    studentDbPtr = nullptr;
    facultyDbPtr = nullptr;
}

StudentDatabase::~StudentDatabase() {

}

bool StudentDatabase::startUp() {
    if (studentDbPtr == nullptr){
        studentDbPtr = new BST<Student>();  //finds space in the heap, calls constructor
    }
    if (facultyDbPtr == nullptr){
        facultyDbPtr = new BST<Faculty>();
    }
    return true;
}                          

bool StudentDatabase::shutDown() {
    if (studentDbPtr != nullptr){
        delete studentDbPtr;    //calls destructor, returns space to the heap
        studentDbPtr = nullptr;
    }
    if (facultyDbPtr != nullptr){
        delete facultyDbPtr;
        facultyDbPtr = nullptr;
    }

    return true;
} 

/* ***** student functions ***** */

void StudentDatabase::addStudent() {

}

void StudentDatabase::displayStudent(int studentID) {
    
}

void StudentDatabase::deleteStudent(int studentID) {
    
}

void StudentDatabase::printAllStudents() {
    
}

void StudentDatabase::printStudentAdvisor(int studentID) {
    
}

void StudentDatabase::changeAdvisorID(int studentID, int facultyID) {
    
}

/* ***** faculty functions ***** */

void StudentDatabase::addFaculty() {
    
}

void StudentDatabase::displayFaculty(int facultyID) {
    
}

void StudentDatabase::deleteFaculty(int facultyID) {
    
}

void StudentDatabase::printAllFaculty() {
    
}

void StudentDatabase::printAdvisees(int facultyID) {
    
}

void StudentDatabase::removeAdvisee(int studentID) {
    
}

/* ***** program functions ***** */

void StudentDatabase::fileProcessor() {
    
}

void StudentDatabase::Rollback() {
    
}

void StudentDatabase::exit() {
    
}