#include "StudentDatabase.h"
//initialize class constants
const std::string StudentDatabase::studentFileName = "studentTable.txt";
const std::string StudentDatabase::facultyFileName = "facultyTable.txt";

StudentDatabase::StudentDatabase() {
    masterStudentPtr = nullptr;
    masterFacultyPtr = nullptr;
}

StudentDatabase::~StudentDatabase() {

}

bool StudentDatabase::startUp() {
    if (masterStudentPtr == nullptr){
        masterStudentPtr = new BST<Student>();  //finds space in the heap, calls constructor
    }
    if (masterFacultyPtr == nullptr){
        masterFacultyPtr = new BST<Faculty>();
    }

    return true;
}                          

bool StudentDatabase::shutDown() {
    if (masterStudentPtr != nullptr){
        delete masterStudentPtr;    //calls destructor, returns space to the heap
        masterStudentPtr = nullptr;
    }
    if (masterFacultyPtr != nullptr){
        delete masterFacultyPtr;
        masterFacultyPtr = nullptr;
    }

    return true;
} 

/* ***** student functions ***** */

void StudentDatabase::addStudent(int studentID, std::string studentName, std::string studentLevel, std::string studentMajor, double GPA, int sAdvisorID) {

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

void StudentDatabase::addFaculty(int facultyID, std::string facultyName, std::string facultyLevel, std::string Department, std::vector<int> aList) {
    
}

void StudentDatabase::displayFaculty(int facultyID) {
    
}

void StudentDatabase::deleteFaculty(int facultyID) {
    
}

void StudentDatabase::printAllFaculty() {
    
}

void StudentDatabase::printAdvisees(int facultyID) {
    
}

void StudentDatabase::removeAdvisee(int facultyID, int studentID) {
    
}

std::vector<int> StudentDatabase::getAdviseeList(int facultyID) {

}

/* ***** program functions ***** */

bool StudentDatabase::loadFromFiles() {
    bool rVal = true;
    if ( ! masterStudentPtr->loadStudentsFromFile(studentFileName) ) {
        cout << "ERROR: Unable to load students from file" << endl;
        rVal = false;
    }
    if ( ! masterFacultyPtr->loadFacultyFromFile(facultyFileName) ) {
        cout << "ERROR: Unable to load faculty from file" << endl;
        rVal = false;
    }
    return rVal;
}

bool StudentDatabase::saveToFiles() {
    
}

void StudentDatabase::Rollback() {
    
}

void StudentDatabase::exit() {
    
}
