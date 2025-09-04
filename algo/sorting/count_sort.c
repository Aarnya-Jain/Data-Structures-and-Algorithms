#include <stdio.h>
#include <stdlib.h>

void count_sort(int *arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int *freq = calloc(max + 1, sizeof(int));

    for (int i = 0; i < size; i++) {
        freq[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (freq[i] > 0) {
            arr[index++] = i;
            freq[i]--;
        }
    }

    free(freq);
}

int main() {
    int arr[] = {5, 3, 6, 2, 5, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    count_sort(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
