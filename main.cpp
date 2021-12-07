/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 6: Student Database
*/
#include <iostream>
#include "StudentDatabase.h"

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
void rollbackChange();
void exitProgram();
int selectOneStudent(std::string aTitle);
int selectOneStudent(std::vector<int> studentIDList);
int selectOneFacultyMember(std::string aTitle);
bool getNewStudentInfo(std::string *sName, std::string *sLevel, std::string *sMajor, double *sGPA, int *sAdvisorID);
bool getNewFacultyInfo(std::string *fName, std::string *fLevel, std::string *Department, std::vector<int> *aList);

//global variables
StudentDatabase *masterDBPtr;

int main (int argc, char **argv){
    char optionLine[5];
    int option;

    //start up student database
    masterDBPtr = new StudentDatabase();
    if ( masterDBPtr == nullptr || ! masterDBPtr->startUp() ) {
        cout << "Student Database start up was unsucessful" << endl;
        return -1;
    }
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

        //get option and validate. if invalid, error message, continue (goes to end of loop)
        cout << "Please enter the number of the option you have chosen: ";
        std::cin.getline(optionLine, 5);
        option = atoi(optionLine);
        if (option < 1 || option > 14) {
            cout << "You must enter a number between 1-14, please try again" << endl;
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
            break;
        case 8:
            deleteStudent();
            break;
        case 9:
            addFacultyMember();
            break;
        case 10:
            deleteFacultyMember();
            break;
        case 11:
            changeStudentAdvisor();
            break;
        case 12:
            removeFacultyAdvisee();
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
}

/* 2. Print all faculty and their information (sorted by ascending id #) */
void displayAllFaculty() {
    masterDBPtr->printAllFaculty();
}

/* 3. Find and display student information given the students id */
void displaySelectedStudent() {
    int tempID = selectOneStudent("Select the student you want to display");
    masterDBPtr->displayStudent(tempID);
}

/*4. Find and display faculty information given the faculty id */
void displaySelectedFaculty() {
    int tempID = selectOneFacultyMember("Select the faculty you want to display");
    masterDBPtr->displayFaculty(tempID);
}

/*5. Given a student’s id, print the name and info of their faculty advisor */
void displayStudentAdvisor() {
    int tempID = selectOneStudent("Select the student whose advisor you want to display");
    masterDBPtr->printStudentAdvisor(tempID);
}

/*6. Given a faculty id, print ALL the names and info of his/her advisees. */
void displayFacultyAdvisees() {
    int tempID = selectOneFacultyMember("Select a faculty member whose advisees you want to display");
    masterDBPtr->getAdviseeList(tempID);
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
        studentID = masterDBPtr->addStudent( studentName, studentLevel, Major, GPA);
    }
    cout << "New student added, ID: " << studentID << endl;
    return studentID;
}

/*8. Delete a student given the id */
void deleteStudent() {
    int tempID = selectOneStudent("Select the student you would like to delete");
    masterDBPtr->deleteStudent(tempID);
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
    return facultyID;
}

/*10. Delete a faculty member given the id. */
void deleteFacultyMember() {
    int tempID = selectOneFacultyMember("Select the faculty memebr you would like to delete");
    masterDBPtr->deleteFaculty(tempID);

}

/*11. Change a student’s advisor given the student id and the new faculty id. */
void changeStudentAdvisor() {
    int tempStudentID = selectOneStudent("Select the student for who's advisor you would like to change");
    int tempFacultyID = selectOneFacultyMember("Select the advisor you like to remove");
    masterDBPtr->changeAdvisorID(tempStudentID, tempFacultyID);

}

/*12. Remove an advisee from a faculty member given the ids */
void removeFacultyAdvisee() {
    int tempFacultyID = selectOneFacultyMember("Select the faculty member whose advisee you would like to remove");
    std::vector<int> aList = masterDBPtr->getAdviseeList(tempFacultyID);
    int tempStudentID = selectOneStudent(aList);
    masterDBPtr->removeAdvisee(tempFacultyID, tempStudentID);
}

/*13. Rollback */
/*The Rollback command is used if the user realizes they have made a mistake in their data 
processing.  The Rollback command will “undo” the previous action, but only if that 
action changed the structure of the DB.  Your program should allow the user to roll back 
the last 5 commands that CHANGED the DB.  (Commands that simply display data do 
not count.)  This will involve keeping snapshots of the DB before and after commands 
are issued.  The implementation details for this are left up to you.  */
void rollbackChange() {
    masterDBPtr->Rollback();
}

/*14. Exit */
/*If the user chooses to exit, you should write the faculty and student tables back out to the 
“facultyTable” and “studentTable” files (see appendix A), clean up, and quit gracefully. */
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
    //look up ID in tree
    //do while loop until we find it
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
    //look up ID in tree
    //do while loop until we find it
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
            moreAdvisees = true;
        } else if (option == "no") {
            moreAdvisees = false;
        } else {
            cout << "ERROR: yes or no only" <<endl;
        }
    }
    return true;
}
