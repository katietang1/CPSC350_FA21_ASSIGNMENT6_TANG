#include "Faculty.h"
#include <iostream>
#include <fstream>

int Faculty::lastFacultyID = 1000;

/* ***** static class functions ***** */

int Faculty::getNextFacultyID(){
    return ++Faculty::lastFacultyID;
}

void Faculty::setLastFacultyID(int lastFID){
    if (lastFID > Faculty::lastFacultyID){
        Faculty::lastFacultyID = lastFID;
    }
}

/* ***** object functions ***** */
Faculty::Faculty() {
    this->facultyID = getNextFacultyID();
    this->facultyName = "";
    this->facultyLevel = "";
    this->facultyDepartment = "";
    this->adviseeListPtr = new std::vector<int>();
}

Faculty::Faculty(int fID, std::string fName, std::string fLevel, std::string fDepartment){
    this->facultyID = fID;
    this->facultyName = fName;
    this->facultyLevel = fLevel;
    this->facultyDepartment = facultyDepartment;
    //this->adviseeListPtr = 
}

Faculty::Faculty(std::string fBuff){
     size_t idIdx=0, nameIdx=0, levelIdx=0, departIdx=0;
    std::string tempToken;
    idIdx = fBuff.find_first_of (',', 0);
    if (idIdx > 0) {
        nameIdx = fBuff.find_first_of (',', idIdx + 1);
        if (nameIdx > 0) {
            levelIdx = fBuff.find_first_of (',', nameIdx + 1);
            if (levelIdx > 0) {
                departIdx = fBuff.find_first_of (',', levelIdx + 1);
            }
        }
    }
    if (idIdx > 0) {
        tempToken = fBuff.substr(0, idIdx);
        this->facultyID = stoi(tempToken);
    } else {
        this->facultyID = 0;
    }

    if (nameIdx > 0) {
        this->facultyName = fBuff.substr(idIdx + 1, nameIdx - idIdx);
    } else {
        this->facultyName = "";
    }

    if (levelIdx > 0) {
        this->facultyLevel = fBuff.substr(nameIdx + 1, levelIdx - nameIdx);
    } else {
        this->facultyLevel = "";
    }

    if (departIdx > 0) {
        this->facultyDepartment  = fBuff.substr(levelIdx + 1, departIdx - levelIdx);
    } else {
        this->facultyDepartment = "";
    }
    
    if (departIdx > 0) {
        tempToken = fBuff.substr(departIdx + 1);
        //this->adviseeListPtr = stoi(tempToken);
    } else {
        //this->adviseeListPtr = 0;
    }
}

Faculty::~Faculty(){
    
}

std::string Faculty::toString(){
    return " ";
}

std::string Faculty::toDisplay(){
    return " ";
}
int Faculty::getFacultyID(){
    return -1;
}

std::string Faculty::getFacultyName(){
    return " ";
}

std::string Faculty::getFacultyLevel(){
    return " ";
}

std::string Faculty::getFacultyDepartment(){
    return " ";
}

std::vector<int> Faculty::getAdviseeList(){
    //return vector;
}

bool Faculty::setAdvisee(int fStudentID){
    return false;
}

bool Faculty::removeAdvisee(int fStudentID){
    return false;
}

bool Faculty::loadFacultyFromFile(std::string fileName) {
    return false;
}

bool Faculty::saveFacultyToFile(std::string fileName) {
    return false;
}

bool Faculty::operator<(const Faculty& facultyB) {
    return this->facultyID < facultyB.facultyID;
}

Faculty& Faculty::operator=(const Faculty& facultyB) {
    if ( this != &facultyB) {
        this->facultyID = facultyB.facultyID;
        this->facultyName = facultyB.facultyName;
        this->facultyLevel = facultyB.facultyLevel;
        this->facultyDepartment = facultyB.facultyDepartment;
        for (int i = 0; i < facultyB.adviseeListPtr->size(); i++) {
            this->adviseeListPtr->push_back( facultyB.adviseeListPtr->at(i) );
        }
    }
    return *this;
}

bool Faculty::operator==(const Faculty& facultyB) {
    return this->facultyID == facultyB.facultyID;
}