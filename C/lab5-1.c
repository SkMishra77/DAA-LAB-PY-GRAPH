#include <stdio.h>
#include <stdlib.h>

// Get the maximum value in arr[]
int getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Using counting sort to sort the elements based on significant places
void countingSort(int arr[], int size, int place) {
    const int max = 10;
    int output[size];
    int count[max];

    for (int i = 0; i < max; i++) {
        count[i] = 0;
    }

    // Count the occurrences of elements based on place
    for (int i = 0; i < size; i++) {
        count[(arr[i] / place) % 10]++;
    }

    // Update count[i] to store the position of the next occurrence
    for (int i = 1; i < max; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] contains sorted numbers
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort
void radixSort(int arr[], int size) {
    int max = getMax(arr, size);

    // Perform counting sort for every digit
    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(arr, size, place);
    }
}

int main() {
    int arraySize;

    // Input array size from the user
    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);

    int myArray[arraySize];

    // Input array elements from the user
    printf("Enter %d elements for the array:\n", arraySize);
    for (int i = 0; i < arraySize; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &myArray[i]);
    }

    // Perform radix sort
    radixSort(myArray, arraySize);

    // Display the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    return 0;
}
