#include <iostream>
#include "../header_files/dataStructures.h"
using namespace std;

template <class T>
ostream &operator<<(ostream &os, BinaryNode<T> const &m){
    return os << m.data;
}

template<class T>
ostream &operator<<(ostream &os, Node<T> const &m){
    return os << m.data;
}

template <class T>
int getHeight(BinaryNode<T>* root){
    if (root) return root -> height;
    else return -1;
}

template <class T>
int getSize(BinaryNode<T>* root){
    if (root) return root -> size;
    else return 0;
}

template<class T>
int getBalance(BinaryNode<T>* root){
    if(!root) return 0;
    return getHeight(root -> left) - getHeight(root -> right);
}

template <class T>
void updateHeightAndSize(BinaryNode<T> *root){
    if(!root) return;
    if(!root -> left && !root -> right) {
        root -> height = 0;
        root -> size = 1;
    }
    root -> height = max(getHeight(root -> left), getHeight(root -> right)) + 1;
    root -> size = getSize(root -> left) + getSize(root -> right) + 1;
}

template<class T>
BinaryNode<T>::BinaryNode(T data){
    this->left = nullptr;
    this -> right = nullptr;
    this -> data = data;
    this -> parent = nullptr;
    this -> height = 0;
    this -> size = 1;
}

template<class T>
void InOrderTraversal(BinaryNode<T>* root){
    if(!root) return;
    InOrderTraversal(root -> left);
    cout << root -> data << " ";
    InOrderTraversal(root -> right);    
}

template<class T>
void PreOrderTraversal(BinaryNode<T>* root){
    if(!root) return;
    cout << root -> data << " ";
    PreOrderTraversal(root -> left);   
    PreOrderTraversal(root -> right);   
}

template<class T>
void PostOrderTraversal(BinaryNode<T>* root){
    cout << endl;
    if(!root) return;
    PostOrderTraversal(root -> left);
    PostOrderTraversal(root -> right);   
    cout << root -> data << " ";
}

template <class T>
void BFTraversal(BinaryNode<T>* root){
    Queue<BinaryNode<T>> BFQueue = Queue<BinaryNode<T>>(*(root));
    cout << endl;
    while(!BFQueue.isEmpty()){
        BinaryNode<T> current = BFQueue.deQueue();
        cout << current.data << " ";
        if (current.left)
            BFQueue.enQueue(*(current.left));
        if (current.right)
            BFQueue.enQueue(*(current.right));
    }
}

