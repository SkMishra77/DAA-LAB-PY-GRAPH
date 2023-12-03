#include <stdio.h>

int recursiveLinearSearch(int arr[], int target, int index, int size) {
    if (index == size) {
        return -1;
    }

    if (arr[index] == target) {
        return index;
    }

    return recursiveLinearSearch(arr, target, index + 1, size);
}

int main() {
    int arraySize;

    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);

    int myArray[arraySize];

    printf("Enter %d elements for the array:\n", arraySize);
    for (int i = 0; i < arraySize; ++i) {
        printf("Element %d: ", i + 1);
        scanf("%d", &myArray[i]);
    }

    int targetElement;

    printf("Enter the target element to search: ");
    scanf("%d", &targetElement);

    int result = recursiveLinearSearch(myArray, targetElement, 0, arraySize);

    if (result != -1) {
        printf("Element %d found at index %d.\n", targetElement, result);
    } else {
        printf("Element %d not found in the array.\n", targetElement);
    }

    return 0;
}
