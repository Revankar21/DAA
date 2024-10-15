#include <stdio.h>

#define MAX 100 // Define a maximum number of vertices

void bfs(int adjmatrix[MAX][MAX], int vertices, int start)
{
    int visited[MAX] = {0}; // Initialize visited array with zeros
    int current, i, queue[100], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front != rear)
    {
        current = queue[front++];
        printf("%d ", current);

        for (i = 0; i < vertices; ++i)
        {
            if (adjmatrix[current][i] && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int i, j, n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int adjmatrix[MAX][MAX]; // Use static 2D array

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adjmatrix[i][j]);
        }
    }


    int start;
    printf("Enter starting node: ");
    scanf("%d", &start);
    
    printf("BFS traversal:\n");
    bfs(adjmatrix, n, start);

    return 0;
}
