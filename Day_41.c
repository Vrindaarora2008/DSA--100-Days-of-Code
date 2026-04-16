/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.
Input Format:
First line contains integer N
Second line contains N space-separated integers
Output Format:
Print the reversed queue
Example:
Input:
5
10 20 30 40 50
Output:
50 40 30 20 10*/
#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Queue {
    struct Node* front;
    struct Node* rear;
};
struct Stack {
    struct Node* top;
};
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
struct Stack* createStack() {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->top = NULL;
    return s;
}
void enqueue(struct Queue* q, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return -1; // Queue is empty
    }
    struct Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL; // Queue is now empty
    }
    free(temp);
    return value;
}
void push(struct Stack* s, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = s->top;
    s->top = temp;
}
int pop(struct Stack* s) {
    if (s->top == NULL) {
        return -1; // Stack is empty
    }
    struct Node* temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}
void reverseQueue(struct Queue* q) {
    struct Stack* s = createStack();
    while (q->front != NULL) {
        push(s, dequeue(q));
    }
    while (s->top != NULL) {
        enqueue(q, pop(s));
    }
}
int main() {
    int N, value;
    scanf("%d", &N);
    struct Queue* q = createQueue();
    for (int i = 0; i < N; i++) {
        scanf("%d", &value);
        enqueue(q, value);
    }
    reverseQueue(q);
    while (q->front != NULL) {
        printf("%d ", dequeue(q));
    }
    return 0;
}
