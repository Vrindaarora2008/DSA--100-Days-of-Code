/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.
Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal
Output Format:
- Print postorder traversal of constructed tree
Example:
Input:
5
1 2 4 5 3
4 2 5 1 3
Output:
4 5 2 3 1
Explanation:
Preorder identifies root, inorder splits left and right subtrees.*/
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
struct Node* buildTree(int* preorder, int* inorder, int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) {
        return NULL;
    }
    struct Node* node = createNode(preorder[*preIndex]);
    (*preIndex)++;
    if (inStart == inEnd) {
        return node;
    }
    int inIndex;
    for (inIndex = inStart; inIndex <= inEnd; inIndex++) {
        if (inorder[inIndex] == node->data) {
            break;
        }
    }
    node->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    node->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);
    return node;
}
void postorderTraversal(struct Node* root) {
    if (root == NULL) 
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}
int main() {
    int N;
    scanf("%d", &N);
    int preorder[N], inorder[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &preorder[i]);
    }
    for (int i = 0; i < N; i++) 
    {
        scanf("%d", &inorder[i]);
    }
    int preIndex = 0;
    struct Node* root = buildTree(preorder, inorder, 0, N - 1, &preIndex);
    postorderTraversal(root);
    return 0;
}
