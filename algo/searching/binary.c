#include <stdio.h>

// iterative approach
int binary_sort(int * arr,int size,int key){
  int start = 0;
  int last = size-1;

  while(start<=last){
    int mid = start + (last - start) / 2;

    if(arr[mid] > key){
      last = mid-1;
    }

    else if(arr[mid] < key){
      start = mid+1;
    }

    else {
      return mid;
    }
  }
  return -1;
}


// recursive approach
int rec_binary_search(int * arr,int key,int start,int end){ // here start = 0, end = size-1 initially while giving params

  if(start > end) return -1;

  int mid = start + (end - start) / 2;
  if(arr[mid] == key) return mid;
  if(arr[mid] > key) return rec_binary_search(arr,key,start,mid-1);
  if(arr[mid] < key) return rec_binary_search(arr,key,mid+1,end);
}