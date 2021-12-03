#ifndef FACULTY_H
#define FACULTY_H

#include <fstream>
#include <iostream>
#include <vector>

class Faculty{

private:
    static int lastFacultyID;
    int facultyID;
    std::string facultyName;
    std::string facultyLevel;
    std::string facultyDepartment;
    std::vector<int> *adviseeListPtr;

public:
    //static methods
    static int getNextFacultyID();
    static void setLastFacultyID(int lastFID);
    //object methods
    Faculty();
    Faculty(int fID, std::string fName, std::string fLevel, std::string fDepartment);
    Faculty(std::string fBuff);
    ~Faculty();
    std::string toString();
    std::string toDisplay();
    int getFacultyID();
    std::string getFacultyName();
    std::string getFacultyLevel();
    std::string getFacultyDepartment();
    std::vector<int>* getAdviseeList();
    bool setAdvisee(int fStudentID);
    bool removeAdvisee(int fStudentID);
    //operators
    bool operator<(const Faculty& facultyB);
    Faculty& operator=(const Faculty& facultyB);
    bool operator==(const Faculty& facultyB);
    //add another operator, add default constructor 
};

#endif 