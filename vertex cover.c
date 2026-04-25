#include <stdio.h>
#define V 5 // Number of vertices in our graph

/* A simple greedy approach to find a Vertex Cover.
 * It follows a 2-approximation strategy.
 */
void findVertexCover(int graph[V][V])
{
    int visited[V]; // Array to represent our Cover Set 'C'

    // Start with an empty set C by marking all vertices as "unmarked = 0"
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }

    // Repeat until no unmarked edges remain
    // Scan every possible edge (u, v)
    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            // graph[u][v] == 1 --> Edge exists
            // !visited[u] && !visited[v] --> Both endpoints are unmarked
            if (graph[u][v] == 1 && !visited[u] && !visited[v])
            {
                // Add BOTH endpoints to cover set C
                visited[u] = 1;
                visited[v] = 1;

                /*
                No need to explicitly remove edges.
                Once u and v are marked visited,
                future checks automatically skip their edges.
                */
            }
        }
    }

    // Print the Cover Set C
    printf("Approximate Vertex Cover: ");
    int count = 0;
    for (int i = 0; i < V; i++)
    {
        if (visited[i])
        {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nTotal vertices in the cover: %d\n", count);
}

int main()
{
    // Adjacency Matrix representation
    int graph[V][V] = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}};

    printf("Executing Vertex Cover Approximation...\n");
    findVertexCover(graph);

    return 0;
}
