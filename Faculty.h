#ifndef FACULTY_H
#define FACULTY_H

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
    Faculty(int fID, std::string fName, std::string fLevel, std::string fDepartment);
    Faculty(std::string fBuff);
    ~Faculty();
    std::string toFString();
    std::string toFDisplay();
    int getFacultyID();
    std::string getFacultyName();
    std::string getFacultyLevel();
    std::string getFacultyDepartment();
    std::vector<int> getAdviseeList();
    void setAdviseeList(int fStudentID);

private:
    static int getNextFacultyID();
    static void setLastFacultyID(int lastFID);

};

#endif 