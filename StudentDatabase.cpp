#include <iostream>
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
//returns ID for new student
int StudentDatabase::addStudent(std::string studentName, std::string studentLevel, std::string studentMajor, double GPA) {
    int sID;
    sID = Student::getNextStudentID();
    Student *newStudent = new Student(sID, studentName, studentLevel, studentMajor);
    if (newStudent == nullptr) {
        cout << "ERROR: Unable to construct new student" << endl;
        return 0;
    }
    newStudent->setStudentGPA(GPA);
    newStudent->setStudentAdvisorID(0);
    masterStudentPtr->insert(*newStudent);
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

int StudentDatabase::addFaculty(int facultyID, std::string facultyName, std::string facultyLevel, std::string Department, std::vector<int> aList) {
    int fID;
    fID = Faculty::getNextFacultyID(); 
    Faculty *newFaculty = new Faculty(fID, facultyName, facultyLevel, Department);
    if (newFaculty == nullptr) {
        cout << "ERROR: Unable to construct new faculty" << endl;
        return 0;
    }
    //newFaculty->setAdvisee(aList);
    masterFacultyPtr->insert(*newFaculty);
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
    if ( ! loadStudentsFromFile(studentFileName) ) {
        cout << "ERROR: Unable to load students from file" << endl;
        rVal = false;
    }
    if ( ! loadFacultyFromFile(facultyFileName) ) {
        cout << "ERROR: Unable to load faculty from file" << endl;
        rVal = false;
    }
    return rVal;
}

bool StudentDatabase::loadStudentsFromFile(std::string fileName) {
    std::string line;
    std::ifstream studentFile;
    Student *newStudent;
    studentFile.open(studentFileName);
    if (!studentFile) {
        std::cout << "ERROR: Invald file" << std::endl;
    }
    while (!studentFile.eof()) {
        while (getline(studentFile, line)) {
            newStudent = new Student(line);
            masterStudentPtr->insert(*newStudent);
        }
    }
    studentFile.close();

    return false;
}

bool StudentDatabase::loadFacultyFromFile(std::string fileName) {

}

bool StudentDatabase::saveToFiles() {
    
}

bool StudentDatabase::saveStudentsToFile(std::string fileName) {

}

bool StudentDatabase::saveFacultyToFile(std::string fileName) {

}

void StudentDatabase::Rollback() {
    
}

void StudentDatabase::exit() {
    
}
