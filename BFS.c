#include <stdio.h>
#include <stdlib.h>

// Global variables
int a[20][20], q[20] = {0}, visited[20] = {0}, n, i, j, f = 0, r = -1;

// Breadth-First Search (BFS) function
void bfs(int v)
{
    // Explore all adjacent vertices of the current vertex
    for (i = 0; i < n; i++)
    {
        if (a[v][i] == 1 && visited[i] == 0)
        {
            // Add unvisited adjacent vertices to the queue
            q[++r] = i;
            visited[i] = 1;
        }
    }

    // If there are still vertices in the queue, recursively call BFS
    if (f <= r)
    {
        bfs(q[f++]);
    }
}

int main()
{
    int v;

    printf("\n Enter The number of vertices: ");
    scanf("%d", &n);

    printf("\n ENTER GRAPH DATA IN MATRIX FORM:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n Enter the starting vertex: ");
    scanf("%d", &v);

    // Perform BFS starting from the given vertex
    bfs(v);

    int allReachable = 1;

    // Print the visited vertices (reachable nodes)
    for (i = 0; i < n; i++)
    {
        if (visited[i])
        {
            printf("%d\t", i);
        }
        else
        {
            // If any node is not visited, set allReachable to 0
            allReachable = 0;
            break;
        }
    }

    // Check if all nodes are reachable
    if (!allReachable)
    {
        printf("\n BFS is not possible. Not all nodes are reachable.\n");
    }

    return 0;
}
