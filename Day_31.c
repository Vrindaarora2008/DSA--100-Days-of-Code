/*Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.
Input:
First line: integer n (number of operations)
Next n lines: operation type and value (if applicable)
1 value: push value
2: pop
3: display
Output:
For display: print stack elements from top to bottom
For pop: print popped element or 'Stack Underflow'*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
int TOP=-1;
void pop();
void push();
void traverse();
int main()
{
    int choice, n;
    while(1) {
        printf("1-Push\n 2-Pop\n 3-Traversal\n 4-Exit");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            printf("Enter value to insert\n");
            scanf("%d", &n);
            push(n);
            break;
            case 2:
            pop();
            break;
            case 3:
            traverse();
            break;
            default:
            exit;
        }
    }
}
void push(int a)
{
    if(TOP == MAX-1)
    {
        printf("Overflow");
    }
    else
    {
        TOP = TOP-1;
    }
}
void pop()
{
    if(TOP==-1)
    {
        printf("Underflow");
    }
    else {
        TOP = TOP-1;
    }
}
void traverse()
{
    if(TOP==-1)
    {
        printf("Underrflow");
     }
     else{
        for(int i=TOP; i<=0; i--)
        {
            printf("%d", stack[i]);
        }
     }
}