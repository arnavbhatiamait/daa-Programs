// 0/1 Knapsack Problem using Dynamic programming in c
#include <stdio.h>
int max(int x, int y) { return (x > y) ? x : y; }
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main()
{
    int n, we;
    printf("Enter the max weight:\n");
    scanf("%d", &we);
    printf("\nEnter the number of items:\n");
    scanf("%d", &n);
    int wt[n], val[n];
    printf("\nEnter the weight of each item:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &wt[i]);
    printf("\nEnter the value of each item:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]);
    int val_returned = knapSack(we, wt, val, n);
    printf("\nThe maximum value is %d\n", val_returned);
    return 0;
}