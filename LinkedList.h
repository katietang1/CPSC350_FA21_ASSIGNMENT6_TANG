#define LINKEDLIST_H

#include <iostream>
#include <exception>
#include "ListNode.h"

using namespace std;

template <class T>
class LinkedList{

private:
    ListNode<T> *front;
    ListNode<T> *back;
    unsigned int size;

public:
    LinkedList();
    ~LinkedList();

    void insertFront(T d);
    void insertBack(T d);
    T removeFront();
    T removeBack();
    T getBack();
    T getFront();
    T deleteAtPos(int pos);
    ListNode<T>* removeNode(T value);
    ListNode<T>* findPos(T pos);
    int find(T value);//search
    bool isEmpty();
    unsigned int getSize();
};

template <class T>
LinkedList<T>::LinkedList(){
    front=NULL;
    back=NULL;
    size=0;
}

template <class T>
LinkedList<T>::~LinkedList(){

}

template <class T>
void LinkedList<T>::insertFront(T d){
    ListNode<T> *node = new ListNode<T>(d);

    node -> next = front;
    front = node;
    ++size;
}

template <class T>
void LinkedList<T>::insertBack(T d)
{
    ListNode<T> *node = new ListNode<T>(d);
    if (isEmpty())
    {
        front = node;
    }
    else
    {
        back->next = node;
    }
    back = node;
    size++;
}

template <class T>
T LinkedList<T>::removeFront(){
    //check if empty
    if (size == 0)
    {
        cout << "LinkedList is Empty, Nothing to remove" << endl;
    }
    else{
        ListNode<T> *node = front;
        if(front->next == NULL){
          back = NULL;
         }
        //else{
        //   front->next->prev = NULL;
        // }
        front = front->next;
        --size;
        node->next = NULL;
        T temp = node->data;

        delete node;
        return temp;
    }
}

template <class T>
T LinkedList<T>::removeBack(){
    //check if empty
    if (size == 0)
    {
        cout << "LinkedList is Empty, Nothing to remove" << endl;

    }
    else if(back == front) {
      T temp = back -> data;
      front = NULL;
      back = NULL;
      size--;
      return temp;
    }
    else{
        T temp = back -> data;
        ListNode<T> *curr = front;
        while (curr -> next != back)
        {
            curr = curr -> next;
        }
        curr -> next = NULL;
        back = curr;
        --size;
        return temp;
    }
}

template <class T>
T LinkedList<T>::getBack(){
    //check if empty
    if (size == 0)
    {
        cout << "LinkedList is Empty, Nothing to return" << endl;
    }
    else{
        T temp = back -> data;
        return temp;
    }
}

template <typename T>
T LinkedList<T>::getFront(){
  return front->data;
}

template <class T>
int LinkedList<T>::find(T value){
    int pos = -1;
    ListNode<T> *curr = front;

    while(curr != NULL){
        ++pos;
        if(curr ->data == value){
            break;
        }
        curr = curr -> next;
    }
    if(curr == NULL){
        pos=-1;
        cout << "Didn't find value in LinkedList" << endl;
    }

    return pos;
}

template <class T>
ListNode<T>* LinkedList<T>::findPos(T pos){

    ListNode<T> *curr = front;

    for(int i = 0; i < getSize(); i++){
        if(i != pos){
            curr = curr -> next;
        }else{
            return curr;
        }
    }
}

template <class T>
bool LinkedList<T>::isEmpty(){
    return (size ==0);
}

template <class T>
unsigned int LinkedList<T>::getSize(){
    return size;

}

template <class T>
T LinkedList<T>::deleteAtPos(int pos){
    //error checking, you can always before you continue

    int nodePosition = 0;
    ListNode<T> *curr = front;
    ListNode<T> *prev = front;

    while(nodePosition != pos){
        prev = curr;
        curr = curr->next;
        ++nodePosition;
    }

    //found it

    //make sure to check whether ndoe/position is front or back
    prev->next = curr->next;
    curr->next = NULL;
    T d = curr->data;
    --size;
    delete curr;
    return d;
}

template <class T>
ListNode<T>* LinkedList<T>::removeNode(T value){
    
    ListNode<T> *node = findPos(value); //assume the find() function returns a pointer to ListNode

    if(node == NULL){
        return NULL;
    }
    ListNode<T> *curr = front;
    ListNode<T> *prev = front;

    while(curr != node){
        prev = curr;
        curr = curr->next;
    }

    if(node == front){
        front = front->next;
    }
    else if(node == back){
        prev->next = NULL;
        back = prev;
    }
    else{
        //its between front and back
        prev->next = curr->next;
        curr->next = NULL;
    }
    --size;
    return curr;

}

