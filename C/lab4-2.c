#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int* count = (int*)malloc((max + 1) * sizeof(int));

    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    int k = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[k++] = i;
            count[i]--;
        }
    }

    free(count);
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

    countingSort(myArray, arraySize);

    printf("Sorted array: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    return 0;
}
