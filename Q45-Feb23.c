#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data) 
{
    struct Node* n = malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}
struct Node* merge(struct Node* a, struct Node* b) 
{
    if (!a) 
    return b;
    if (!b) 
    return a;
    if (a->data < b->data) 
    {
        a->next = merge(a->next, b);
        return a;
    }
     else 
     {
        b->next = merge(a, b->next);
        return b;
    }
}
void print(struct Node* head) 
{
    while (head) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
int main() 
{
    int n, m, x;
    struct Node *h1=NULL, *t1=NULL, *h2=NULL, *t2=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        struct Node* n1=createNode(x);
        if(!h1) 
        h1=t1=n1;
        else 
        t1=t1->next=n1;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&x);
        struct Node* n2=createNode(x);
        if(!h2) h2=t2=n2;
        else t2=t2->next=n2;
    }
    struct Node* result = merge(h1,h2);
    print(result);
    return 0;
}