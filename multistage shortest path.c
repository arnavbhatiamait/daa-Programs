#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

// Function to find the minimum cost path in a multistage graph
void shortestPath(int stages, int vertices, int graph[vertices][vertices]) {
    int cost[vertices], path[vertices];
    int i, j, k;

    // Initialize the cost of the last vertex to 0
    cost[vertices - 1] = 0;

    // Calculate the minimum cost for each vertex from the last stage to the first
    for (i = vertices - 2; i >= 0; i--) {
        cost[i] = INF;
        for (j = i + 1; j < vertices; j++) {
            if (graph[i][j] != INF && graph[i][j] + cost[j] < cost[i]) {
                cost[i] = graph[i][j] + cost[j];
                path[i] = j;
            }
        }
    }

    // Print the minimum cost
    printf("Minimum cost: %d\n", cost[0]);

    // Print the path
    printf("Path: ");
    i = 0;
    while (i < vertices - 1) {
        printf("%d -> ", i);
        i = path[i];
    }
    printf("%d\n", vertices - 1);
}

int main() {
    int stages = 4;
    int vertices = 8;
    int graph[8][8] = {
        {INF, 1, 2, 5, INF, INF, INF, INF},
        {INF, INF, INF, INF, 4, 11, INF, INF},
        {INF, INF, INF, INF, 9, 5, 16, INF},
        {INF, INF, INF, INF, INF, INF, 2, INF},
        {INF, INF, INF, INF, INF, INF, INF, 18},
        {INF, INF, INF, INF, INF, INF, INF, 13},
        {INF, INF, INF, INF, INF, INF, INF, 2},
        {INF, INF, INF, INF, INF, INF, INF, INF}
    };

    shortestPath(stages, vertices, graph);

    return 0;
}
