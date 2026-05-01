/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.
Input Format
n m
u v w
source
Output Format
Distances to all vertices.
Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1
Sample Output
0 2 3 9 6*/
#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 1000
int graph[INT_MAX][INT_MAX];
int dist[INT_MAX];
int visited[INT_MAX];
void dijkstra(int source, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[source] = 0;
    for (int count = 0; count < n - 1; count++) 
    {
        int minDist = INT_MAX, minIndex;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] < minDist) 
            {
                minDist = dist[v];
                minIndex = v;
            }
        }
        visited[minIndex] = 1;
        for (int v = 0; v < n; v++) 
        {
            if (!visited[v] && graph[minIndex][v] && dist[minIndex] != INT_MAX &&
                dist[minIndex] + graph[minIndex][v] < dist[v]) 
                {
                dist[v] = dist[minIndex] + graph[minIndex][v];
            }
        }
    }
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) 
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u - 1][v - 1] = w;
        graph[v - 1][u - 1] = w; 
    }
    int source;
    scanf("%d", &source);
    dijkstra(source - 1, n);
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", dist[i]);
    }
    return 0;
}
