/*Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.
Input Format:
- First line contains integer N
- Second line contains level-order traversal
Output Format:
- Print YES if valid Min-Heap, otherwise NO
Example:
Input:
7
1 3 5 7 9 8 10
Output:
YES
Explanation:
Each parent node must be smaller than its children.*/
#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int isMinHeap(struct Node* root) {
    if (root == NULL) {
        return 1; // An empty tree is a Min-Heap
    }
    int leftData = (root->left != NULL) ? root->left->data : INT_MAX;
    int rightData = (root->right != NULL) ? root->right->data : INT_MAX;
    if (root->data > leftData || root->data > rightData) {
        return 0; // Not a Min-Heap
    }
    return isMinHeap(root->left) && isMinHeap(root->right);
}
int main() {
    int N;
    scanf("%d", &N);
    if (N <= 0) {
        printf("YES\n"); // An empty tree is a Min-Heap
        return 0;
    }
    struct Node* root = NULL;
    struct Node* queue[N];
    int front = 0, rear = 0;
    for (int i = 0; i < N; i++) {
        int data;
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        if (root == NULL) {
            root = newNode;
        } else {
            if (queue[front]->left == NULL) {
                queue[front]->left = newNode;
            } else {
                queue[front]->right = newNode;
                front++;
            }
        }
        queue[rear++] = newNode;
    }
    if (isMinHeap(root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
