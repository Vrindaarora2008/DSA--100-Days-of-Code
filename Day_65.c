/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.
Output:
YES or NO*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};
void initGraph(struct Graph* graph, int vertices) {
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; 
}
int isCyclicUtil(struct Graph* graph, int vertex, int visited[], int parent) {
    visited[vertex] = 1;
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i]) {
            if (!visited[i]) {
                if (isCyclicUtil(graph, i, visited, vertex)) {
                    return 1;
                }
            } else if (i != parent) {
                return 1; 
            }
        }
    }
    return 0;
}
int isCyclic(struct Graph* graph) {
    int visited[MAX_VERTICES] = {0};
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(graph, i, visited, -1)) {
                return 1; 
            }
        }
    }
    return 0; 
}
int main() 
{
    struct Graph graph;
    int vertices, edges, src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    initGraph(&graph, vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }
    if (isCyclic(&graph)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
