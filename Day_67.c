/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int graph[MAX][MAX], visited[MAX], stack[MAX], top = -1, n;
void dfs(int v) 
{
    visited[v] = 1;
    for (int i = 0; i < n; i++) 
    {
        if (graph[v][i] == 1 && !visited[i]) 
        {
            dfs(i);
        }
    }
    stack[++top] = v;
}
void topologicalSort() {
    for (int i = 0; i < n; i++) 
    {
        if (!visited[i])
     {
            dfs(i);
        }
    }
    printf("Topological Order: ");
    for (int i = top; i >= 0; i--)
     {
        printf("%d ", stack[i]);
    }
}
int main() 
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &graph[i][j]);
        }
    }
    topologicalSort();
    return 0;
}