/*Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.
Input:
- n (vertices)
- m (edges)
- edges (u, v)
Output:
- List of adjacency lists for each vertex*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
// Structure for a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
// Structure for the graph
typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
} Graph;
// Function to create a new graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}
// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    // Add edge from dest to src (for undirected graph)
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
// Function to print the adjacency list of the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main() {
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    Graph* graph = createGraph(n);
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }
    printf("Adjacency List:\n");
    printGraph(graph);
    return 0;
}
