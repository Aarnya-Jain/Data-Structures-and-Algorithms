/*
    Worst Case Complexity: O(n^2)
    When there are elements of close range in the array, they are likely to be placed in the same bucket.
    This may result in some buckets having more number of elements than others.

    Best Case Complexity: O(n+k)
    It occurs when the elements are uniformly distributed in the buckets with a nearly equal number of
    elements in each bucket.

    Average Case Complexity: O(n)
    It occurs when the elements are distributed randomly in the array. Even if the elements are not
    distributed uniformly, bucket sort runs in linear time
*/

#include <stdio.h>
#include <stdlib.h>

void insertion_sort(float *arr, int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucket_sort(float *arr, int n) {
    int bucket_count = n;
    float **buckets = malloc(bucket_count * sizeof(float *));
    int *sizes = calloc(bucket_count, sizeof(int));

    for (int i = 0; i < bucket_count; i++) {
        buckets[i] = malloc(n * sizeof(float));
    }

    for (int i = 0; i < n; i++) {
        int idx = (int)(arr[i] * bucket_count);
        if (idx >= bucket_count) idx = bucket_count - 1;
        buckets[idx][sizes[idx]++] = arr[i];
    }

    for (int i = 0; i < bucket_count; i++) {
        if (sizes[i] > 0) {
            insertion_sort(buckets[i], sizes[i]);
        }
    }

    int index = 0;
    for (int i = 0; i < bucket_count; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }

    free(buckets);
    free(sizes);
}

int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    return 0;
}
