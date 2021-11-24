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

std::string Faculty::toFString(){
    return " ";
}

std::string Faculty::toFDisplay(){
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

void Faculty::setAdviseeList(int fStudentID){
    
}