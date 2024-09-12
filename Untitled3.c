#include <stdio.h>
#include <stdlib.h>

void sortArray(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int find3rdLargestIndex(int arr[], int n) {
    // Create a copy of the array to sort
    int* sortedArr = (int*)malloc(n * sizeof(int));
    if (sortedArr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }


    for (int i = 0; i < n; i++) {
        sortedArr[i] = arr[i];
    }


    sortArray(sortedArr, n);

    int thirdLargest = sortedArr[n - 3];

    free(sortedArr);


    for (int i = 0; i < n; i++) {
        if (arr[i] == thirdLargest) {
            return i;
        }
    }


    return -1;
}

void insertValue(int arr[], int* n, int index, int value) {

    (*n)++;

    for (int i = *n - 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
}

int main() {
    int arr[] = {10, 20, 5, 8, 30, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int valueToInsert = 15;


    int index = find3rdLargestIndex(arr, n);


    if (index != -1) {
        insertValue(arr, &n, index, valueToInsert);
    }

    printf("Updated Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
