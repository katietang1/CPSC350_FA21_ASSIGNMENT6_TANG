/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 6: Student Database
*/
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
    bool studentsLoaded, facultyLoaded;
    
    //create empty faculty and student trees
    if (masterStudentPtr == nullptr){
        masterStudentPtr = new BST<Student>();  //finds space in the heap, calls constructor
    }
    if (masterFacultyPtr == nullptr){
        masterFacultyPtr = new BST<Faculty>();
    }

    //attempt to load student from file
    studentsLoaded = loadStudentsFromFile(studentFileName);
    if (studentsLoaded == true) {
        cout << "Student table loaded from file." << endl;
    } else {
        cout << "No student table file, empty tree created" << endl;
    }

    //attempt to load faculty from file
    facultyLoaded = loadFacultyFromFile(facultyFileName);
    if (facultyLoaded == true) {
        cout << "Faculty table loaded from file." << endl;
    } else {
        cout << "No faculty table file, empty tree created" << endl;
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
int StudentDatabase::addStudent(std::string studentName, std::string studentLevel, std::string studentMajor, double GPA, int facultyID) {
    int sID;
    sID = Student::getNextStudentID();
    Student *newStudent = new Student(sID, studentName, studentLevel, studentMajor);
    if (newStudent == nullptr) {
        cout << "ERROR: Unable to construct new student" << endl;
        return 0;
    }
    newStudent->setStudentGPA(GPA);
    newStudent->setStudentAdvisorID(facultyID);
    masterStudentPtr->insert(*newStudent);
    return sID;
}

void StudentDatabase::displayStudent(int studentID) {
    Student tempStudent(studentID, "", "", "");
    Student *tempPtr = masterStudentPtr->find(tempStudent);
    if (tempPtr != nullptr) { 
        cout << tempPtr->toDisplay() << endl;
    } else {
        cout << "ERROR: No such student" << endl;
    }
}

void StudentDatabase::deleteStudent(int studentID) {
    Student tempStudent(studentID, "", "", "");
    Student *tempPtr = masterStudentPtr->find(tempStudent);
    if (tempPtr == nullptr) { 
        cout << "ERROR: No such student" << endl; //print ID
    } else {
        masterStudentPtr->deleteNode(*tempPtr);
    }
}

void StudentDatabase::printAllStudents() {
   masterStudentPtr->printNodes();
}

void StudentDatabase::printStudentAdvisor(int studentID) {
    Student tempStudent(studentID, "", "", "");
    Student *tempStudentPtr = masterStudentPtr->find(tempStudent);
    if (tempStudentPtr == nullptr) {
        cout << "ERROR: No such student" << endl;
    } else {
        int studentAdvisorID = tempStudentPtr->getStudentAdvisorID();
        //check if student has ID
        if ( studentAdvisorID == 0) {
            cout << "ERROR: This student does not have an advisor assigned" << endl;
        } else {
            Faculty tempFaculty(studentAdvisorID, "", "", "");
            Faculty *tempFacultyPtr = masterFacultyPtr->find(tempFaculty);
            if (tempFacultyPtr == nullptr) {
                cout << "ERROR: Student faculty advisor " << studentAdvisorID << " not found" << endl;
            } else {
                cout << "Student advisor: " << tempFacultyPtr->toDisplay() << endl;
            }
        }
    }
}

void StudentDatabase::changeAdvisorID(int studentID, int facultyID) {
    Student tempStudent(studentID, "", "", "");
    Student *tempStudentPtr = masterStudentPtr->find(tempStudent);
    if (tempStudentPtr == nullptr) {
        cout << "ERROR: No such student" << endl;
    } else {
        tempStudentPtr->setStudentAdvisorID(facultyID);
        cout << "Student advisor changed" << endl;
    }
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
    for( std::vector<int>::iterator it = aList.begin() ; it != aList.end(); ++it ) {
        newFaculty->setAdvisee(*it);
    }
    masterFacultyPtr->insert(*newFaculty);
    return fID;
}

void StudentDatabase::displayFaculty(int facultyID) {
    Faculty tempFaculty(facultyID, "", "", "");
    Faculty *tempPtr = masterFacultyPtr->find(tempFaculty);
    if (tempPtr != nullptr) { 
        cout << tempPtr->toDisplay() << endl;
    } else {
        cout << "ERROR: No such faculty" << endl;
    }
}

void StudentDatabase::deleteFaculty(int facultyID) {
    Faculty tempFaculty(facultyID, "", "", "");
    Faculty *tempPtr = masterFacultyPtr->find(tempFaculty);
    if (tempPtr == nullptr) { 
        cout << "ERROR: No such faculty" << endl; //print ID
    } else {
        masterFacultyPtr->deleteNode(*tempPtr);
    }
}

void StudentDatabase::printAllFaculty() {
    masterFacultyPtr->printNodes();
}

void StudentDatabase::printAdvisees(int facultyID) {
    std::vector<int> aList = getAdviseeList(facultyID);
    for( std::vector<int>::iterator it = aList.begin() ; it != aList.end(); ++it ) {
        cout << *it << endl;
    }
}

void StudentDatabase::removeAdvisee(int facultyID, int studentID) {
    Faculty tempFaculty(facultyID, "", "", "");
    Faculty *tempPtr = masterFacultyPtr->find(tempFaculty);
    tempFaculty.removeAdvisee(studentID);
    cout << "Advisee: " << studentID << " removed.";
}

std::vector<int> StudentDatabase::getAdviseeList(int facultyID) {
    Faculty tempFaculty(facultyID, "", "", "");
    std::vector<int> aList = *tempFaculty.getAdviseeList();
    for( std::vector<int>::iterator it = aList.begin() ; it != aList.end(); ++it ) {
        cout << *it << endl;
    }
    return aList;
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
    studentFile.open(fileName);
    if (!studentFile) {
        std::cout << "ERROR: Invalid file or no file found" << std::endl;
        return false;
    }
    while (!studentFile.eof()) {
        getline(studentFile, line);
        if ( !studentFile.eof() ) {
            if ( studentFile.good() ) {
                newStudent = new Student(line);
                if ( newStudent->getStudentID() > Student::getLastStudentID() ) {
                    Student::setLastStudentID(newStudent->getStudentID() );
                }
                masterStudentPtr->insert(*newStudent);
            } else {
                cout << "ERROR: Unable to create student node" <<endl;
            }
        }
    }
    studentFile.close();
    return true;
}

bool StudentDatabase::loadFacultyFromFile(std::string fileName) {
    std::string line;
    std::ifstream facultyFile;
    Faculty *newFaculty;
    facultyFile.open(fileName);
    if (!facultyFile) {
        std::cout << "ERROR: Invalid file or no file found" << std::endl;
        return false;
    }
    while (!facultyFile.eof()) {
        getline(facultyFile, line);
        if ( !facultyFile.eof() ) {
            if ( facultyFile.good() ) {
                newFaculty = new Faculty(line);
                if ( newFaculty->getFacultyID() > Faculty::getLastFacultyID() ) {
                    Faculty::setLastFacultyID(newFaculty->getFacultyID() );
                }
                masterFacultyPtr->insert(*newFaculty);
            } else {
                cout << "ERROR: Unable to create faculty node" <<endl;
            }
        }
    }
    facultyFile.close();
    return true;
}

bool StudentDatabase::saveToFiles() {
    bool rVal = true;
    if ( ! saveStudentsToFile(studentFileName) ) {
        cout << "ERROR: Unable to save students to file" << endl;
        rVal = false;
    }
    if ( ! saveFacultyToFile(facultyFileName) ) {
        cout << "ERROR: Unable to save faculty to file" << endl;
        rVal = false;
    }
    return rVal;
}

bool StudentDatabase::saveStudentsToFile(std::string fileName) {
    std::ofstream studentFile;
    Student *tempStudentPtr;
    std::string tempStr;
    studentFile.open(studentFileName);
    TreeNode<Student> *nextNode = masterStudentPtr->getFirst();
    while (nextNode != nullptr) {
        tempStudentPtr = &(nextNode->key);
        tempStr = tempStudentPtr->toString();
        studentFile << tempStr << endl;
        nextNode = masterStudentPtr->getSuccessor(nextNode);
    }
    studentFile.close();
    return true;
}

bool StudentDatabase::saveFacultyToFile(std::string fileName) {
    std::ofstream facultyFile;
    Faculty *tempFacultyPtr;
    std::string tempStr;
    facultyFile.open(facultyFileName);
    TreeNode<Faculty> *nextNode = masterFacultyPtr->getFirst();
    while (nextNode != nullptr) {
        tempFacultyPtr = &(nextNode->key);
        tempStr = tempFacultyPtr->toString();
        facultyFile << tempStr << endl;
        nextNode = masterFacultyPtr->getSuccessor(nextNode);
    }
    facultyFile.close();
    return true;
}

void StudentDatabase::exit() {
    delete masterStudentPtr;
    delete masterFacultyPtr;
    //exit();
}
