#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

int compare(const void *a, const void *b) {
    double ratio_a = ((struct Item*)a)->value / (double)((struct Item*)a)->weight;
    double ratio_b = ((struct Item*)b)->value / (double)((struct Item*)b)->weight;
    return (ratio_b > ratio_a) ? 1 : -1;
}

double greedy_knapsack(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(struct Item), compare);

    double max_value = 0.0;
    int current_weight = 0;

    printf("Selecting Items :\n");


    for (int i = 0; i < n; i++) {
        if (current_weight + items[i].weight <= capacity) {
            current_weight += items[i].weight;
            max_value += items[i].value;
            printf("Added item { value: %4d , weight : %4d } to bag\n",items[i].value,items[i].weight);
        } else {
            double remaining_capacity = capacity - current_weight;
            max_value += (remaining_capacity / items[i].weight) * items[i].value;
            break;
        }
    }

    return max_value;
}

int main() {
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30},{50,10},{200,10}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    double max_value = greedy_knapsack(items, n, capacity);

    printf("Maximum value: %.2lf\n", max_value);

    return 0;
}
