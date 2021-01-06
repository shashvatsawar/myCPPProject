#include <iostream>
#include "../header_files/myAlgorithms.h"
#include "../header_files/utilities.h"

using namespace std;
void mergeSort(int *arr, int size){
    mergeSortUtil(arr, 0, size - 1);
}

void mergeSortUtil(int *arr, int start, int end){
    if (end <= start) return; 
    int mid = getMid(start, end);
    mergeSortUtil(arr, start, mid);
    mergeSortUtil(arr, mid + 1, end);
    merge(arr, start, mid, end);

}

void merge(int *arr, int start, int mid, int end){
    int i, j, k;
    int* temp = new int[end - start + 1];
    i = start;
    j = mid + 1;
    k = 0;
    while(i <= mid && j <= end){
        if (arr[j] < arr[i]){
            temp[k++] = arr[j++];
        }
        else{
            temp[k++] = arr[i++];
        }
    }

    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= end){
        temp[k++] = arr[j++];
    }
    for(int i = 0 ; i <= end - start ; i++){
        arr[i+start] = temp[i];
    }
}