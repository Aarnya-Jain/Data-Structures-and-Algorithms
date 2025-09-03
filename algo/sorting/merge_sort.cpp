#include <iostream>
using namespace std;

void merge_func(int arr[], int lower, int mid, int higher) {
    int n1 = mid - lower + 1;
    int n2 = higher - mid;

    // Temporary arrays
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[lower + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = lower;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    // Copy remaining
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void merge_sort(int arr[], int lower, int higher) {
    if (lower < higher) {
        int mid = (lower + higher) / 2;
        merge_sort(arr, lower, mid);
        merge_sort(arr, mid + 1, higher);
        merge_func(arr, lower, mid, higher);
    }
}

int main() {
    int arr[] = {2, 3, 2, 4, 3, 5, 2, 4, 2, 4, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
