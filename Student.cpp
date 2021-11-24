#include "Student.h"

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

Student::Student(int sID, std::string sName, std::string sLevel, std::string sMajor){
   
}

Student::Student(std::string sBuff) {
   
}

Student::~Student() {
    
}

std::string Student::toSString() {
    return " ";
}

std::string Student::toSDisplay() {
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
