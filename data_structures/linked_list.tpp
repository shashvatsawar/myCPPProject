#include <iostream>
#include "../header_files/dataStructures.h"
#include "../header_files/utilities.h"
using namespace std;

template<class T>
LinkedList<T>::LinkedList(T data){
    this -> head = new Node<T>(data);
    this -> size = 1;
    this -> tail = this -> head;
}
template<class T>
LinkedList<T>::LinkedList(){
    this -> head = nullptr;
    this -> size = 0;
    this -> tail = nullptr;
}
template<class T>
void LinkedList<T>::empty(){
    Node<T> *current = this -> head;
    while(current -> next != nullptr){
        Node<T> *temp = current -> next;
        delete(current);
        current = temp;
    }
    this -> head = nullptr;
    this -> size = 0;
    this -> tail = nullptr;
}
template<class T>
LinkedList<T>::LinkedList(T* arr, T size){
    this -> head = new Node<T>(arr[0]);
    Node<T> *current = this -> head;
    for(T i = 1 ; i < size ; i++){
        current -> next = new Node<T>(arr[i]);
        current = current -> next;
    }
    this -> tail = current;
    current -> next = nullptr;
    this -> size = size;
}
template<class T>
void LinkedList<T>::pushFront(T data){
    if(!this -> size) {
        this -> head = new Node<T>(data);
        this -> tail = this -> head;
        this -> size = 1;
        return;
    }
    Node<T>* newNode<T> = new Node<T>(data);
    newNode<T> -> next = head;
    head = newNode<T>;
    (this -> size)++;
    
}
template<class T>
T LinkedList<T>::popFront(){
    T poppedValue;
    if(!(this -> size)) {
        cout << "List empty!";
        return -1;
    }
    if(this -> size == 1){
        poppedValue = this -> head -> data;
        delete(this -> head);
        this -> head = this -> tail = nullptr;
        this -> size = 0;
        return poppedValue;
    }
    Node<T> * newHead = this -> head -> next;
    poppedValue = this -> head -> data;
    delete(this -> head);
    this -> head = newHead;
    (this -> size)--;
    return poppedValue;

}
template<class T>
void LinkedList<T>::pushBack(T data){
    if(!this -> size) {
        this -> head = new Node<T>(data);
        this -> tail = this -> head;
        this -> size = 1;
        return;
    }
    this -> tail -> next = new Node<T>(data);
    this -> tail = this -> tail -> next;
    (this -> size)++;
}
template<class T>
T LinkedList<T>::popBack(){
    T poppedValue;
    Node<T> *current = this -> head;
    if(!this -> size){
        cout << "List empty";
        return -1;
    }
    if (this -> size == 1){
        poppedValue = this -> head -> data;
        delete(this -> head);
        this -> head = nullptr;
        this -> size = 0;
        
        return poppedValue;
    }
    while(current -> next -> next != nullptr){
        current = current -> next;
    }
    this -> tail = current;
    poppedValue = current -> next -> data;
    delete(current -> next);
    current -> next = nullptr;
    (this -> size)--;
    return poppedValue;

}
template<class T>
void LinkedList<T>::print(){

    if(!this -> size){
        cout << "\n---\n|\\|-->\n---\n";
        return;
    }   
    int *noOfDigits = new int[this-> size];
    T *array = new T[this -> size];
    Node<T> *current = this -> head;
    
    for(int i = 0 ; i < this -> size ; i++){
        noOfDigits[i] = getNoOfDigits(current -> data);
        array[i] = current -> data;
        current = current -> next;
    }
    cout << endl;
    for(int i = 0 ; i < this -> size ; i++){
        int digits = noOfDigits[i];
        for(int i = 0 ; i < digits+4 ; i++) cout << "-";
        cout << "   ";
    }
    cout << endl;
    for(int i = 0 ; i< this-> size ; i++){
        cout << "| " << array[i] << " |-->";
    }
    cout << endl;
    for(int i = 0 ; i < this -> size ; i++){
        int digits = noOfDigits[i];
        for(int i = 0 ; i < digits+4 ; i++) cout << "-";
        cout << "   ";
    }
    cout << endl;


}

template<class T>
void LinkedList<T>::reverse(){
    if (this -> size == 0 || this -> size == 1) return;
    cout << "reverse";
    this -> tail = this -> head;
    Node<T> *current = this -> head;
    Node<T> *previous = nullptr;
    Node<T> *ahead = nullptr;

    while(current -> next != nullptr){
        ahead = current -> next;
        current -> next = previous;
        previous = current;
        current = ahead;
    }
    current -> next = previous;
    this -> head = current;
}
template<class T>
bool LinkedList<T>::isEmpty(){
    return this -> head == nullptr;
}


