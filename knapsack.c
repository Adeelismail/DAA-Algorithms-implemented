#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int* knapsackDP(int n, int capacity, int weight[], int profit[]) {
    int **v = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
        v[i] = (int *)malloc((capacity + 1) * sizeof(int));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                v[i][w] = 0;
            else if (weight[i - 1] <= w)
                v[i][w] = max(v[i - 1][w], profit[i - 1] + v[i - 1][w - weight[i - 1]]);
            else
                v[i][w] = v[i - 1][w];
        }
    }

    int *result = (int *)malloc(n * sizeof(int));
    int i = n, w = capacity, idx = 0;
    while (i > 0 && w > 0) {
        if (v[i][w] != v[i - 1][w]) {
            result[idx++] = i;
            w = w - weight[i - 1];
            i--;
        } else {
            i--;
        }
    }

    for (int i = 0; i <= n; i++)
        free(v[i]);
    free(v);

    return result;
}

void knapsackGR(int n, int capacity, int weight[], int profit[]) {
    int *x = (int *)calloc(n, sizeof(int));

    int remaining_cap = capacity;
    int i = 0;
    for (i = 0; i < n; i++) {
        if (weight[i] > remaining_cap)
            break;
        x[i] = 1;
        remaining_cap = remaining_cap - weight[i];
    }

    if (i < n)
        x[i] = (remaining_cap / weight[i]);

    int max_profit = 0;
    for (int i = 0; i < n; i++) {
        max_profit += profit[i] * x[i];
    }

    printf("Max Profit = %d\n", max_profit);
    printf("Selected items: ");
    for (int i = 0; i < n; i++) {
        if (x[i] != 0)
            printf("%d ", i + 1);
    }
    printf("\n");

    free(x);
}

int main() {
    int weight[] = {3, 2, 4, 1};
    int profit[] = {100, 20, 60, 40};
    int n = sizeof(weight) / sizeof(weight[0]);
    int capacity = 5;

    printf("Knapsack using Dynamic Programming:\n");
    int *resultDP = knapsackDP(n, capacity, weight, profit);
    printf("Max Profit = %d\n", resultDP[n - 1]);
    printf("Selected items: ");
    for (int i = 0; i < n; i++) {
        if (resultDP[i] != 0)
            printf("%d ", resultDP[i]);
    }
    printf("\n\n");
    free(resultDP);

    printf("Knapsack using Greedy Approach:\n");
    knapsackGR(n, capacity, weight, profit);

    return 0;
}
