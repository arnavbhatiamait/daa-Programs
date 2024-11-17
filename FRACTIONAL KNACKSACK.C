#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
    double ratio;  // Value-to-weight ratio
} Item;

// Comparison function for sorting items based on their ratio
int compare(const void *a, const void *b) {
    double ratioA = ((Item *)a)->ratio;
    double ratioB = ((Item *)b)->ratio;
    return (ratioB - ratioA > 0) - (ratioB - ratioA < 0);
}

// Function to solve the Fractional Knapsack Problem
double fractional_knapsack(Item items[], int n, int capacity) {
    // Calculate ratio for each item
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    // Sort items based on value-to-weight ratio in descending order
    qsort(items, n, sizeof(Item), compare);

    double total_value = 0.0;
    int remaining_capacity = capacity;

    // Iterate through sorted items
    for (int i = 0; i < n && remaining_capacity > 0; i++) {
        if (items[i].weight <= remaining_capacity) {
            // Take the whole item
            total_value += items[i].value;
            remaining_capacity -= items[i].weight;
        } else {
            // Take the fraction of the item
            double fraction = (double)remaining_capacity / items[i].weight;
            total_value += items[i].value * fraction;
            remaining_capacity = 0;  // Knapsack is now full
        }
    }

    return total_value;
}

int main() {
    // Example items
    Item items[] = {
        {40, 10, 0.0},
        {100, 20, 0.0},
        {120, 30, 0.0}
    };
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    double max_value = fractional_knapsack(items, n, capacity);
    printf("Maximum value in knapsack: %.2f\n", max_value);

    return 0;
}
