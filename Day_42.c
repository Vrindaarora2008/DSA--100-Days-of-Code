/*Problem Statement:
Construct a Binary Tree from the given level-order traversal.
Input Format:
First line contains integer N
Second line contains N space-separated integers (-1 represents NULL)
Output Format:
Print inorder traversal of the constructed tree
Example:
Input:
7
1 2 3 4 5 -1 6
Output:
4 2 5 1 3 6*/
#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* constructTree(int* arr, int n) 
{
    if (n == 0) return NULL;
    struct Node** nodes = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++)
     {
        if (arr[i] != -1) 
        {
            nodes[i] = createNode(arr[i]);
        }
         else 
         {
            nodes[i] = NULL;
        }
    }
    for (int i = 0; i < n; i++) 
    {
        if (nodes[i] != NULL) 
        {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;
            if (leftIndex < n)
             {
                nodes[i]->left = nodes[leftIndex];
            }
            if (rightIndex < n) 
            {
                nodes[i]->right = nodes[rightIndex];
            }
        }
    }
    struct Node* root = nodes[0];
    free(nodes);
    return root;
}
void inorderTraversal(struct Node* root) 
{
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right
);
}
int main() 
{
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = constructTree(arr, n);
    inorderTraversal(root);
    printf("\n");
    free(arr);
    return 0;
}