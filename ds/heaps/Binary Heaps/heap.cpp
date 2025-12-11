#include <iostream>
using namespace std;

#define capacity 100

// declaring
struct heap {
  int size = 0;
  int arr[capacity];
};

// printing heap
void print(heap * h){
  cout << "The Heap : ";
  for(int i=1;i<=h->size;i++){
    cout << h->arr[i] << " ";
  }
  cout << endl;
}

// printing the heap array
void print(int arr[],int n){
  cout << "The heapified array : ";
  for(int i=1;i<=n;i++) {
    cout << arr[i] << " ";
  }
}

// inserting into max_heap
void insert_max (heap * &h , int data) {
  ++ h->size;
  int index = h->size;
  h->arr[index] = data;

  while(index > 1) {
    int parent = index/2;

    if(h->arr[parent] < h->arr[index]){
      swap(h->arr[parent],h->arr[index]);
      index = parent; // Moving up to check if the heap order property is still maintained
    } else {
      break;
    }
  }
}

void delete_max(heap* &h) {
    if (h->size == 0) {
        cout << "Nothing to delete bro" << endl;
        return;
    }

    // replace root with last element
    swap(h->arr[1], h->arr[h->size]);
    h->size--;

    int index = 1;

    while (index <= h->size) {

        int largest = index;
        int left = 2*index;
        int right = (2*index)+1;

        // check if existing childs and if either is big
        if(left <= h->size && h->arr[largest] < h->arr[left]) {
          largest = left;
        }
        if (right <= h->size && h->arr[largest] < h->arr[right]){
          largest = right;
        }

        // if child bigger is found then largest changed means swap
        if (largest != index) {
            swap(h->arr[index], h->arr[largest]);
            index = largest;
        }
        else {
            break;
        }
    }
}


// making max heap
void make_max_heap(heap * &h) {
  cout << "Enter Data to insert ( -1 to exit ) : ";
  int response;
  cin >> response;

  while(response != -1) {
    insert_max(h,response);
    print(h);
    cin >> response;
  }
}


// Heapifying the array , recursively
void heapify(int arr[],int n, int index) {
  int largest = index;
  int left = 2* index;
  int right = (2*index)+1;

  // check if existing childs and either is big
  if(left <= n && arr[largest] < arr[left]) {
    largest = left;
  }
  if (right <= n && arr[largest] < arr[right]){
    largest = right;
  }

  // if not equal means big found
  if(largest!=index) {
    swap(arr[largest],arr[index]);
    heapify(arr,n,largest);
  }
  // else good
}

int main(){
  heap *h = new heap();
  make_max_heap(h);
  delete(h);

  cout << endl;
  int arr[7] = {0, 1, 2, 5, 2, 5, 998};
  int n = 6;

  // building
  for(int i=n/2; i>=1; i--) {
      heapify(arr, n, i);
  }

  print(arr, n);
  cout << endl;

  cout << "Exiting the program ..." << endl;
  return 0;
}
