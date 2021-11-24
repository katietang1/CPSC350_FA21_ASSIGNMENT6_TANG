#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "Faculty.h"

class Student{

private:
    int studentID;
    std::string studentName;
    std::string studentLevel;
    std::string studentMajor;
    double studentGPA;
    int studentAdvisor;

public:
    Student();
    ~Student();

};

#endif 