#include <stdio.h>

struct Item
{
    int value;
    int weight;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsackDP(int capacity, const struct Item items[], int n)
{
    int dp[n + 1][capacity + 1];
    int isSelected[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
                isSelected[i][w] = 0;
            }
            else if (items[i - 1].weight <= w)
            {
                int include = items[i - 1].value + dp[i - 1][w - items[i - 1].weight];
                int exclude = dp[i - 1][w];

                if (include > exclude)
                {
                    dp[i][w] = include;
                    isSelected[i][w] = 1;
                }
                else
                {
                    dp[i][w] = exclude;
                    isSelected[i][w] = 0;
                }
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
                isSelected[i][w] = 0;
            }
        }
    }

    printf("Selected items: \n");

    int i = n, w = capacity;

    while (i > 0 && w > 0)
    {
        if (isSelected[i][w])
        {
            printf("Item { value: %d , weight: %d} \n", items[i - 1].value, items[i - 1].weight);
            w -= items[i - 1].weight;
        }
        i--;
    }
    printf("\n");

    return dp[n][capacity];
}

int main()
{
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}, {50, 10}, {200, 10}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    int max_value = knapsackDP(capacity, items, n);

    printf("Maximum value: %d\n", max_value);

    return 0;
}
