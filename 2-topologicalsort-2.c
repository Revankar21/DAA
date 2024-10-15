#include <stdio.h>
#include <stdlib.h>

int v[10]={0};          // Visited array to mark visited nodes
int stack[10];      // Stack to store the topological sort order
int top = -1;       // Top of the stack



// Function for Depth First Search
void dfs(int node, int n, int a[10][10]) {
    v[node] = 1;    // Mark the current node as visited
    for (int i = 0; i < n; i++) {
        if (a[node][i] == 1 && v[i]==0) {
            dfs(i, n, a);  // Recur for all the vertices adjacent to this vertex
        }
    }
    stack[++top] = node;  // Push the current node to the stack after visiting all its adjacent vertices
}

// Function to perform topological sorting
void topoSort(int n, int a[10][10]) {
    // for (int i = 0; i < n; i++) {
    //     v[i] = 0;  // Initialize all vertices as not visited
    // }
    // int v[n]= {0};
    for (int i = 0; i < n; i++) {
        if (v[i]==0) {
            dfs(i, n, a);  // Call DFS for every unvisited node
        }
    }
}

int main() {
    int n, a[10][10];
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    topoSort(n, a);  
    
    printf("The topological order is: ");
    while (top != -1) {
        printf("%d ", stack[top--]);  // Pop from the stack to get the topological order
    }
    
    return 0;
}

