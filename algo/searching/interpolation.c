// Can be preffered over binary search for sorted data if the data is distributed uniformly too .
// Binary Search goes to the middle element to check.
// On the other hand, Interpolation Search may go to different locations according to the value of the key being searched.

// Formula -> pos = low + [ (key-arr[low]) * (high - low) / (arr[high]-arr[low]) ]

// T(n) = O(log(log(n))) -- avg { better than binary }
// T(n) = O(n) -- worst { not uniformly distributed }
// S(n) = O(1)

#include <stdio.h>

int interpolation(int * arr,int key,int low,int high){
  if (low > high || arr[low] > key || arr[high] < key) // Extra cases for not found
        return -1;

    if (arr[low] == arr[high]) { // what if that single element also ain't equal to key
        if (arr[low] == key) return low;
        else return -1;
    }


  int pos = low + ( (key-arr[low]) * (high - low) / (arr[high]-arr[low]) );

  if(arr[pos] == key) return pos;
  if(arr[pos]>key) return interpolation(arr,key,low,pos-1);
  if(arr[pos]<key) return interpolation(arr,key,pos+1,high);

}

int main(){

}