/*Problem Statement
Using DFS or BFS, count number of connected components.
Input Format
n m
edge
Output Format
Number of connected components.
Sample Input
6 3
1 2
2 3
5 6
Sample Output
3
Explanation
Components: {1,2,3}, {4}, {5,6}*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int vertex;
    struct Node* next;
};
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
void DFS(struct Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    struct Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex]) {
            DFS(graph, adjVertex);
        }
        temp = temp->next;
    }
}
int countConnectedComponents(struct Graph* graph) {
    int count = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            DFS(graph, i);
            count++;
        }
    }
    return count;
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    struct Graph* graph = createGraph(n);
    for (int i = 0; i < m; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src - 1, dest - 1); // Adjusting for 0-based index
    }
    int result = countConnectedComponents(graph);
    printf("%d\n", result);
    return 0;
}
