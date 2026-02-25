/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* deleteKey(struct Node* head, int key)
{
    struct Node *temp = head, *prev = NULL;
    while(temp && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if(!temp) 
    return head;    
    if(!prev) 
    head = temp->next;   // delete head
    else 
    prev->next = temp->next; 
    free(temp);
    return head;
}
int main()
{
    int n, x, key;
    struct Node *head=NULL, *tail=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        struct Node* node = malloc(sizeof(struct Node));
        node->data=x; node->next=NULL;
        if(!head) 
        head=tail=node;
        else 
        tail=tail->next=node;
    }
    scanf("%d",&key);
    head = deleteKey(head,key);
    while(head)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}
