/*Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.
Input:
- n (vertices)
- m (edges)
- m pairs (u, v)
Output:
- n x n adjacency matrix*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void createGraph(int graph[MAX][MAX], int n, int m) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            graph[i][j] = 0; 
        }
    }
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < m; i++) 
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; 
    }
}
void printGraph(int graph[MAX][MAX], int n) 
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main() 
{
    int graph[MAX][MAX];
    int n, m;
    printf("Enter the number of vertices (n) and edges (m): ");
    scanf("%d %d", &n, &m);
    createGraph(graph, n, m);
    printGraph(graph, n);
    return 0;
}