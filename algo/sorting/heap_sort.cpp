#include <iostream>
using namespace std;

// Heapifying the array , recursively
void heapify(int arr[],int n, int index) {
  int largest = index;
  int left = (2*index) +1;
  int right = (2*index) +2;

  // check if existing childs and either is big
  if(left < n && arr[largest] < arr[left]) {
    largest = left;
  }
  if (right < n && arr[largest] < arr[right]){
    largest = right;
  }

  // if not equal means big found
  if(largest!=index) {
    swap(arr[largest],arr[index]);
    heapify(arr,n,largest);
  }
  // else good
}


void heap_sort(int arr[],int size) {
  // convert to heap O(n)
  for ( int i = (size/2)-1; i >= 0 ; i-- ) {
    heapify(arr,size,i);
  }

  // procedure O(nlogn)
  for(int i = size-1; i > 0; i--) {
    swap(arr[0], arr[i]); // swapping root with last element
    heapify(arr, i, 0); // reducing size before heapify to avoid looking for already sorted last element O(logn)
  }

  // if reached here , the arr should be sorted in ascending order
}

