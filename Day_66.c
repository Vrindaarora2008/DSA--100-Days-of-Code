/*Problem: Detect cycle in directed graph using DFS and recursion stack.
Output:
YES if cycle exists*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int graph[MAX][MAX], visited[MAX], recStack[MAX], n;
int isCyclicUtil(int v) {
    if(visited[v] == 0) {
        visited[v] = 1;
        recStack[v] = 1;
        for(int i = 0; i < n; i++) {
            if(graph[v][i]) {
                if(!visited[i] && isCyclicUtil(i))
                    return 1;
                else if(recStack[i])
                    return 1;
            }
        }
    }
    recStack[v] = 0;
    return 0;
}
int isCyclic() {
    for(int i = 0; i < n; i++) {
        if(isCyclicUtil(i))
            return 1;
    }
    return 0;
}
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    if(isCyclic())
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
