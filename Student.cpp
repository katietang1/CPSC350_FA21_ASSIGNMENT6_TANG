#include "Student.h"
#include <fstream>
#include <iostream>

int Student::lastStudentID = 1000;

/* ***** static class functions ***** */

int Student::getNextStudentID(){
    return ++Student::lastStudentID;
}

void Student::setLastStudentID(int lastSID){
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
    if (idIdx > 0) {
        nameIdx = sBuff.find_first_of (',', idIdx + 1);
        if (nameIdx > 0) {
            levelIdx = sBuff.find_first_of (',', nameIdx + 1);
            if (levelIdx > 0) {
                majorIdx = sBuff.find_first_of (',', levelIdx + 1);
                if (majorIdx > 0) {
                    gpaIdx = sBuff.find_first_of (',', majorIdx + 1);
                }
            }
        }
    }
    if (idIdx > 0) {
        tempToken = sBuff.substr(0, idIdx);
        this->studentID = stoi(tempToken);
    } else {
        this->studentID = 0;
    }

    if (nameIdx > 0) {
        this->studentName = sBuff.substr(idIdx + 1, nameIdx - idIdx);
    } else {
        this->studentName = "";
    }

    if (levelIdx > 0) {
        this->studentLevel = sBuff.substr(nameIdx + 1, levelIdx - nameIdx);
    } else {
        this->studentLevel = "";
    }

    if (majorIdx > 0) {
        this->studentMajor  = sBuff.substr(levelIdx + 1, majorIdx - levelIdx);
    } else {
        this->studentMajor = "";
    }

    if (gpaIdx > 0) {
        tempToken = sBuff.substr(majorIdx + 1, gpaIdx - majorIdx);
        this->studentGPA = stod(tempToken);
    } else {
        this->studentGPA = 0.0;
    }
    
    if (gpaIdx > 0) {
        tempToken = sBuff.substr(gpaIdx + 1);
        this->studentAdvisorID = stoi(tempToken);
    } else {
        this->studentAdvisorID = 0;
    }
}

Student::~Student() {
    
}

std::string Student::toString() {
    return " ";
}

std::string Student::toDisplay() {
    return " ";
}

int Student::getStudentID() {
    return -1;
}

std::string Student::getStudentName() {
    return " ";
}

std::string Student::getStudentLevel() {
    return " ";
}

std::string Student::getStudentMajor() {
    return " ";
}

double Student::getStudentGPA() {
    return -1.0;
}

void Student::setStudentGPA(double sGPA) {
    
}

int Student::getStudentAdvisorID() {
    return -1;
}

void Student::setStudentAdvisorID(int sAdvisorID) {
    
}

// bool Student::loadStudentsFromFile(std::string fileName) {
    
// }

// bool Student::saveStudentsToFile(std::string fileName) {
//     return false;
// }

bool Student::operator<(const Student& studentB) {
    return this->studentID < studentB.studentID;
}

Student& Student::operator=(const Student& studentB) {
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

bool Student::operator==(const Student& studentB) {
    return this->studentID == studentB.studentID;
}
