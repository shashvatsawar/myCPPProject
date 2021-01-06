#include <iostream>

#include "../header_files/dataStructures.h"
#include "../header_files/utilities.h"
using namespace std;

template<class T>
// I am fucking with your code
BinaryNode<T> *BST<T>::BSTInsertUtility(BinaryNode<T>* root, T data){
    if(!root) return new BinaryNode<T>(data);
    if(data < root -> data) root -> left = BSTInsertUtility(root -> left, data);
    else root -> right = BSTInsertUtility(root -> right, data);
    updateHeightAndSize(root);
    return root;
}

template<class T>
BinaryNode<T> *BST<T>::BSTDeleteUtility(BinaryNode<T>* root, T data){
    if(data < root -> data) root -> left = BSTDeleteUtility(root -> left, data);        
    else if(data > root -> data) root -> right = BSTDeleteUtility(root -> right, data);
    else{
        if(!root -> right){
            BinaryNode<int>* temp = root -> left; 
            delete root;
            root = temp;
        }
        else{
            BinaryNode<T> *current = root -> right;
            BinaryNode<T> *previous = nullptr;
            while(current -> left){
                previous = current;
                current = current -> left;
            }
            if(!previous) root -> right = current -> right;
            else previous -> left = current -> right;
            root -> data = current -> data;
            delete current;
            
        }   
        updateHeightAndSizeI(root);    
    }
    updateHeightAndSize(root);
    return root;
}

template <class T>
BinaryNode<T> *BST<T>::BSTFindUtility(BinaryNode<T>* root, T data){
    if(!root) return nullptr;
    if(data < root -> data) return BSTFindUtility(root-> left, data);
    else if(data > root -> data) return BSTFindUtility(root -> right, data);
    else return root;
}

template<class T>
BST<T>::BST(){root = nullptr;}

template<class T>
BST<T>::BST(T data){root = new BinaryNode<T>(data);}

template<class T>
void BST<T>::print(bool block){
    cout << endl;
    Queue<BinaryNode<T>> BFQueue = Queue<BinaryNode<T>>(*root);

    int height = root -> height;
    int level = height;
    int previous = 1;
    while(!BFQueue.isEmpty()){
        int size = BFQueue.size;
        int arraySize = size;
        int* temp = new int[arraySize];
        int index = 0;
        int a = 0;
        while(size){
            BinaryNode<int> current = BFQueue.deQueue();
            temp[index++] = current.data;
            if (current.left){
                BFQueue.enQueue(*(current.left));
                a = a | (power(2, 2 * size - 1));
            }                
            if (current.right){
                BFQueue.enQueue(*(current.right));
                a = a | (power(2, 2 * size - 2)); 
            }                
            size--;
            
        } 
        if (block) printLevelWithBlock(temp, height, level, previous);
        else printLevel(temp, height, level, previous);
        previous = a;
        level -= 1;
        cout << endl;
    }
}
template<class T>
void BST<T>::insert(T data){root = BSTInsertUtility(root, data);}

template<class T>
void BST<T>::deleteNode(T data){root = BSTDeleteUtility(root, data);}

template<class T>
BinaryNode<T> *BST<T>::find(T data){return BSTFindUtility(root, data);}

template<class T>
int BST<T>::height(){return root -> height;}
