#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>

class Faculty{

private:
    int facultyID;
    std::string facultyName;
    std::string facultyLevel;
    std::string facultyDepartment;
    //list of integers corresponding to all of the faculty member’s advisees’ ids.

public:
    Faculty();
    ~Faculty();

};

#endif 