#include <iostream>
#include "../header_files/dataStructures.h"
using namespace std;

template<class T>
Queue<T>::Queue(){
    this -> list = LinkedList<T>();
    this -> size = 0;
}
template<class T>
Queue<T>::Queue(T data){
    this -> list = LinkedList<T>(data);
    this -> size = 1;
}
template<class T>
Queue<T>::Queue(T* arr, T size){
    this -> list = LinkedList<T>(arr, size);
    this -> size = size;
}
template<class T>
void Queue<T>::enQueue(T data){
    this -> list.pushBack(data);
    this -> size++;
}
template<class T>
T Queue<T>::deQueue(){
    this -> size--;
    return this -> list.popFront();
} 
template<class T>
bool Queue<T>::isEmpty(){ 
    return this -> list.isEmpty();
} 
template<class T>
T Queue<T>::front(){
    if (this -> list.size == 0){
        cout << "list is empty";
        return -1;
    }
    return this -> list.head -> data;
}
template<class T>
void Queue<T>::print(){
    this -> list.print();
}


