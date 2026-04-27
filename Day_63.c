/*Problem: Perform DFS starting from a given source vertex using recursion.
Input:
- n
- adjacency list
- starting vertex s
Output:
- DFS traversal order*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int visited[MAX];
void DFS(int graph[MAX][MAX], int vertex, int n) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(graph, i, n);
        }
    }
}
int main() {
    int n, s;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int graph[MAX][MAX];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &s);
    printf("DFS Traversal: ");
    DFS(graph, s, n);
    return 0;
}
