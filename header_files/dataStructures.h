#pragma once

enum DFTypes{
    PreOrder,
    InOrder,
    PostOrder,
};

template <class T>
class BinaryNode{
    public:
        BinaryNode<T> *left;
        BinaryNode<T> *right;
        BinaryNode<T> *parent;
        T data;
        int height;
        int size;
        BinaryNode(){}
        BinaryNode(T);
};

template<class T>
class Node{
    public:
        T data;
        Node<T> *next;
        Node(){}
        Node(T data){
            this -> data = data;
            this -> next = nullptr;
        };
};

template<class T>
void updateHeightAndSize(BinaryNode<T>*);

template<class T>
BinaryNode<T>* updateHeightAndSizeI(BinaryNode<T>*);

template<class T>
int getHeight(BinaryNode<T>*);

template<class T>
int getSize(BinaryNode<T>*);

template<class T>
void InOrderTraversal(BinaryNode<T>* root);

template<class T>
void PreOrderTraversal(BinaryNode<T>* root);

template<class T>
void PostOrderTraversal(BinaryNode<T>* root);

template<class T>
void BFTraversal(BinaryNode<T>*);


#include "../data_structures/node.tpp"

template<class T>
class LinkedList{
    public:
        Node<T>* head;
        Node<T>* tail;
        int size;
        LinkedList();
        LinkedList(T);
        LinkedList(T*, T);
        void empty();
        void pushFront(T data);
        T popFront();
        void pushBack(T data);
        T popBack();
        
        void print();
        void reverse();
        bool isEmpty();
        void printAlgorithm();

};
#include "../data_structures/linked_list.tpp"

template <class T>
class Queue{    
    public:
        int size;
        LinkedList<T> list;
        Queue(T);
        Queue();
        Queue(T*, T);
        void enQueue(T);
        T deQueue();
        bool isEmpty();
        T front();
        
        void print();

};
#include "../data_structures/queue.tpp"

template <class T>
class Stack{
    public:
        LinkedList list;
        Stack(T);
        Stack();
        Stack(T*, T);
        void push(T);
        T pop();
        bool isEmpty();
        T top();
        void print();
};
#include "../data_structures/stack.tpp"

template <class T>
class BST{
    private:
        BinaryNode<T> *BSTInsertUtility(BinaryNode<T>*, T);
        BinaryNode<T> *BSTDeleteUtility(BinaryNode<T>*, T);
        BinaryNode<T> *BSTFindUtility(BinaryNode<T>*, T);
        
    public:
        BinaryNode<T> *root;
        BST(T);
        BST();
        BinaryNode<T> *getRoot();
        int height();
        BinaryNode<T> *find(T data);
        void insert(T data);
        void deleteNode(T data);
        void print(bool);
};
#include "../data_structures/binary_search_tree.tpp"

// template<class T>
// class AVL: public BST{
//     private:
//     public:
//         BinaryNode<T>* root;
//         AVL();
//         AVL(T);

// };
