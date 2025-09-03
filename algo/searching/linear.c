#include <stdio.h>

// recursive approach
int Rec_linear_search(int * arr,int key,int index,int size){
  if(index > size) return -1;
  if(arr[index] == key) return index;
  return Rec_linear_search(arr,key,index+1,size);
}

// iterative approach
int linear_search(int * arr,int size,int key){
  for(int i=0;i<size;i++){
    if(arr[i] == key){
      return i;
      break;
    }
  }
  return -1;
}

