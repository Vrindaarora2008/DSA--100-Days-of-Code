/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.
Input Format:
First line contains integer N
Second line contains N space-separated integers
Third line contains two node values
Output Format:
Print the LCA value
Example:
Input:
7
6 2 8 0 4 7 9
2 8
Output:
6*/
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
struct Node* insert(struct Node* root, int data) 
{
    if (root == NULL) 
    {
        return createNode(data);
    }
    if (data < root->data) 
    {
        root->left = insert(root->left, data);
    } 
    else 
    {
        root->right = insert(root->right, data);
    }
    return root;
}
