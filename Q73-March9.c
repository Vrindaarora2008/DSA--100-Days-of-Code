/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.
Supported Operations:
insert x
delete
peek
Input Format:
First line contains integer N
Next N lines contain operations
Output Format:
Print the deleted or peeked element
Print -1 if the queue is empty
Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek
Output:
10
20*/
#include <stdio.h>
#define MAX 5
int pq[MAX];
int n = 0;
void insert() 
{
    if (n == MAX) 
    {
        printf("Queue is Full\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &pq[n]);
    printf("Element %d inserted at position %d", pq[n], n);
    n++;
}
void deletePQ() 
{
    if (n == 0) 
    {
        printf("Queue is Empty\n");
        return;
    }
    int min = pq[0];
    int pos = 0;
    for (int i = 1; i < n; i++) 
    {
        if (pq[i] < min) 
        {
            min = pq[i];
            pos = i;
        }
    }
    printf("Deleted (highest priority): %d\n", min);
    for (int i = pos; i < n - 1; i++) 
    {
        pq[i] = pq[i + 1];
    }

    n--;
}
void display() 
{
    if (n == 0) 
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Elements: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", pq[i]);
    }
    printf("The value of n = %d", n);
}
int main() 
{
    int choice;
    while (1) 
    {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1: insert(); 
            break;
            case 2: deletePQ(); 
            break;
            case 3: display(); 
            break;
            case 4: 
            return 0;
            default: 
            printf("Invalid choice\n");
        }
    }
}