#include<iostream>
using namespace std;
#include "../header_files/dataStructures.h"
#include "../header_files/utilities.h"

template<class T>
BinaryNode<T> *AVL<T>::leftRotate(BinaryNode<T> *root){
    BinaryNode<T> *rotatedNode = root -> right;    
    root -> right = rotatedNode -> left;
    rotatedNode -> left = root;
    updateHeightAndSize(rotatedNode -> right);
    updateHeightAndSize(rotatedNode);
    return rotatedNode;
}

template<class T>
BinaryNode<T> *AVL<T>::rightRotate(BinaryNode<T> *root){
    BinaryNode<T> *rotatedNode = root -> left;
    root -> left = rotatedNode -> right;
    rotatedNode -> right = root;
    updateHeightAndSize(rotatedNode -> right);
    updateHeightAndSize(rotatedNode);
    return rotatedNode;
}

template<class T>
BinaryNode<T> *AVL<T>::AVLInsertUtility(BinaryNode<T> *root, T data){
    if(!root) return new BinaryNode<T>(data);
    if(data < root -> data) root -> left = AVLInsertUtility(root -> left, data);
    else if(data > root -> data) root -> right = AVLInsertUtility(root -> right, data);
    else return root;
    updateHeightAndSize(root);
    return balancedTree(root);
}

template<class T>
BinaryNode<T> *AVL<T>::AVLDeleteUtility(BinaryNode<T>* root, T data){
    if(data < root -> data) root -> left = AVLDeleteUtility(root -> left, data);        
    else if(data > root -> data) root -> right = AVLDeleteUtility(root -> right, data);
    else{
        if(!root -> right || !root -> left){
            BinaryNode<int>* temp;
            if(!root -> right) temp = root -> left; 
            else temp = root -> right;
            delete root;
            root = temp;
        }
        else{
            BinaryNode<T> *current = root -> right;
            while(current -> left) current = current -> left;
            root -> data = current -> data;
            root -> right = AVLDeleteUtility(root -> right, current -> data);            
        }   
    }
    updateHeightAndSize<T>(root);
    return balancedTree(root);
}

template <class T>
BinaryNode<T> *AVL<T>::AVLFindUtility(BinaryNode<T>* root, T data){
    if(!root) return nullptr;
    if(data < root -> data) return AVLFindUtility(root-> left, data);
    else if(data > root -> data) return AVLFindUtility(root -> right, data);
    else return root;
}

template<class T>
void AVL<T>::print(bool block){
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

template <class T>
BinaryNode<T>* AVL<T>::balancedTree(BinaryNode<T>* root){
    int balance = getBalance(root);
    if(!root) return root;
    if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
    if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);   
    if (balance > 1 && getBalance(root->left) < 0){  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }   
    if (balance < -1 && getBalance(root->right) > 0){  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }
    return root;
}

template <class T>
AVL<T>::AVL(){root = nullptr;}

template <class T>
AVL<T>::AVL(T data){root = new BinaryNode<T>(data);}

template<class T>
void AVL<T>::insert(T data){root = AVLInsertUtility(root, data);}

template<class T>
void AVL<T>::deleteNode(T data){root = AVLDeleteUtility(root, data);}

template<class T>
BinaryNode<T> *AVL<T>::find(T data){return AVLFindUtility(root, data);}

template<class T>
int AVL<T>::height(){return root -> height;}

