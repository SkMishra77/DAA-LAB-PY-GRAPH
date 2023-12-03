#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arraySize;

    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);

    int myArray[arraySize];

    printf("Enter %d elements for the array:\n", arraySize);
    for (int i = 0; i < arraySize; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &myArray[i]);
    }

    insertionSort(myArray, arraySize);

    printf("Sorted array: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    return 0;
}