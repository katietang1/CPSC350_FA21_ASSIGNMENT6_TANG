/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 6: Student Database
*/
#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include <exception>
using namespace std;

template<typename T>
class GenStack{
    public:
        GenStack();//default constructor
        GenStack(int maxSize);//overloaded constructor
        ~GenStack();//destructor

        //core functions
        void push(T data);
        T pop();

        //aux/helper functions
        T peek();//aka top()
        bool isEmpty();
        bool isFull();
        int getSize();

    private:  
        GenStack<T> *myArray;
        int mSize;
        int top;
};

#endif