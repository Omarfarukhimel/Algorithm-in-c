#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int total;

// Depth-First Search (DFS) function
void DFS(int vertex);

int main()
{
    int i, j;

    printf("Enter the total number of vertices in the graph: ");
    scanf("%d", &total);

    // Adjacency matrix input
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < total; i++) {
        for (j = 0; j < total; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize visited array to 0 (not visited)
    for (i = 0; i < total; i++) {
        visited[i] = 0;
    }

    printf("\nDFS traversal:\n");
    DFS(0); // Perform DFS starting from vertex 0

    return 0;
}

void DFS(int vertex)
{
    int j;
    printf("%d\t", vertex); // Print the current vertex
    visited[vertex] = 1; // Mark the vertex as visited

    // Explore all adjacent vertices of the current vertex
    for (j = 0; j < total; j++) {
        if (!visited[j] && graph[vertex][j] == 1) {
            // If an adjacent vertex is not visited and there is an edge, recursively call DFS
            DFS(j);
        }
    }
}
