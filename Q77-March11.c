/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.
Supported Operations:
insert x
extractMin
peek
Input Format:
First line contains integer N
Next N lines contain heap operations
Output Format:
Print results of extractMin and peek
Print -1 if operation cannot be performed
Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek
Output:
10
10
30*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
typedef struct MinHeap {
    int size;
    int arr[MAX_SIZE];
} MinHeap;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyUp(MinHeap *heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->arr[index] < heap->arr[parent]) {
            swap(&heap->arr[index], &heap->arr[parent]);
            index = parent;
        } else {
            break;
        }
    }
}
void heapifyDown(MinHeap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < heap->size && heap->arr[left] < heap->arr[smallest]) {
        smallest = left;
    }
    if (right < heap->size && heap->arr[right] < heap->arr[smallest]) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}
void insert(MinHeap *heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("-1\n");
        return;
    }
    heap->arr[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}
int extractMin(MinHeap *heap) {
    if (heap->size == 0) {
        return -1;
    }
    int min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return min;
}
int peek(MinHeap *heap) {
    if (heap->size == 0) {
        return -1;
    }
    return heap->arr[0];
}
int main() {
    MinHeap heap;
    heap.size = 0;
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char operation[10];
        scanf("%s", operation);
        if (strcmp(operation, "insert") == 0) {
            int value;
            scanf("%d", &value);
            insert(&heap, value);
        } else if (strcmp(operation, "extractMin") == 0) {
            int min = extractMin(&heap);
            printf("%d\n", min);
        } else if (strcmp(operation, "peek") == 0) {
            int min = peek(&heap);
            printf("%d\n", min);
        }
    }
    return 0;
}
