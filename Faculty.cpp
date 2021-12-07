/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 6: Student Database
*/
#include "Faculty.h"
#include <iostream>
#include <fstream>

int Faculty::lastFacultyID = 1000;

/* ***** static class functions ***** */

int Faculty::getNextFacultyID(){
    return ++Faculty::lastFacultyID;
}

int Faculty::getLastFacultyID() {
    return Faculty::lastFacultyID;
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
    this->adviseeListPtr = new std::vector<int>();
}

Faculty::Faculty(std::string fBuff){
    size_t idIdx=0, nameIdx=0, levelIdx=0, departIdx=0;
    std::string tempToken;
    this->adviseeListPtr = new std::vector<int>();
    idIdx = fBuff.find_first_of (',', 0);
    if (idIdx != std::string::npos) {
        nameIdx = fBuff.find_first_of (',', idIdx + 1);
        if (nameIdx != std::string::npos) {
            levelIdx = fBuff.find_first_of (',', nameIdx + 1);
            if (levelIdx != std::string::npos) {
                departIdx = fBuff.find_first_of (',', levelIdx + 1);
            }
        }
    }
    if (idIdx != std::string::npos) {
        tempToken = fBuff.substr(0, idIdx);
        this->facultyID = stoi(tempToken);
    } else {
        this->facultyID = 0;
    }

    if (nameIdx != std::string::npos) {
        this->facultyName = fBuff.substr(idIdx + 1, nameIdx - idIdx -1);
    } else {
        this->facultyName = "";
    }

    if (levelIdx != std::string::npos) {
        this->facultyLevel = fBuff.substr(nameIdx + 1, levelIdx - nameIdx -1);
    } else {
        this->facultyLevel = "";
    }

    if (departIdx != std::string::npos) {
        this->facultyDepartment  = fBuff.substr(levelIdx + 1, departIdx - levelIdx-1);
    } else {
        this->facultyDepartment = "";
    }
    
    if (departIdx != std::string::npos) {
        std::string tempAdviseeStr;
        int tempIdx = departIdx, tempAdvisee;
        int startIdx, length;
        tempToken = fBuff.substr(departIdx + 1);
        while (tempIdx > 0) {
            tempIdx = fBuff.find_first_of (',', departIdx + 1);
            if (tempIdx != std::string::npos) {
                startIdx = departIdx + 1;
                length = tempIdx - departIdx -1;
                tempAdviseeStr = fBuff.substr(startIdx, length);
                departIdx = tempIdx;
            } else {
                tempAdviseeStr = fBuff.substr(departIdx + 1);
            }
            tempAdvisee = stoi(tempAdviseeStr);
            this->adviseeListPtr->push_back(tempAdvisee);
        }
    } else {
        this->adviseeListPtr = nullptr;
    }
}

Faculty::~Faculty(){
    
}

std::string Faculty::toString() const {
    std::string facultyStr;
    std::string adviseesStr;
    std::string adviseeStr;
    for( std::vector<int>::iterator it = adviseeListPtr->begin() ; it != adviseeListPtr->end(); ++it ) {
        adviseeStr = std::to_string(*it);
        adviseesStr += adviseeStr + ",";
    }
    facultyStr = std::to_string(this->facultyID) + "," 
                + this->facultyName + ","
                + this->facultyLevel + "," 
                + this->facultyDepartment + ","
                + adviseesStr;
    return facultyStr;
}

std::string Faculty::toDisplay() const {
    std::string facultyDisplay;
    std::string adviseesStr;
    std::string adviseeStr;
    for( std::vector<int>::iterator it = adviseeListPtr->begin() ; it != adviseeListPtr->end(); ++it ) {
        adviseeStr = std::to_string(*it);
        adviseesStr += adviseeStr + ",";
    }
    facultyDisplay = "Faculty ID: " + std::to_string(this->facultyID) + "\n" 
                    + "Faculty Name: " + this->facultyName + "\n"
                    + "Faculty Level: " + this->facultyLevel + "\n" 
                    + "Faculty Major: " + this->facultyDepartment + "\n"
                    + "Faculty Advisee(s): " + adviseesStr;
    return facultyDisplay;
}

int Faculty::getFacultyID(){
    return facultyID;
}

std::string Faculty::getFacultyName(){
    return facultyName;
}

std::string Faculty::getFacultyLevel(){
    return facultyLevel;
}

std::string Faculty::getFacultyDepartment(){
    return facultyDepartment;
}

std::vector<int>* Faculty::getAdviseeList(){
    return adviseeListPtr;
}

bool Faculty::setAdvisee( int fStudentID ){
    if( this->advises(fStudentID) ) {
        std::cout << "ERROR: Faculty already has this student as an advisee" << std::endl;
        return false;
    } else {
        adviseeListPtr->push_back( fStudentID ); 
        return true;
    }
}

bool Faculty::removeAdvisee( int fStudentID ){
    for( std::vector<int>::iterator it = adviseeListPtr->begin() ; it != adviseeListPtr->end(); ++it ) {
        if( *it == fStudentID ) {
            adviseeListPtr->erase(it);
            return true;
        }
    }
    std::cout << "ERROR: Faculty does not have this advisee" << std::endl;
    return false;
}

bool Faculty::advises( int fStudentID ) {
    bool rVal = false;
    for( int idx = 0; idx < adviseeListPtr->size(); idx++ ) {
        if( adviseeListPtr->at(idx) == fStudentID ) {
            rVal = true;
        } 
    }
    return rVal;
}

bool Faculty::operator<( const Faculty& facultyB ) {
    return this->facultyID < facultyB.facultyID;
}

Faculty& Faculty::operator=( const Faculty& facultyB ) {
    if ( this != &facultyB ) {
        this->facultyID = facultyB.facultyID;
        this->facultyName = facultyB.facultyName;
        this->facultyLevel = facultyB.facultyLevel;
        this->facultyDepartment = facultyB.facultyDepartment;
        for( int i = 0; i < facultyB.adviseeListPtr->size(); i++ ) {
            this->adviseeListPtr->push_back( facultyB.adviseeListPtr->at(i) );
        }
    }
    return *this;
}

bool Faculty::operator==( const Faculty& facultyB ) {
    return this->facultyID == facultyB.facultyID;
}

std::ostream& operator<<(std::ostream &out, Faculty &f) {
    out << f.toDisplay();
    return out;
}