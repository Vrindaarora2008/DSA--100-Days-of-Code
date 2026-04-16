/*Problem: BST Search
Implement the solution for this problem.
Input:
Input specifications
Output:
Output specifications*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void search(struct Node* root, int key) {
    if (root == NULL) {
        printf("Key not found in the BST.\n");
        return;
    }
    if (root->data == key) {
        printf("Key found in the BST.\n");
        return;
    }
    if (key < root->data) {
        search(root->left, key);
    } else {
        search(root->right, key);
    }
}

