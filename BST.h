#ifndef BST_H
#define BST_H
#include <iostream>

using namespace std;

template <class T>
class TreeNode{
    public:
        TreeNode();
        TreeNode(T key);
        virtual ~TreeNode();

        T key; // data
        TreeNode<T> *left;
        TreeNode<T> *right;
};

template <class T>
TreeNode<T>::TreeNode(){
    left = nullptr;
    right = nullptr;
    key = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T k){
    left = nullptr;
    right = nullptr;
    key = k;

}

template <class T>
TreeNode<T>::~TreeNode(){
    left = nullptr;
    right = nullptr;
}

template <class T>
class BST{
    public:
        BST();
        virtual ~BST();
        void insert(T value);
        bool contains(T value); //search
        T *find(T target);
        bool deleteNode(T k);
        bool isEmpty();

        T* getMin();
        T* getMax();
        TreeNode<T> *getFirst();
        TreeNode<T> *getSuccessor(TreeNode <T> *d); // d represents the node we are going to delete
        void printNodes();
        void recPrint(TreeNode<T> *node);

    private: //helper functions
        void clear(TreeNode <T> *d);    //recursive clear
    private:
        TreeNode<T> *root;
};

template <class T>
BST<T>::BST(){
    root = NULL;
}

template <class T>
BST<T>::~BST(){
    this->clear(root);
}

template <class T>
void BST<T>::clear(TreeNode <T> *d) {   //belts and suspenders
    if (d == nullptr){      
        return;
    }
    if (d->left != nullptr){
        clear(d->left);
        d->left = nullptr;
    }
    if (d->right != nullptr){
        clear(d->right);
        d->right = nullptr;
    }
    
    delete d;
}

template <class T>
void BST<T>::recPrint(TreeNode<T> *node){
    if (node == nullptr)
        return;
    if (node->left != nullptr){
        recPrint(node ->left);
    }
    cout << node->key << endl;
    if (node->right != nullptr){
        recPrint(node->right);
    }
}

template <class T> 
void BST<T>::printNodes(){
    recPrint(root);
}

template <class T> 
bool BST<T>::isEmpty(){
    return (root == nullptr);
}

template <class T> 
T* BST<T>::getMin(){
    TreeNode<T> *current = root;
    if(isEmpty())
        return NULL;
    while(current ->left != NULL){
        current = current->left;
    }
    return &(current->key);

}

template <class T> 
T* BST<T>::getMax(){
    TreeNode<T> *current = root;
    if(isEmpty())
        return NULL;
    while(current ->right != NULL){
        current = current->right;
    }
    return &(current->key);

}

template <class T> 
void BST<T>::insert(T value){
    TreeNode<T> *node = new TreeNode<T>(value);

    if (isEmpty()){
        root = node;
    }
    else {
        //tree is not empty, lets go find the insertion point for node
        TreeNode<T> *current = root;
        TreeNode<T> *parent = NULL;

        while (true) {
            parent = current;

            if(value < current->key){
                current = current->left;

                if(current == NULL){
                    //we found the insertion point
                    parent->left = node;
                    break;
                }
            }
            else {
                current = current->right;
                if (current == NULL){
                    //found the insertion point
                    parent->right = node;
                    break;
                }
            }
        }
    }
}

template <class T> 
bool BST<T>::contains(T value) {
    if (isEmpty())
        return false;
    else {
        //its not empty, lets find it
        TreeNode<T> *current = root;
        while(current->key != value){
            if (value < current-> key)
                current = current->left;
            else{
                current = current->right;
            }
            if (current = NULL)
                return false;
        }       
    }
    return true;
}

template <class T> 
T *BST<T>::find(T target) {
    TreeNode<T> *current = root;
    while(current != nullptr && ! (current->key == target)){
        if (current->key < target) {
            current = current->right;
        } else {
            current = current->left;
        }
    }
    if ( current == nullptr) {
        return nullptr;
    } else {
        return &(current->key);
    }   
}

template <class T> 
bool BST<T>::deleteNode(T k) {
    if (isEmpty())
        return false;
    //not empty, we need to find it and set our pointers
    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    while(!(current->key == k)){
        parent = current;

        if(k <current->key){
            isLeft = true;
            current = current->left;
        }
        else{
            isLeft = false;
            current = current->right;
        }
        if (current == NULL)
            return false;
    }
    // if we make it here, we found the node, now lets proceed to delete
    /*no children, node to be deleted is a leaf*/
    if(current->left == NULL && current->right == NULL){
        if(current == root)
            root = NULL;
        else if (isLeft)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    /*has a left child*/
    else if (current->right = NULL){
        if(current == root)
            root = current->left;
        else if (isLeft)
            parent->left = current->left;
        else
            parent->right = current->left;
    }
    /*has a right child*/
    else if (current->left = NULL){
        if(current == root)
            root = current->right;
        else if (isLeft)
            parent->left = current->right;
        else
            parent->right = current->right;
        
    }
    // two children uh oh 
    else {
        TreeNode<T> *successor = getSuccessor(current);

        if (current == root)
            root = successor;
        else if (isLeft)
            parent->left = successor;
        else 
            parent->right = successor;
        
        successor->left = current->left;
        current->left = NULL;
        current->right = NULL;
    }
    return true;
}

template <class T>
TreeNode<T> *BST<T>::getFirst() {
    TreeNode<T> *current = root;
    if(isEmpty())
        return NULL;
    while(current ->left != NULL){
        current = current->left;
    }
    return current;
}

template <class T>
// get the next node in order as determined by the type 
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){
    TreeNode<T> *sp = d; //successors parent 
    TreeNode<T> *successor = d;
    TreeNode<T> *current =d->right;

    while(current != NULL){
        sp = successor;
        successor = current;
        current = current->left;
    }
    //all pointers should be in the correct locations
    //check if succ is a descendant of the right child
    if (successor != d->right){
        sp->left = successor->right;
        successor->right = d->right;
    }
    return successor;

}

#endif