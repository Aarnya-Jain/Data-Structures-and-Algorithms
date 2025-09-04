#include<stdio.h>

void insertion_sort(int * arr,int size){
  int temp;
  for(int i=1;i<size;i++){
    temp = arr[i];
    int j = i-1;
    while(temp<arr[j] && j>=0){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = temp;
  }
}

int main(){
  int arr[] = {2,1,4,2,4};
  for(int i=0;i<5;i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
  insertion_sort(arr,5);
  for(int i=0;i<5;i++){
    printf("%d ",arr[i]);
  }
  printf("\n");

}