/*Problem: Perform BFS from a given source using queue.
Input:
- n
- adjacency list
- source s
Output:
- BFS traversal order*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
// Queue implementation
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}
int isEmpty(Queue* q) {
    return q->front == -1;
}
int isFull(Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
}
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}
// BFS implementation
void bfs(int graph[MAX][MAX], int n, int s) {
    int visited[MAX] = {0};
    Queue q;
    initQueue(&q);
    visited[s] = 1;
    enqueue(&q, s);
    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
}
int main() {
    int n, s;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int graph[MAX][MAX] = {0};
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter source vertex: ");
    scanf("%d", &s);
    printf("BFS Traversal: ");
    bfs(graph, n, s);
    return 0;
}
