/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 6: Student Database
*/
#include <iostream>
#include "StudentDatabase.h"
#include "LinkedList.h"

//forward declarations 
void displayAllStudents();
void displayAllFaculty();
void displaySelectedStudent();
void displaySelectedFaculty();
void displayStudentAdvisor();
void displayFacultyAdvisees();
int addStudent();
void deleteStudent();
int addFacultyMember();
void deleteFacultyMember();
void changeStudentAdvisor();
void removeFacultyAdvisee();
void exitProgram();
int selectOneStudent(std::string aTitle);
int selectOneStudent(std::vector<int> studentIDList);
int selectOneFacultyMember(std::string aTitle);
bool getNewStudentInfo(std::string *sName, std::string *sLevel, std::string *sMajor, double *sGPA, int *sAdvisorID);
bool getNewFacultyInfo(std::string *fName, std::string *fLevel, std::string *Department, std::vector<int> *aList);
void rollbackChange();
void storeRollDB();

//global variables
StudentDatabase *masterDBPtr;
LinkedList<StudentDatabase> rollList;

int main (int argc, char **argv){
    char optionLine[5];
    int option;

    //start up student database
    masterDBPtr = new StudentDatabase();
    if ( masterDBPtr == nullptr || ! masterDBPtr->startUp() ) {
        cout << "Student Database start up was unsucessful" << endl;
        return -1;
    }

    //Store DB for first RollBack
    storeRollDB();

    //execute menu
    do {
        cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
        cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
        cout << "3. Find and display student information given the students id" << endl; 
        cout << "4. Find and display faculty information given the faculty id" << endl; 
        cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl; 
        cout << "6. Given a faculty id, print ALL the names and info of his/her advisees" << endl; 
        cout << "7. Add a new student" << endl; 
        cout << "8. Delete a student given the id" << endl; 
        cout << "9. Add a new faculty member" << endl; 
        cout << "10. Delete a faculty member given the id" << endl; 
        cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl; 
        cout << "12. Remove an advisee from a faculty member given the ids" << endl; 
        cout << "13. Rollback" << endl;
        cout << "14. Exit" << endl;
        cout << endl;

        //get option and validate. if invalid, error message, continue (goes to end of loop)
        cout << "Please enter the number of the option you have chosen: ";
        std::cin.getline(optionLine, 5);
        option = atoi(optionLine);
        if (option < 1 || option > 14) {
            cout << "You must enter a number between 1-14, please try again" << endl;
            cout << endl;
            continue;
        }
    
        //switch on option to call action function
        switch(option){
        case 1:
            displayAllStudents();
            break;
        case 2:
            displayAllFaculty();
            break;
        case 3:
            displaySelectedStudent();
            break;
        case 4:
            displaySelectedFaculty();
            break;
        case 5:
            displayStudentAdvisor();
            break;
        case 6:
            displayFacultyAdvisees();
            break;
        case 7:
            addStudent();
            storeRollDB();
            break;
        case 8:
            deleteStudent();
            storeRollDB();
            break;
        case 9:
            addFacultyMember();
            storeRollDB();
            break;
        case 10:
            deleteFacultyMember();
            storeRollDB();
            break;
        case 11:
            changeStudentAdvisor();
            storeRollDB();
            break;
        case 12:
            removeFacultyAdvisee();
            storeRollDB();
            break;
        case 13:
            rollbackChange();
            break;
        case 14:
            exitProgram();
            break;
        default: 
            cout << "You must enter a number between 1-14" << endl;
        }

    } while (option != 14);


}       //main

/* 1. Print all students and their information (sorted by ascending id #) */
void displayAllStudents() {
    masterDBPtr->printAllStudents();
    cout << endl;
}

/* 2. Print all faculty and their information (sorted by ascending id #) */
void displayAllFaculty() {
    masterDBPtr->printAllFaculty();
    cout << endl;
}

/* 3. Find and display student information given the students id */
void displaySelectedStudent() {
    int tempID = selectOneStudent("Select the student you want to display");
    masterDBPtr->displayStudent(tempID);
    cout << endl;
}

/*4. Find and display faculty information given the faculty id */
void displaySelectedFaculty() {
    int tempID = selectOneFacultyMember("Select the faculty you want to display");
    masterDBPtr->displayFaculty(tempID);
    cout << endl;
}

/*5. Given a student’s id, print the name and info of their faculty advisor */
void displayStudentAdvisor() {
    int tempID = selectOneStudent("Select the student whose advisor you want to display");
    masterDBPtr->printStudentAdvisor(tempID);
    cout << endl;
}

/*6. Given a faculty id, print ALL the names and info of his/her advisees. */
void displayFacultyAdvisees() {
    int tempID = selectOneFacultyMember("Select a faculty member whose advisees you want to display");
    masterDBPtr->getAdviseeList(tempID);
    cout << endl;
}

/*7. Add a new student */
int addStudent() {
    int studentID;
    std::string studentName;
    std::string studentLevel;
    std::string Major;
    double GPA;
    int AdvisorID;
    if ( getNewStudentInfo(&studentName, &studentLevel, &Major, &GPA, &AdvisorID) ) {
        studentID = masterDBPtr->addStudent( studentName, studentLevel, Major, GPA, AdvisorID);
    }
    cout << "New student added, ID: " << studentID << endl;
    cout << endl;
    return studentID;
}

