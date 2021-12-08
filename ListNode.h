#include <iostream>


using namespace std;

template <class T>
class ListNode{
    public:
        ListNode();
        ListNode(T d);
        ~ListNode();
        T data;
        ListNode *next;
};
template <class T>
ListNode<T>::ListNode(){

}
template <class T>
ListNode<T>::ListNode(T d){
    data = d;
    next = NULL;
}
template <class T>
ListNode<T>::~ListNode(){
    //delete next;
    next = NULL;
}
