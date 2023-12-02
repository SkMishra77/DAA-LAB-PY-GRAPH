#include <stdio.h>

// Function to perform recursive linear search
int recursiveLinearSearch(int arr[], int target, int index, int size) {
    // Base case: element not found
    if (index == size) {
        return -1;
    }

    // Base case: element found
    if (arr[index] == target) {
        return index;
    }

    // Recursive case: continue searching
    return recursiveLinearSearch(arr, target, index + 1, size);
}

int main() {
    int arraySize;

    // Input array size from the user
    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);

    int myArray[arraySize];

    // Input array elements from the user
    printf("Enter %d elements for the array:\n", arraySize);
    for (int i = 0; i < arraySize; ++i) {
        printf("Element %d: ", i + 1);
        scanf("%d", &myArray[i]);
    }

    int targetElement;

    // Input target element from the user
    printf("Enter the target element to search: ");
    scanf("%d", &targetElement);

    // Perform recursive linear search
    int result = recursiveLinearSearch(myArray, targetElement, 0, arraySize);

    // Display the result
    if (result != -1) {
        printf("Element %d found at index %d.\n", targetElement, result);
    } else {
        printf("Element %d not found in the array.\n", targetElement);
    }

    return 0;
}
