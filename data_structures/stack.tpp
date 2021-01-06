#include <iostream>
#include "../header_files/dataStructures.h"
using namespace std;

template<class T>
Stack<T>::Stack(){
    this -> list = LinkedList();
}
template<class T>
Stack<T>::Stack(T data){
    this -> list = LinkedList(data);
}
template<class T>
Stack<T>::Stack(T* arr, T size){
    this -> list = LinkedList(arr, size);
}
template<class T>
void Stack<T>::push(T data){
    this -> list.pushBack(data);
}
template<class T>
T Stack<T>::pop(){
    return this -> list.popFront();
}
template<class T>
bool Stack<T>::isEmpty(){
    return this -> list.isEmpty();
}
template<class T>
T Stack<T>::top(){
    return this -> list.head -> data;
}

