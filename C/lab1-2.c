#include <stdio.h>

// Function to perform recursive binary search
int recursiveBinarySearch(int arr[], int target, int low, int high) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        // Base case: element found
        if (arr[mid] == target) {
            return mid;
        }

        // Recursive case: search in the left or right half
        if (arr[mid] > target) {
            return recursiveBinarySearch(arr, target, low, mid - 1);
        } else {
            return recursiveBinarySearch(arr, target, mid + 1, high);
        }
    }

    // Base case: element not found
    return -1;
}

int main() {
    int arraySize;

    // Input array size from the user
    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);

    int myArray[arraySize];

    // Input array elements from the user
    printf("Enter %d sorted elements for the array:\n", arraySize);
    for (int i = 0; i < arraySize; ++i) {
        printf("Element %d: ", i + 1);
        scanf("%d", &myArray[i]);
    }

    int targetElement;

    // Input target element from the user
    printf("Enter the target element to search: ");
    scanf("%d", &targetElement);

    // Perform recursive binary search
    int result = recursiveBinarySearch(myArray, targetElement, 0, arraySize - 1);

    // Display the result
    if (result != -1) {
        printf("Element %d found at index %d.\n", targetElement, result);
    } else {
        printf("Element %d not found in the array.\n", targetElement);
    }

    return 0;
}
