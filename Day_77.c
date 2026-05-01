/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.
Input Format
n m
edges
Output Format
CONNECTED
NOT CONNECTED
Sample Input
4 2
1 2
3 4
Sample Output
NOT CONNECTED*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
void DFS(int vertex, int n) 
{
    visited[vertex] = 1;
    for (int i = 0; i < n; i++) 
    {
        if (graph[vertex][i] == 1 && !visited[i]) 
        {
            DFS(i, n);
        }
    }
}
int main() 
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }
    for (int i = 0; i < m; i++) 
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u-1][v-1] = 1; 
        graph[v-1][u-1] = 1; 
    }
    DFS(0, n);
    int connected = 1;
    for (int i = 0; i < n; i++) 
    {
        if (!visited[i]) 
        {
            connected = 0;
            break;
        }
    }
    if (connected) 
    {
        printf("CONNECTED\n");
    } else {
        printf("NOT CONNECTED\n");
    }
    return 0;
}
