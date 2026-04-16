/*Problem Statement:
Convert a binary tree into its mirror image by swapping left and right children at every node.
Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)
Output Format:
- Print inorder traversal of mirrored tree
Example:
Input:
7
1 2 3 4 5 6 7
Output:
7 3 6 1 5 2 4
Explanation:
Each node’s left and right children are swapped recursively.*/
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
void mirror(struct Node* root)
 {
    if (root == NULL) 
    {
        return;
    }
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}
void inorder(struct Node* root) 
{
    if (root == NULL) {
        return;

    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main() {
    int N;
    scanf("%d", &N);
    if (N <= 0) 
    {
        return 0;
    }
    struct Node* root = NULL;
    struct Node* queue[N];
    int front = 0, rear = 0;
    for (int i = 0; i < N; i++) {
        int data;
        scanf("%d", &data);
        if (data == -1) {
            continue;
        }
        struct Node* newNode = createNode(data);
        if (root == NULL) 
        {
            root = newNode;
        } 
        else 
        {
            if (queue[front]->left == NULL) 
            {
                queue[front]->left = newNode;
            } 
            else 
            {
                queue[front]->right = newNode;
                front++;
            }
        }
        queue[rear++] = newNode;
    }
    mirror(root);
    inorder(root);
    return 0;
}
