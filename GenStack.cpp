/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 6: Student Database
*/
#include "GenStack.h"

template<typename T>
GenStack<T>::GenStack(){
    mSize = 128;
    top = -1;
    myArray = new char[mSize];
}

template<typename T>
GenStack<T>::GenStack(int maxSize){
    mSize = maxSize;
    top = -1;
    myArray = new char[mSize];
}

template<typename T>
GenStack<T>::~GenStack(){
    cout << "stack destructed" << endl;
    delete [] myArray;
}

template<typename T>
void GenStack<T>::push(T data){
    //check if full
    if(isFull()){
        throw runtime_error("stack is full !!!!");
    }
    myArray[++top] = data;
}

template<typename T>
T GenStack<T>::pop(){
    //check if empty
    if(isEmpty()){
        throw runtime_error("stack empty can NOT pop!!");
    }
    return myArray[top--];
}

template<typename T>
T GenStack<T>::peek(){
    //check if empty
    if(isEmpty()){
        throw runtime_error("stack empty can NOT peek!!");
    }
    return myArray[top];
}

template<typename T>
bool GenStack<T>::isFull(){
    return (top == mSize-1);
}

template<typename T>
bool GenStack<T>::isEmpty(){
    return (top == -1);
}

template<typename T>
int GenStack<T>::getSize(){
    return (top + 1);
}