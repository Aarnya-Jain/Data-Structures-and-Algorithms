/*
  The selection of pivot highly determines the complexity of the solution
  Like some common ways are  : p = start ( as we did here )
                              p = end
                              p = 3-median ->  (start+middle+end) / 3 : start < middle < end
*/

#include<stdio.h>

int partition(int * arr,int start,int end){
  // first get the count of elements smaller than pivot
  int cnt = 0;
  int pivot = arr[start];
  int pivotindex;

  for(int i=start;i<=end;i++){
    if(arr[i]<pivot){
      cnt++;
    }
  }

  pivotindex = start + cnt;
  // swap with that
  int temp = arr[start];
  arr[start] = arr[pivotindex];
  arr[pivotindex] = temp;

  int i=start;
  int j=end;

  while (i < pivotindex && j > pivotindex) {
        if (arr[i] <= pivot) {
            i++;
        } else if (arr[j] > pivot) {
            j--;
        } else {
            // Swap
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i++;
            j--;
        }
    }


  // the array is partitioned
  // now return the pivotindex

  return pivotindex;
}

void quick_sort(int * arr,int start,int end){
  // base case
  if(start>=end){
    return;
  }

  int p = partition(arr,start,end);

  quick_sort(arr,start,p-1);
  quick_sort(arr,p+1,end);
}

int main(){
  int arr[] = {2, 3, 2, 4, 3, 5, 2, 4, 2, 4, 3, 2, 4};
  for(int i=0;i<13;i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
  quick_sort(arr,0,13-1);
  for(int i=0;i<13;i++){
    printf("%d ",arr[i]);
  }
  printf("\n");

}