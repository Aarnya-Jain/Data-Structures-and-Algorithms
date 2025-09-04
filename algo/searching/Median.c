// Also known as QuickSelect ( idk maybe the searching brother of Quicksort : ) Maybe)
// Finds the kth smallest element
// T(n) = O(n) -- average
// T(n) = O(n^2) -- worst { always pick min/max as pivot }
// S(n) = O(n)

#include <stdio.h>


// recursive approach
int rec_median(int * arr,int k,int left,int right){

  if(left==right) return arr[left]; // remember the base case

  int index = left + rand()%(right-left+1);

  int s1[100], s2[100], s3[100];
  int size1 = 0, size2 = 0, size3 = 0;

  for(int i=left;i<=right;i++){
    if(arr[i]==arr[index]){
      s2[size2++] = arr[i];
    }

    else if(arr[i] < arr[index]){
      s1[size1++] = arr[i];
    }

    else {
      s3[size3++] = arr[i];
    }
  }

  if(k <= size1) return median(s1,k,0,size1-1);
  else if(k <= size1+size2) return s2[0];
  else return median(s3,k-size1-size2,0,size3-1); // k is reduced to search effectively in s3
}

// iterative approach
int median(int * arr,int k,int left,int right){
  while(left<right){
    int index = left + rand()%(right-left+1);

    int s1[100], s2[100], s3[100];
    int size1 = 0, size2 = 0, size3 = 0;

  for(int i=left;i<=right;i++){
    if(arr[i]==arr[index]){
      s2[size2++] = arr[i];
    }

    else if(arr[i] < arr[index]){
      s1[size1++] = arr[i];
    }

    else {
      s3[size3++] = arr[i];
    }
  }

  if(k <= size1){
    for(int i=0;i<size1;i++){
      arr[i] = s1[i];
    }
    right = size1-1;
  }

  else if(k <= (size2 + size1)){
    return s2[0];
  }

  else {
    for(int i=0;i<size3;i++){
      arr[i] = s3[i];
    }
    right = size3 - 1;
    k = k - (size1+size2);
  }

  }
  return arr[left];
}



int main(){
  int arr[] = {1,4,5,3,6,7};
  printf("The 2nd smallest element is : %d",rec_median(arr,2,0,6-1));
}