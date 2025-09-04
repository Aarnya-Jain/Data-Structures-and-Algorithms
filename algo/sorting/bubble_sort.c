#include <stdio.h>

void bubble_sort(int * arr,int size){
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      if(arr[i]<arr[j]){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main(){
  int arr[] = {2,1,4,2,4};
  for(int i=0;i<5;i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
  bubble_sort(arr,5);
  for(int i=0;i<5;i++){
    printf("%d ",arr[i]);
  }
  printf("\n");

}