#include "StudentDatabase.h"

StudentDatabase::StudentDatabase() {
    studentDbPtr = nullptr;
    facultyDbPtr = nullptr;
}

StudentDatabase::~StudentDatabase() {

}

bool StudentDatabase::startUp() {
    if (studentDbPtr == nullptr){
        studentDbPtr = new BST<Student>();  //finds space in the heap, calls constructor
    }
    if (facultyDbPtr == nullptr){
        facultyDbPtr = new BST<Faculty>();
    }
    return true;
}                          

bool StudentDatabase::shutDown() {
    if (studentDbPtr != nullptr){
        delete studentDbPtr;    //calls destructor, returns space to the heap
        studentDbPtr = nullptr;
    }
    if (facultyDbPtr != nullptr){
        delete facultyDbPtr;
        facultyDbPtr = nullptr;
    }

    return true;
} 