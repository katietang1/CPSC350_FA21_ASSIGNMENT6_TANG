#include "Faculty.h"

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

Faculty::Faculty(int fID, std::string fName, std::string fLevel, std::string fDepartment){
    
}

Faculty::Faculty(std::string fBuff){
    
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