/*8. Delete a student given the id */
void deleteStudent() {
    int tempID = selectOneStudent("Select the student you would like to delete");
    masterDBPtr->deleteStudent(tempID);
    cout << endl;
}

/*9. Add a new faculty member */
int addFacultyMember() {
    int facultyID;
    std::string facultyName;
    std::string facultyLevel;
    std::string Department;
    std::vector<int> aList;
    if ( getNewFacultyInfo(&facultyName, &facultyLevel, &Department, &aList) ) {
        masterDBPtr->addFaculty(facultyID, facultyName, facultyLevel, Department, aList);
    }
    cout << "New faculty added, ID: " << facultyID << endl;
    cout << endl;
    return facultyID;
}

/*10. Delete a faculty member given the id. */
void deleteFacultyMember() {
    int tempID = selectOneFacultyMember("Select the faculty memebr you would like to delete");
    masterDBPtr->deleteFaculty(tempID);
    cout << endl;
}

/*11. Change a student’s advisor given the student id and the new faculty id. */
void changeStudentAdvisor() {
    int tempStudentID = selectOneStudent("Select the student for who's advisor you would like to change");
    int tempFacultyID = selectOneFacultyMember("Select the advisor you like to remove");
    masterDBPtr->changeAdvisorID(tempStudentID, tempFacultyID);
    cout << endl;
}

/*12. Remove an advisee from a faculty member given the ids */
void removeFacultyAdvisee() {
    int tempFacultyID = selectOneFacultyMember("Select the faculty member whose advisee you would like to remove");
    std::vector<int> aList = masterDBPtr->getAdviseeList(tempFacultyID);
    int tempStudentID = selectOneStudent(aList);
    masterDBPtr->removeAdvisee(tempFacultyID, tempStudentID);
    cout << endl;
}

/*13. Rollback */
void rollbackChange() {
    if (rollList.getSize() == 0)
    {
        cout << "You have no more chance to rollback." << endl;
        return;
    }
    else{
        rollList.removeFront();
        StudentDatabase rollDB = rollList.getFront();
        masterDBPtr = &rollDB;
        rollList.removeFront();
    }
    cout << endl;
}

void storeRollDB() {
    if (rollList.getSize() <= 6)
    {
        StudentDatabase rollDB = *masterDBPtr;
        rollList.insertFront(rollDB);
    }
    else {
        rollList.removeBack();
        StudentDatabase rollDB = *masterDBPtr;
        rollList.insertFront(rollDB);
    }
}

/*14. Exit */
void exitProgram() {
    masterDBPtr->saveToFiles();
    masterDBPtr->exit();
}

/* ***** helper functions ***** */
/* helper to select a single student and return ID*/
int selectOneStudent(std::string aTitle) {
    std::string tempIDStr;
    int tempID;
    cout << aTitle << endl;
    cout << "Enter the ID of the student: ";
    cin >> tempIDStr;
    tempID = stoi(tempIDStr);
    cout << "The student you have selected is :";
    return tempID;
}

/* helper to select a single student from Advisee list and return ID*/
int selectOneStudent(std::vector<int> aList) {
    std::string tempIDStr;
    int tempID;
    for (int i = 0; i < aList.size(); i++) { //doesnt print, how to call list? 
        cout << aList[i] << endl;
    }
    cout << "Enter the ID of the advisee from the list: ";
    cin >> tempIDStr;
    tempID = stoi(tempIDStr);
    cout << "The advisee you have selected is: ";
    return tempID;

}

/* helper to select a single faculty and return ID*/
int selectOneFacultyMember(std::string aTitle) {
    std::string tempIDStr;
    int tempID;
    cout << aTitle << endl;
    cout << "Enter the ID of the Faculty: ";
    cin >> tempIDStr;
    tempID = stoi(tempIDStr);
    cout << "The faculty you have selected is :";
    return tempID;
}

bool getNewStudentInfo(std::string *sName, std::string *sLevel, std::string *sMajor, double *sGPA, int *sAdvisorID) {
    cout << "Student Name: ";
    cin >> *sName;
    cout << "Level: ";
    cin >> *sLevel;
    cout << "Major: ";
    cin >> *sMajor;
    cout << "GPA: ";
    cin >> *sGPA;
    cout << "Advisor ID: ";
    cin >> *sAdvisorID;
    return true;
}

bool getNewFacultyInfo(std::string *fName, std::string *fLevel, std::string *Department, std::vector<int> *aList) {
    bool moreAdvisees = true;
    int tempID;
    std::string option;
    cout << "Faculty Name: ";
    cin >> *fName;
    cout << "Faculty Level: ";
    cin >> *fLevel;
    cout << "Faculty Department: ";
    cin >> *Department;
    cout << "Advisee IDs (one at a time please): ";
    while (moreAdvisees = true) {
        cin >> tempID;
        aList->push_back(tempID);
        cout << "Would you like to add another advisee? yes or no" << endl;
        cin >> option;
        if (option == "yes") {
            continue;
        } else if (option == "no") {
            break;
            moreAdvisees = false;
        } else {
            cout << "ERROR: yes or no only" <<endl;
        }
    }
    return true;
}