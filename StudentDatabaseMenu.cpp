#include "StudentDatabase.h"

//forward declarations 
void displayAllStudents();
void displayAllFaculty();
void displaySelectedStudent();
void displaySelectedFaculty();
void displayStudentAdvisor();
void displayFacultyAdvisees();
void addStudent();
void deleteStudent();
void addFacultyMember();
void deleteFacultyMember();
void changeStudentAdvisor();
void removeFacultyAdvisee();
void rollbackChange();
void exitProgram();
int selectOneStudent();
int selectOneStudent(std::vector<int> studentIDList);
int selectOneFacultyMember();
bool getNewStudentInfo(int *sID, std::string *sName, std::string *sLevel, std::string *Major, double *GPA, int *sAdvisorID);
bool getNewFacultyInfo(int *fID, std::string *fName, std::string *fLevel, std::string *Department, std::vector<int> *aList);

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
    int tempID = selectOneStudent();
    masterDBPtr->displayStudent(tempID);
}

/*4. Find and display faculty information given the faculty id */
void displaySelectedFaculty() {
    int tempID = selectOneFacultyMember();
    masterDBPtr->displayFaculty(tempID);
}

/*5. Given a student’s id, print the name and info of their faculty advisor */
void displayStudentAdvisor() {
    int tempID = selectOneStudent();
    masterDBPtr->printStudentAdvisor(tempID);
}
/*6. Given a faculty id, print ALL the names and info of his/her advisees. */
void displayFacultyAdvisees() {
    int tempID = selectOneFacultyMember();
    masterDBPtr->getAdviseeList(tempID);
}
/*7. Add a new student */
void addStudent() {
    int studentID;
    std::string studentName;
    std::string studentLevel;
    std::string Major;
    double GPA;
    int sAdvisorID;
    if ( getNewStudentInfo(&studentID, &studentName, &studentLevel, &Major, &GPA, &sAdvisorID) ) {
        masterDBPtr->addStudent(studentID, studentName, studentLevel, Major, GPA, sAdvisorID);
    }
   
}
/*8. Delete a student given the id */
void deleteStudent() {
    int tempID = selectOneStudent();
    masterDBPtr->deleteStudent(tempID);
}
/*9. Add a new faculty member */
void addFacultyMember() {
    int facultyID;
    std::string facultyName;
    std::string facultyLevel;
    std::string Department;
    std::vector<int> aList;
    if ( getNewFacultyInfo(&facultyID, &facultyName, &facultyLevel, &Department, &aList) ) {
        masterDBPtr->addFaculty(facultyID, facultyName, facultyLevel, Department, aList);
    }
}
/*10. Delete a faculty member given the id. */
void deleteFacultyMember() {
    int tempID = selectOneFacultyMember();
    masterDBPtr->deleteFaculty(tempID);

}
/*11. Change a student’s advisor given the student id and the new faculty id. */
void changeStudentAdvisor() {
    int tempStudentID = selectOneStudent();
    int tempFacultyID = selectOneFacultyMember();
    masterDBPtr->changeAdvisorID(tempStudentID, tempFacultyID);

}
/*12. Remove an advisee from a faculty member given the ids */
void removeFacultyAdvisee() {
    int tempFacultyID = selectOneFacultyMember();
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
//create vector to store values 
//keep track of operation 
}
/*14. Exit */
/*If the user chooses to exit, you should write the faculty and student tables back out to the 
“facultyTable” and “studentTable” files (see appendix A), clean up, and quit gracefully. */
void exitProgram() {

}
/* ***** helper functions ***** */
/* helper to select a single student and return ID*/
int selectOneStudent() {

}
/* helper to select a single student from Advisee list and return ID*/
int selectOneStudent(std::vector<int> studentIDList) {

}
/* helper to select a single faculty and return ID*/
int selectOneFacultyMember() {

}

bool getNewStudentInfo(int *sID, std::string *sName, std::string *sLevel, std::string *Major, double *GPA, int *sAdvisorID) {
    return false;
}

bool getNewFacultyInfo(int *fID, std::string *fName, std::string *fLevel, std::string *Department, std::vector<int> *aList) {
    return false;
}
