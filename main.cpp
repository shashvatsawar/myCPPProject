#include <iostream>
#include "header_files/myAlgorithms.h"
#include "header_files/dataStructures.h"
#include "header_files/utilities.h"

using namespace std;

void printAllHeights(BinaryNode<int>* root){
    if (root == nullptr) return;
    cout << root -> height;
    printAllHeights(root->left);
    printAllHeights(root->right);
}

int main(int, char**) {
    // Queue<int> myQueue = Queue<int>(6); // samyak jain is my name and i am a very good boy and i love to dan e 
    // myQueue.enQueue(4);
    // myQueue.enQueue(10);
    // myQueue.enQueue(15);
    // //hello world 
    // myQueue.print();
    // BST<int> binarySearchTree = BST<int>();
    // for(int const &i: {7, 10, 5, 13, 9, 4}) binarySearchTree.insert(i);
    // binarySearchTree.deleteNode(0);

    // binarySearchTree.print(1);
    // Node<int> *search = binarySearchTree.find(10);
    // AVL<int> avlTree = AVL<int>();
    // for(int const &i: {7, 10, 5, 13, 9, 4}) avlTree.insert(i);
    // avlTree.insert(0);
    // avlTree.insert(-2);
    // avlTree.deleteNode(5);
    // avlTree.print(1);
    return 0;
} 

