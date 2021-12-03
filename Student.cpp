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

std::string Student::toString() {
    return " ";
}

std::string Student::toDisplay() {
    return " ";
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

void Student::setStudentGPA(double sGPA) {
    
}

int Student::getStudentAdvisorID() {
    return studentAdvisorID;
}

void Student::setStudentAdvisorID(int sAdvisorID) {
    
}


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
