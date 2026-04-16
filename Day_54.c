/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.
Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)
Output Format:
- Print traversal in zigzag order
Example:
Input:
7
1 2 3 4 5 6 7
Output:
1 3 2 4 5 6 7
Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.*/
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
void zigzagTraversal(struct Node* root) {
    if (root == NULL) return;
    struct Node* currentLevel[100];
    struct Node* nextLevel[100];
    int currentIndex = 0, nextIndex = 0;
    int leftToRight = 1; // Start with left-to-right
    currentLevel[currentIndex++] = root;
    while (currentIndex > 0) {
        struct Node* node = currentLevel[--currentIndex];
        printf("%d ", node->data);
        if (leftToRight) {
            if (node->left) nextLevel[nextIndex++] = node->left;
            if (node->right) nextLevel[nextIndex++] = node->right;
        } else {
            if (node->right) nextLevel[nextIndex++] = node->right;
            if (node->left) nextLevel[nextIndex++] = node->left;
        }
        if (currentIndex == 0) {
            leftToRight = !leftToRight; // Toggle direction
            for (int i = 0; i < nextIndex; i++) {
                currentLevel[i] = nextLevel[i];
            }
            currentIndex = nextIndex;
            nextIndex = 0;
        }
    }
}
int main() {
    int N;
    scanf("%d", &N);
    struct Node* root = NULL;
    struct Node* nodes[100];
    for (int i = 0; i < N; i++) {
        int data;
        scanf("%d", &data);
        if (data != -1) {
            nodes[i] = createNode(data);
            if (i == 0) {
                root = nodes[i];
            } else {
                int parentIndex = (i - 1) / 2;
                if (i % 2 == 1) {
                    nodes[parentIndex]->left = nodes[i];
                } else {
                    nodes[parentIndex]->right = nodes[i];
                }
            }
        } else {
            nodes[i] = NULL;
        }
    }
    zigzagTraversal(root);
    return 0;
}