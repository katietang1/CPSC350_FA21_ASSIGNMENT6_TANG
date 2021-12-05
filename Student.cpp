#include "Student.h"
#include <fstream>
#include <iostream>

int Student::lastStudentID = 1000;

/* ***** static class functions ***** */

int Student::getNextStudentID() {
    return ++Student::lastStudentID;
}

int Student::getLastStudentID() {
    return Student::lastStudentID;
}

void Student::setLastStudentID(int lastSID) {
    if (lastSID > Student::lastStudentID){
        Student::lastStudentID = lastSID;
    }
}

/* ***** object functions ***** */
Student::Student() {
    this->studentID = getNextStudentID();
    this->studentName = "";
    this->studentLevel = "";
    this->studentMajor = "";
    this->studentGPA = 0.0;
    this->studentAdvisorID = 0;
}

Student::Student(int sID, std::string sName, std::string sLevel, std::string sMajor){
   this->studentID = sID;
   this->studentName = sName;
   this->studentLevel = sLevel;
   this->studentMajor = sMajor;
   this->studentGPA = 0.0;
   this->studentAdvisorID = 0;
}

Student::Student(std::string sBuff) {
    size_t idIdx=0, nameIdx=0, levelIdx=0, majorIdx=0, gpaIdx=0;
    std::string tempToken;
    idIdx = sBuff.find_first_of (',', 0);
    if (idIdx != std::string::npos) {
        nameIdx = sBuff.find_first_of (',', idIdx + 1);
        if (nameIdx != std::string::npos) {
            levelIdx = sBuff.find_first_of (',', nameIdx + 1);
            if (levelIdx != std::string::npos) {
                majorIdx = sBuff.find_first_of (',', levelIdx + 1);
                if (majorIdx != std::string::npos) {
                    gpaIdx = sBuff.find_first_of (',', majorIdx + 1);
                }
            }
        }
    }
    if (idIdx != std::string::npos) {
        tempToken = sBuff.substr(0, idIdx);
        this->studentID = stoi(tempToken);
    } else {
        this->studentID = 0;
    }

    if (nameIdx != std::string::npos) {
        this->studentName = sBuff.substr(idIdx + 1, nameIdx - idIdx-1);
    } else {
        this->studentName = "";
    }

    if (levelIdx != std::string::npos) {
        this->studentLevel = sBuff.substr(nameIdx + 1, levelIdx - nameIdx-1);
    } else {
        this->studentLevel = "";
    }

    if (majorIdx != std::string::npos) {
        this->studentMajor  = sBuff.substr(levelIdx + 1, majorIdx - levelIdx-1);
    } else {
        this->studentMajor = "";
    }

    if (gpaIdx != std::string::npos) {
        tempToken = sBuff.substr(majorIdx + 1, gpaIdx - majorIdx-1);
        this->studentGPA = stod(tempToken);
    } else {
        this->studentGPA = 0.0;
    }
    
    if (gpaIdx != std::string::npos) {
        tempToken = sBuff.substr(gpaIdx + 1);
        this->studentAdvisorID = stoi(tempToken);
    } else {
        this->studentAdvisorID = 0;
    }
}

Student::~Student() {
    
}
/*toString() appends values with delimiter to write to file*/
std::string Student::toString() const {
    std::string studentStr;
    studentStr = std::to_string(this->studentID) + "," 
                + this->studentName + ","
                + this->studentLevel + "," 
                + this->studentMajor + ","
                + std::to_string(this->studentGPA) + ","
                + std::to_string(this->studentAdvisorID);
    return studentStr;
}

std::string Student::toDisplay() const {
    std::string studentDisplay;
    studentDisplay = "Student ID: " + std::to_string(this->studentID) + "\n" 
                    + "Student Name: " + this->studentName + "\n"
                    + "Student Level: " + this->studentLevel + "\n" 
                    + "Student Major: " + this->studentMajor + "\n"
                    + "Student GPA: " + std::to_string(this->studentGPA) + "\n" 
                    + "Student Advisor: " + std::to_string(this->studentAdvisorID);
    return studentDisplay;
}

int Student::getStudentID() {
    return studentID;
}

std::string Student::getStudentName() {
    return studentName;
}

std::string Student::getStudentLevel() {
    return studentLevel;
}

std::string Student::getStudentMajor() {
    return studentMajor;
}

double Student::getStudentGPA() {
    return studentGPA;
}

bool Student::setStudentGPA( double sGPA ) {
    if ( sGPA < 0.0 || sGPA > 4.0) {
        std::cout << "ERROR: GPA must be within 0.0-4.0 range" << std::endl;
        return false;
    }
    this->studentGPA = sGPA;
    return true;
}

int Student::getStudentAdvisorID() {
    return studentAdvisorID;
}

void Student::setStudentAdvisorID( int sAdvisorID ) {
    this->studentAdvisorID = sAdvisorID;
}


bool Student::operator<( const Student& studentB ) {
    return this->studentID < studentB.studentID;
}

Student& Student::operator=( const Student& studentB ) {
    if ( this != &studentB) {
        this->studentID = studentB.studentID;
        this->studentName = studentB.studentName;
        this->studentLevel = studentB.studentLevel;
        this->studentMajor = studentB.studentMajor;
        this->studentGPA = studentB.studentGPA;
        this->studentAdvisorID = studentB.studentAdvisorID;
    }
    return *this;
}

bool Student::operator==( const Student& studentB ) {
    return this->studentID == studentB.studentID;
}

std::ostream& operator<<(std::ostream &os, const Student &s) {
    os << s.toDisplay();
    return os;
}
