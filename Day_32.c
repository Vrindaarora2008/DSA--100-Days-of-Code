/*Problem: Implement push and pop operations on a stack and verify stack operations.
Input:
First line: integer n
Second line: n integers to push
Third line: integer m (number of pops)
Output:
Print remaining stack elements from top to bottom*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
int TOP=-1;
void pop();
void push();
int main()
{
    int choice, n;
    while(1) {
        printf("1-Push\n 2-Pop\n 3-Exit");
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