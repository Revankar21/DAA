#include <stdio.h>


// Function to print the shortest distance matrix
void printSolution(int dist[][100], int V) {
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == 999)
                printf("%7s", "999");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

// Floyd-Warshall algorithm to find shortest paths
void floydWarshall(int graph[][100], int V) {
    int dist[100][100], i, j, k;

    // Initialize the solution matrix same as the input graph matrix
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Update the solution matrix by considering all vertices as intermediate vertices
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist, V);
}

int main() {
    int V;

    // Prompt user for the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[100][100];

    // Prompt user to enter the adjacency matrix
    printf("Enter the adjacency matrix (use 999 to represent Infinity):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Execute Floyd-Warshall algorithm
    floydWarshall(graph, V);

    return 0;
}
