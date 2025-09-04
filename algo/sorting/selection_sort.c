#include<stdio.h>

void selection_sort(int * arr, int size){
  int min;
  int index_min;
  for(int i=0;i<size;i++){
    min = arr[i];
    for(int j=i;j<size;j++){
      if(arr[j]<min){
        min = arr[j];
        index_min = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[index_min];
    arr[index_min] = temp;
  }
}

int main(){
  int arr[] = {2,1,4,2,4};
  for(int i=0;i<5;i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
  selection_sort(arr,5);
  for(int i=0;i<5;i++){
    printf("%d ",arr[i]);
  }
  printf("\n");

}