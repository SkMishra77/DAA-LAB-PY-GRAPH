#include <stdio.h>
#include <stdbool.h>

bool isSubsetSum(int set[], int n, int sum) {
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    if (set[n - 1] > sum)
        return isSubsetSum(set, n - 1, sum);

    return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

int main() {
    int n, sum;

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int set[n];

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &sum);

    if (isSubsetSum(set, n, sum)) {
        printf("Found a subset with the given sum\n");
    } else {
        printf("No subset with the given sum\n");
    }

    return 0;
}
